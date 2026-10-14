/* Non-matching: best partial attempt (95.69% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"
#include "rel/option/globals.h"
#include "font.h"
struct fn_4_2D4_Copy88 { u32 a[22]; };
struct fn_4_2D4_lbl_4_rodata_0 {
    u8 pad_0[8]; f32 unk_8; u32 unk_C;
    f64 unk_10; f64 unk_18; u8 pad_20[8]; f64 unk_28; f64 unk_30;
    u8 pad_38[12]; f32 unk_44; f32 unk_48; u8 pad_4C[4];
    f32 unk_50; u8 pad_54[4]; f32 unk_58; u8 pad_5C[4];
    f64 unk_60; f64 unk_68; u8 pad_70[16]; f32 unk_80; f32 unk_84;
    f64 unk_88; f64 unk_90; f64 unk_98; f32 unk_A0; u8 pad_A4[4];
    f64 unk_A8; f32 unk_B0; f32 unk_B4; f32 unk_B8;
};
struct fn_4_2D4_lbl_801A66B4 { u32 unk_0[1]; };
#define unk_0 unk_0[0]
struct fn_4_2D4_TableView { u32 entries[9]; };
#define TABLE(base, off) (((struct fn_4_2D4_TableView *)((base) + (off)))->entries)
extern struct fn_4_2D4_lbl_4_rodata_0 lbl_4_rodata_0;
extern struct fn_4_2D4_lbl_801A66B4 lbl_801A66B4;
extern u32 fn_1_5233C();
extern void fn_1_49410(void);
extern void fn_1_4954C(f32);
extern void fn_1_49590(f32);
extern void fn_1_495B0(u32);
extern void fn_1_495C8(u8);
extern void fn_1_496FC(f32, f32);
extern void fn_1_49738(u32);
extern void fn_1_49748(f32);
extern void fn_1_4AE0C(const char *, ...);
extern f32 fn_1_4B040(u32);
extern s16 lbl_1_bss_962;
extern struct fn_4_2D4_Copy88 lbl_1_rodata_26F8;
extern f32 lbl_8006D188(s16);
extern int fn_1_4F734(FontDrawPacket *);
extern void fn_1_53BD8(void *, f32, f32, f32, f32, f32);
#pragma opt_dead_assignments off
static inline f64 fn_4_2D4_read_pointer(struct fn_4_2D4_lbl_4_rodata_0 * owner) { return owner->unk_A8; }
#pragma opt_propagation off
#pragma opt_loop_invariants off
void fn_4_2D4(u32 arg0, u32 arg1, f64 arg2) {
    f64 fzgx_live;
    s32 state;
    f32 sy;
    f32 sx;
    f32 y;
    u32 lab_t0_2;
    f32 x;
    f64 product;
    f64 direction;
    f32 z;
    f64 center;
    f64 half;
    f32 span;
    f32 right;
    f32 left;
    f32 width;
    struct fn_4_2D4_lbl_4_rodata_0 *p_lbl_4_rodata_0;
    u8 *p_lbl_4_data_0;
    struct fn_4_2D4_Copy88 packet;
    u32 lab_t0;
    p_lbl_4_data_0 = (u8 *)&lbl_4_data_0;
    p_lbl_4_rodata_0 = (struct fn_4_2D4_lbl_4_rodata_0 *)&lbl_4_rodata_0;
    fn_1_49410();
    fn_1_495C8(9);
    fn_1_4954C(p_lbl_4_rodata_0->unk_80);
    fn_1_49738((u32)fn_1_5233C);
    fn_1_49748(p_lbl_4_rodata_0->unk_48);
    if ((s32)lbl_801A66B4.unk_0 != 5) {
        fn_1_495B0(0x80000000);
        fn_1_49590(p_lbl_4_rodata_0->unk_8);
    }
    fn_1_496FC(p_lbl_4_rodata_0->unk_50, p_lbl_4_rodata_0->unk_84);
    fn_1_4AE0C((const char *)(p_lbl_4_data_0 + 0x1210), arg1);
    lab_t0 = arg1;
    width = fn_1_4B040(lab_t0);
    {
        struct fn_4_2D4_lbl_801A66B4 *mode = &lbl_801A66B4;
        u32 index = mode->unk_0;
        u32 *table = TABLE(p_lbl_4_data_0, 0x584);
        lab_t0_2 = table[index];
    }
    left = fn_1_4B040(lab_t0_2);
    {
        struct fn_4_2D4_lbl_801A66B4 *mode = &lbl_801A66B4;
        u32 *table = TABLE(p_lbl_4_data_0, 0x5A8);
        lab_t0_2 = table[mode->unk_0];
    }
    right = fn_1_4B040(lab_t0_2);
    if (left > right) right = left;
    span = p_lbl_4_rodata_0->unk_88 + right;
    half = p_lbl_4_rodata_0->unk_98 * span;
    fzgx_live = p_lbl_4_rodata_0->unk_90;
    fn_1_496FC(fzgx_live - half, p_lbl_4_rodata_0->unk_A0);
    {
        u32 *table = TABLE(p_lbl_4_data_0, 0x584);
        struct fn_4_2D4_lbl_801A66B4 *mode = &lbl_801A66B4;
        fn_1_4AE0C((const char *)(p_lbl_4_data_0 + 0x1210), table[mode->unk_0]);
    }
{
    f64 fzgx_live_2;
    fzgx_live_2 = p_lbl_4_rodata_0->unk_90;
    fn_1_496FC(fzgx_live_2 + half, p_lbl_4_rodata_0->unk_A0);
    {
        u32 *table = TABLE(p_lbl_4_data_0, 0x5A8);
        struct fn_4_2D4_lbl_801A66B4 *mode = &lbl_801A66B4;
        fn_1_4AE0C((const char *)(p_lbl_4_data_0 + 0x1210), table[mode->unk_0]);
    }
    if (span + right > width) width = span + right;
    if (p_lbl_4_data_0[0x1213] != arg0 || *(s16 *)(p_lbl_4_data_0 + 0x1214) != lbl_1_bss_962) {
        lbl_4_bss_2 = 0;
        state = (s16)(lbl_1_bss_962);
        p_lbl_4_data_0[0x1213] = arg0;
        *(s16 *)(p_lbl_4_data_0 + 0x1214) = state;
    }
    packet = lbl_1_rodata_26F8;
    packet.a[0] = 18;
    fzgx_live_2 = p_lbl_4_rodata_0->unk_90;
    center = fzgx_live_2;
}
    direction = arg0 == 0 ? fn_4_2D4_read_pointer(p_lbl_4_rodata_0) : p_lbl_4_rodata_0->unk_98;
    product = span * direction;
    y = p_lbl_4_rodata_0->unk_A0;
    sx = (right + p_lbl_4_rodata_0->unk_10) * p_lbl_4_rodata_0->unk_18;
{
    f32 zl;
    zl = p_lbl_4_rodata_0->unk_B0;
    z = zl;
    sy = p_lbl_4_rodata_0->unk_44;
    x = center + product;
    *(f32 *)&packet.a[2] = y;
    *(f32 *)&packet.a[1] = x;
    *(f32 *)&packet.a[3] = z;
}
    *(f32 *)&packet.a[4] = sx;
    *(f32 *)&packet.a[5] = sy;
    packet.a[12] = 10;
    *(f32 *)&packet.a[11] = p_lbl_4_rodata_0->unk_28 * (p_lbl_4_rodata_0->unk_30 + lbl_8006D188((s16)(0x4000 + (lbl_4_bss_2 << 10))));
    packet.a[14] = p_lbl_4_rodata_0->unk_C;
    fn_1_4F734((FontDrawPacket *)&packet);
    fn_1_53BD8(0, p_lbl_4_rodata_0->unk_50, p_lbl_4_rodata_0->unk_58, p_lbl_4_rodata_0->unk_60 + width, p_lbl_4_rodata_0->unk_68 + p_lbl_4_rodata_0->unk_B4, p_lbl_4_rodata_0->unk_B8);
}
#pragma opt_loop_invariants reset

#pragma opt_propagation reset

#pragma opt_dead_assignments reset
