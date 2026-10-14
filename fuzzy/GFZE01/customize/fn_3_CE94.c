/* Non-matching: best partial attempt (63.97% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"
#include "font.h"
#include "rel/customize/emb_memcard.h"

typedef struct {
    u32 image;
    f32 x;
    f32 y;
    f32 z;
    f32 scale_x;
    u8 pad_14[0x18];
    f32 unk_2C;
    u32 flags;
    u32 unk_34;
    u8 color_r;
    u8 color_g;
    u8 color_b;
    u8 pad_3B[0x1D];
} Pkt;

typedef struct {
    f32 unk_0;
    f32 unk_4;
    f32 unk_8;
    f32 unk_C;
    u8 pad_10[4];
    f32 unk_14;
    u8 pad_18[0x14];
    f32 unk_2C;
    f32 unk_30;
    f32 unk_34;
    u32 unk_38;
    f32 unk_3C;
    u8 pad_40[8];
    f64 unk_48;
    u32 unk_50;
    u32 unk_54;
    u32 unk_58;
    f32 unk_5C;
    f32 unk_60;
    f32 unk_64;
    f32 unk_68;
    f32 unk_6C;
    f32 unk_70;
    f32 unk_74;
    f32 unk_78;
    f32 unk_7C;
    f32 unk_80;
    f32 unk_84;
    f32 unk_88;
    f32 unk_8C;
    f32 unk_90;
    f32 unk_94;
    f64 unk_98;
} Pool;

extern Pool lbl_3_rodata_288;
extern u32 lbl_1_rodata_26F8;
extern u32 lbl_801A66A0;
extern u32 lbl_801A66B4;
extern s32 fn_1_A5DC4(void);
extern int fn_1_4F734(FontDrawPacket *);
extern u32 fn_1_50190(void *, f32, f32, f32, f32, f32, f32);
extern void fn_1_51678(FontDrawPacket *, u32, s16, s16, s16, s16);
extern f32 lbl_8006D188(u32);
extern void fn_1_50164(f32, f32, f32, f32, void *);
extern void fn_1_49410(void);
extern void fn_1_49514(u32 *);
extern void fn_1_495C8(u8);
extern void fn_1_4954C(f32);
extern void fn_1_49590(f32);
extern void fn_1_495B0(u32);
extern void fn_1_4955C(f32, f32);
extern void fn_1_496FC(f32, f32);
extern void fn_1_4AE0C(const char *, ...);
extern char *fn_1_14EA74(s16, char *, s16);

void fn_3_CE94(u32 arg0, u32 arg1, u32 arg2, u32 arg3) {
    char buf[0x100];
    Pkt loc;
    u32 tmpA;
    u32 tmpB;
    u32 tmpC;
    u8 *p_data;
    Pool *p_ro;
    Obj_3_bss_7EDD8 *p_st;
    s16 v3;
    s16 v32;
    s16 t1;
    s16 t2;
    s32 v0;
    f32 fa;
    f32 fb;
    s16 tb;
    s16 ts;

    p_data = (u8 *)&lbl_3_data_1A40;
    p_ro = &lbl_3_rodata_288;
    v0 = arg3;
    if ((s8)fn_1_A5DC4() != 0) {
        fa = p_ro->unk_0 * (f32)((lbl_3_bss_7EDD8.unk_24 - 5) < 0 ? 0
            : ((lbl_3_bss_7EDD8.unk_24 - 5) > 10 ? 10 : (lbl_3_bss_7EDD8.unk_24 - 5)));
        v0 = (s32)(fa - p_ro->unk_4);
    } else {
        fa = p_ro->unk_8 * (f32)((lbl_3_bss_7EDD8.unk_24 - 5) < 0 ? 0
            : ((lbl_3_bss_7EDD8.unk_24 - 5) > 10 ? 10 : (lbl_3_bss_7EDD8.unk_24 - 5)));
        v0 = (s32)(fa - p_ro->unk_C);
    }
    loc = *(Pkt *)&lbl_1_rodata_26F8;
    v3 = (s16)v0;
    loc.image = 0x10000 - 30440;
    loc.y = p_ro->unk_5C;
    loc.x = (f32)(v3 + 38);
    loc.z = p_ro->unk_2C;
    loc.flags = 5;
    fn_1_4F734((FontDrawPacket *)&loc);
    loc = *(Pkt *)&lbl_1_rodata_26F8;
    loc.image = 12;
    loc.y = p_ro->unk_60;
    loc.x = (f32)(v3 + 30);
    loc.z = p_ro->unk_14;
    loc.flags = 5;
    fn_1_50190((void *)&loc, p_ro->unk_64, p_ro->unk_68, p_ro->unk_6C, p_ro->unk_6C, p_ro->unk_6C, p_ro->unk_6C);
    loc = *(Pkt *)&lbl_1_rodata_26F8;
    v32 = v3 + 0x20;
    loc.image = 0x10000 - 30431;
    loc.y = p_ro->unk_70;
    loc.x = (f32)v32;
    loc.z = p_ro->unk_2C;
    fn_1_51678((FontDrawPacket *)&loc, 12, 7, 0x16, 2, 2);
    loc.flags = 5;
    loc.scale_x = p_ro->unk_74;
    fn_1_4F734((FontDrawPacket *)&loc);
    p_st = &lbl_3_bss_7EDD8;
    if (*((u8 *)lbl_3_bss_7EDC0.unk_0 + p_st->unk_46 * 0x81C0 + 8) > 1) {
        if (*(s32 *)((u8 *)&lbl_3_bss_7EE40 + p_st->unk_15 * 0x2060 + 0x24) < 0
            || (p_st->unk_C & 0x18) != 0) {
            loc = *(Pkt *)&lbl_1_rodata_26F8;
            loc.image = 0x10000 - 30434;
            loc.y = (f32)(p_st->unk_1C * 25 + 214);
            loc.x = (f32)v32;
            loc.z = p_ro->unk_2C;
            loc.unk_2C = p_ro->unk_3C;
            if ((p_st->unk_C & 0x08000000) != 0) {
                fa = p_ro->unk_7C * ((f32)(lbl_801A66A0 % 60) - p_ro->unk_98) / p_ro->unk_80;
                lbl_8006D188((s32)fa);
                fa = p_ro->unk_78 * fa;
                fa = p_ro->unk_78 + fa;
                loc.color_r = (u8)fa;
                fa = p_ro->unk_7C * ((f32)(lbl_801A66A0 % 60) - p_ro->unk_98) / p_ro->unk_80;
                lbl_8006D188((s32)fa);
                fa = p_ro->unk_84 * fa;
                fa = p_ro->unk_84 + fa;
                loc.color_g = (u8)fa;
                fa = p_ro->unk_84 * fb;
                fa = p_ro->unk_84 + fa;
                loc.color_b = (u8)fa;
            } else {
                loc.color_r = 0x50;
                loc.color_g = 0xa0;
                loc.color_b = 0xa0;
                loc.flags = 5;
            }
            fn_1_50164(p_ro->unk_88, p_ro->unk_14, p_ro->unk_34, p_ro->unk_34, (void *)&loc);
        }
    }
    fn_1_49410();
    tmpA = p_ro->unk_50;
    fn_1_49514(&tmpA);
    fn_1_495C8(0);
    fn_1_4954C(p_ro->unk_30);
    if (*((u8 *)lbl_3_bss_7EDC0.unk_0 + p_st->unk_46 * 0x81C0 + 5) >= 0x29) {
        if (lbl_801A66B4 == 5) {
            fn_1_4955C(p_ro->unk_3C, p_ro->unk_3C);
            tb = 0;
        } else {
            fn_1_49590(p_ro->unk_3C);
            fn_1_495B0(0x8000);
            fn_1_4955C(p_ro->unk_8C, p_ro->unk_8C);
            tb = -2;
        }
        fa = (f32)(v3 + 0x28);
        fb = (f32)(tb + 0xdb);
        fn_1_496FC(fa, fb);
        fn_1_4AE0C((const char *)(p_data + 0x186c), *(u32 *)(p_data + 0x240 + 4 * lbl_801A66B4));
        fb = (f32)(tb + 0xf4);
        fn_1_496FC(fa, fb);
        fn_1_4AE0C((const char *)(p_data + 0x186c), *(u32 *)(p_data + 0x27c + 4 * lbl_801A66B4));
        fb = (f32)(tb + 0x10d);
        fn_1_496FC(fa, fb);
        fn_1_4AE0C((const char *)(p_data + 0x186c), *(u32 *)(p_data + 0x2b8 + 4 * lbl_801A66B4));
        if (lbl_801A66B4 == 5) {
            fn_1_4955C(p_ro->unk_94, p_ro->unk_94);
        } else {
            fn_1_4955C(p_ro->unk_90, p_ro->unk_90);
        }
        fn_1_14EA74(lbl_3_bss_7EE40.pad_68[0x813C], buf, (s16)lbl_801A66B4);
        v3 += 0x9e;
        fa = (f32)v3;
        fb = (f32)(tb + 0xdc);
        fn_1_496FC(fa, fb);
        fn_1_4AE0C((const char *)(p_data + 0x186c), buf);
        fb = (f32)(tb + 0xf5);
        fn_1_496FC(fa, fb);
        fn_1_14EA74(lbl_3_bss_7EE40.pad_68[0x8144], buf, (s16)lbl_801A66B4);
        fn_1_4AE0C((const char *)(p_data + 0x186c), buf);
        fb = (f32)(tb + 0x10e);
        fn_1_496FC(fa, fb);
        fn_1_14EA74(lbl_3_bss_7EE40.pad_68[0x814C], buf, (s16)lbl_801A66B4);
        fn_1_4AE0C((const char *)(p_data + 0x186c), buf);
    } else {
        if (lbl_801A66B4 == 5) {
            fn_1_4955C(p_ro->unk_3C, p_ro->unk_3C);
            ts = 0;
        } else {
            fn_1_49590(p_ro->unk_3C);
            fn_1_495B0(0x8000);
            fn_1_4955C(p_ro->unk_8C, p_ro->unk_8C);
            ts = -2;
        }
        if (lbl_3_bss_7EE40.unk_8 >= 2) {
            tmpB = p_ro->unk_54;
            fn_1_49514(&tmpB);
            if (lbl_3_bss_7EE40.pad_68[0x8138] == 4) {
                fa = (f32)(v3 + 0x28);
                fb = (f32)(ts + 0xdb);
                fn_1_496FC(fa, fb);
                fn_1_4AE0C((const char *)(p_data + 0x186c), *(u32 *)(p_data + 0x304 + 4 * lbl_801A66B4));
                fb = (f32)(ts + 0xf4);
                fn_1_496FC(fa, fb);
                fn_1_4AE0C((const char *)(p_data + 0x186c), *(u32 *)(p_data + 0x354 + 4 * lbl_801A66B4));
            }
            if (lbl_3_bss_7EE40.pad_68[0x8138] == 0x28) {
                fa = (f32)(v3 + 0x28);
                fb = (f32)(ts + 0xdb);
                fn_1_496FC(fa, fb);
                fn_1_4AE0C((const char *)(p_data + 0x186c), *(u32 *)(p_data + 0x3a4 + 4 * lbl_801A66B4));
                fb = (f32)(ts + 0xf4);
                fn_1_496FC(fa, fb);
                fn_1_4AE0C((const char *)(p_data + 0x186c), *(u32 *)(p_data + 0x3f8 + 4 * lbl_801A66B4));
                fb = (f32)(ts + 0x10d);
                fn_1_496FC(fa, fb);
                fn_1_4AE0C((const char *)(p_data + 0x186c), *(u32 *)(p_data + 0x44c + 4 * lbl_801A66B4));
            }
        }
    }
    tmpC = p_ro->unk_58;
    fn_1_49514(&tmpC);
}
