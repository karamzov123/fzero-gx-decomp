/* Non-matching: best partial attempt (87.63% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"
#include "font.h"

extern f32 lbl_1_rodata_4E0[];
extern f32 lbl_1_rodata_26F8[];
extern s16 lbl_1_bss_960;
extern s32 fn_1_F2F34(void);
extern s32 fn_1_40BB4(void);
extern u32 fn_1_E688(f32);
extern void fn_1_49410(void);
extern void fn_1_494DC(s16);
extern void fn_1_495B0(u32);
extern void fn_1_495C8(u8);
extern void fn_1_49590(f32);
extern void fn_1_495A0(f32);
extern void fn_1_496FC(f32, f32);
extern void fn_1_4966C(f32, f32);
extern void fn_1_4AE0C(const char *, ...);
extern void fn_1_A8F40(u8);
extern f32 fn_1_8652C(int);
extern void fn_1_520A0(void);
extern void fn_1_52070(u32);
extern int fn_1_4F734(FontDrawPacket *);
extern void fn_1_520CC(void);

typedef struct {
    s8 unk_0;
    u8 unk_1;
    u8 pad_2[4];
    s16 unk_6;
    u8 pad_8[0xA];
    s16 unk_12;
} Fn1F3D0Ctx;

typedef struct {
    u8 pad_0[8];
    f32 unk_8;
    f32 unk_C;
    f32 unk_10;
    u8 unk_14;
    u8 pad_15[3];
    f32 unk_18;
    f32 unk_1C;
    f32 unk_20;
} Fn1F3D0Cam;

extern Fn1F3D0Cam lbl_1_bss_1148;

#pragma opt_common_subs off
#pragma opt_propagation off
#pragma opt_dead_assignments off
extern void OSReport(const char *, ...);
#pragma section code_type ".fzgxpool"
static void fzgx_string_layout(void) {
    /* fzgx-allow: S2 layout primer: MWCC emits string literals in first-use order; the section is dropped at integration */
    OSReport("OVERTAKE");
}
#pragma section code_type ".text"

#pragma opt_strength_reduction off
#pragma opt_lifetimes off
void fn_1_F3D0(Fn1F3D0Ctx *arg0, f32 arg1) {
    u8 *dat = (u8 *)"OVERTAKE";
    Fn1F3D0Cam *cam = &lbl_1_bss_1148;
    f32 *ro = (f32 *)&lbl_1_rodata_4E0;
    Fn1F3D0Ctx *ctx = arg0;
    f32 scale;
    f32 a;
    f32 b;
    s32 value;
    FontDrawPacket pktA;
    FontDrawPacket pktB;

    if (fn_1_F2F34() != 0 && ctx->unk_12 != 5 && fn_1_40BB4() == 0) {
        cam->unk_14 = 1;
        fn_1_E688(cam->unk_8);
        scale = cam->unk_18;
        fn_1_49410();
        fn_1_494DC(6);
        fn_1_495B0(0xC0000000);
        fn_1_495C8(9);
        fn_1_49590(ro[6]);
        fn_1_496FC(ro[2], ro[32]);
        fn_1_495A0(scale);
        switch (ctx->unk_1) {
        case 1:
            fn_1_4AE0C((const char *)(dat + 0x240));
            break;
        case 2:
            fn_1_4AE0C((const char *)(dat + 0x250));
            break;
        case 0:
            if (ctx->unk_0 == 3) {
                fn_1_4AE0C((const char *)(dat + 0x268));
            } else {
                fn_1_A8F40(0x33);
                {
                    u32 *tbl = (u32 *)(dat + 0x1BC);
                    fn_1_4AE0C((const char *)(dat + 0x278), tbl[(u8)ctx->unk_0]);
                }
                fn_1_A8F40(0xFF);
            }
            break;
        }
        a = cam->unk_1C;
        value = (s32)fn_1_8652C(ctx->unk_6);
        fn_1_49410();
        if (lbl_1_bss_960 == 12) {
            fn_1_494DC(0x2B);
        } else {
            fn_1_494DC(0xF);
        }
        fn_1_520A0();
        fn_1_52070(0x220);
        fn_1_496FC(ro[33], ro[34]);
        fn_1_4966C(ro[7], ro[5]);
        fn_1_495A0(a);
        fn_1_4AE0C((const char *)(dat + 0x27C), value);
        pktA = *(FontDrawPacket *)(((s32)((u8 *)&lbl_1_rodata_26F8 - 4)) + 4);
        pktA.image = (lbl_1_bss_960 == 12) ? 0x9602 : 0x941F;
        pktA.x = ro[35];
        pktA.y = ro[36];
        *(f32 *)((u8 *)&pktA + 0x2C) = a;
        fn_1_4F734(&pktA);
        fn_1_520CC();
        pktB = *(FontDrawPacket *)(((s32)((u8 *)&lbl_1_rodata_26F8 - 4)) + 4);
        b = cam->unk_20;
        pktB.image = (lbl_1_bss_960 == 12) ? 0x9602 : 0x941F;
        fn_1_520A0();
        fn_1_52070(0x220);
        pktB.x = ro[37];
        pktB.y = ro[38];
        *(f32 *)((u8 *)&pktB + 0x2C) = b;
        fn_1_4F734(&pktB);
        fn_1_520CC();
    }
}
#pragma opt_lifetimes reset

#pragma opt_strength_reduction reset

#pragma opt_propagation reset

#pragma opt_dead_assignments reset

#pragma opt_common_subs reset

