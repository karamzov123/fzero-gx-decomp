/* Non-matching: best partial attempt (93.00% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"

struct fn_1_B724_Arg0 {
    u8 pad_0[0x8];
    u32 unk_8;
};
struct fn_1_B724_Arg1 {
    u32 unk_0;
    u32 unk_4;
    u32 unk_8;
};
struct fn_1_B724_Copy8 { u32 a[2]; };
struct fn_1_B724_lbl_1_bss_1010 {
    u8 pad_0[0x4];
    u8 unk_4;
    u8 unk_5;
    u8 pad_6[0x26];
    f32 unk_2C;
    f32 unk_30;
    f32 unk_34;
    u8 unk_38;
    u8 unk_39;
    u8 pad_3A[0x2];
    u32 unk_3C;
};
struct fn_1_B724_lbl_1_rodata_400 {
    f32 unk_0;
    f32 unk_4;
    f32 unk_8;
};

extern f32 lbl_8006D0B4(f32);
extern struct fn_1_B724_lbl_1_bss_1010 lbl_1_bss_1010;
extern struct fn_1_B724_lbl_1_rodata_400 lbl_1_rodata_400;

f32 fn_1_B724(struct fn_1_B724_Arg0 *arg0, struct fn_1_B724_Arg1 *arg1, u32 arg2, f32 arg3) {
    struct fn_1_B724_lbl_1_bss_1010 *p_lbl_1_bss_1010;
    struct fn_1_B724_lbl_1_rodata_400 *p_lbl_1_rodata_400;
    void * v0;
    f32 vz;
    f32 vy;
    f32 vx;
    u32 v3;
    u32 v4;
    void * v12;
    f32 v13;
    f32 v14;
    f32 v15;
    f32 t0;
    p_lbl_1_bss_1010 = (struct fn_1_B724_lbl_1_bss_1010 *)&lbl_1_bss_1010;
    v0 = (void *)(((u8 *)(u32)p_lbl_1_bss_1010 + 8));
    p_lbl_1_rodata_400 = (struct fn_1_B724_lbl_1_rodata_400 *)&lbl_1_rodata_400;
    *(struct fn_1_B724_Copy8 *)((u8 *)v0 + 4) = *(struct fn_1_B724_Copy8 *)(u32)arg0;
    *(u32 *)((u8 *)v0 + 12) = arg0->unk_8;
    v3 = arg1->unk_0;
    v4 = arg1->unk_4;
    *(u32 *)((u8 *)v0 + 16) = v3;
    *(u32 *)((u8 *)v0 + 20) = v4;
    *(u32 *)((u8 *)v0 + 24) = arg1->unk_8;
    *(f32 *)((u8 *)v0 + 28) = arg3;
    *(u16 *)((u8 *)v0 + 32) = arg2;
    vx = *(f32 *)((u8 *)v0 + 4);
    vy = *(f32 *)((u8 *)v0 + 8);
    vz = *(f32 *)((u8 *)v0 + 12);
    vx = (f32)(vx - *(f32 *)((u8 *)v0 + 16));
    vy = (f32)(vy - *(f32 *)((u8 *)v0 + 20));
    vz = (f32)(vz - *(f32 *)((u8 *)v0 + 24));
    t0 = lbl_8006D0B4((f32)(vx * vx) + vy * vy + vz * vz);
    v12 = (void *)(((u8 *)(u32)p_lbl_1_bss_1010 + 60));
    v13 = p_lbl_1_rodata_400->unk_0;
    v14 = p_lbl_1_rodata_400->unk_4;
    v15 = p_lbl_1_rodata_400->unk_8;
    p_lbl_1_bss_1010->unk_2C = t0;
    p_lbl_1_bss_1010->unk_30 = v13;
    p_lbl_1_bss_1010->unk_34 = v14;
    p_lbl_1_bss_1010->unk_38 = 1;
    p_lbl_1_bss_1010->unk_39 = 1;
    p_lbl_1_bss_1010->unk_4 = 0;
    p_lbl_1_bss_1010->unk_5 = 0;
    p_lbl_1_bss_1010->unk_3C = 0;
    *(u32 *)((u8 *)v12 + 4) = 0;
    *(u32 *)((u8 *)v12 + 8) = 200;
    *(f32 *)((u8 *)v12 + 12) = v15;
    return t0;
}
