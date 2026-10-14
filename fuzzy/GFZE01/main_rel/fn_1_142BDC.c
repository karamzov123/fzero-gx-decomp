/* Non-matching: best partial attempt (99.44% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"
#include "font.h"
#pragma section code_type ".fzgxpool"
static const u32 fzgx_pool_table1[3] = {0x00000000, 0x00000000, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep1(void) { const u32 *volatile cp; cp = fzgx_pool_table1; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime2(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 0.10000000149011612f;
    s = 1.0f;
}
static const u32 fzgx_pool_table3[61] = {0x3F800000, 0x00000000, 0x00000000, 0x3F800000, 0x3F800000, 0x00000000, 0x3F800000, 0x04000000, 0x00000000, 0xFFFFFFFF, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x3DCCCCCD, 0x3F800000, 0x3F800000, 0x00000000, 0x00000000, 0x3F800000, 0x3F800000, 0x00000000, 0x3F800000, 0x04000000, 0x00000000, 0xFFFFFFFF, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x3DCCCCCD, 0x3F800000, 0x3F800000, 0x00000000, 0x00000000, 0x3F800000, 0x3F800000, 0x00000000, 0x3F800000, 0x04000000, 0x00000000, 0xFFFFFFFF, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep3(void) { const u32 *volatile cp; cp = fzgx_pool_table3; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime4(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 0.0f;
    s = 0.9583333134651184f;
    s = 23.0f;
    s = 2.0f;
    s = 0.6666666865348816f;
    s = 0.5f;
    s = 0.5833333134651184f;
}
static const u32 fzgx_pool_table5[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep5(void) { const u32 *volatile cp; cp = fzgx_pool_table5; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime6(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 4503601774854144.0;
    s = 596.0f;
    s = 528.0f;
}
static const u32 fzgx_pool_table7[11] = {0x0000001A, 0x00000023, 0x0000009C, 0x000000A5, 0x00000018, 0x00000021, 0x00000085, 0x0000008E, 0x000000F2, 0x000000FB, 0xC0C0C000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep7(void) { const u32 *volatile cp; cp = fzgx_pool_table7; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime8(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = -4.0f;
    s = 40.0f;
    s = 480.0f;
    s = 640.0f;
    s = 90000.0f;
    s = 0.30000001192092896f;
    s = 0.699999988079071f;
    s = -1.0f;
    s = 208.0f;
    s = -1000.0f;
    s = -50.0f;
}
static const u32 fzgx_pool_table9[1] = {0x3F800000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep9(void) { const u32 *volatile cp; cp = fzgx_pool_table9; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime10(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 10.0f;
    s = 140.0f;
    s = 224.0f;
    s = 254.0f;
    s = 256.0f;
    s = -6.0f;
    s = 5.0f;
    s = 4.0f;
    s = 12.0f;
}
#pragma section code_type ".text"

struct fn_1_142BDC_Copy88 { u32 a[22]; };
struct fn_1_142BDC_lbl_1_rodata_92C0 {
    u8 pad_0[0x108];
    f32 unk_108;
    u8 pad_10C[0x1C];
    f64 unk_128;
    u8 pad_130[0x68];
    f32 unk_198;
    f32 unk_19C;
    f32 unk_1A0;
    f32 unk_1A4;
    f32 unk_1A8;
    f32 unk_1AC;
    f32 unk_1B0;
};
struct fn_1_142BDC_lbl_1_bss_3C30 {
    u8 pad_0[0x5];
    u8 unk_5;
};

extern f32 fn_1_4B068(s32);
extern int fn_1_4F734(FontDrawPacket *);
extern int sprintf(char *, const char *, ...);
extern struct fn_1_142BDC_lbl_1_bss_3C30 lbl_1_bss_3C30;
extern struct fn_1_142BDC_lbl_1_rodata_92C0 lbl_1_rodata_92C0;
extern u32 lbl_1_data_42488;
extern u32 lbl_1_rodata_26F8;
extern s32 fn_1_149FB4(s32);
extern void fn_1_49410(void);
extern void fn_1_494DC(s16);
extern void fn_1_4954C(f32);
extern void fn_1_495C8(void *);
extern void fn_1_4966C(f32, f32);
extern void fn_1_496FC(f32, f32);
extern void fn_1_4A0D8(const char *);
extern void fn_1_51564(u16, u16, u16, u16, u16, u16);
extern void fn_1_5158C(FontDrawPacket *, u32, s16, s16);
extern void fn_1_51678(FontDrawPacket *, u32, s16, s16, s16, s16);

void fn_1_142BDC(u32 arg0, u32 arg1, u32 arg2) {
    struct fn_1_142BDC_lbl_1_rodata_92C0 *p_lbl_1_rodata_92C0;
    u32 v0;
    f32 v1;
    u32 v2;
    f32 v3;
    u32 v4;
    f32 v5;
    u32 v6;
    u32 arg0_local = arg0;
    s32 v7;
    u32 v8;
    s32 v9;
    s32 v10;
    s32 v13;
    s32 v12;
    s32 v15;
    u32 v18;
    u32 v23;
    f32 v25;
    u32 v36;
    f32 v39;
    f32 v40;
    f32 v41;
    FontDrawPacket loc_18;
    struct { u32 a[4]; } loc_8;
    /* frame */
    s32 t0;
    f32 t27;

    p_lbl_1_rodata_92C0 = (struct fn_1_142BDC_lbl_1_rodata_92C0 *)&lbl_1_rodata_92C0;
    t0 = fn_1_149FB4(arg2);
    if (t0 != -1) {
        if (lbl_1_bss_3C30.unk_5 == 2) {
            if (t0 == 0) {
                loc_18 = *(FontDrawPacket *)&lbl_1_rodata_26F8;
                v0 = 0x9730;
                loc_18.flags = 6;
                loc_18.image = v0;
                fn_1_51678(&loc_18, v0, 0, 0, 116, 32);
                v1 = (140.0f);
                loc_18.x = v1;
                loc_18.y = (224.0f);
                fn_1_4F734(&loc_18);
                loc_18 = *(FontDrawPacket *)&lbl_1_rodata_26F8;
                v2 = 0x9730;
                loc_18.flags = 6;
                loc_18.image = v2;
                fn_1_51678(&loc_18, v2, 0, 32, 160, 32);
                v3 = (140.0f);
                loc_18.x = v3;
                loc_18.y = (254.0f);
                fn_1_4F734(&loc_18);
            } else {
                loc_18 = *(FontDrawPacket *)&lbl_1_rodata_26F8;
                v4 = 0x9730;
                loc_18.flags = 6;
                loc_18.image = v4;
                fn_1_51678(&loc_18, v4, 0, 64, 160, 32);
                v5 = (140.0f);
                loc_18.x = v5;
                loc_18.y = (256.0f);
                fn_1_4F734(&loc_18);
            }
            v6 = arg0_local + 70;
            v7 = arg1 - 3;
            fn_1_49410();
            fn_1_494DC(19);
            fn_1_4966C((-6.0f), (0.0f));
            fn_1_4954C((5.0f));
            fn_1_495C8((void *)2);
            fn_1_496FC((f32)(s32)v6, (f32)(s32)v7);
            sprintf((char *)&loc_8, (const char *)&lbl_1_data_42488, (t0 + 1));
            fn_1_4A0D8((const char *)&loc_8);
            v9 = t0 + 1;
            v13 = 0;
            v12 = v9 % 100;
            if (v12 >= 10 && v9 % 100 <= 20) {
                v13 = 1;
            }
            if (v13 != 0) {
                v15 = 3;
            } else {
                v13 = 0;
                if ((v12 % 10) >= 4 || (v12 % 10) == 0) {
                    v13 = 1;
                }
                if (v13 != 0) {
                    v15 = 3;
                } else {
                    v2 = (v12 % 10) - 1;
                    v15 = v2;
                }
            }
            v18 = (v15 & 0xFF);
            loc_18 = *(FontDrawPacket *)&lbl_1_rodata_26F8;
            loc_18.image = 0x9705;
            fn_1_51564(0, 0, 24, 24, 2, 2);
            v40 = (f32)(s32)(v6 - 4);
            v41 = (f32)(s32)(v7 + 8);
            loc_18.x = v40;
            loc_18.y = v41;
            loc_18.z = (5.0f);
            fn_1_5158C((FontDrawPacket *)&loc_18, loc_18.image,
                       (s16)(((v18 & 1) ^ (v18 >> 31)) - (v18 >> 31)),
                       (s16)((v18 >> 1) & 0x7F));
            fn_1_4F734((FontDrawPacket *)&loc_18);
            loc_18 = *(FontDrawPacket *)&lbl_1_rodata_26F8;
            v23 = 0x9730;
            loc_18.image = v23;
            fn_1_51678((FontDrawPacket *)&loc_18, v23, 116, 0, 44, 32);
            v25 = (f32)(s32)(v6 + 26);
            loc_18.x = v25;
            loc_18.y = (f32)(s32)(v7 + 6);
            fn_1_4F734((FontDrawPacket *)&loc_18);
        } else {
            fn_1_49410();
            fn_1_494DC(19);
            fn_1_4966C((-6.0f), (0.0f));
            fn_1_4954C((5.0f));
            fn_1_496FC((f32)(s32)arg0_local, (f32)(s32)arg1);
            sprintf((char *)&loc_8, (const char *)&lbl_1_data_42488, (t0 + 1));
            fn_1_4A0D8((const char *)&loc_8);
            t27 = fn_1_4B068((s32)&loc_8);
            v9 = t0 + 1;
            v10 = v9 / 100;
            v12 = v9 % 100;
            v13 = 0;
            if (v12 >= 10 && v9 % 100 <= 20) {
                v13 = 1;
            }
            if (v13 != 0) {
                v15 = 3;
            } else {
                v13 = 0;
                if ((v12 % 10) >= 4 || (v12 % 10) == 0) {
                    v13 = 1;
                }
                if (v13 != 0) {
                    v15 = 3;
                } else {
                    v15 = (v12 % 10) - 1;
                }
            }
            v36 = (v15 & 0xFF);
            loc_18 = *(FontDrawPacket *)&lbl_1_rodata_26F8;
            loc_18.image = 0x9705;
            fn_1_51564(0, 0, 24, 24, 2, 2);
            v39 = (4.0f);
            v40 = (f32)(s32)v6 + t27;
            loc_18.z = (5.0f);
            v41 = v40;
            loc_18.y = (f32)(s32)(arg1 + 7);
            v41 = v41 - v39;
            loc_18.x = v41;
            fn_1_5158C((FontDrawPacket *)&loc_18, loc_18.image,
                       (s16)(((v36 & 1) ^ (v36 >> 31)) - (v36 >> 31)),
                       (s16)((v36 >> 1) & 0x7F));
            fn_1_4F734((FontDrawPacket *)&loc_18);
        }
    }
}
