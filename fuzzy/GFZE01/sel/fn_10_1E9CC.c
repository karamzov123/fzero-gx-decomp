/* Non-matching: best partial attempt (58.89% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"
#include "font.h"
typedef struct {
    u32 f0; u32 f4; u8 pad8[8]; u32 f10; u32 f14; u32 f18; u32 f1C;
    u32 f20; u32 f24; u32 f28; u8 pad2C[0xC]; u32 f38; u32 f3C;
    u32 f40; u8 pad44[8]; u32 f4C;
} Sig_fn_10_1E6F4_Obj;
union Copy88 { u32 a[22]; f32 f[22]; };
struct Pool {
    u8 pad_0[0x44]; f32 unk_44, unk_48, unk_4C; u8 pad_50[8]; f32 unk_58;
    u8 pad_5C[0x2C]; f64 unk_88, unk_90; u8 pad_98[0xA0]; f32 unk_138;
    u8 pad_13C[0x38]; f32 unk_174; u8 pad_178[0x10C]; f32 unk_284;
    u8 pad_288[0x14]; f32 unk_29C; u8 pad_2A0[4]; f32 unk_2A4;
    u8 pad_2A8[0xBC]; f32 unk_364; u8 pad_368[0x2F4]; f32 unk_65C;
    u8 pad_660[0x95C]; f32 unk_FBC; u8 pad_FC0[0x44]; f32 unk_1004;
    u8 pad_1008[0x1A8]; u32 unk_11B0; f32 unk_11B4, unk_11B8, unk_11BC;
    f32 unk_11C0, unk_11C4, unk_11C8, unk_11CC, unk_11D0;
};
extern s32 fn_10_1E6F4(s32, Sig_fn_10_1E6F4_Obj *);
extern u16 fn_1_48690(u32);
extern u16 fn_1_486C4(u32);
extern u32 fn_10_1EF04(void *, f32);
extern u32 fn_1_50A90(void *, u32, u32, u32, u32);
extern u32 fn_1_5233C(void);
extern u32 lbl_1_rodata_26F8;
extern struct Pool lbl_10_rodata_158;
extern int fn_1_4F734(FontDrawPacket *);
extern void fn_1_49410(void);
extern void fn_1_496FC(f32, f32);
extern void fn_1_495C8(void *);
extern void fn_1_495B0(u32);
extern void fn_1_49590(f32);
extern void fn_1_4955C(f32, f32);
extern void fn_1_4966C(f32, f32);
extern void fn_1_495A0(f32);
extern void fn_1_49514(u32 *);
extern void fn_1_49738(void *);
extern void fn_1_49748(f32);
extern void fn_1_4A0D8(const char *);

void fn_10_1E9CC(s32 arg0, u32 arg1, u32 arg2, f32 arg3) {
    struct Pool *p = &lbl_10_rodata_158;
    s32 v0, amount;
    f32 t, d;
    union Copy88 loc_5C;
    u32 loc_58;
    struct { u32 a[19]; } loc_C;
    u32 loc_8;
    if (!fn_10_1E6F4(arg0, (Sig_fn_10_1E6F4_Obj *)&loc_C)) return;
    if ((s32)arg2 != 0) {
        if ((s32)loc_C.a[0] != 2) return;
        amount = (s32)(f32)(((f32)(10 - (s32)arg1) * p->unk_2A4) / p->unk_29C);
    } else if ((s32)loc_C.a[0] == 1) {
        amount = (s32)(f32)(((f32)(s32)arg1 * p->unk_11B4) / p->unk_29C);
    } else {
        amount = 0;
    }
    loc_5C = *(union Copy88 *)&lbl_1_rodata_26F8;
    loc_5C.a[0] = 0x10000 - 24794;
    loc_5C.f[1] = p->unk_58 + (f32)amount;
    loc_5C.f[2] = p->unk_364;
    loc_5C.f[3] = p->unk_138;
    loc_5C.a[11] = (u32)(p->unk_11B8 * arg3);
    loc_5C.a[12] = 6;
    fn_1_50A90(&loc_5C, 30, 30, (u32)p->unk_11B8, (u32)p->unk_FBC);
    loc_5C = *(union Copy88 *)&lbl_1_rodata_26F8;
    loc_5C.a[0] = 18;
    loc_5C.a[1] = (u32)(p->unk_58 + (f32)amount);
    loc_5C.a[2] = (u32)p->unk_364;
    loc_5C.a[3] = (u32)p->unk_174;
    v0 = fn_1_48690(18);
    loc_5C.a[4] = (u32)((f32)loc_5C.a[4] * (p->unk_11BC / (f32)(u16)v0));
    fn_1_486C4(loc_5C.a[0]);
    loc_5C.a[11] = (u32)(p->unk_48 * arg3);
    ((u8 *)&loc_5C)[56] = 40;
    ((u8 *)&loc_5C)[57] = 80;
    ((u8 *)&loc_5C)[58] = 80;
    loc_5C.a[12] = 6;
    loc_5C.a[5] = (u32)((f32)loc_5C.a[5] * (p->unk_11C0 / (f32)(u16)fn_1_486C4(loc_5C.a[0])));
    fn_1_4F734((FontDrawPacket *)&loc_5C);
    if (loc_C.a[1] != 0) {
        fn_1_49410();
        fn_1_496FC(p->unk_58 + (f32)amount, p->unk_174);
        fn_1_495C8((void *)1);
        fn_1_495B0(0x80000000);
        fn_1_49590(p->unk_48);
        fn_1_4955C(p->unk_11C4, p->unk_11C4);
        fn_1_4966C(p->unk_284, p->unk_4C);
        fn_1_495A0(arg3);
        loc_8 = p->unk_11B0;
        fn_1_49514(&loc_8);
        fn_1_49738((void *)fn_1_5233C);
        fn_1_49748(p->unk_44);
        fn_1_4A0D8((const char *)loc_C.a[1]);
    }
    loc_C.a[2] = amount; loc_C.a[3] = 121; loc_C.a[4] = 104; loc_C.a[8] = 176;
    loc_C.a[11] = amount; loc_C.a[12] = 232; loc_C.a[13] = 80; loc_C.a[17] = 286;
    if ((s32)arg2 != 0) { loc_C.a[9] = 0; loc_C.a[18] = 0; }
    else { loc_C.a[9] = arg1; loc_C.a[18] = arg1; }
    if (loc_C.a[6] != 0 && loc_C.a[15] != 0) {
        if ((s32)loc_C.a[10] == 1) {
            t = (f32)(s32)loc_C.a[9] / p->unk_29C;
            if (t < p->unk_4C) t = p->unk_4C;
            else if (t > p->unk_44) t = p->unk_44;
            d = p->unk_44 - t;
            loc_C.a[3] = (u32)(s32)(p->unk_11C8 + p->unk_65C * d);
            loc_C.a[8] = (u32)(s32)(p->unk_1004 + p->unk_65C * d);
        }
        if ((s32)loc_58 == 1) {
            f32 t = (f32)(s32)loc_C.a[18] / p->unk_29C;
            if (t < p->unk_4C) t = p->unk_4C;
            else if (t > p->unk_44) t = p->unk_44;
            d = p->unk_44 - t;
            loc_C.a[12] = (u32)(s32)(p->unk_11CC - p->unk_364 * d);
            loc_C.a[17] = (u32)(s32)(p->unk_11D0 - p->unk_364 * d);
        }
        fn_10_1EF04((u8 *)&loc_C + 8, arg3);
        fn_10_1EF04((u8 *)&loc_C + 44, arg3);
    } else if (loc_C.a[6] != 0) {
        loc_C.a[3] = 175;
        fn_10_1EF04((u8 *)&loc_C + 8, arg3);
    } else if (loc_C.a[15] != 0) {
        loc_C.a[12] = 160;
        loc_C.a[17] = 214;
        fn_10_1EF04((u8 *)&loc_C + 44, arg3);
    }
}
