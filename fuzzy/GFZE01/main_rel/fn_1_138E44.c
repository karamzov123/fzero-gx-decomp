/* Non-matching: best partial attempt (92.61% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"
#include "font.h"

typedef struct {
    u8 pad_0[0xE];
    s16 unk_E;
    u8 pad_10[0x10];
} fn_1_138E44_Ent;

extern const f32 lbl_1_rodata_85EC;
extern const f32 lbl_1_rodata_861C;
extern const f32 lbl_1_rodata_863C;
extern const f32 lbl_1_rodata_86D0;
extern const f32 lbl_1_rodata_87DC;
extern const f32 lbl_1_rodata_8A50;
extern const f32 lbl_1_rodata_8B40;
extern const f32 lbl_1_rodata_8B84;
extern int fn_1_4F734(FontDrawPacket *);
extern void fn_1_5158C(FontDrawPacket *, u32, s16, s16);
extern f32 lbl_1_rodata_26F8[22];
extern fn_1_138E44_Ent lbl_1_bss_8B3A0[1];
extern u32 fn_1_141F94(u8);
extern const u8 lbl_1_data_40F58[];
extern void fn_1_135D7C(s16, s16, u32, s16, u32, s16, u32, f32, f32, f32);
extern u32 fn_1_136CC4(u32, u32, u32, s16);
extern void fn_1_49410(void);
extern void fn_1_494DC(s16);
extern void fn_1_4954C(f32);
extern void fn_1_4955C(f32, f32);
extern void fn_1_495C8(void *);
extern void fn_1_4966C(f32, f32);
extern void fn_1_496FC(f32, f32);
extern void fn_1_4A0D8(const char *);
extern void fn_1_51564(u16, u16, u16, u16, u16, u16);

#pragma opt_dead_assignments off
void fn_1_138E44(s32 arg0, u32 arg1, u32 arg2) {
    s32 c;
    s32 a;
    u16 v10;
    u32 s;
    u32 m;
    u16 b;
    u32 w;
    s16 v0;
    const char *strs;
    FontDrawPacket loc;
    s16 lab_t1;
    u8 v11;

    strs = (const char *)lbl_1_data_40F58;
    v0 = lbl_1_bss_8B3A0[arg2].unk_E;
    w = fn_1_141F94(arg2);
    loc = *(FontDrawPacket *)&lbl_1_rodata_26F8;
    b = w & 0xFF;
    loc.image = 0x10000 - 25332;
    loc.x = (f32)(s32)arg0;
    loc.y = (f32)(s32)arg1;
    loc.z = (f32)(100 - b);
    fn_1_4F734(&loc);
    fn_1_51564(0, 0, 24, 20, 2, 2);

    loc = *(FontDrawPacket *)&lbl_1_rodata_26F8;
    m = b & 1;
    s = b >> 31;
    v11 = (s16)((m ^ s) - s);
    v10 = (s16)((w >> 1) & 0x7F);
    loc.image = 0x10000 - 25333;
    loc.x = (f32)(s32)(arg0 + 18);
    loc.y = (f32)(s32)(arg1 + 18);
    loc.z = lbl_1_rodata_86D0;
    loc.flags = 10;
    fn_1_5158C(&loc, loc.image, v11, v10);
    fn_1_4F734(&loc);

    loc = *(FontDrawPacket *)&lbl_1_rodata_26F8;
    loc.image = 0x10000 - 25336;
    loc.x = (f32)(s32)(arg0 + 7);
    loc.y = (f32)(s32)(arg1 + 33);
    loc.z = lbl_1_rodata_86D0;
    fn_1_4F734(&loc);

    fn_1_135D7C((s16)(arg0 + 36), (lab_t1 = (s16)(arg1 + 18)), 9, v0, 0, (s16)arg2, 0, lbl_1_rodata_8A50, lbl_1_rodata_8A50, lbl_1_rodata_87DC);
    fn_1_136CC4(arg0 + 16, arg1 + 42, v0, (s16)arg2);
    fn_1_49410();
    fn_1_495C8((void *)10);
    fn_1_494DC(4);
    fn_1_4966C(lbl_1_rodata_8B40, lbl_1_rodata_861C);
    fn_1_4954C(lbl_1_rodata_8B84);

    a = v11 * 301;
    c = v10 * 201 + 242;
    fn_1_496FC((f32)(a + 312), (f32)c);
    fn_1_4A0D8(&strs[2984]);
    fn_1_49410();
    fn_1_495C8((void *)10);
    fn_1_4954C(lbl_1_rodata_863C);
    fn_1_4955C(lbl_1_rodata_85EC, lbl_1_rodata_85EC);
    fn_1_496FC((f32)(a + 218), (f32)c);
    fn_1_4A0D8(&strs[3000]);
    fn_1_4954C(lbl_1_rodata_863C);
    fn_1_496FC((f32)(a + 290), (f32)c);
    fn_1_4A0D8(&strs[3008]);
}
#pragma opt_dead_assignments reset

