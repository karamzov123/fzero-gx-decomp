/* Non-matching: best partial attempt (77.21% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"
#include "font.h"

struct fn_4_8B3C_lbl_4_bss_0 {
    u8 pad_0[0x2];
    u8 unk_2;
    u8 pad_3[0xD];
    u16 unk_10;
    u8 pad_12[0x272];
    u8 unk_284;
    u8 unk_285;
    u8 unk_286;
};
struct fn_4_8B3C_lbl_4_rodata_0 {
    u8 pad_0[0x8];
    f32 unk_8;
    u32 unk_C;
    u8 pad_10[0x18];
    f64 unk_28;
    f64 unk_30;
    u8 pad_38[0xC];
    f32 unk_44;
    f32 unk_48;
    u8 pad_4C[0x4];
    f32 unk_50;
    u8 pad_54[0x4];
    f32 unk_58;
    u8 pad_5C[0x6C];
    f32 unk_C8;
    u8 pad_CC[0x34];
    f64 unk_100;
    u8 pad_108[0x68];
    f32 unk_170;
    u8 pad_174[0x9C];
    f32 unk_210;
    u8 pad_214[0x74];
    f32 unk_288;
    u8 pad_28C[0x148];
    u32 unk_3D4;
    u32 unk_3D8;
    f32 unk_3DC;
    f32 unk_3E0;
    f32 unk_3E4;
    f32 unk_3E8;
    f32 unk_3EC;
};
struct fn_4_8B3C_Copy88 {
    u32 w_00;
    f32 f_04;
    f32 f_08;
    f32 f_0C;
    f32 f_10;
    f32 f_14;
    f32 pad_18[5];
    f32 f_2C;
    u32 w_30;
    u32 pad_34;
    u32 w_38;
    u32 pad_3C[7];
};

extern struct fn_4_8B3C_lbl_4_bss_0 lbl_4_bss_0;
extern struct fn_4_8B3C_lbl_4_rodata_0 lbl_4_rodata_0;
extern s32 lbl_801A66B4;
extern u32 lbl_4_data_0[];
extern u32 lbl_1_rodata_26F8[];

extern int fn_1_4F734(FontDrawPacket *);
extern u32 fn_1_13ABA8(u32);
extern u32 fn_1_5233C();
extern f32 lbl_8006D188(s16, u32, u32, u32, f32, f32, f32, f64, f32);
extern u8 fn_1_B7C00(void);
extern void fn_1_1380F0(void *);
extern void fn_1_49410(void);
extern void fn_1_49590(f32);
extern void fn_1_495B0(u32);
extern void fn_1_495C8(u8);
extern void fn_1_496FC(f32, f32);
extern void fn_1_49738(u32);
extern void fn_1_49748(f32);
extern void fn_1_4A0D8(const char *);
extern void fn_1_4D0A0(void);
extern void fn_1_4D274(u32 *, f32);
extern void fn_1_53BD8(void *, f32, f32, f32, f32, f32);

void fn_4_8B3C(f32 arg0) {
    struct fn_4_8B3C_lbl_4_bss_0 *bss = &lbl_4_bss_0;
    u32 *data = lbl_4_data_0;
    struct fn_4_8B3C_lbl_4_rodata_0 *rod = &lbl_4_rodata_0;
    u32 *p;
    u32 tail_a;
    u32 tail_b;
    struct fn_4_8B3C_Copy88 loc_10;
    u32 vC;
    u32 v8;
    u32 m;
    f32 f1_ret;
    f32 fv;
    u8 cur;
    s32 pos;

    vC = rod->unk_3D4;
    tail_b = 0;
    p = data + 0x69;
    tail_a = p[lbl_801A66B4];

    if (bss->unk_10 == 0) {
        if ((fn_1_B7C00() & 0xFF) == 0) {
            if (bss->unk_285 == 3) {
            } else if (bss->unk_285 == 4) {
            } else {
                fn_1_49410();
                fn_1_495C8(9);
                fn_1_49738((u32)fn_1_5233C);
                fn_1_49748(rod->unk_48);
                if (lbl_801A66B4 != 5) {
                    fn_1_495B0(0x80000000);
                    fn_1_49590(rod->unk_8);
                }
                fn_1_4D0A0();
                fn_1_496FC(rod->unk_50, rod->unk_C8);
                p = data + 0x38C;
                fn_1_4A0D8((const char *)p[lbl_801A66B4]);
                v8 = rod->unk_3D8;
                fn_1_4D274(&v8, rod->unk_3DC);
                if (bss->unk_285 == 0) {
                    fn_1_496FC(rod->unk_50, rod->unk_3E0);
                    p = data + 0x39C;
                    fn_1_4A0D8((const char *)p[lbl_801A66B4]);
                    fn_1_496FC(rod->unk_50, rod->unk_3E4);
                    p = data + 0x3AC;
                    fn_1_4A0D8((const char *)p[lbl_801A66B4]);
                    fn_1_53BD8(&vC, rod->unk_50, rod->unk_58, rod->unk_288,
                               rod->unk_170, rod->unk_210);
                    cur = bss->unk_286;
                    if (bss->unk_284 != cur) {
                        bss->unk_284 = cur;
                        bss->unk_2 = 0;
                    }
                    loc_10 = *(struct fn_4_8B3C_Copy88 *)lbl_1_rodata_26F8;
                    m = cur * 40 + 220;
                    fv = -(f32)m;
                    pos = (s16)((bss->unk_2 << 10) + 0x4000);
                    loc_10.w_00 = 0x12;
                    loc_10.f_04 = rod->unk_50;
                    loc_10.f_08 = fv;
                    loc_10.f_0C = rod->unk_3E8;
                    loc_10.f_10 = rod->unk_3EC;
                    loc_10.f_14 = rod->unk_44;
                    loc_10.w_30 = 10;
                    f1_ret = lbl_8006D188(pos, 10, m ^ 0x8000, 0x12,
                                          rod->unk_3EC, rod->unk_3E8, fv,
                                          rod->unk_100, rod->unk_50);
                    loc_10.w_38 = rod->unk_C;
                    loc_10.f_2C = (f32)(rod->unk_28 * (rod->unk_30 + f1_ret));
                    fn_1_4F734((FontDrawPacket *)&loc_10);
                    tail_b = 0x28000000;
                    p = data + 0x3A;
                    tail_a = p[lbl_801A66B4];
                }
            }
        }
    }
    fn_1_1380F0((void *)tail_a);
    fn_1_13ABA8(tail_b);
}
