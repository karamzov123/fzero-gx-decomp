#include "types.h"
#include "rel/sel/name_entry.h"

struct fn_10_266AC_D {
    u32 unk_0;
    f32 unk_4;
    f32 unk_8;
    f32 unk_C;
    u8 pad_10[0x20];
    u32 unk_30;
    u8 pad_34[0x24];
};
struct fn_10_266AC_S {
    u32 color;
    struct fn_10_266AC_D d;
};
struct fn_10_266AC_pool {
    u8 pad_0[0x38];
    f32 unk_38, unk_3C, unk_40, unk_44, unk_48, unk_4C, unk_50;
    f32 unk_54, unk_58, unk_5C, unk_60, unk_64, unk_68, unk_6C;
    u8 pad_70[0x38];
    u32 unk_A8;
    f32 unk_AC, unk_B0, unk_B4;
};
extern struct fn_10_266AC_pool lbl_10_rodata_1D70;
extern struct fn_10_266AC_D lbl_1_rodata_26F8;
extern u32 lbl_801A66B4;
extern u32 fn_10_261E4(u32, u32);
extern u32 fn_1_4AEC0(u32);
extern u8 fn_1_B7C00(void);
extern void fn_1_49410(void);
extern void fn_1_4954C(f32);
extern void fn_1_4955C(f32, f32);
extern void fn_1_49590(f32);
extern void fn_1_495B0(u32);
extern void fn_1_495C8(u8);
extern void fn_1_4966C(f32, f32);
extern void fn_1_496FC(f32, f32);
extern void fn_1_4A0D8(const char *);
extern void fn_1_4AEB4(f32);
extern void fn_1_4FD64(void);
extern void fn_1_50164(void *, f32, f32, f32, f32);
extern void fn_8003462C(u32, u32, u32);
extern void fn_800371F8(s32, void *);
extern void fn_8007245C(u32);
extern void fn_80072864(u32);
extern void fn_800728A8(s32, s32, s32, s32);
extern void fn_80072AB0(s32, s32, s32);
extern void fn_80072C24(s32, s32, s32, s32, s32);
extern void fn_80072CC4(s32, s32, s32, s32, s32);
extern void fn_80072D64(s32, s32, s32, s32, u8, s32);
extern void fn_80072E20(s32, s32, s32, s32, u8, s32);
extern void fn_800734A8(u32, s32, s32, s32);
extern void fn_80073678(u32);
extern void fn_80073C6C(s32);
extern void fn_80074660(u32);
extern void fn_80074788(u32);
extern void fn_800747D0(u32, u32, s32, s32, u32, s32, s32);
extern void fn_80074918(u8, s32, u8);

static inline f32 fn_10_266AC_read_pointer(struct fn_10_266AC_pool * owner) { return owner->unk_58; }
#pragma opt_common_subs off
void fn_10_266AC(void) {
    struct fn_10_266AC_S loc;
    struct fn_10_266AC_pool *p = &lbl_10_rodata_1D70;
    u32 str;
    u32 v;
    u32 lab_t0;
    if (fn_1_B7C00() != 0 || lbl_10_bss_55CE1 != 0) {
    fn_1_4FD64();
    fn_80074918(0, 7, 0);
    fn_80074788(1);
    lab_t0 = 0;
    fn_80074660(lab_t0);
    fn_80073678(1);
    fn_80073C6C(0);
    fn_800747D0(4, 0, 0, 0, 0, 2, 2);
    fn_80072AB0(0, 0, 0);
    fn_800734A8(0, 255, 255, 4);
    fn_80072C24(0, 15, 15, 15, 2);
    fn_80072D64(0, 0, 0, 0, 1, 0);
    fn_80072CC4(0, 7, 7, 7, 1);
    fn_80072E20(0, 0, 0, 0, 1, 0);
    fn_800728A8(1, 4, 5, 0);
    fn_80072864(2);
    fn_8007245C(512);
    loc.color = p->unk_A8;
    fn_800371F8(1, (void *)&loc.color);
    fn_8003462C(128, 7, 4);
    *(f32 *)((u8 *)0xCC010000 - 32768) = p->unk_6C;  /* fzgx-allow: A1,A2 GX write-gather FIFO hardware address */
    *(f32 *)((u8 *)0xCC010000 - 32768) = p->unk_6C;  /* fzgx-allow: A1,A2 GX write-gather FIFO hardware address */
    *(f32 *)((u8 *)0xCC010000 - 32768) = p->unk_64;  /* fzgx-allow: A1,A2 GX write-gather FIFO hardware address */
    *(f32 *)((u8 *)0xCC010000 - 32768) = p->unk_AC;  /* fzgx-allow: A1,A2 GX write-gather FIFO hardware address */
    *(f32 *)((u8 *)0xCC010000 - 32768) = p->unk_6C;  /* fzgx-allow: A1,A2 GX write-gather FIFO hardware address */
    *(f32 *)((u8 *)0xCC010000 - 32768) = p->unk_64;  /* fzgx-allow: A1,A2 GX write-gather FIFO hardware address */
    *(f32 *)((u8 *)0xCC010000 - 32768) = p->unk_AC;  /* fzgx-allow: A1,A2 GX write-gather FIFO hardware address */
    *(f32 *)((u8 *)0xCC010000 - 32768) = p->unk_B0;  /* fzgx-allow: A1,A2 GX write-gather FIFO hardware address */
    *(f32 *)((u8 *)0xCC010000 - 32768) = p->unk_64;  /* fzgx-allow: A1,A2 GX write-gather FIFO hardware address */
    *(f32 *)((u8 *)0xCC010000 - 32768) = p->unk_6C;  /* fzgx-allow: A1,A2 GX write-gather FIFO hardware address */
    *(f32 *)((u8 *)0xCC010000 - 32768) = p->unk_B0;  /* fzgx-allow: A1,A2 GX write-gather FIFO hardware address */
    *(f32 *)((u8 *)0xCC010000 - 32768) = p->unk_64;  /* fzgx-allow: A1,A2 GX write-gather FIFO hardware address */
    }
    if (lbl_10_bss_55CE1 != 0) {
    *(struct fn_10_266AC_D *)((u8 *)&loc + 4) = lbl_1_rodata_26F8;
    loc.d.unk_0 = 2;
    loc.d.unk_4 = p->unk_38;
    loc.d.unk_8 = p->unk_3C;
    loc.d.unk_C = p->unk_40;
    loc.d.unk_30 = 10;
    fn_1_50164((void *)&loc.d, p->unk_44, p->unk_48, p->unk_4C, p->unk_50);
    str = ((u32 *)lbl_10_data_6B2C)[lbl_801A66B4];
    v = fn_1_4AEC0(1);
    fn_1_4AEB4(p->unk_54);
    fn_1_49410();
    fn_1_4955C(fn_10_266AC_read_pointer(p), fn_10_266AC_read_pointer(p));
    fn_1_4954C(p->unk_5C);
    fn_1_495B0(0x80000000);
    fn_1_49590(p->unk_60);
    fn_1_495C8(9);
    fn_1_496FC(p->unk_38, p->unk_B4);
    fn_1_4966C(p->unk_64, p->unk_68);
    fn_1_4A0D8((const char *)str);
    v = fn_1_4AEC0(0);
    fn_1_4AEB4(p->unk_6C);
    fn_10_261E4(0x118, lbl_10_bss_55CE2);
    }
}
#pragma opt_common_subs reset

