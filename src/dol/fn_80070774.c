#include "types.h"

struct Sig_GXInitFifoBase_GXInitFifoBase_Arg0 {
    u32 unk_0;
    u32 unk_4;
    u8 unk_8;
    u8 pad_C[0x10];
    u32 unk_1C;
};
struct Sig_GXInitFifoPtrs_GXInitFifoPtrs_Arg0 {
    u8 pad_0[0x8];
    u32 unk_8;
    u8 pad_C[0x8];
    u32 unk_14;
    u32 unk_18;
    s32 unk_1C;
};
typedef u8 Sig_fn_80034ECC_GXBool;
typedef enum Sig_fn_80037C2C__GXPixelFmt {
    Sig_fn_80037C2C_GX_PF_RGB8_Z24,
    Sig_fn_80037C2C_GX_PF_RGBA6_Z24,
    Sig_fn_80037C2C_GX_PF_RGB565_Z16,
    Sig_fn_80037C2C_GX_PF_Z24,
    Sig_fn_80037C2C_GX_PF_Y8,
    Sig_fn_80037C2C_GX_PF_U8,
    Sig_fn_80037C2C_GX_PF_V8,
    Sig_fn_80037C2C_GX_PF_YUV420,
} Sig_fn_80037C2C_GXPixelFmt;
typedef enum Sig_fn_80037C2C__GXZFmt16 {
    Sig_fn_80037C2C_GX_ZC_LINEAR,
    Sig_fn_80037C2C_GX_ZC_NEAR,
    Sig_fn_80037C2C_GX_ZC_MID,
    Sig_fn_80037C2C_GX_ZC_FAR,
} Sig_fn_80037C2C_GXZFmt16;
typedef u8 Sig_fn_80037D14_GXBool;
typedef u8 Sig_fn_80035110_GXBool;

struct fn_80070774_lbl_801A6CF4_T {
    u32 unk_0;
    u16 unk_4;
    u16 unk_6;
    u16 unk_8;
    u8 pad_A[0xF];
    u8 unk_19;
    u8 unk_1A[0x18];
    u8 unk_32[0];
};
struct fn_80070774_lbl_801A6D30_T {
    u32 unk_0;
    u32 unk_4;
    u32 unk_8;
    u32 unk_C;
    u32 unk_10;
    u32 unk_14;
    u32 unk_18;
};

extern f32 lbl_801A7410;
extern f32 lbl_801A7414;
extern f64 lbl_801A7418;
extern s32 VIConfigure(u32 *);
extern struct fn_80070774_lbl_801A6CF4_T *lbl_801A6CF4;
extern struct fn_80070774_lbl_801A6D30_T *lbl_801A6D30;
extern u32 GXInit(u32, u32);
extern u32 GXSetDispCopyYScale(f32);
extern u32 fn_80037D40(u32, u32);
extern u32 fn_80038EEC(f32, f32, f32, f32, f32, f32);
extern u32 fn_80070CF8(u32);
extern void fn_80071D30(void);
extern void fn_80074188(u32, u32, u32, u32);
extern void fn_8007423C(u32, u32, u32, u32);
extern void fn_800743C4(s32, u32);
extern void fn_800744F8(void *, u32);
extern void fn_80034ECC(u8, u8 *, u32, u8 *);
extern void fn_80037C2C(Sig_fn_80037C2C_GXPixelFmt, Sig_fn_80037C2C_GXZFmt16);
extern void fn_80037D14(Sig_fn_80037D14_GXBool);
extern u8 lbl_8019E18C[];
extern u32 lbl_801A6CE0;
extern u32 lbl_801A6CE4;
extern u32 lbl_801A7918;
extern void DCFlushRange(void *, u32);
extern void GXInitFifoBase(struct Sig_GXInitFifoBase_GXInitFifoBase_Arg0 *, u32, u32);
extern void GXInitFifoPtrs(struct Sig_GXInitFifoPtrs_GXInitFifoPtrs_Arg0 *, u32, u32);
extern void VIWaitForRetrace(void);
extern void VIFlush(void);
extern void VISetNextFrameBuffer(u32);
extern void GXSetDispCopyGamma(u32);
extern void fn_80035110(void *, Sig_fn_80035110_GXBool);

