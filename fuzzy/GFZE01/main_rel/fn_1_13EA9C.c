/* Non-matching: best partial attempt (92.22% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"
#include "font.h"
#include "rel/main_rel/globals.h"

struct Copy17 { u32 w0; u32 w4; u32 w8; u32 wC; u8 b10; };
struct Copy29 { u32 w0; u32 w4; u32 w8; u32 wC; u32 w10; u32 w14; u32 w18; u8 b1C; };
struct F32_8E04 { f32 v; };
struct F32_8670 { f32 v; };
struct F32_87D0 { f32 v; };

extern struct Copy17 lbl_1_rodata_8E38;
extern struct Copy29 lbl_1_rodata_8E4C;
extern struct F32_8E04 lbl_1_rodata_8E04;
extern struct F32_8670 lbl_1_rodata_8670;
extern struct F32_87D0 lbl_1_rodata_87D0;
extern const f32 lbl_1_rodata_85EC;
extern const f32 lbl_1_rodata_85F0;
extern const f32 lbl_1_rodata_8648;
extern const f32 lbl_1_rodata_86C4;
extern const f32 lbl_1_rodata_8820;
extern const f32 lbl_1_rodata_8C70;
extern const f32 lbl_1_rodata_8E6C;
extern const f32 lbl_1_rodata_8E70;
extern const f32 lbl_1_rodata_8E74;
extern const f32 lbl_1_rodata_8E78;
extern const f32 lbl_1_rodata_8E7C;
extern const f32 lbl_1_rodata_8E80;
extern const f32 lbl_1_rodata_8E84;
extern const f32 lbl_1_rodata_8E88;
extern u32 lbl_1_rodata_26F8;
extern int fn_1_8623C(void);
extern void fn_1_50164(f32, f32, f32, f32, void *);
extern void fn_1_51564(u16 first, u16 second, u16 third, u16 fourth, u16 fifth, u16 sixth);
extern u32 fn_1_5158C(FontDrawPacket *, u32, u32, u32);
extern int fn_1_4F734(FontDrawPacket *);
extern void fn_1_49410(void);
extern void fn_1_496FC(f32, f32);
extern void fn_1_495C8(void *);
extern void fn_1_4955C(f32, f32);
extern void fn_1_4965C(u8);
extern void fn_1_495B0(u32);
extern void fn_1_49590(f32);
extern void fn_1_4CE48(Obj_1_bss_4B9CC *, f32);
extern u32 fn_1_53FE4(u32, u32);

static inline f32 fn_1_13EA9C_read_pointer(struct F32_8E04 * owner) { return owner->v; }
#pragma opt_common_subs off
void fn_1_13EA9C(void) {
    int t0;
    struct Copy17 loc_28;
    struct Copy29 loc_8;
    FontDrawPacket loc_3C;
    u32 a28;
    u32 a8;

    a28 = (u32)&loc_28;
    a8 = (u32)&loc_8;
    loc_28.w4 = lbl_1_rodata_8E38.w4;
    loc_28.w0 = lbl_1_rodata_8E38.w0;
    loc_28.w8 = lbl_1_rodata_8E38.w8;
    loc_28.wC = lbl_1_rodata_8E38.wC;
    loc_28.b10 = lbl_1_rodata_8E38.b10;
    loc_8.w0 = lbl_1_rodata_8E4C.w0;
    loc_8.w4 = lbl_1_rodata_8E4C.w4;
    loc_8.w8 = lbl_1_rodata_8E4C.w8;
    loc_8.wC = lbl_1_rodata_8E4C.wC;
    loc_8.w10 = lbl_1_rodata_8E4C.w10;
    loc_8.w14 = lbl_1_rodata_8E4C.w14;
    loc_8.w18 = lbl_1_rodata_8E4C.w18;
    loc_8.b1C = lbl_1_rodata_8E4C.b1C;
    t0 = fn_1_8623C();
    loc_3C = *(FontDrawPacket *)&lbl_1_rodata_26F8;
    loc_3C.image = 12;
    loc_3C.flags = 5;
    loc_3C.x = lbl_1_rodata_8E6C;
    loc_3C.y = lbl_1_rodata_8648;
    loc_3C.z = fn_1_13EA9C_read_pointer(&lbl_1_rodata_8E04);
    fn_1_50164(lbl_1_rodata_8670.v, lbl_1_rodata_87D0.v, lbl_1_rodata_86C4, lbl_1_rodata_86C4, (void *)&loc_3C);
    loc_3C = *(FontDrawPacket *)&lbl_1_rodata_26F8;
    loc_3C.image = (0x10000 - 25068);
    fn_1_51564(0, 0, 24, 20, 2, 2);
    {
        int v7 = (u32)t0 >> 31;
        fn_1_5158C(&loc_3C, loc_3C.image, (s16)(((t0 & 1) ^ v7) - v7), (s16)((v7 + t0) >> 1));
    }
    loc_3C.x = lbl_1_rodata_8E70;
    loc_3C.y = lbl_1_rodata_8E74;
    loc_3C.z = lbl_1_rodata_8E78;
    loc_3C.scale_x = loc_3C.scale_x * lbl_1_rodata_85EC;
    loc_3C.scale_y = loc_3C.scale_y * lbl_1_rodata_85EC;
    loc_3C.flags = 9;
    fn_1_4F734(&loc_3C);
    fn_1_49410();
    fn_1_496FC(lbl_1_rodata_8820, lbl_1_rodata_8E74);
    fn_1_495C8((void *)8);
    fn_1_4955C(lbl_1_rodata_8C70, lbl_1_rodata_8C70);
    fn_1_4965C(2);
    fn_1_495B0(0x40000000);
    fn_1_49590(lbl_1_rodata_85F0);
    fn_1_4CE48((Obj_1_bss_4B9CC *)a28, lbl_1_rodata_8E7C);
    loc_3C = *(FontDrawPacket *)&lbl_1_rodata_26F8;
    loc_3C.y = lbl_1_rodata_8E74;
    loc_3C.x = lbl_1_rodata_8E80;
    loc_3C.z = lbl_1_rodata_8E78;
    loc_3C.flags = 10;
    loc_3C.image = (0x10000 - 27392);
    fn_1_53FE4((u32)&loc_3C, 0);
    fn_1_49410();
    fn_1_496FC(lbl_1_rodata_8E84, lbl_1_rodata_8E74);
    fn_1_495C8((void *)8);
    fn_1_4955C(lbl_1_rodata_8C70, lbl_1_rodata_8C70);
    fn_1_4965C(2);
    fn_1_495B0(0x40000000);
    fn_1_49590(lbl_1_rodata_85F0);
    fn_1_4CE48((Obj_1_bss_4B9CC *)&loc_8, lbl_1_rodata_8E88);
}
#pragma opt_common_subs reset

