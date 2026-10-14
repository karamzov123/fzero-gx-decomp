/* Non-matching: best partial attempt (93.33% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"

struct fn_80071D30_lbl_8019E250 {
    u8 unk_0;
    u8 unk_1;
    u8 unk_2;
    u8 unk_3;
    u8 pad_4[0x1C];
    u32 unk_20;
    u8 pad_24[0x8];
    u32 unk_2C;
    u32 unk_30;
    u32 unk_34;
    u8 pad_38[0x80];
};

extern f32 lbl_801A744C;
extern f32 lbl_801A7450;
extern f32 lbl_801A7454;
extern f32 lbl_801A7458;
extern f32 lbl_801A745C;
extern struct fn_80071D30_lbl_8019E250 lbl_8019E250;
extern u32 fn_800720B0(u32);
extern u32 fn_800793D4(u8 *, u32, u32);
extern u32 lbl_801A6D2C;
extern u32 lbl_801A7448;
extern u32 lbl_801A7920;
extern void fn_80071ED4(f32, f32, s32);
extern void fn_800721FC(f32, f32, f32, f32);
extern void fn_800725DC(u32 *);
extern void fn_80072614(u32 *);

void fn_80071D30(void) {
    struct fn_80071D30_lbl_8019E250 *p;
    void * v1;
    u32 v2;
    void * v3;
    struct { u32 a[3]; } loc_C;
    u32 loc_8;
    /* frame */
    p = &lbl_8019E250;
    v1 = (void *)((u8 *)p + 56);
    loc_C.a[2] = lbl_801A7920;
    loc_C.a[1] = lbl_801A7448;
    p->unk_2C = 0;
    p->unk_0 = 0;
    p->unk_1 = 0;
    p->unk_2 = 0;
    p->unk_3 = 0;
    lbl_801A6D2C = (u32)(v1);
    v3 = v1;
    for (v2 = 2; v2 != 0; v2--) {
    *(s8 *)((u8 *)v3 + 0) = -1;
    *(s8 *)((u8 *)v3 + 1) = -1;
    *(s8 *)((u8 *)v3 + 2) = -1;
    *(s8 *)((u8 *)v3 + 3) = -1;
    *(s8 *)((u8 *)v3 + 4) = -1;
    *(s8 *)((u8 *)v3 + 5) = -1;
    *(s8 *)((u8 *)v3 + 8) = -1;
    *(s8 *)((u8 *)v3 + 9) = -1;
    *(s8 *)((u8 *)v3 + 10) = -1;
    *(s8 *)((u8 *)v3 + 11) = -1;
    *(s8 *)((u8 *)v3 + 12) = -1;
    *(s8 *)((u8 *)v3 + 13) = -1;
    *(s8 *)((u8 *)v3 + 16) = -1;
    *(s8 *)((u8 *)v3 + 17) = -1;
    *(s8 *)((u8 *)v3 + 18) = -1;
    *(s8 *)((u8 *)v3 + 19) = -1;
    *(s8 *)((u8 *)v3 + 20) = -1;
    *(s8 *)((u8 *)v3 + 21) = -1;
    *(s8 *)((u8 *)v3 + 24) = -1;
    *(s8 *)((u8 *)v3 + 25) = -1;
    *(s8 *)((u8 *)v3 + 26) = -1;
    *(s8 *)((u8 *)v3 + 27) = -1;
    *(s8 *)((u8 *)v3 + 28) = -1;
    *(s8 *)((u8 *)v3 + 29) = -1;
    *(s8 *)((u8 *)v3 + 32) = -1;
    *(s8 *)((u8 *)v3 + 33) = -1;
    *(s8 *)((u8 *)v3 + 34) = -1;
    *(s8 *)((u8 *)v3 + 35) = -1;
    *(s8 *)((u8 *)v3 + 36) = -1;
    *(s8 *)((u8 *)v3 + 37) = -1;
    *(s8 *)((u8 *)v3 + 40) = -1;
    *(s8 *)((u8 *)v3 + 41) = -1;
    *(s8 *)((u8 *)v3 + 42) = -1;
    *(s8 *)((u8 *)v3 + 43) = -1;
    *(s8 *)((u8 *)v3 + 44) = -1;
    *(s8 *)((u8 *)v3 + 45) = -1;
    *(s8 *)((u8 *)v3 + 48) = -1;
    *(s8 *)((u8 *)v3 + 49) = -1;
    *(s8 *)((u8 *)v3 + 50) = -1;
    *(s8 *)((u8 *)v3 + 51) = -1;
    *(s8 *)((u8 *)v3 + 52) = -1;
    *(s8 *)((u8 *)v3 + 53) = -1;
    *(s8 *)((u8 *)v3 + 56) = -1;
    *(s8 *)((u8 *)v3 + 57) = -1;
    *(s8 *)((u8 *)v3 + 58) = -1;
    *(s8 *)((u8 *)v3 + 59) = -1;
    *(s8 *)((u8 *)v3 + 60) = -1;
    *(s8 *)((u8 *)v3 + 61) = -1;
    v3 = (void *)((u8 *)v3 + 64);
    }
    fn_800793D4((u8 *)((u8 *)p + 184), 255, 3328);
    p->unk_20 = loc_C.a[2];
    p->unk_30 = loc_C.a[2];
    p->unk_34 = loc_C.a[2];
    fn_800721FC(lbl_801A744C, lbl_801A7450, lbl_801A7454, lbl_801A7458);
    fn_80071ED4(lbl_801A745C, lbl_801A745C, 4);
    fn_800720B0(0);
    loc_C.a[0] = loc_C.a[1];
    fn_800725DC((u32 *)&loc_C.a[0]);
    loc_8 = loc_C.a[1];
    fn_80072614((u32 *)&loc_8);
}