static inline u8 * fn_80070774_read_pointer(struct fn_80070774_lbl_801A6CF4_T * owner) { return owner->unk_1A; }
#pragma opt_common_subs off
void fn_80070774(u32 arg0, u32 arg1, u32 arg2) {
    u32 t7;
    u32 t5;
    u32 t4;
    struct { u32 value; } t2;
    struct { u32 value; } t0;
    s32 v5;
    u32 v4;
    u32 v3;
    struct { u32 value; } v2;
    struct { u32 value; } v1;
    u32 v0;
    u32 loc_8;

    v0 = (((((lbl_801A6CF4->unk_4 + 15) & 0xFFF0) * 528) << 1));
    t0.value = fn_80070CF8(v0);
    v1.value = ((v0 + 31) & ~0x1F);
    DCFlushRange((void *)t0.value, v1.value);
    if ((lbl_801A6CE0 & 0x10) == 0) {
        t2.value = fn_80070CF8(v0);
        v2.value = t2.value;
        DCFlushRange((void *)t2.value, v1.value);
    }
    t4 = fn_80070CF8(arg1);
    lbl_801A6CE4 = arg1;
    t5 = GXInit(t4, arg1);
    lbl_801A6D30->unk_14 = t5;
    if ((s32)arg0 != 0) {
        lbl_801A6CE0 = (lbl_801A6CE0 | 4);
        lbl_801A6D30->unk_18 = (u32)lbl_8019E18C;
{
    u32 t6;
        t4 = fn_80070CF8(arg1);
        t6 = t4;
        GXInitFifoBase((struct Sig_GXInitFifoBase_GXInitFifoBase_Arg0 *)(u32)lbl_8019E18C, t6, arg1);
        GXInitFifoPtrs((struct Sig_GXInitFifoPtrs_GXInitFifoPtrs_Arg0 *)(u32)lbl_8019E18C, t6, t6);
}
    }
    lbl_801A6D30->unk_4 = t0.value;
    if ((lbl_801A6CE0 & 0x10) != 0) {
        lbl_801A6D30->unk_8 = t0.value;
    } else {
        lbl_801A6D30->unk_8 = v2.value;
    }
    lbl_801A6D30->unk_0 = lbl_801A6D30->unk_8;
    lbl_801A6D30->unk_C = 0;
    lbl_801A6D30->unk_10 = 0;
    fn_80071D30();
    fn_80038EEC(0.0f, 0.0f, (f32)(u32)lbl_801A6CF4->unk_4, (f32)(u32)lbl_801A6CF4->unk_6,
                0.0f, 1.0f);
    fn_80074188(0, 0, lbl_801A6CF4->unk_4, lbl_801A6CF4->unk_6);
    fn_8007423C(0, 0, lbl_801A6CF4->unk_4, lbl_801A6CF4->unk_6);
    fn_800743C4(lbl_801A6CF4->unk_4, lbl_801A6CF4->unk_8);
    GXSetDispCopyYScale((f32)(u32)lbl_801A6CF4->unk_8 / (f32)(u32)lbl_801A6CF4->unk_6);
    fn_80034ECC(lbl_801A6CF4->unk_19, fn_80070774_read_pointer(lbl_801A6CF4), 1, lbl_801A6CF4->unk_32);
    if ((s32)arg2 != 0) {
        fn_80037C2C(Sig_fn_80037C2C_GX_PF_RGBA6_Z24, Sig_fn_80037C2C_GX_ZC_LINEAR);
        fn_80037D14(1);
        fn_80037D40(1, 0);
    } else {
        fn_80037C2C(Sig_fn_80037C2C_GX_PF_RGB8_Z24, Sig_fn_80037C2C_GX_ZC_LINEAR);
        fn_80037D14(0);
    }
    loc_8 = lbl_801A7918;
    fn_800744F8((void *)&loc_8, 0xFFFFFF);
    fn_80035110((void *)lbl_801A6D30->unk_4, 1);
    fn_80035110((void *)lbl_801A6D30->unk_8, 0);
    fn_80035110((void *)lbl_801A6D30->unk_4, 0);
    GXSetDispCopyGamma(0);
    VIConfigure((u32 *)lbl_801A6CF4);
    VISetNextFrameBuffer(t0.value);
    VIFlush();
    VIWaitForRetrace();
    if ((lbl_801A6CF4->unk_0 & 0x1) != 0) {
        VIWaitForRetrace();
    }
}
#pragma opt_common_subs reset

