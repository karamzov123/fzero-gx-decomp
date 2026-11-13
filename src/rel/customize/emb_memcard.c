#include "types.h"
#include "rel/customize/globals.h"
#include "rel/customize/emb_memcard.h"


extern u32 lbl_3_bss_7ED58[18];
extern u32 lbl_801A6410;
extern u32 lbl_3_data_1A18;
extern u8 fn_1_B7C00(void);
extern void fn_1_C1394(u32 *arg0);
extern void fn_1_46B4(u32 arg0, u32 arg1, char *arg2, u32 arg3);
extern u32 lbl_3_rodata_288[60];
extern void lbl_8006DCA4(void);
extern void lbl_8006E1D8(struct Vec3 *, f32, f32, f32);
extern void fn_1_7BCCC(struct Vec3 *);
extern void fn_80035680(struct GXLightObj *, f32, f32, f32);
extern void fn_80035690(struct GXLightObj *, f32, f32, f32);
extern void fn_80035420(struct GXLightObj *, f32, int);
extern void fn_800356AC(struct GXLightObj *, u32 *);
extern void GXInitLightDistAttn(struct GXLightObj *, f32, f32, int);
extern void fn_1_7BB80(struct GXLightObj *, int);
extern void fn_1_7BD6C(int);
extern void fn_80074CF4(f32, f32, f32);
extern u32 lbl_1_rodata_26F8;
extern s32 lbl_3_bss_120;
extern s32 fn_1_4C10(void);
extern s16 fn_3_B270(void);
extern u16 lbl_1_bss_96A;
extern u32 lbl_3_bss_243A8[6];
extern void fn_1_4A00(s32, s32, u32);
extern u16 lbl_3_bss_20[104];
extern u32 lbl_3_bss_2C7C0[66624];
extern void fn_80008BEC(void *arg0, u32 arg1, u32 arg2);
extern void fn_1_FDFF4(void);
extern void fn_1_FC4E0(void *, s32);
extern u32 lbl_3_bss_7EBA4;
extern u32 lbl_3_bss_7EBA8;
extern u8 lbl_3_data_11DC[84];
extern void fn_1_7F3AC(u32);
extern void fn_1_BC29C(u32 *arg0);
extern void fn_1_B9C0C(void);
extern char lbl_3_data_1A1C[17];
extern s32 fn_1_B7CD4(void);
extern s32 fn_1_B7C5C(void);
extern void OSReport(const char *, ...);
extern u32 lbl_3_bss_A179C;
extern u32 lbl_3_data_1A14;
extern u32 lbl_3_bss_87000[16];
extern void fn_3_D9A0_primer_f(f32);
extern void fn_3_D9A0_primer_d(f64);
extern f32 lbl_3_rodata_378[84];
extern void fn_1_870BC(u32 arg0, u32 arg1, u32 arg2, u32 arg3, u32 arg4, f32 arg5);
extern void fn_1_151BDC(void *arg0);
extern u32 fn_1_14E2DC(u32 arg0, u32 arg1, f32 arg2);
extern u8 lbl_3_bss_87040[33216];
extern u32 fn_1_4AEC0(u32);
extern void fn_1_4A0D8(const char *);

/* fzgx:begin fn_3_C328 */
#include "types.h"

extern u32 lbl_3_bss_7ED58[18];
extern u32 lbl_801A6410;

extern u32 lbl_3_data_1A18;
extern u8 fn_1_B7C00(void);
extern void fn_1_46B4(u32 arg0, u32 arg1, char *arg2, u32 arg3);

void fn_3_C328(void) {
    u32 *state;

    if (!fn_1_B7C00()) {
        state = lbl_3_bss_7ED58;
        fn_1_C1394(state);
        if (state[2] != 0) {
            fn_1_46B4(lbl_801A6410, state[2], (*(char (*)[14])&lbl_3_data_1A30), 0x154);
            state[2] = 0;
            state[3] = 0;
        }
        lbl_3_data_1A18 = 0;
    }
}
/* fzgx:end fn_3_C328 */

/* fzgx:begin fn_3_C3B4 noprologue */
#include "types.h"

extern s32 lbl_3_bss_120;


extern s32 fn_1_4C10(void);
extern s16 fn_3_B270(void);
extern u16 lbl_1_bss_96A;
extern u32 lbl_3_bss_20850;
extern u32 lbl_3_bss_243A8[6];
extern void fn_1_4A00(s32, s32, u32);
extern u16 lbl_3_bss_20[104];
extern u32 lbl_3_bss_2C7C0[66624];
extern void fn_80008BEC(void *, s32, s32);
extern void fn_1_FDFF4(void);
extern void fn_1_FC4E0(void *, s32);
extern u32 lbl_3_bss_7EBA4;
extern u32 lbl_3_bss_7EBA8;
extern u8 lbl_3_data_11DC[84];
extern u32 lbl_801A6410;
extern void fn_1_7F3AC(u32);
extern void fn_1_46B4(u32, u32, u8 *, s32);
extern void fn_1_BC29C(u32 *arg0);
extern void fn_1_B9C0C(void);
extern char lbl_3_data_1A1C[17];
extern u8 fn_1_B7C00(void);
extern s32 fn_1_B7CD4(void);
extern s32 fn_1_B7C5C(void);
extern void OSReport(const char *, ...);
extern u32 lbl_3_bss_A179C;
extern u32 lbl_3_data_1A14;

extern u32 lbl_3_bss_7ED58[18];
extern u32 lbl_3_bss_A179C;
extern u32 lbl_3_data_1A14;
extern u32 lbl_3_data_1A18;

extern void fn_1_BC29C(u32 *arg0);
extern void fn_1_B9C0C(void);

void fn_3_C3B4(void) {
    fn_1_BC29C(lbl_3_bss_7ED58);
    fn_1_B9C0C();
    lbl_3_bss_A179C = 1;
    lbl_3_data_1A14 = -1;
    lbl_3_data_1A18 = -1;
}
/* fzgx:end fn_3_C3B4 */

/* fzgx:begin fn_3_C400 noprologue */
#include "types.h"
#include "rel/customize/globals.h"
#include "rel/customize/emb_memcard.h"


extern u32 lbl_3_bss_7ED58[18];
extern u32 lbl_801A6410;
extern u32 lbl_3_data_1A18;
extern u8 fn_1_B7C00(void);
extern void fn_1_C1394(u32 *arg0);
extern void fn_1_46B4(u32 arg0, u32 arg1, char *arg2, u32 arg3);
extern u32 lbl_3_rodata_288[60];
extern void lbl_8006DCA4(void);
extern void lbl_8006E1D8(struct Vec3 *, f32, f32, f32);
extern void fn_1_7BCCC(struct Vec3 *);
extern void fn_80035680(struct GXLightObj *, f32, f32, f32);
extern void fn_80035690(struct GXLightObj *, f32, f32, f32);
extern void fn_80035420(struct GXLightObj *, f32, int);
extern void fn_800356AC(struct GXLightObj *, u32 *);
extern void GXInitLightDistAttn(struct GXLightObj *, f32, f32, int);
extern void fn_1_7BB80(struct GXLightObj *, int);
extern void fn_1_7BD6C(int);
extern void fn_80074CF4(f32, f32, f32);

#include "font.h"

typedef struct { u32 unk_0; } Sig_fn_1_4FC50_InputObject;
extern s32 fn_1_4FC50(Sig_fn_1_4FC50_InputObject *, u32, u16, u16, u32);
extern s32 fn_1_A5DC4(void);
extern u8 lbl_1_rodata_26F8[];
extern u16 fn_1_48690(u32);
#define DRAW() fn_1_4F734(&pkt)
#define INIT() (pkt = *(FontDrawPacket *)lbl_1_rodata_26F8)
/* Pool primer: retail lays the TU literal pool out in first-use order, so the
 * loop's 129/15 come before 10/0 (the loop hoists them). Reference the
 * literals in retail order first; the section is dropped at integration. */
#pragma section code_type ".fzgxpool"
extern void fzgx_pool_sink(f32);
void fzgx_pool_fn_3_C400(void) {
    fzgx_pool_sink(50.0f);
    fzgx_pool_sink(500.0f);
    fzgx_pool_sink(31.2f);
    fzgx_pool_sink(312.0f);
    fzgx_pool_sink(68.0f);
    fzgx_pool_sink(20.0f);
    fzgx_pool_sink(96.0f);
    fzgx_pool_sink(1.36f);
    fzgx_pool_sink(161.0f);
    fzgx_pool_sink(1.015625f);
    fzgx_pool_sink(129.0f);
    fzgx_pool_sink(15.0f);
    fzgx_pool_sink(10.0f);
    fzgx_pool_sink(0.0f);
    fzgx_pool_sink(86.0f);
    fzgx_pool_sink(0.5f);
    fzgx_pool_sink(139.0f);
    fzgx_pool_sink(75.0f);
}
#pragma section code_type ".text"
#pragma opt_propagation off
void fn_3_C400(u32 arg0, u32 arg1) {
    u8 *p_lbl_1_rodata_26F8;
    s32 v12;
#define v7 (v6 + 169) /* recomputed expression: retail keeps it as a CSE web above the locals */
    s32 left;
    s32 right;
    s32 offset;
    s32 v0;
    s32 clamped;
    s32 c;
    s32 clamped2;
    s32 c2;
    f32 v35;
    f32 alpha_value;
    f32 x;
    f32 v37;
    f32 v38;
    f32 v39;
    f32 v36;
    s32 v47;
    s32 alpha;
    Obj_3_bss_7EE40 *slot;
    s16 v6;
    s32 v40;
    s16 v1;
    s16 v50;
    s16 v51;
    FontDrawPacket pkt;
    v6 = 0;
    v40 = 0;
    if ((s8)fn_1_A5DC4() != 0) {
        v0 = lbl_3_bss_7EDD8.unk_24;
        c = v0 - 5;
        if (c < 0) clamped = 0;
        else { clamped = 10; if (c <= 10) clamped = c; }
        offset = (s32)((f32)(50.0f * (f32)clamped) - 500.0f);
        c = v0 - 15;
        if (c < 0) clamped = 0;
        else { clamped = 10; if (c <= 10) clamped = c; }
        v1 = clamped;
    } else {
        v0 = lbl_3_bss_7EDD8.unk_24;
        c2 = v0 - 5;
        if (c2 < 0) clamped2 = 0;
        else { clamped2 = 10; if (c2 <= 10) clamped2 = c2; }
        offset = (s32)((f32)(31.2f * (f32)clamped2) - 312.0f);
        c2 = v0 - 15;
        if (c2 < 0) clamped2 = 0;
        else { clamped2 = 10; if (c2 <= 10) clamped2 = c2; }
        v1 = clamped2;
    }
    v6 = offset;
    if (v7 >= 0) {
        INIT();
        x = (f32)(v6 + 25);
        pkt.image = 0x8924;
        pkt.y = 68.0f;
        pkt.x = x;
        pkt.z = 20.0f;
        pkt.flags = 5;
        fn_1_51678(&pkt, 0x8924, 0, 0, 144, 28);
        DRAW();
    }
    v12 = v6 + 313;
    if (v12 >= 0) {
        INIT();
        pkt.flags = 5;
        pkt.image = 0x8924;
        pkt.x = (f32)v7;
        pkt.y = 68.0f;
        pkt.z = 20.0f;
        pkt.flags = 0x80005;
        fn_1_51678(&pkt, 0x8924, 0, 0, 144, 28);
        DRAW();
    }
    if (v7 >= 0) {
        INIT();
        x = (f32)(v6 + 25);
        pkt.image = 0x8924;
        pkt.y = 96.0f;
        pkt.x = x;
        pkt.z = 20.0f;
        pkt.flags = 5;
        fn_1_51678(&pkt, 0x8924, 0, 29, 144, 2);
        pkt.scale_y = 1.36f;
        DRAW();
    }
    if (v12 >= 0) {
        INIT();
        x = (f32)v7;
        pkt.image = 0x8924;
        pkt.y = 96.0f;
        pkt.x = x;
        pkt.z = 20.0f;
        pkt.flags = 0x80005;
        fn_1_51678(&pkt, 0x8924, 0, 29, 144, 2);
        pkt.scale_y = 1.36f;
        DRAW();
    }
    if (v7 >= 0) {
        INIT();
        x = (f32)(v6 + 25);
        pkt.image = 0x8924;
        pkt.y = 161.0f;
        pkt.x = x;
        pkt.z = 20.0f;
        pkt.flags = 5;
        fn_1_51678(&pkt, 0x8924, 0, 32, 144, 12);
        DRAW();
    }
    if (v12 >= 0) {
        INIT();
        x = (f32)v7;
        pkt.image = 0x8924;
        pkt.y = 161.0f;
        pkt.x = x;
        pkt.z = 20.0f;
        pkt.flags = 0x80005;
        fn_1_51678(&pkt, 0x8924, 0, 32, 144, 12);
        DRAW();
    }
    alpha = v1 * 65535;
    v35 = 1.015625f;
    v36 = 10.0f;
    v37 = v35 * (f32)v1;
    v39 = v37 / v36;
    p_lbl_1_rodata_26F8 = lbl_1_rodata_26F8;
    v40 = 0;
    while ((u8)v40 < 4) {
        pkt = *(FontDrawPacket *)p_lbl_1_rodata_26F8;
        if ((s8)fn_1_A5DC4() != 0 && (u8)v40 == 0)
            pkt.x = (f32)((u8)v40 * 69 + 65);
        else
            pkt.x = (f32)((u8)v40 * 69 + 66);
        pkt.y = 129.0f;
        pkt.z = 15.0f;
        v38 = 0.0f;
        pkt.flags = 10;
        if ((s8)fn_1_A5DC4() != 0) {
            if ((u8)v40 != 0)
                pkt.scale_x = (f32)v1 / 10.0f;
            else
                pkt.scale_x = (f32)v1 / 10.0f;
        } else {
            pkt.scale_x = v37 / 10.0f;
        }
        pkt.scale_y = v39;
        pkt.rotation_z = (s16)((f32)alpha / v36);
        if (v38 != pkt.scale_x && v38 != pkt.scale_y) {
            slot = (Obj_3_bss_7EE40 *)((u8 *)&lbl_3_bss_7EE40 + (u8)v40 * 0x2060);
            if (slot->unk_24 & 0x80000000) {
                fn_1_4FC50((Sig_fn_1_4FC50_InputObject *)&pkt, 5, 64, 64, (u32)((u8 *)slot + 128));
            } else {
                pkt.image = 0x8916;
                pkt.scale_x = (f32)v1 / v36;
                pkt.scale_y = pkt.scale_x;
                DRAW();
            }
        }
        v40++;
    }
    v47 = lbl_3_bss_7EDD8.unk_15 * 69;
    v50 = v47 + 21;
    v51 = v47 + 77;
    INIT();
    pkt.image = 0x890B;
    if ((left = v50 + v6) + fn_1_48690(0x890B) >= 0) {
        x = (f32)left;
        pkt.y = 86.0f;
        pkt.z = 10.0f;
        pkt.x = x;
        if (!(lbl_3_bss_7EDD8.unk_C & 0x40000000))
            pkt.alpha = 0.5f;
        pkt.flags = 5;
        DRAW();
    }
    if ((right = v51 + v6) + fn_1_48690(0x890B) >= 0) {
        x = (f32)right;
        pkt.y = 86.0f;
        pkt.z = 10.0f;
        pkt.x = x;
        if (!(lbl_3_bss_7EDD8.unk_C & 0x40000000))
            pkt.alpha = 0.5f;
        pkt.flags = 5;
        pkt.flags |= 0x80000;
        DRAW();
    }
    if (left + fn_1_48690(0x890B) >= 0) {
        x = (f32)left;
        pkt.y = 139.0f;
        pkt.z = 10.0f;
        pkt.x = x;
        if (!(lbl_3_bss_7EDD8.unk_C & 0x40000000))
            pkt.alpha = 0.5f;
        pkt.flags = 0x100005;
        DRAW();
    }
    if (right + fn_1_48690(0x890B) >= 0) {
        x = (f32)right;
        pkt.y = 139.0f;
        pkt.z = 10.0f;
        pkt.x = x;
        if (!(lbl_3_bss_7EDD8.unk_C & 0x40000000))
            pkt.alpha = 0.5f;
        pkt.flags |= 0x80000;
        DRAW();
    }
    if (v6 + 38 + fn_1_48690(0x8914) >= 0) {
        INIT();
        x = (f32)(v6 + 38);
        pkt.image = 0x8914;
        pkt.y = 75.0f;
        pkt.x = x;
        pkt.z = 10.0f;
        pkt.flags = 5;
        DRAW();
    }
}

#pragma opt_propagation reset
/* fzgx:end fn_3_C400 */

/* fzgx:begin fn_3_CE94 */
#include "types.h"
#include "font.h"
#include "rel/customize/emb_memcard.h"

#pragma section code_type ".fzgxpool"
__declspec(section ".fzgxpool") static void fzgx_pool_prime1(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    s = 50.0f;
    s = 500.0f;
    s = 31.200000762939453f;
    s = 312.0f;
    s = 68.0f;
    s = 20.0f;
    s = 96.0f;
    s = 1.3600000143051147f;
    s = 161.0f;
    s = 1.015625f;
    s = 129.0f;
    s = 15.0f;
    s = 10.0f;
    s = 0.0f;
    s = 86.0f;
    s = 0.5f;
    s = 139.0f;
    s = 75.0f;
    d = 4503601774854144.0;
}
static const unsigned long fzgx_pool_table2[1] = {0xFFFF0000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep2(void) { const unsigned long *volatile cp; cp = fzgx_pool_table2; }  /* fzgx-allow: S2 pool primer sink */
static const unsigned long fzgx_pool_table3[1] = {0xFFFF0000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep3(void) { const unsigned long *volatile cp; cp = fzgx_pool_table3; }  /* fzgx-allow: S2 pool primer sink */
static const unsigned long fzgx_pool_table4[1] = {0xFFFFFF00};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep4(void) { const unsigned long *volatile cp; cp = fzgx_pool_table4; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime5(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    s = 185.0f;
    s = 180.0f;
    s = 276.0f;
    s = 116.0f;
    s = 7.0f;
    s = 205.0f;
    s = 11.399999618530273f;
    s = 40.0f;
    s = 65536.0f;
    s = 60.0f;
    s = 80.0f;
    s = 274.0f;
    s = 0.5833333134651184f;
    s = 0.5416666865348816f;
    s = 0.4583333432674408f;
    d = 4503599627370496.0;
}
#pragma section code_type ".text"

struct fn_3_CE94_lbl_3_bss_7EE40_0_E8288 {
    u8 pad_0[0x24];
    u32 unk_24;
    u8 pad_28[0x2038];
};
struct fn_3_CE94_Copy88 { u32 a[22]; };
struct fn_3_CE94_CardSlot { u8 pad_0[5]; u8 unk_5; u8 pad_6[2]; u8 unk_8; u8 pad_9[0x81C0 - 9]; };
struct fn_3_CE94_lbl_3_rodata_288 {
    f32 unk_0; f32 unk_4; f32 unk_8; f32 unk_C;
    u8 pad_10[4]; f32 unk_14; u8 pad_18[0x14]; f32 unk_2C;
    f32 unk_30; f32 unk_34; u8 pad_38[4]; f32 unk_3C;
    u8 pad_40[8]; f64 unk_48;
    u32 unk_50; u32 unk_54; u32 unk_58;
    f32 unk_5C; f32 unk_60; f32 unk_64; f32 unk_68;
    f32 unk_6C; f32 unk_70; f32 unk_74; f32 unk_78;
    f32 unk_7C; f32 unk_80; f32 unk_84; f32 unk_88;
    f32 unk_8C; f32 unk_90; f32 unk_94; f64 unk_98;
};
extern int fn_1_4F734(FontDrawPacket *);
extern s32 fn_1_A5DC4(void);




extern void fn_1_50190(void *, f32, f32, f32, f32, f32, f32);
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
extern u32 lbl_801A66A0;
extern s32 lbl_801A66B4;


extern u8 fn_3_10260__fzgx_offset_0[];
extern u8 fn_3_104C4__fzgx_offset_0[];
extern u8 fn_3_106FC__fzgx_offset_0[];
extern u8 fn_3_10B68__fzgx_offset_0[];
extern u8 fn_3_10CB8__fzgx_offset_0[];
extern u8 fn_3_113AC__fzgx_offset_0[];
extern u8 fn_3_1180C__fzgx_offset_0[];
extern u8 fn_3_118BC__fzgx_offset_0[];
extern u8 fn_3_F984__fzgx_offset_0[];
extern u8 fn_3_FD30__fzgx_offset_0[];
extern u8 lbl_3_data_1A44__fzgx_offset_0[];
extern u8 lbl_3_data_1A6C__fzgx_offset_0[];
extern u8 lbl_3_data_1A70__fzgx_offset_0[];
extern u8 lbl_3_data_1ACC__fzgx_offset_0[];
extern u8 lbl_3_data_1B24__fzgx_offset_0[];
extern u8 lbl_3_data_1BB4__fzgx_offset_0[];
extern u8 lbl_3_data_1C04__fzgx_offset_0[];
extern u8 lbl_3_data_1C64__fzgx_offset_0[];
extern u8 lbl_3_data_1C70__fzgx_offset_0[];
extern u8 lbl_3_data_1C98__fzgx_offset_0[];
extern u8 lbl_3_data_1CA8__fzgx_offset_0[];
extern u8 lbl_3_data_1CD4__fzgx_offset_0[];
extern u8 lbl_3_data_1CE4__fzgx_offset_0[];
extern u8 lbl_3_data_1D10__fzgx_offset_0[];
extern u8 lbl_3_data_1D24__fzgx_offset_0[];
extern u8 lbl_3_data_1D5C__fzgx_offset_0[];
extern u8 lbl_3_data_1D74__fzgx_offset_0[];
extern u8 lbl_3_data_1DAC__fzgx_offset_0[];
extern u8 lbl_3_data_1DC4__fzgx_offset_0[];
extern u8 lbl_3_data_1DFC__fzgx_offset_0[];
extern u8 lbl_3_data_1E14__fzgx_offset_0[];
extern u8 lbl_3_data_1E50__fzgx_offset_0[];
extern u8 lbl_3_data_1E68__fzgx_offset_0[];
extern u8 lbl_3_data_1EA4__fzgx_offset_0[];
extern u8 lbl_3_data_1EA8__fzgx_offset_0[];
extern u8 lbl_3_data_1EB0__fzgx_offset_0[];
extern u8 lbl_3_data_1EB4__fzgx_offset_0[];
extern u8 lbl_3_data_2DCC__fzgx_offset_0[];
extern u8 lbl_3_data_2DE0__fzgx_offset_0[];
extern u8 lbl_3_data_2DFC__fzgx_offset_0[];
extern u8 lbl_3_data_2E24__fzgx_offset_0[];
extern u8 lbl_3_data_2E54__fzgx_offset_0[];
extern u8 lbl_3_data_2E64__fzgx_offset_0[];
extern u8 lbl_3_data_2E80__fzgx_offset_0[];
extern u8 lbl_3_data_2E90__fzgx_offset_0[];
extern u8 lbl_3_data_2EAC__fzgx_offset_0[];
extern u8 lbl_3_data_2EC0__fzgx_offset_0[];
extern u8 lbl_3_data_2EE0__fzgx_offset_0[];
extern u8 lbl_3_data_2EF4__fzgx_offset_0[];
extern u8 lbl_3_data_2F04__fzgx_offset_0[];
extern u8 lbl_3_data_2F20__fzgx_offset_0[];
extern u8 lbl_3_data_2F3C__fzgx_offset_0[];
extern u8 lbl_3_data_2F50__fzgx_offset_0[];
extern u8 lbl_3_data_2F64__fzgx_offset_0[];
extern u8 lbl_3_data_3068__fzgx_offset_0[];
extern u8 lbl_3_data_307C__fzgx_offset_0[];
extern u8 lbl_3_data_309C__fzgx_offset_0[];
extern u8 lbl_3_data_30AC__fzgx_offset_0[];
extern u8 lbl_3_data_30C8__fzgx_offset_0[];
extern u8 lbl_3_data_30D4__fzgx_offset_0[];
extern u8 lbl_3_data_30E0__fzgx_offset_0[];
extern u8 lbl_3_data_30EC__fzgx_offset_0[];
extern u8 lbl_3_data_30FC__fzgx_offset_0[];
extern u8 lbl_3_data_3120__fzgx_offset_0[];
extern u8 lbl_3_data_315C__fzgx_offset_0[];
extern u8 lbl_3_data_3168__fzgx_offset_0[];
extern u8 lbl_3_data_3174__fzgx_offset_0[];
extern u8 lbl_3_data_3180__fzgx_offset_0[];
u16 lbl_3_data_1A40 = 0xFFFF;
static union { u32 w[143]; u8 v[0x23C]; } fzgx_pool_init_fzgx_data_4 = {{  /* fzgx-allow: A1 retail data bytes and bindings */
    0x53617669, 0x6E672063, 0x75727265, 0x6E742063, 0x68616E67, 0x65732E0A, 0x20497320, 0x74686973,
    0x204F4B3F, 0x20000000, 0x0, 0x8CBB5B82, 0xB082F15D, 0x8DDD5B82, 0xB482A25D, 0x82CC95CF,
    0x5B82D682, 0xF15D8D58, 0x5B82B182, 0xA45D82F0, 0x835A815B, 0x837582B5, 0x82DC82B7, 0x81420A82,  /* fzgx-allow: A1 retail data bytes */
    0xE682EB82, 0xB582A282, 0xC582B782, 0xA93F0000, (u32)lbl_3_data_1A44__fzgx_offset_0, (u32)lbl_3_data_1A6C__fzgx_offset_0, (u32)lbl_3_data_1A6C__fzgx_offset_0, (u32)lbl_3_data_1A6C__fzgx_offset_0,
    (u32)lbl_3_data_1A6C__fzgx_offset_0, (u32)lbl_3_data_1A70__fzgx_offset_0, 0x50617374, 0x6564206F, 0x626A6563, 0x74732068, 0x61766520, 0x6368616E,
    0x6765642E, 0xA205072, 0x65706172, 0x696E6720, 0x746F2073, 0x61766520, 0x616E6420, 0x72657475,
    0x726E2074, 0x6F207468, 0x65204761, 0x72616765, 0x2E0A4973, 0x20746869, 0x73204F4B, 0x3F200000,
    0x935C5B82, 0xCD5D82E8, 0x95745B82, 0xC25D82AF, 0x82AA95CF, 0x5B82D682, 0xF15D8D58, 0x5B82B182,
    0xA45D82B3, 0x82EA82C4, 0x82A282DC, 0x82B78142, 0xA835A81, 0x5B837582, 0xB582C491, 0x4F5B82DC,
    0x82A65D82, 0xCC89E65B, 0x82AA5D96, 0xCA5B82DF, 0x82F15D82, 0xC996DF5B, 0x82E082C7, 0x5D82E882,
    0xDC82B781, 0x420A82E6, 0x82EB82B5, 0x82A282C5, 0x82B782A9, 0x3F000000, (u32)lbl_3_data_1ACC__fzgx_offset_0, (u32)lbl_3_data_1A6C__fzgx_offset_0,
    (u32)lbl_3_data_1A6C__fzgx_offset_0, (u32)lbl_3_data_1A6C__fzgx_offset_0, (u32)lbl_3_data_1A6C__fzgx_offset_0, (u32)lbl_3_data_1B24__fzgx_offset_0, 0x52657475, 0x726E696E, 0x6720746F, 0x20746865,
    0x20707265, 0x76696F75, 0x73207363, 0x7265656E, 0xA207769, 0x74686F75, 0x74207361, 0x76696E67,
    0x20637572, 0x72656E74, 0x20636861, 0x6E676573, 0x2E0A2049, 0x73207468, 0x6973204F, 0x4B3F2000,
    0x835A815B, 0x837582B9, 0x82B882C9, 0x914F5B82, 0xDC82A65D, 0x82CC89E6, 0x5B82AA5D, 0x96CA5B82,
    0xDF82F15D, 0x82C996DF, 0x5B82E082, 0xC75D82E8, 0x82DC82B7, 0x81420A82, 0xE682EB82, 0xB582A282,  /* fzgx-allow: A1 retail data bytes */
    0xC582B782, 0xA93F0000, (u32)lbl_3_data_1BB4__fzgx_offset_0, (u32)lbl_3_data_1A6C__fzgx_offset_0, (u32)lbl_3_data_1A6C__fzgx_offset_0, (u32)lbl_3_data_1A6C__fzgx_offset_0, (u32)lbl_3_data_1A6C__fzgx_offset_0, (u32)lbl_3_data_1C04__fzgx_offset_0,
    0x426F6479, 0x20506172, 0x74730000, 0x837B8366, 0x83428370, 0x815B8363, 0x0  /* fzgx-allow: A1 retail data bytes */
}};
static union { u32 w[6]; const char *v[6]; } fzgx_pool_init_fzgx_text_240 = {{  /* fzgx-allow: A1 retail data bytes and bindings */
    (u32)lbl_3_data_1C64__fzgx_offset_0, (u32)lbl_3_data_1A6C__fzgx_offset_0, (u32)lbl_3_data_1A6C__fzgx_offset_0, (u32)lbl_3_data_1A6C__fzgx_offset_0, (u32)lbl_3_data_1A6C__fzgx_offset_0, (u32)lbl_3_data_1C70__fzgx_offset_0
}};
static union { u32 w[9]; u8 v[0x24]; } fzgx_pool_init_fzgx_data_258 = {{  /* fzgx-allow: A1 retail data bytes and bindings */
    0x436F636B, 0x70697420, 0x50617274, 0x73000000, 0x8352834E, 0x83728362, 0x83678370, 0x815B8363,  /* fzgx-allow: A1 retail data bytes */
    0x0
}};
static union { u32 w[6]; const char *v[6]; } fzgx_pool_init_fzgx_text_27C = {{  /* fzgx-allow: A1 retail data bytes and bindings */
    (u32)lbl_3_data_1C98__fzgx_offset_0, (u32)lbl_3_data_1A6C__fzgx_offset_0, (u32)lbl_3_data_1A6C__fzgx_offset_0, (u32)lbl_3_data_1A6C__fzgx_offset_0, (u32)lbl_3_data_1A6C__fzgx_offset_0, (u32)lbl_3_data_1CA8__fzgx_offset_0
}};
static union { u32 w[9]; u8 v[0x24]; } fzgx_pool_init_fzgx_data_294 = {{  /* fzgx-allow: A1 retail data bytes and bindings */
    0x426F6F73, 0x74657220, 0x50617274, 0x73000000, 0x8375815B, 0x8358835E, 0x815B8370, 0x815B8363,  /* fzgx-allow: A1 retail data bytes */
    0x0
}};
static union { u32 w[6]; const char *v[6]; } fzgx_pool_init_fzgx_text_2B8 = {{  /* fzgx-allow: A1 retail data bytes and bindings */
    (u32)lbl_3_data_1CD4__fzgx_offset_0, (u32)lbl_3_data_1A6C__fzgx_offset_0, (u32)lbl_3_data_1A6C__fzgx_offset_0, (u32)lbl_3_data_1A6C__fzgx_offset_0, (u32)lbl_3_data_1A6C__fzgx_offset_0, (u32)lbl_3_data_1CE4__fzgx_offset_0
}};
static union { u32 w[13]; u8 v[0x34]; } fzgx_pool_init_fzgx_data_2D0 = {{  /* fzgx-allow: A1 retail data bytes and bindings */
    0x46697265, 0x20537469, 0x6E677261, 0x7920426F, 0x64790000, 0x83748340, 0x83438341, 0x83588365,
    0x83428393, 0x834F838C, 0x834382CC, 0x837B8366, 0x83420000
}};
static union { u32 w[6]; const char *v[6]; } fzgx_pool_init_fzgx_text_304 = {{  /* fzgx-allow: A1 retail data bytes and bindings */
    (u32)lbl_3_data_1D10__fzgx_offset_0, (u32)lbl_3_data_1A6C__fzgx_offset_0, (u32)lbl_3_data_1A6C__fzgx_offset_0, (u32)lbl_3_data_1A6C__fzgx_offset_0, (u32)lbl_3_data_1A6C__fzgx_offset_0, (u32)lbl_3_data_1D24__fzgx_offset_0
}};
static union { u32 w[14]; u8 v[0x38]; } fzgx_pool_init_fzgx_data_31C = {{  /* fzgx-allow: A1 retail data bytes and bindings */
    0x46697265, 0x20537469, 0x6E677261, 0x79205061, 0x72747320, 0x31000000, 0x83748340, 0x83438341,
    0x83588365, 0x83428393, 0x834F838C, 0x834382CC, 0x8370815B, 0x83630000
}};
static union { u32 w[6]; const char *v[6]; } fzgx_pool_init_fzgx_text_354 = {{  /* fzgx-allow: A1 retail data bytes and bindings */
    (u32)lbl_3_data_1D5C__fzgx_offset_0, (u32)lbl_3_data_1A6C__fzgx_offset_0, (u32)lbl_3_data_1A6C__fzgx_offset_0, (u32)lbl_3_data_1A6C__fzgx_offset_0, (u32)lbl_3_data_1A6C__fzgx_offset_0, (u32)lbl_3_data_1D74__fzgx_offset_0
}};
static union { u32 w[14]; u8 v[0x38]; } fzgx_pool_init_fzgx_data_36C = {{  /* fzgx-allow: A1 retail data bytes and bindings */
    0x5261696E, 0x626F7720, 0x50686F65, 0x6E697820, 0x426F6479, 0x0, 0x838C8343, 0x8393837B,
    0x815B8374, 0x8346836A, 0x8362834E, 0x835882CC, 0x837B8366, 0x83420000  /* fzgx-allow: A1 retail data bytes */
}};
static union { u32 w[6]; const char *v[6]; } fzgx_pool_init_fzgx_text_3A4 = {{  /* fzgx-allow: A1 retail data bytes and bindings */
    (u32)lbl_3_data_1DAC__fzgx_offset_0, (u32)lbl_3_data_1A6C__fzgx_offset_0, (u32)lbl_3_data_1A6C__fzgx_offset_0, (u32)lbl_3_data_1A6C__fzgx_offset_0, (u32)lbl_3_data_1A6C__fzgx_offset_0, (u32)lbl_3_data_1DC4__fzgx_offset_0
}};
static union { u32 w[15]; u8 v[0x3c]; } fzgx_pool_init_fzgx_data_3BC = {{  /* fzgx-allow: A1 retail data bytes and bindings */
    0x5261696E, 0x626F7720, 0x50686F65, 0x6E697820, 0x50617274, 0x73203100, 0x838C8343, 0x8393837B,
    0x815B8374, 0x8346836A, 0x8362834E, 0x835882CC, 0x8370815B, 0x83638250, 0x0  /* fzgx-allow: A1 retail data bytes */
}};
static union { u32 w[6]; const char *v[6]; } fzgx_pool_init_fzgx_text_3F8 = {{  /* fzgx-allow: A1 retail data bytes and bindings */
    (u32)lbl_3_data_1DFC__fzgx_offset_0, (u32)lbl_3_data_1A6C__fzgx_offset_0, (u32)lbl_3_data_1A6C__fzgx_offset_0, (u32)lbl_3_data_1A6C__fzgx_offset_0, (u32)lbl_3_data_1A6C__fzgx_offset_0, (u32)lbl_3_data_1E14__fzgx_offset_0
}};
static union { u32 w[15]; u8 v[0x3c]; } fzgx_pool_init_fzgx_data_410 = {{  /* fzgx-allow: A1 retail data bytes and bindings */
    0x5261696E, 0x626F7720, 0x50686F65, 0x6E697820, 0x50617274, 0x73203200, 0x838C8343, 0x8393837B,
    0x815B8374, 0x8346836A, 0x8362834E, 0x835882CC, 0x8370815B, 0x83638251, 0x0  /* fzgx-allow: A1 retail data bytes */
}};
static union { u32 w[6]; const char *v[6]; } fzgx_pool_init_fzgx_text_44C = {{  /* fzgx-allow: A1 retail data bytes and bindings */
    (u32)lbl_3_data_1E50__fzgx_offset_0, (u32)lbl_3_data_1A6C__fzgx_offset_0, (u32)lbl_3_data_1A6C__fzgx_offset_0, (u32)lbl_3_data_1A6C__fzgx_offset_0, (u32)lbl_3_data_1A6C__fzgx_offset_0, (u32)lbl_3_data_1E68__fzgx_offset_0
}};
static union { u32 w[1282]; u8 v[0x1408]; } fzgx_pool_init_fzgx_data_464 = {{  /* fzgx-allow: A1 retail data bytes and bindings */
    0x4E4F0000, 0x82A282A2, 0x82A60000, 0x59455300, 0x82CD82A2, 0x0, (u32)lbl_3_data_1EA4__fzgx_offset_0, (u32)lbl_3_data_1A6C__fzgx_offset_0,
    (u32)lbl_3_data_1A6C__fzgx_offset_0, (u32)lbl_3_data_1A6C__fzgx_offset_0, (u32)lbl_3_data_1A6C__fzgx_offset_0, (u32)lbl_3_data_1EA8__fzgx_offset_0, (u32)lbl_3_data_1EB0__fzgx_offset_0, (u32)lbl_3_data_1A6C__fzgx_offset_0, (u32)lbl_3_data_1A6C__fzgx_offset_0, (u32)lbl_3_data_1A6C__fzgx_offset_0,
    (u32)lbl_3_data_1A6C__fzgx_offset_0, (u32)lbl_3_data_1EB4__fzgx_offset_0, 0x3F000000, 0x3ECCCCCD, 0xC0200000, 0xBF800000, 0xC0400000, 0x40200000,  /* fzgx-allow: A1 retail data bytes */
    0x40000000, 0x40600000, 0x3F19999A, 0x3ECCCCCD, 0xBFCCCCCD, 0xBF4CCCCD, 0xC02CCCCD, 0x3FCCCCCD,  /* fzgx-allow: A1 retail data bytes */
    0x3FCCCCCD, 0x4019999A, 0x3F19999A, 0x3ECCCCCD, 0xBFE66666, 0xBF4CCCCD, 0xC02CCCCD, 0x3FE66666,  /* fzgx-allow: A1 retail data bytes */
    0x3FCCCCCD, 0x402CCCCD, 0x3F000000, 0x3ED70A3D, 0xBFE66666, 0xBF4CCCCD, 0xC0400000, 0x3FE66666,  /* fzgx-allow: A1 retail data bytes */
    0x3FCCCCCD, 0x40400000, 0x3F000000, 0x3E800000, 0xBFE66666, 0xBF4CCCCD, 0xC0266666, 0x3FE66666,  /* fzgx-allow: A1 retail data bytes */
    0x3FCCCCCD, 0x40400000, 0x3F19999A, 0x3ED70A3D, 0xC0200000, 0xBF4CCCCD, 0xC0266666, 0x40200000,  /* fzgx-allow: A1 retail data bytes */
    0x40000000, 0x40266666, 0x3F266666, 0x3F000000, 0xBFE66666, 0xBF4CCCCD, 0xC0266666, 0x3FE66666,  /* fzgx-allow: A1 retail data bytes */
    0x40000000, 0x40266666, 0x3F19999A, 0x3ECCCCCD, 0xBFE66666, 0xBF4CCCCD, 0xC0266666, 0x3FE66666,  /* fzgx-allow: A1 retail data bytes */
    0x3FCCCCCD, 0x40266666, 0x3F000000, 0x3ECCCCCD, 0xBFE66666, 0xBF4CCCCD, 0xC0266666, 0x3FE66666,  /* fzgx-allow: A1 retail data bytes */
    0x40000000, 0x40266666, 0x3F000000, 0x3F000000, 0xC0000000, 0xBF4CCCCD, 0xC0333333, 0x40000000,  /* fzgx-allow: A1 retail data bytes */
    0x400CCCCD, 0x40333333, 0x3F19999A, 0x3ECCCCCD, 0xC0000000, 0xBF4CCCCD, 0xC0333333, 0x40000000,  /* fzgx-allow: A1 retail data bytes */
    0x400CCCCD, 0x40333333, 0x3F000000, 0x3EE66666, 0xC0000000, 0xBF4CCCCD, 0xC00CCCCD, 0x40000000,  /* fzgx-allow: A1 retail data bytes */
    0x40000000, 0x40333333, 0x3F000000, 0x3F000000, 0xBFE66666, 0xBF4CCCCD, 0xC0333333, 0x3FE66666,  /* fzgx-allow: A1 retail data bytes */
    0x40200000, 0x404CCCCD, 0x3F19999A, 0x3ECCCCCD, 0xBFE66666, 0xBF4CCCCD, 0xC0333333, 0x3FE66666,  /* fzgx-allow: A1 retail data bytes */
    0x3FE66666, 0x40333333, 0x3F19999A, 0x3EB33333, 0xBFE66666, 0xBF4CCCCD, 0xC0333333, 0x3FE66666,  /* fzgx-allow: A1 retail data bytes */
    0x3FE66666, 0x40333333, 0x3F19999A, 0x3EB33333, 0xBFE66666, 0xBF4CCCCD, 0xC0333333, 0x3FE66666,  /* fzgx-allow: A1 retail data bytes */
    0x3FCCCCCD, 0x40333333, 0x3F000000, 0x3F000000, 0xBFE66666, 0xBF4CCCCD, 0xC02CCCCD, 0x3FE66666,  /* fzgx-allow: A1 retail data bytes */
    0x3FCCCCCD, 0x402CCCCD, 0x3F000000, 0x3F000000, 0xBFE66666, 0xBF4CCCCD, 0xC02CCCCD, 0x3FE66666,  /* fzgx-allow: A1 retail data bytes */
    0x3FCCCCCD, 0x40400000, 0x3F000000, 0x3EC28F5C, 0xBFE66666, 0xBF4CCCCD, 0xC02CCCCD, 0x3FE66666,  /* fzgx-allow: A1 retail data bytes */
    0x40133333, 0x40400000, 0x3F266666, 0x3EF5C28F, 0xBFE66666, 0xBF4CCCCD, 0xC02CCCCD, 0x3FE66666,  /* fzgx-allow: A1 retail data bytes */
    0x400CCCCD, 0x40400000, 0x3F000000, 0x3F000000, 0xBFE66666, 0xBF4CCCCD, 0xC02CCCCD, 0x3FE66666,  /* fzgx-allow: A1 retail data bytes */
    0x400CCCCD, 0x40400000, 0x3F19999A, 0x3ECCCCCD, 0xBFE66666, 0xBF4CCCCD, 0xC02CCCCD, 0x3FE66666,  /* fzgx-allow: A1 retail data bytes */
    0x40000000, 0x40400000, 0x3F000000, 0x3E0F5C29, 0xBFE66666, 0xBF4CCCCD, 0xC02CCCCD, 0x3FE66666,  /* fzgx-allow: A1 retail data bytes */
    0x3FE66666, 0x40400000, 0x3F19999A, 0x3F000000, 0xC0000000, 0xBF4CCCCD, 0xC02CCCCD, 0x40000000,  /* fzgx-allow: A1 retail data bytes */
    0x4019999A, 0x40400000, 0x3F000000, 0x3E4CCCCD, 0xC0000000, 0xBF4CCCCD, 0xC02CCCCD, 0x40000000,  /* fzgx-allow: A1 retail data bytes */
    0x40000000, 0x40400000, 0x3F000000, 0x3E99999A, 0xC0000000, 0xBF4CCCCD, 0xC02CCCCD, 0x40000000,  /* fzgx-allow: A1 retail data bytes */
    0x40000000, 0x402CCCCD, 0x3F000000, 0x3EB33333, 0xC0000000, 0xBF4CCCCD, 0xC02CCCCD, 0x40000000,  /* fzgx-allow: A1 retail data bytes */
    0x40000000, 0x402CCCCD, 0x3F000000, 0x3EB33333, 0xC0000000, 0xBF4CCCCD, 0xC02CCCCD, 0x40000000,  /* fzgx-allow: A1 retail data bytes */
    0x40000000, 0x402CCCCD, 0x3F000000, 0x3E99999A, 0xC0000000, 0xBF4CCCCD, 0xC02CCCCD, 0x40000000,  /* fzgx-allow: A1 retail data bytes */
    0x400CCCCD, 0x40400000, 0x3F19999A, 0x3E99999A, 0xC0133333, 0xBF4CCCCD, 0xC0533333, 0x40133333,  /* fzgx-allow: A1 retail data bytes */
    0x40333333, 0x40400000, 0x3F19999A, 0x3E99999A, 0xC0133333, 0xBF4CCCCD, 0xC0400000, 0x40133333,  /* fzgx-allow: A1 retail data bytes */
    0x40133333, 0x40400000, 0x3F000000, 0x3E19999A, 0xC0133333, 0xBF4CCCCD, 0xC0200000, 0x4019999A,  /* fzgx-allow: A1 retail data bytes */
    0x40133333, 0x40333333, 0x3F19999A, 0x3E4CCCCD, 0xBFF33333, 0xBF4CCCCD, 0xC0200000, 0x3FF33333,  /* fzgx-allow: A1 retail data bytes */
    0x40333333, 0x40533333, 0x3ECCCCCD, 0x3E19999A, 0xC0200000, 0xBF4CCCCD, 0xC039999A, 0x40200000,  /* fzgx-allow: A1 retail data bytes */
    0x40133333, 0x40533333, 0x3F000000, 0x3E4CCCCD, 0xC0200000, 0xBF4CCCCD, 0xC039999A, 0x40200000,  /* fzgx-allow: A1 retail data bytes */
    0x40133333, 0x40533333, 0x3F000000, 0x3E19999A, 0xBFCCCCCD, 0xBF4CCCCD, 0xBFE66666, 0x3FCCCCCD,
    0x3FE66666, 0x40000000, 0x3F000000, 0x3E99999A, 0xC0000000, 0xBF4CCCCD, 0xC0200000, 0x40000000,  /* fzgx-allow: A1 retail data bytes */
    0x40000000, 0x40200000, 0x3F000000, 0x3EB33333, 0xC0000000, 0xBF4CCCCD, 0xC0133333, 0x40000000,  /* fzgx-allow: A1 retail data bytes */
    0x400CCCCD, 0x4019999A, 0x3F000000, 0x3F000000, 0xC0000000, 0xBF4CCCCD, 0xC0400000, 0x40000000,  /* fzgx-allow: A1 retail data bytes */
    0x400CCCCD, 0x404CCCCD, 0x3F000000, 0x3ECCCCCD, 0xC0000000, 0xBF4CCCCD, 0xC039999A, 0x40000000,  /* fzgx-allow: A1 retail data bytes */
    0x40200000, 0x40333333, 0x3F266666, 0x3E99999A, 0xC0200000, 0xBF4CCCCD, 0xC0400000, 0x40200000,  /* fzgx-allow: A1 retail data bytes */
    0x400CCCCD, 0x40333333, 0x3F000000, 0x3F000000, 0xBF4CCCCD, 0xBF800000, 0xC0000000, 0x3FF33333,  /* fzgx-allow: A1 retail data bytes */
    0x3F4CCCCD, 0x3F800000, 0x3F000000, 0x3F000000, 0xBFF33333, 0xBF800000, 0xC0000000, 0x3F4CCCCD,  /* fzgx-allow: A1 retail data bytes */
    0x3F4CCCCD, 0x3F800000, 0x3F000000, 0x3F000000, 0xBF000000, 0xBF4CCCCD, 0xBFE66666, 0x3F000000,
    0x3FE66666, 0x3F666666, 0x3F000000, 0x3EAE147B, 0xC0133333, 0xBF333333, 0xC0000000, 0x40133333,  /* fzgx-allow: A1 retail data bytes */
    0x3FF33333, 0x3FC00000, 0x3F000000, 0x3ECCCCCD, 0xC0266666, 0xBF333333, 0xBFC00000, 0x40266666,  /* fzgx-allow: A1 retail data bytes */
    0x3FA66666, 0x40133333, 0x3F000000, 0x3F000000, 0xC0133333, 0xBF800000, 0xC0133333, 0x40133333,  /* fzgx-allow: A1 retail data bytes */
    0x40000000, 0x40133333, 0x3F000000, 0x3F000000, 0xBFB33333, 0xBF800000, 0xC0133333, 0x3FB33333,  /* fzgx-allow: A1 retail data bytes */
    0x3FC00000, 0x40266666, 0x3F000000, 0x3E99999A, 0xC0000000, 0xBF4CCCCD, 0xC0000000, 0x40000000,  /* fzgx-allow: A1 retail data bytes */
    0x3F99999A, 0x40266666, 0x3F000000, 0x3E99999A, 0xC0200000, 0xBF666666, 0xC00CCCCD, 0x40200000,  /* fzgx-allow: A1 retail data bytes */
    0x3FE66666, 0x40000000, 0x3F000000, 0x3E99999A, 0xC0066666, 0xBF8CCCCD, 0xBFB33333, 0x40066666,  /* fzgx-allow: A1 retail data bytes */
    0x40066666, 0x40200000, 0x3EE66666, 0x3F000000, 0xC0133333, 0xBF800000, 0xC0200000, 0x40133333,  /* fzgx-allow: A1 retail data bytes */
    0x40000000, 0x40200000, 0x3F000000, 0x3E99999A, 0xC0000000, 0xBF4CCCCD, 0xC0133333, 0x40000000,  /* fzgx-allow: A1 retail data bytes */
    0x3FC00000, 0x402CCCCD, 0x3F000000, 0x3E4CCCCD, 0xC0333333, 0xBF000000, 0xBFE66666, 0x40266666,  /* fzgx-allow: A1 retail data bytes */
    0x3FC00000, 0x3FE66666, 0x3F000000, 0x3DCCCCCD, 0xC0333333, 0xBF4CCCCD, 0xBFD9999A, 0x40333333,  /* fzgx-allow: A1 retail data bytes */
    0x3FD9999A, 0x40133333, 0x3F000000, 0x3E800000, 0xC0000000, 0xBF4CCCCD, 0xC0200000, 0x40000000,  /* fzgx-allow: A1 retail data bytes */
    0x3FC00000, 0x40200000, 0x3F000000, 0x3E4CCCCD, 0xC0000000, 0xBF4CCCCD, 0xBFE66666, 0x3FE66666,  /* fzgx-allow: A1 retail data bytes */
    0x3FE66666, 0x40133333, 0x3F000000, 0x3E800000, 0xC0200000, 0xBF333333, 0xC0133333, 0x40200000,  /* fzgx-allow: A1 retail data bytes */
    0x40000000, 0x40333333, 0x3F000000, 0x3E800000, 0xC019999A, 0xBF666666, 0xC0333333, 0x4019999A,  /* fzgx-allow: A1 retail data bytes */
    0x3FCCCCCD, 0x40333333, 0x3F000000, 0x3E4CCCCD, 0xBFC00000, 0xBF99999A, 0xC019999A, 0x3FC00000,  /* fzgx-allow: A1 retail data bytes */
    0x40200000, 0x4019999A, 0x3F000000, 0x3E4CCCCD, 0xBFF33333, 0xBF333333, 0xC0000000, 0x3FF33333,  /* fzgx-allow: A1 retail data bytes */
    0x400CCCCD, 0x40800000, 0x3F000000, 0x3E4CCCCD, 0xC0066666, 0xBF333333, 0xC0000000, 0x40066666,  /* fzgx-allow: A1 retail data bytes */
    0x3FE66666, 0x40400000, 0x3F000000, 0x3DCCCCCD, 0xBFD9999A, 0xBF000000, 0xC019999A, 0x3FD9999A,  /* fzgx-allow: A1 retail data bytes */
    0x40200000, 0x40400000, 0x3F000000, 0x3EB851EC, 0xC0000000, 0xBF4CCCCD, 0xBFC00000, 0x40000000,  /* fzgx-allow: A1 retail data bytes */
    0x3FF33333, 0x40333333, 0x3F000000, 0x3E19999A, 0xC0000000, 0xBF4CCCCD, 0xC0200000, 0x40000000,  /* fzgx-allow: A1 retail data bytes */
    0x3FF33333, 0x400CCCCD, 0x3F000000, 0x3E4CCCCD, 0xC019999A, 0xBF666666, 0xC019999A, 0x4019999A,  /* fzgx-allow: A1 retail data bytes */
    0x40000000, 0x4019999A, 0x3F000000, 0x3E4CCCCD, 0xC00CCCCD, 0xBF800000, 0xBFE66666, 0x400CCCCD,  /* fzgx-allow: A1 retail data bytes */
    0x40000000, 0x402CCCCD, 0x3F000000, 0x3E19999A, 0xC0466666, 0xBF333333, 0xC00CCCCD, 0x40466666,  /* fzgx-allow: A1 retail data bytes */
    0x40000000, 0x4079999A, 0x3F000000, 0x3E99999A, 0xC0466666, 0xBF19999A, 0xC0000000, 0x40466666,  /* fzgx-allow: A1 retail data bytes */
    0x40000000, 0x40266666, 0x3F000000, 0x3ECCCCCD, 0xBFA66666, 0xBF333333, 0xBFB33333, 0x3FA66666,
    0x3FC00000, 0x3FB33333, 0x3F4CCCCD, 0x3C23D70A, 0xBFA66666, 0xBF333333, 0xBFC00000, 0x3FA66666,
    0x3FA66666, 0x3FC00000, 0x3F000000, 0x3F000000, 0xBFB33333, 0xBF666666, 0xC0000000, 0x3FB33333,  /* fzgx-allow: A1 retail data bytes */
    0x3FC00000, 0x40200000, 0x3F000000, 0x3E4CCCCD, 0xBFB33333, 0xBF800000, 0xBFC00000, 0x3FB33333,
    0x3FC00000, 0x3FC00000, 0x3F000000, 0x3E99999A, 0xBFC00000, 0xBF4CCCCD, 0xBFC00000, 0x3FC00000,
    0x3FCCCCCD, 0x3FC00000, 0x3F000000, 0x3E99999A, 0xBFA66666, 0xBECCCCCD, 0xBFC00000, 0x3FA66666,
    0x3FA66666, 0x3FCCCCCD, 0x3F000000, 0x3E99999A, 0xC0066666, 0xBF4CCCCD, 0xBFA66666, 0x40066666,  /* fzgx-allow: A1 retail data bytes */
    0x3F8CCCCD, 0x3FC00000, 0x3F19999A, 0x3ECCCCCD, 0xBFC00000, 0xBF800000, 0xBFCCCCCD, 0x3FC00000,
    0x3FC00000, 0x3FCCCCCD, 0x3F000000, 0x3E99999A, 0xC02CCCCD, 0xBF666666, 0xBFE66666, 0x402CCCCD,  /* fzgx-allow: A1 retail data bytes */
    0x3FB33333, 0x3FCCCCCD, 0x3F000000, 0x3E4CCCCD, 0xC0000000, 0xBF4CCCCD, 0xBFCCCCCD, 0x40000000,  /* fzgx-allow: A1 retail data bytes */
    0x3FC00000, 0x3FCCCCCD, 0x3F000000, 0x3DCCCCCD, 0xC0000000, 0xBF4CCCCD, 0xBFCCCCCD, 0x40000000,  /* fzgx-allow: A1 retail data bytes */
    0x40000000, 0x400CCCCD, 0x3F000000, 0x3E800000, 0xC019999A, 0xBF4CCCCD, 0xBFCCCCCD, 0x4019999A,  /* fzgx-allow: A1 retail data bytes */
    0x3FB33333, 0x3FCCCCCD, 0x3F000000, 0x3EE66666, 0xBFD9999A, 0xBF666666, 0xBFD9999A, 0x3FD9999A,
    0x3FCCCCCD, 0x40400000, 0x3F000000, 0x3E800000, 0xBFD9999A, 0xBF666666, 0xBFCCCCCD, 0x3FCCCCCD,
    0x3FB33333, 0x3FCCCCCD, 0x3F000000, 0x3E800000, 0xBFB33333, 0xBF4CCCCD, 0xBFCCCCCD, 0x3FB33333,
    0x3FB33333, 0x40000000, 0x3F000000, 0x3E4CCCCD, 0xBFB33333, 0xBF4CCCCD, 0xBFCCCCCD, 0x3FB33333,
    0x3F99999A, 0x3FCCCCCD, 0x3F000000, 0x3E4CCCCD, 0xBFB33333, 0xBF4CCCCD, 0xBFCCCCCD, 0x3FB33333,
    0x3F99999A, 0x3FCCCCCD, 0x3F000000, 0x3E4CCCCD, 0xBFF33333, 0xBF4CCCCD, 0xBFCCCCCD, 0x3FF33333,
    0x3FB33333, 0x3FCCCCCD, 0x3F000000, 0x3E99999A, 0xBFD9999A, 0xBF4CCCCD, 0xBFCCCCCD, 0x3FD9999A,
    0x3FB33333, 0x3FF33333, 0x3F000000, 0x3E800000, 0xBFF33333, 0xBF4CCCCD, 0xBFCCCCCD, 0x3FF33333,
    0x3FCCCCCD, 0x3FCCCCCD, 0x3F000000, 0x3E99999A, 0xBFB33333, 0xBF4CCCCD, 0xBFCCCCCD, 0x3FB33333,
    0x3FC00000, 0x3FCCCCCD, 0x3F000000, 0x3E4CCCCD, 0xBFB33333, 0xBF4CCCCD, 0xBFCCCCCD, 0x3FB33333,
    0x40000000, 0x3FCCCCCD, 0x3F000000, 0x3E4CCCCD, 0xBFB33333, 0xBF4CCCCD, 0xBFCCCCCD, 0x3FB33333,
    0x3FD9999A, 0x3FCCCCCD, 0x3F000000, 0x3E99999A, 0xBFCCCCCD, 0xBF4CCCCD, 0xBFCCCCCD, 0x3FCCCCCD,
    0x3FD9999A, 0x3FCCCCCD, 0x3F000000, 0x3EAE147B, 0xBFC00000, 0xBF4CCCCD, 0xBFCCCCCD, 0x3FC00000,
    0x3FD9999A, 0x3FCCCCCD, 0x3F000000, 0x3F000000, 0xBFE66666, 0xBF333333, 0xBFC00000, 0x3FE66666,
    0x3F4CCCCD, 0x3F666666, 0x3F000000, 0x3EE66666, 0xBFA66666, 0xBF800000, 0xBF4CCCCD, 0x3FA66666,
    0x3F99999A, 0x3F4CCCCD, 0x3F000000, 0x3EE66666, 0xBFB33333, 0xBF800000, 0xBFCCCCCD, 0x3FB33333,
    0x3FC00000, 0x3F333333, 0x3F000000, 0x3E99999A, 0xBFB33333, 0xBFC00000, 0xBFCCCCCD, 0x3FB33333,
    0x3FC00000, 0x3F19999A, 0x3F000000, 0x3ECCCCCD, 0xBF99999A, 0xBF666666, 0xBFC00000, 0x3F99999A,
    0x3FC00000, 0x3F666666, 0x3F000000, 0x3E99999A, 0xBFA66666, 0xBF8CCCCD, 0xBFB33333, 0x3FA66666,
    0x3F8CCCCD, 0x3F4CCCCD, 0x3F000000, 0x3E99999A, 0xBFC00000, 0xBF4CCCCD, 0xBFA66666, 0x3FC00000,
    0x3F8CCCCD, 0x3FC00000, 0x3F19999A, 0x3ECCCCCD, 0xBFB33333, 0xBFA66666, 0xC019999A, 0x3FB33333,  /* fzgx-allow: A1 retail data bytes */
    0x3FA66666, 0x3F800000, 0x3F000000, 0x3E4CCCCD, 0xBFCCCCCD, 0xBFB33333, 0xBF4CCCCD, 0x3FCCCCCD,
    0x3FCCCCCD, 0x3FC00000, 0x3F000000, 0x3E4CCCCD, 0xBFD9999A, 0xBF99999A, 0xBF99999A, 0x3FD9999A,
    0x3F99999A, 0x3F4CCCCD, 0x3F000000, 0x3DCCCCCD, 0xC0066666, 0xBF4CCCCD, 0xC0000000, 0x40066666,  /* fzgx-allow: A1 retail data bytes */
    0x3FC00000, 0x3F4CCCCD, 0x3F000000, 0x3E800000, 0xBFE66666, 0xBF8CCCCD, 0xBFE66666, 0x3FE66666,
    0x3FE66666, 0x3F666666, 0x3F000000, 0x3E99999A, 0xBFF33333, 0xBF8CCCCD, 0xBFD9999A, 0x3FF33333,
    0x3F8CCCCD, 0x3F4CCCCD, 0x3F000000, 0x3EE66666, 0xC00CCCCD, 0xBFA66666, 0xBFE66666, 0x400CCCCD,  /* fzgx-allow: A1 retail data bytes */
    0x3F8CCCCD, 0x3F333333, 0x3F000000, 0x3E4CCCCD, 0xBF99999A, 0xBF4CCCCD, 0xC0200000, 0x3F99999A,  /* fzgx-allow: A1 retail data bytes */
    0x3FCCCCCD, 0x3F666666, 0x3F000000, 0x3E4CCCCD, 0xC00CCCCD, 0xBF99999A, 0xC0000000, 0x400CCCCD,  /* fzgx-allow: A1 retail data bytes */
    0x3F800000, 0x3F4CCCCD, 0x3F000000, 0x3E4CCCCD, 0xC00CCCCD, 0xBF99999A, 0xBFCCCCCD, 0x400CCCCD,  /* fzgx-allow: A1 retail data bytes */
    0x3F8CCCCD, 0x3F4CCCCD, 0x3F000000, 0x3E99999A, 0xC00CCCCD, 0xBF99999A, 0xBFCCCCCD, 0x400CCCCD,  /* fzgx-allow: A1 retail data bytes */
    0x3F8CCCCD, 0x3F4CCCCD, 0x3F000000, 0x3E99999A, 0xBFCCCCCD, 0xBFC00000, 0xC0000000, 0x3FCCCCCD,  /* fzgx-allow: A1 retail data bytes */
    0x3F8CCCCD, 0x3F4CCCCD, 0x3F000000, 0x3E800000, 0xBFCCCCCD, 0xBF8CCCCD, 0xBFF33333, 0x3FCCCCCD,
    0x3F8CCCCD, 0x3F4CCCCD, 0x3F000000, 0x3E99999A, 0xC0000000, 0xBF8CCCCD, 0xBFC00000, 0x40000000,  /* fzgx-allow: A1 retail data bytes */
    0x3FB33333, 0x3F4CCCCD, 0x3F000000, 0x3E4CCCCD, 0xBFC00000, 0xBF99999A, 0xBFC00000, 0x3FC00000,
    0x40066666, 0x3F4CCCCD, 0x3F000000, 0x3E4CCCCD, 0xBFCCCCCD, 0xBFB33333, 0xBFC00000, 0x3FCCCCCD,
    0x3FA66666, 0x3F4CCCCD, 0x3F000000, 0x3E19999A, 0xBFF33333, 0xBF99999A, 0xC0000000, 0x3FF33333,  /* fzgx-allow: A1 retail data bytes */
    0x3F99999A, 0x3F800000, 0x3F000000, 0x3EAE147B, 0xBFF33333, 0xBF800000, 0xBFD9999A, 0x3FF33333,
    0x3F800000, 0x3F333333, 0x4C6F6164, 0x696E6720, 0x456D626C, 0x656D2E2E, 0x2E000000, 0x83478393,
    0x8375838C, 0x838082F0, 0x838D815B, 0x83689286, 0x82C582B7, 0x81420000, 0x53656C65, 0x63742061,  /* fzgx-allow: A1 retail data bytes */
    0x20506C61, 0x63652074, 0x6F205265, 0x67697374, 0x65722074, 0x68652045, 0x6D626C65, 0x6D2E2000,
    0x83478393, 0x8375838C, 0x838082F0, 0x936F985E, 0x82B782E9, 0x8FEA8F8A, 0x82F09149, 0x91F082B5,
    0x82C482AD, 0x82BE82B3, 0x82A28142, 0x0, 0x52656D6F, 0x76652045, 0x6D626C65, 0x6D3F0000,
    0x83478393, 0x8375838C, 0x838082F0, 0x82CD82AA, 0x82B582DC, 0x82B782A9, 0x81480000, 0x53656C65,  /* fzgx-allow: A1 retail data bytes */
    0x63742050, 0x61727473, 0x2E200000, 0x8370815B, 0x836382F0, 0x914991F0, 0x82B582C4, 0x82AD82BE,
    0x82B382A2, 0x81420000, 0x53656C65, 0x63742061, 0x6E20456D, 0x626C656D, 0x2E200000, 0x83478393,  /* fzgx-allow: A1 retail data bytes */
    0x8375838C, 0x838082F0, 0x914991F0, 0x82B582C4, 0x82AD82BE, 0x82B382A2, 0x81420000, 0x8FE38F91,  /* fzgx-allow: A1 retail data bytes */
    0x82AB8A6D, 0x94469286, 0x82C582B7, 0x81420000, 0x4170706C, 0x7920456D, 0x626C656D, 0x2E200000,  /* fzgx-allow: A1 retail data bytes */
    0x83478393, 0x8375838C, 0x838082F0, 0x935C82E8, 0x957482AF, 0x82DC82B7, 0x81420000, 0x436F6D70,  /* fzgx-allow: A1 retail data bytes */
    0x6C657469, 0x6E672070, 0x726F6365, 0x7373696E, 0x672E2E2E, 0x0, 0x8F4997B9, 0x8F88979D,
    0x928682C5, 0x82B78142, 0x0, 0x436F6E66, 0x69726D69, 0x6E672073, 0x6176652E, 0x2E2E0000,
    0x835A815B, 0x83758A6D, 0x94469286, 0x82C582B7, 0x81420000, (u32)lbl_3_data_2DCC__fzgx_offset_0, (u32)lbl_3_data_1A6C__fzgx_offset_0, (u32)lbl_3_data_1A6C__fzgx_offset_0,  /* fzgx-allow: A1 retail data bytes */
    (u32)lbl_3_data_1A6C__fzgx_offset_0, (u32)lbl_3_data_1A6C__fzgx_offset_0, (u32)lbl_3_data_2DE0__fzgx_offset_0, (u32)lbl_3_data_2DFC__fzgx_offset_0, (u32)lbl_3_data_1A6C__fzgx_offset_0, (u32)lbl_3_data_1A6C__fzgx_offset_0, (u32)lbl_3_data_1A6C__fzgx_offset_0, (u32)lbl_3_data_1A6C__fzgx_offset_0,
    (u32)lbl_3_data_2E24__fzgx_offset_0, (u32)lbl_3_data_2E54__fzgx_offset_0, (u32)lbl_3_data_1A6C__fzgx_offset_0, (u32)lbl_3_data_1A6C__fzgx_offset_0, (u32)lbl_3_data_1A6C__fzgx_offset_0, (u32)lbl_3_data_1A6C__fzgx_offset_0, (u32)lbl_3_data_2E64__fzgx_offset_0, (u32)lbl_3_data_2E80__fzgx_offset_0,
    (u32)lbl_3_data_1A6C__fzgx_offset_0, (u32)lbl_3_data_1A6C__fzgx_offset_0, (u32)lbl_3_data_1A6C__fzgx_offset_0, (u32)lbl_3_data_1A6C__fzgx_offset_0, (u32)lbl_3_data_2E90__fzgx_offset_0, (u32)lbl_3_data_2EAC__fzgx_offset_0, (u32)lbl_3_data_1A6C__fzgx_offset_0, (u32)lbl_3_data_1A6C__fzgx_offset_0,
    (u32)lbl_3_data_1A6C__fzgx_offset_0, (u32)lbl_3_data_1A6C__fzgx_offset_0, (u32)lbl_3_data_2EC0__fzgx_offset_0, (u32)lbl_3_data_1A6C__fzgx_offset_0, (u32)lbl_3_data_1A6C__fzgx_offset_0, (u32)lbl_3_data_1A6C__fzgx_offset_0, (u32)lbl_3_data_1A6C__fzgx_offset_0, (u32)lbl_3_data_1A6C__fzgx_offset_0,
    (u32)lbl_3_data_2EE0__fzgx_offset_0, (u32)lbl_3_data_2EF4__fzgx_offset_0, (u32)lbl_3_data_1A6C__fzgx_offset_0, (u32)lbl_3_data_1A6C__fzgx_offset_0, (u32)lbl_3_data_1A6C__fzgx_offset_0, (u32)lbl_3_data_1A6C__fzgx_offset_0, (u32)lbl_3_data_2F04__fzgx_offset_0, (u32)lbl_3_data_1A6C__fzgx_offset_0,
    (u32)lbl_3_data_1A6C__fzgx_offset_0, (u32)lbl_3_data_1A6C__fzgx_offset_0, (u32)lbl_3_data_1A6C__fzgx_offset_0, (u32)lbl_3_data_1A6C__fzgx_offset_0, (u32)lbl_3_data_1A6C__fzgx_offset_0, (u32)lbl_3_data_2F20__fzgx_offset_0, (u32)lbl_3_data_1A6C__fzgx_offset_0, (u32)lbl_3_data_1A6C__fzgx_offset_0,
    (u32)lbl_3_data_1A6C__fzgx_offset_0, (u32)lbl_3_data_1A6C__fzgx_offset_0, (u32)lbl_3_data_2F3C__fzgx_offset_0, (u32)lbl_3_data_2F50__fzgx_offset_0, (u32)lbl_3_data_1A6C__fzgx_offset_0, (u32)lbl_3_data_1A6C__fzgx_offset_0, (u32)lbl_3_data_1A6C__fzgx_offset_0, (u32)lbl_3_data_1A6C__fzgx_offset_0,
    (u32)lbl_3_data_2F64__fzgx_offset_0, 0x83AD2052, 0x6F746174, 0x65204D61, 0x6368696E, 0x65000000, 0x83AD208E, 0xD45B82AD,
    0x82E982DC, 0x5D82CC89, 0xF15B82A9, 0x82A25D93, 0x5D5B82C4, 0x82F15D00, 0x83A6204D, 0x6F766520,
    0x43616D65, 0x72610000, 0x83A62083, 0x4A838183, 0x8982CC88, 0xDA5B82A2, 0x5D93AE5B, 0x82C782A4,
    0x5D000000, 0x83A183AF, 0x205A6F6F, 0x6D000000, 0x83A183AF, 0x20835981, 0x5B838000, 0x83A42050,
    0x72657669, 0x65770000, 0x83A42083, 0x76838C83, 0x72838581, 0x5B000000, 0x83B283B4, 0x20496E63,
    0x72656173, 0x652F5265, 0x64756365, 0x20456D62, 0x6C656D20, 0x53697A65, 0x0, 0x83B283B4,
    0x20834783, 0x93837583, 0x8C838082, 0xCC8A675B, 0x82A982AD, 0x5D91E55B, 0x82BE82A2, 0x5D81458F,
    0x6B5B82B5, 0x82E382AD, 0x205D8FAC, 0x5B2082B5, 0x82E582A4, 0x5D000000, 0x839F2050, 0x61737465,
    0x0, 0x839F2093, 0x5C5B82CD, 0x5D82E900, 0x839F2050, 0x65656C20, 0x6F666600, 0x839F2082,
    0xCD82AA82, 0xB7000000, (u32)lbl_3_data_3068__fzgx_offset_0, (u32)lbl_3_data_1A6C__fzgx_offset_0, (u32)lbl_3_data_1A6C__fzgx_offset_0, (u32)lbl_3_data_1A6C__fzgx_offset_0, (u32)lbl_3_data_1A6C__fzgx_offset_0, (u32)lbl_3_data_307C__fzgx_offset_0,
    (u32)lbl_3_data_309C__fzgx_offset_0, (u32)lbl_3_data_1A6C__fzgx_offset_0, (u32)lbl_3_data_1A6C__fzgx_offset_0, (u32)lbl_3_data_1A6C__fzgx_offset_0, (u32)lbl_3_data_1A6C__fzgx_offset_0, (u32)lbl_3_data_30AC__fzgx_offset_0, (u32)lbl_3_data_30C8__fzgx_offset_0, (u32)lbl_3_data_1A6C__fzgx_offset_0,
    (u32)lbl_3_data_1A6C__fzgx_offset_0, (u32)lbl_3_data_1A6C__fzgx_offset_0, (u32)lbl_3_data_1A6C__fzgx_offset_0, (u32)lbl_3_data_30D4__fzgx_offset_0, (u32)lbl_3_data_30E0__fzgx_offset_0, (u32)lbl_3_data_1A6C__fzgx_offset_0, (u32)lbl_3_data_1A6C__fzgx_offset_0, (u32)lbl_3_data_1A6C__fzgx_offset_0,
    (u32)lbl_3_data_1A6C__fzgx_offset_0, (u32)lbl_3_data_30EC__fzgx_offset_0, (u32)lbl_3_data_30FC__fzgx_offset_0, (u32)lbl_3_data_1A6C__fzgx_offset_0, (u32)lbl_3_data_1A6C__fzgx_offset_0, (u32)lbl_3_data_1A6C__fzgx_offset_0, (u32)lbl_3_data_1A6C__fzgx_offset_0, (u32)lbl_3_data_3120__fzgx_offset_0,
    (u32)lbl_3_data_315C__fzgx_offset_0, (u32)lbl_3_data_1A6C__fzgx_offset_0, (u32)lbl_3_data_1A6C__fzgx_offset_0, (u32)lbl_3_data_1A6C__fzgx_offset_0, (u32)lbl_3_data_1A6C__fzgx_offset_0, (u32)lbl_3_data_3168__fzgx_offset_0, (u32)lbl_3_data_3174__fzgx_offset_0, (u32)lbl_3_data_1A6C__fzgx_offset_0,
    (u32)lbl_3_data_1A6C__fzgx_offset_0, (u32)lbl_3_data_1A6C__fzgx_offset_0, (u32)lbl_3_data_1A6C__fzgx_offset_0, (u32)lbl_3_data_3180__fzgx_offset_0, 0x0, (u32)lbl_3_data_1A6C__fzgx_offset_0, (u32)fn_3_F984__fzgx_offset_0, 0x1,
    (u32)lbl_3_data_1A6C__fzgx_offset_0, (u32)fn_3_FD30__fzgx_offset_0, 0x2, (u32)lbl_3_data_1A6C__fzgx_offset_0, (u32)fn_3_104C4__fzgx_offset_0, 0x3, (u32)lbl_3_data_1A6C__fzgx_offset_0, (u32)fn_3_10260__fzgx_offset_0,
    0x4, (u32)lbl_3_data_1A6C__fzgx_offset_0, (u32)fn_3_106FC__fzgx_offset_0, 0x5, (u32)lbl_3_data_1A6C__fzgx_offset_0, (u32)fn_3_10B68__fzgx_offset_0, 0x6, (u32)lbl_3_data_1A6C__fzgx_offset_0,
    (u32)fn_3_10CB8__fzgx_offset_0, 0x7, (u32)lbl_3_data_1A6C__fzgx_offset_0, (u32)fn_3_118BC__fzgx_offset_0, 0x8, (u32)lbl_3_data_1A6C__fzgx_offset_0, (u32)fn_3_1180C__fzgx_offset_0, 0x9,
    (u32)lbl_3_data_1A6C__fzgx_offset_0, (u32)fn_3_113AC__fzgx_offset_0
}};
static union { u32 w[1]; char v[4]; } fzgx_pool_init_fzgx_format = {{  /* fzgx-allow: A1 retail data bytes and bindings */
    0x25730A00
}};
#define fzgx_data_4 fzgx_pool_init_fzgx_data_4.v
#define fzgx_text_240 fzgx_pool_init_fzgx_text_240.v
#define fzgx_data_258 fzgx_pool_init_fzgx_data_258.v
#define fzgx_text_27C fzgx_pool_init_fzgx_text_27C.v
#define fzgx_data_294 fzgx_pool_init_fzgx_data_294.v
#define fzgx_text_2B8 fzgx_pool_init_fzgx_text_2B8.v
#define fzgx_data_2D0 fzgx_pool_init_fzgx_data_2D0.v
#define fzgx_text_304 fzgx_pool_init_fzgx_text_304.v
#define fzgx_data_31C fzgx_pool_init_fzgx_data_31C.v
#define fzgx_text_354 fzgx_pool_init_fzgx_text_354.v
#define fzgx_data_36C fzgx_pool_init_fzgx_data_36C.v
#define fzgx_text_3A4 fzgx_pool_init_fzgx_text_3A4.v
#define fzgx_data_3BC fzgx_pool_init_fzgx_data_3BC.v
#define fzgx_text_3F8 fzgx_pool_init_fzgx_text_3F8.v
#define fzgx_data_410 fzgx_pool_init_fzgx_data_410.v
#define fzgx_text_44C fzgx_pool_init_fzgx_text_44C.v
#define fzgx_data_464 fzgx_pool_init_fzgx_data_464.v
#define fzgx_format fzgx_pool_init_fzgx_format.v
#pragma opt_pointer_analysis off
static inline const char **text_array(u32 p) { return (const char **)p; }
static inline const char *text_format(u32 p) { return (const char *)p; }
static inline Obj_3_bss_7EDC0_At0 *card_slot(u32 offset) { return (Obj_3_bss_7EDC0_At0 *)((u8 *)lbl_3_bss_7EDC0.unk_0 + offset); }
static inline Obj_3_bss_7EE40 *editor_slot(u32 offset) { return (Obj_3_bss_7EE40 *)((u8 *)&lbl_3_bss_7EE40 + offset); }
#pragma opt_pointer_analysis on
static inline s32 clamp_menu(s32 n) { return n < 0 ? 0 : n > 10 ? 10 : n; }
static inline u8 fn_3_CE94_array_read(u8 *array, s32 index) { return array[index]; }
#pragma opt_lifetimes off
void fn_3_CE94(u32 arg0, u32 arg1, u32 arg2, u32 arg3) {
    s16 v3;
    struct { u32 value; } data_base;
    struct fn_3_CE94_lbl_3_rodata_288 *p_lbl_3_rodata_288;
    Obj_3_bss_7EDD8 *p_lbl_3_bss_7EDD8;
    s16 v0;
    s32 v1;
    s32 v2;
    f32 v4;
    u32 v5;
    f64 v6;
    f32 v7;
    f32 v8;
    f32 v9;
    u32 v10;
    f32 v11;
    f64 v12;
    f32 v13;
    u32 v14;
    f64 v15;
    FontDrawPacket loc_14;
    char buffer[256];
    u32 color0, color1, color2;

    struct { s32 value; } x0;
    s32 y0, y1, y2;
    s32 x1;
    u8 *slot;
    s32 t0;
    s32 x2;
    s16 dy0, dy1;
    data_base.value = (u32)&lbl_3_data_1A40;
    t0 = fn_1_A5DC4();
    v0 = arg3;
    if ((s8)t0 != 0) {
        v1 = lbl_3_bss_7EDD8.unk_24 - 5;
        v0 = (f32)(50.0f * (f32)clamp_menu(v1)) - 500.0f;
    } else {
        v2 = lbl_3_bss_7EDD8.unk_24 - 5;
        v0 = (f32)(31.2f * (f32)clamp_menu(v2)) - 312.0f;
    }
    loc_14 = *(FontDrawPacket *)&lbl_1_rodata_26F8;
    v5 = 0x8918;
    v6 = 4503601774854144.0;
    loc_14.image = v5;
    v7 = (f32)(s32)(v0 + 38);
    loc_14.x = v7;
    loc_14.y = 185.0f;
    loc_14.z = 15.0f;
    loc_14.flags = 5;
    fn_1_4F734(&loc_14);
    loc_14 = *(FontDrawPacket *)&lbl_1_rodata_26F8;
    v8 = 7.0f;
    v9 = (f32)(s32)(v0 + 30);
    loc_14.image = 12;
    loc_14.x = v9;
    loc_14.y = 180.0f;
    loc_14.z = 20.0f;
    loc_14.flags = 5;
    fn_1_50190(&loc_14, 276.0f, 116.0f, v8, v8, v8, v8);
    loc_14 = *(FontDrawPacket *)&lbl_1_rodata_26F8;
    v10 = v0 + 32;
    v12 = 4503601774854144.0;
    loc_14.image = 0x8921;
    v13 = (f32)(s32)v10;
    loc_14.x = v13;
    loc_14.y = 205.0f;
    loc_14.z = 15.0f;
    fn_1_51678(&loc_14, 12, 7, 22, 2, 2);
    loc_14.flags = 5;
    loc_14.scale_x = 11.4f;
    fn_1_4F734(&loc_14);
    p_lbl_3_bss_7EDD8 = (Obj_3_bss_7EDD8 *)&lbl_3_bss_7EDD8;
    if (card_slot(p_lbl_3_bss_7EDD8->unk_46 * 0x81C0)->unk_8 > 1) {
        if (*(u32 *)((u8 *)&lbl_3_bss_7EE40.unk_24 + p_lbl_3_bss_7EDD8->unk_15 * 0x2060) & 0x80000000 ||
            (p_lbl_3_bss_7EDD8->unk_C & 0x18000000)) {
            loc_14 = *(FontDrawPacket *)&lbl_1_rodata_26F8;
            v14 = 0x891E;
            v15 = 4503601774854144.0;
            loc_14.image = v14;
            loc_14.x = (f32)(s32)v10;
            loc_14.y = (f32)(lbl_3_bss_7EDD8.unk_1C * 25 + 214);
            loc_14.z = 15.0f;
            *(f32 *)((u8 *)&loc_14 + 0x2C) = 0.5f;
            if ((__rlwnm(lbl_3_bss_7EDD8.unk_C, 32 - (28), 31, 31))) {
                loc_14.color[0] = (40.0f + (f32)(40.0f * lbl_8006D188((s32)((f32)(65536.0f * (f32)(lbl_801A66A0 % 60)) / 60.0f))));
                loc_14.color[1] = (80.0f + (f32)(80.0f * lbl_8006D188((s32)((f32)(65536.0f * (f32)(lbl_801A66A0 % 60)) / 60.0f))));
                loc_14.color[2] = (80.0f + (f32)(80.0f * lbl_8006D188((s32)((f32)(65536.0f * (f32)(lbl_801A66A0 % 60)) / 60.0f))));
                loc_14.flags = 5;
            } else {
                loc_14.color[0] = 80;
                loc_14.color[1] = 160;
                loc_14.color[2] = 160;
                loc_14.flags = 5;
            }
            fn_1_50164(274.0f, 20.0f, 0.0f, 0.0f, &loc_14);
        }
    }
    fn_1_49410();
    color0 = fzgx_pool_table2[0];
    fn_1_49514(&color0);
    fn_1_495C8(0);
    fn_1_4954C(10.0f);
    if (*(&lbl_3_bss_7EDC0.unk_0->unk_5 + p_lbl_3_bss_7EDD8->unk_46 * 0x81C0) >= 41) {
        if (lbl_801A66B4 != 5) {
            dy0 = -2;
            fn_1_49590(0.5f);
            fn_1_495B0(0x80000000);
            fn_1_4955C(0.5833333134651184f, 0.5833333134651184f);
        } else {
            dy0 = 0;
            fn_1_4955C(0.5f, 0.5f);
        }
        x0.value = v0 + 40;
        y0 = dy0;
        fn_1_496FC((f32)x0.value, (f32)(y0 + 219));
        fn_1_4AE0C(fzgx_format, fzgx_text_240[lbl_801A66B4]);
        fn_1_496FC((f32)x0.value, (f32)(y0 + 244));
        fn_1_4AE0C(fzgx_format, fzgx_text_27C[lbl_801A66B4]);
        fn_1_496FC((f32)x0.value, (f32)(y0 + 269));
        fn_1_4AE0C(fzgx_format, fzgx_text_2B8[lbl_801A66B4]);
        if (lbl_801A66B4 != 5) fn_1_4955C(0.5416666865348816f, 0.5416666865348816f);
        else fn_1_4955C(0.4583333432674408f, 0.4583333432674408f);
        fn_1_14EA74(*((u8 *)&lbl_3_bss_7EE40 + 0x81A4), buffer, (s16)lbl_801A66B4);
        x1 = v0 + 158;
        fn_1_496FC((f32)x1, (f32)(y0 + 220));
        fn_1_4AE0C(fzgx_format, buffer);
        fn_1_496FC((f32)x1, (f32)(y0 + 245));
        fn_1_14EA74(*((u8 *)&lbl_3_bss_7EE40 + 0x81AC), buffer, (s16)lbl_801A66B4);
        fn_1_4AE0C(fzgx_format, buffer);
        fn_1_496FC((f32)x1, (f32)(y0 + 270));
        fn_1_14EA74(*((u8 *)&lbl_3_bss_7EE40 + 0x81B4), buffer, (s16)lbl_801A66B4);
        fn_1_4AE0C(fzgx_format, buffer);
    } else {
        if (lbl_801A66B4 != 5) {
            dy1 = -2;
            fn_1_49590(0.5f);
            fn_1_495B0(0x80000000);
            fn_1_4955C(0.5833333134651184f, 0.5833333134651184f);
        } else {
            dy1 = 0;
            fn_1_4955C(0.5f, 0.5f);
        }
        if (lbl_3_bss_7EE40.unk_8 >= 2) {
            color1 = fzgx_pool_table3[0];
            fn_1_49514(&color1);
            slot = (u8 *)&lbl_3_bss_7EE40 + 0x10000;
            if (fn_3_CE94_array_read(slot, -0x7E60) == 4) {
                x2 = v0 + 40;
                y1 = dy1;
                fn_1_496FC((f32)x2, (f32)(y1 + 219));
                fn_1_4AE0C(fzgx_format, fzgx_text_304[lbl_801A66B4]);
                fn_1_496FC((f32)x2, (f32)(y1 + 244));
                fn_1_4AE0C(fzgx_format, fzgx_text_354[lbl_801A66B4]);
            }
            if (fn_3_CE94_array_read(slot, -0x7E60) == 40) {
                y2 = dy1;
                x1 = v0 + 40;
                fn_1_496FC((f32)x1, (f32)(y2 + 219));
                fn_1_4AE0C(fzgx_format, fzgx_text_3A4[lbl_801A66B4]);
                fn_1_496FC((f32)x1, (f32)(y2 + 244));
                fn_1_4AE0C(fzgx_format, fzgx_text_3F8[lbl_801A66B4]);
                fn_1_496FC((f32)x1, (f32)(y2 + 269));
                fn_1_4AE0C(fzgx_format, fzgx_text_44C[lbl_801A66B4]);
            }
        }
    }
    color2 = fzgx_pool_table4[0];
    fn_1_49514(&color2);
}
#pragma opt_lifetimes reset
/* fzgx:end fn_3_CE94 */

/* fzgx:begin fn_3_D9A0 */
#include "font.h"

extern u32 lbl_3_bss_7ED58[18];
extern u32 lbl_801A6410;
extern u32 lbl_3_data_1A18;
extern u8 fn_1_B7C00(void);
extern void fn_1_46B4(u32 arg0, u32 arg1, char *arg2, u32 arg3);
extern u32 lbl_3_rodata_288[60];
extern void lbl_8006DCA4(void);
extern void lbl_8006E1D8(struct Vec3 *, f32, f32, f32);
extern void fn_1_7BCCC(struct Vec3 *);
extern void fn_80035680(struct GXLightObj *, f32, f32, f32);
extern void fn_80035690(struct GXLightObj *, f32, f32, f32);
extern void fn_80035420(struct GXLightObj *, f32, int);
extern void fn_800356AC(struct GXLightObj *, u32 *);
extern void GXInitLightDistAttn(struct GXLightObj *, f32, f32, int);
extern void fn_1_7BB80(struct GXLightObj *, int);
extern void fn_1_7BD6C(int);
extern void fn_80074CF4(f32, f32, f32);

extern u32 lbl_3_bss_7ED58[18];
extern u32 lbl_801A6410;
extern u32 lbl_3_data_1A18;
extern u8 fn_1_B7C00(void);
extern void fn_1_46B4(u32 arg0, u32 arg1, char *arg2, u32 arg3);
extern u32 lbl_3_rodata_288[60];
extern void lbl_8006DCA4(void);
extern void lbl_8006E1D8(struct Vec3 *, f32, f32, f32);
extern void fn_1_7BCCC(struct Vec3 *);
extern void fn_80035680(struct GXLightObj *, f32, f32, f32);
extern void fn_80035690(struct GXLightObj *, f32, f32, f32);
extern void fn_80035420(struct GXLightObj *, f32, int);
extern void fn_800356AC(struct GXLightObj *, u32 *);
extern void GXInitLightDistAttn(struct GXLightObj *, f32, f32, int);
extern void fn_1_7BB80(struct GXLightObj *, int);
extern void fn_1_7BD6C(int);
extern void fn_80074CF4(f32, f32, f32);

extern u32 lbl_3_bss_7ED58[18];
extern u32 lbl_801A6410;
extern u32 lbl_3_data_1A18;
extern u8 fn_1_B7C00(void);
extern void fn_1_46B4(u32 arg0, u32 arg1, char *arg2, u32 arg3);
extern u32 lbl_3_rodata_288[60];
extern void lbl_8006DCA4(void);
extern void lbl_8006E1D8(struct Vec3 *, f32, f32, f32);
extern void fn_1_7BCCC(struct Vec3 *);
extern void fn_80035680(struct GXLightObj *, f32, f32, f32);
extern void fn_80035690(struct GXLightObj *, f32, f32, f32);
extern void fn_80035420(struct GXLightObj *, f32, int);
extern void fn_800356AC(struct GXLightObj *, u32 *);
extern void GXInitLightDistAttn(struct GXLightObj *, f32, f32, int);
extern void fn_1_7BB80(struct GXLightObj *, int);
extern void fn_1_7BD6C(int);
extern void fn_80074CF4(f32, f32, f32);

struct fn_3_D9A0_lbl_3_bss_87000_0_E12 {
    u16 unk_0;
    u16 pad_2;
    u8 *unk_4;
    u32 *unk_8;
};
struct fn_3_D9A0_Copy88 { u32 a[22]; };
struct fn_3_D9A0_lbl_3_bss_87000 {
    struct fn_3_D9A0_lbl_3_bss_87000_0_E12 unk_0[1];
};
extern f32 lbl_8006D188(u32);
extern int fn_1_4F734(FontDrawPacket *);
extern s32 fn_1_A5DC4(void);

extern void fn_1_51678(FontDrawPacket *, u32, s16, s16, s16, s16);
extern s32 fn_1_4FC50(FontDrawPacket *, u32, u16, u16, u32);

#pragma section code_type ".fzgxpool"
static void fzgx_fn_3_D9A0_pool_head(void) {
    fn_3_D9A0_primer_f(50.0f);
    fn_3_D9A0_primer_f(500.0f);
    fn_3_D9A0_primer_f(31.2f);
    fn_3_D9A0_primer_f(312.0f);
    fn_3_D9A0_primer_f(68.0f);
    fn_3_D9A0_primer_f(20.0f);
    fn_3_D9A0_primer_f(96.0f);
    fn_3_D9A0_primer_f(1.36f);
    fn_3_D9A0_primer_f(161.0f);
    fn_3_D9A0_primer_f(1.015625f);
    fn_3_D9A0_primer_f(129.0f);
    fn_3_D9A0_primer_f(15.0f);
    fn_3_D9A0_primer_f(10.0f);
    fn_3_D9A0_primer_f(0.0f);
    fn_3_D9A0_primer_f(86.0f);
    fn_3_D9A0_primer_f(0.5f);
    fn_3_D9A0_primer_f(139.0f);
    fn_3_D9A0_primer_f(75.0f);
    fn_3_D9A0_primer_d(4503601774854144.0);
}
#pragma section code_type ".text"
const u32 fzgx_pool_fn_3_D9A0_pool_words[] = { 0xFFFF0000, 0xFFFF0000, 0xFFFFFF00 };
#pragma section code_type ".fzgxpool"
static void fzgx_fn_3_D9A0_pool_tail(void) {
    fn_3_D9A0_primer_f(185.0f);
    fn_3_D9A0_primer_f(180.0f);
    fn_3_D9A0_primer_f(276.0f);
    fn_3_D9A0_primer_f(116.0f);
    fn_3_D9A0_primer_f(7.0f);
    fn_3_D9A0_primer_f(205.0f);
    fn_3_D9A0_primer_f(11.4f);
    fn_3_D9A0_primer_f(40.0f);
    fn_3_D9A0_primer_f(65536.0f);
    fn_3_D9A0_primer_f(60.0f);
    fn_3_D9A0_primer_f(80.0f);
    fn_3_D9A0_primer_f(274.0f);
    fn_3_D9A0_primer_f(0.5833333f);
    fn_3_D9A0_primer_f(0.5416667f);
    fn_3_D9A0_primer_f(0.45833334f);
    fn_3_D9A0_primer_d(4503599627370496.0);
    fn_3_D9A0_primer_f(320.0f);
    fn_3_D9A0_primer_f(240.0f);
    fn_3_D9A0_primer_f(5.0f);
    fn_3_D9A0_primer_f(6.1f);
    fn_3_D9A0_primer_f(0.8f);
    fn_3_D9A0_primer_f(228.0f);
    fn_3_D9A0_primer_f(252.0f);
    fn_3_D9A0_primer_f(0.1f);
    fn_3_D9A0_primer_f(-30.0f);
    fn_3_D9A0_primer_f(750.0f);
    fn_3_D9A0_primer_f(48.0f);
    fn_3_D9A0_primer_f(660.0f);
    fn_3_D9A0_primer_f(44.0f);
    fn_3_D9A0_primer_f(24.0f);
    fn_3_D9A0_primer_f(302.0f);
    fn_3_D9A0_primer_f(70.0f);
    fn_3_D9A0_primer_f(330.0f);
    fn_3_D9A0_primer_f(1.27f);
    fn_3_D9A0_primer_f(390.0f);
    fn_3_D9A0_primer_f(308.0f);
    fn_3_D9A0_primer_f(1.0f);
    fn_3_D9A0_primer_f(368.0f);
    fn_3_D9A0_primer_f(360.0f);
    fn_3_D9A0_primer_f(30.0f);
    fn_3_D9A0_primer_f(0.4f);
    fn_3_D9A0_primer_f(32768.0f);
    fn_3_D9A0_primer_f(0.90625f);
    fn_3_D9A0_primer_f(0.921875f);
    fn_3_D9A0_primer_f(0.9375f);
}
#pragma section code_type ".text"

static inline f32 packet_x(s16 x, f32 offset) { return offset + (f32)x; }
static inline s32 packet_offset(s32 x, s32 offset) { return x + offset; }
static inline s32 packet_int_x(s16 x) { return x; }

static inline s32 clamp15(s32 n) {
    return n < 0 ? 0 : n > 15 ? 15 : n;
}

void fn_3_D9A0(void) {
    struct fn_3_D9A0_lbl_3_bss_87000 *p_lbl_3_bss_87000;
    u8 *p_lbl_1_rodata_26F8;
    Obj_3_bss_7EDD8 *p_arrow;
    Obj_3_bss_7EDD8 *p_lbl_3_bss_7EDD8;
    struct { u32 value; } index;
    struct { s32 value; } fade;
    s32 v65;
    u32 v64;
    s16 v19;
    s16 v68;
    struct { u32 value; } v66;
    s32 v0;
    s16 v1;
    u8 v67;
    Obj_3_bss_7EDD8 *p_selected;
    Obj_3_bss_7EDD8 *p_bottom;
    s32 v2;
    s32 v4;
    f32 v11;
    f32 v14;
    f32 v40;
    f32 v47;
    f32 v51;
    f32 v57;
    struct { s32 value; } n;
    s32 d;
    s32 cn;
    s32 cd;
    u8 start;
    u32 image;
    struct fn_3_D9A0_lbl_3_bss_87000_0_E12 *entry;
    FontDrawPacket loc_8;

    if ((s8)fn_1_A5DC4() != 0) {
        v2 = lbl_3_bss_7EDD8.unk_24;
        n.value = (s16)v2 < 0 ? 0 : v2 > 15 ? 15 : v2;
        d = v2 - 15;
        v0 = (s32)(f32)(-30.0f + (f32)(750.0f - (f32)(48.0f * (f32)n.value)));
        v1 = (s16)clamp15(d);
    } else {
        v4 = lbl_3_bss_7EDD8.unk_24;
        n.value = (s16)v4 < 0 ? 0 : v4 > 15 ? 15 : v4;
        d = v4 - 15;
        v0 = (s32)(f32)(660.0f - (f32)(44.0f * (f32)n.value));
        v1 = (s16)clamp15(d);
    }
    loc_8 = *(FontDrawPacket *)&(*(u8 (*)[])&lbl_1_rodata_26F8);
    loc_8.image = 0x8925;
    v11 = packet_x(v0, 24.0f);
    loc_8.y = 302.0f;
    loc_8.z = 70.0f;
    loc_8.flags = 5;
    loc_8.x = v11;
    fn_1_51678(&loc_8, 0x8925, 0, 0, 296, 28);
    fn_1_4F734(&loc_8);
    v14 = packet_x(v0, 320.0f);
    loc_8.flags |= 0x80000;
    loc_8.x = v14;
    fn_1_4F734(&loc_8);
    loc_8 = *(FontDrawPacket *)&(*(u8 (*)[])&lbl_1_rodata_26F8);
    loc_8.image = 0x8925;
    loc_8.x = v11;
    loc_8.y = 330.0f;
    loc_8.z = 70.0f;
    loc_8.flags = 5;
    fn_1_51678(&loc_8, 0x8925, 0, 28, 296, 8);
    loc_8.scale_y = 1.27f;
    fn_1_4F734(&loc_8);
    loc_8.x = v14;
    loc_8.flags |= 0x80000;
    fn_1_4F734(&loc_8);
    loc_8 = *(FontDrawPacket *)&(*(u8 (*)[])&lbl_1_rodata_26F8);
    loc_8.image = 0x8925;
    loc_8.x = v11;
    loc_8.y = 390.0f;
    loc_8.z = 70.0f;
    loc_8.flags = 5;
    fn_1_51678(&loc_8, 0x8925, 0, 36, 296, 12);
    fn_1_4F734(&loc_8);
    loc_8.x = v14;
    loc_8.flags |= 0x80000;
    fn_1_4F734(&loc_8);
    loc_8 = *(FontDrawPacket *)&(*(u8 (*)[])&lbl_1_rodata_26F8);
    v19 = (s16)v0;
    loc_8.image = 0x8915;
    loc_8.x = (f32)(s32)(v19 + 38);
    loc_8.y = 308.0f;
    loc_8.z = 60.0f;
    loc_8.flags = 5;
    fn_1_4F734(&loc_8);
    loc_8 = *(FontDrawPacket *)&(*(u8 (*)[])&lbl_1_rodata_26F8);
    loc_8.x = (f32)(s32)(v19 + 405);
    p_lbl_3_bss_7EDD8 = &lbl_3_bss_7EDD8;
    loc_8.image = 0x891C;
    loc_8.y = 308.0f;
    loc_8.z = 60.0f;
    if (p_lbl_3_bss_7EDD8->unk_3C == 0) {
        loc_8.alpha = 1.0f;
    } else {
        loc_8.alpha = 0.5f;
    }
    loc_8.flags = 5;
    fn_1_4F734(&loc_8);
    loc_8 = *(FontDrawPacket *)&(*(u8 (*)[])&lbl_1_rodata_26F8);
    loc_8.image = 0x891D;
    loc_8.x = (f32)(s32)(v19 + 510);
    loc_8.y = 308.0f;
    loc_8.z = 60.0f;
    if (p_lbl_3_bss_7EDD8->unk_3C == 1) {
        loc_8.alpha = 1.0f;
    } else {
        loc_8.alpha = 0.5f;
    }
    loc_8.flags = 5;
    fn_1_4F734(&loc_8);
    loc_8 = *(FontDrawPacket *)&(*(u8 (*)[])&lbl_1_rodata_26F8);
    loc_8.image = 0x891B;
    loc_8.x = (f32)(s32)(v19 + 300);
    loc_8.y = 308.0f;
    loc_8.z = 60.0f;
    if (p_lbl_3_bss_7EDD8->unk_3C == 2) {
        loc_8.alpha = 1.0f;
    } else {
        loc_8.alpha = 0.5f;
    }
    loc_8.flags = 5;
    fn_1_4F734(&loc_8);
    if ((lbl_3_bss_7EDD8.unk_C & 0x8000000) != 0) {
        loc_8 = *(FontDrawPacket *)&(*(u8 (*)[])&lbl_1_rodata_26F8);
        p_selected = &lbl_3_bss_7EDD8;
        loc_8.image = 0x890B;
        n.value = p_selected->unk_1F * 62;
        n.value += v19;
        loc_8.x = (f32)(n.value + 31);
        loc_8.y = 320.0f;
        loc_8.z = 60.0f;
        loc_8.flags = 5;
        fn_1_4F734(&loc_8);
        {
            struct { s32 value; } sum;
            n.value = p_selected->unk_1F * 62;
            sum.value = n.value;
            sum.value += v19;
            loc_8.x = (f32)(sum.value + 80);
            loc_8.flags |= 0x80000;
            fn_1_4F734(&loc_8);
            n.value = p_selected->unk_1F * 62;
            sum.value = n.value;
            sum.value += v19;
            loc_8.x = (f32)(sum.value + 31);
            loc_8.y = 368.0f;
            loc_8.z = 60.0f;
            loc_8.flags = 0x100005;
            fn_1_4F734(&loc_8);
            {
                struct { u32 value; } final_sum;
                n.value = p_selected->unk_1F * 62;
                final_sum.value = v19;
                final_sum.value = n.value + final_sum.value;
                loc_8.x = (f32)(s32)(final_sum.value + 80);
                loc_8.flags |= 0x80000;
                fn_1_4F734(&loc_8);
            }
        }
    }
    loc_8 = *(FontDrawPacket *)&(*(u8 (*)[])&lbl_1_rodata_26F8);
    p_arrow = &lbl_3_bss_7EDD8;
    loc_8.image = 0x8901;
    loc_8.x = (f32)(s32)(v19 + 30);
    loc_8.y = 360.0f;
    loc_8.z = 30.0f;
    loc_8.flags = 10;
    if (p_arrow->unk_1E != 0) {
        v47 = lbl_8006D188((s32)(f32)(32768.0f * (f32)((f32)(u32)p_arrow->unk_20 / 10.0f)));
        v51 = (f32)(0.4f * v47);
        loc_8.scale_x = (f32)(1.0f + v51);
        loc_8.scale_y = loc_8.scale_x;
        loc_8.alpha = (f32)(1.0f - v51);
        fn_1_4F734(&loc_8);
        if (p_arrow->unk_20 < 10) {
            p_arrow->unk_20++;
        }
    }
    if ((s32)(p_arrow->unk_1E + 9) < (s32)((struct fn_3_D9A0_lbl_3_bss_87000 *)&lbl_3_bss_87000)->unk_0[p_lbl_3_bss_7EDD8->unk_3C].unk_0) {
        p_bottom = &lbl_3_bss_7EDD8;
        v47 = lbl_8006D188((s32)(f32)(32768.0f * (f32)((f32)(u32)p_bottom->unk_21 / 10.0f)));
        v57 = (f32)(0.4f * v47);
        loc_8.scale_x = (f32)(1.0f + v57);
        loc_8.scale_y = loc_8.scale_x;
        loc_8.alpha = (f32)(1.0f - v57);
        loc_8.x = (f32)(s32)(v19 + 610);
        loc_8.flags |= 0x80000;
        fn_1_4F734(&loc_8);
        if (p_bottom->unk_21 < 10) {
            p_bottom->unk_21++;
        }
    }
    {
    v68 = p_arrow->unk_1E;
    index.value = (s16)v68 << 2;
    v66.value = 65535;
    fade.value = v1;
    p_lbl_1_rodata_26F8 = (u8 *)&(*(u8 (*)[])&lbl_1_rodata_26F8);
    p_lbl_3_bss_87000 = (struct fn_3_D9A0_lbl_3_bss_87000 *)&lbl_3_bss_87000;
    for (; (start = p_arrow->unk_1E), v68 < start + 9; index.value += 4, v68++) {
        loc_8 = *(FontDrawPacket *)p_lbl_1_rodata_26F8;
        v67 = v68 - start;
        n.value = v67 * 62;
        n.value += v19;
        loc_8.x = (f32)packet_offset(n.value, 72);
        loc_8.y = 360.0f;
        loc_8.z = 30.0f;
        loc_8.flags = 10;
        if ((s8)fn_1_A5DC4() != 0) {
            n.value = clamp15(fade.value - v67);
            d = clamp15(15 - v67);
            loc_8.scale_x = (f32)(0.90625f * (f32)n.value) / (f32)d;
        } else {
            n.value = clamp15(fade.value - v67);
            d = clamp15(15 - v67);
            loc_8.scale_x = (f32)(0.921875f * (f32)n.value) / (f32)d;
        }
        {
            struct { s32 value; } numerator;
            struct { f32 value; } clamped;
            numerator.value = fade.value - v67;
            cn = clamp15(numerator.value);
            d = 15 - v67;
            cd = clamp15(d);
            v40 = (f32)(numerator.value * (s32)v66.value) / (f32)d;
            loc_8.scale_y = (f32)(0.9375f * (f32)cn) / (f32)cd;
            *(u16 *)((u8 *)&loc_8 + 0x28) = (u16)v40;
        }
        entry = &((struct fn_3_D9A0_lbl_3_bss_87000 *)&lbl_3_bss_87000)->unk_0[p_lbl_3_bss_7EDD8->unk_3C];
        if (entry->unk_8 == 0 || (image = *(u32 *)((u8 *)entry->unk_8 + index.value)) == 0 || entry->unk_4[v68] == 0) {
            loc_8.image = 0x8917;
            fn_1_4F734(&loc_8);
        } else {
            fn_1_4FC50(&loc_8, 5, 64, 64, image);
        }
    }
    }
}
/* fzgx:end fn_3_D9A0 */

/* fzgx:begin fn_3_E5D4 */
#include "types.h"

typedef struct CustomizeSlot {
    u8 pad[5];
    u8 field5;
    u8 tail[0x81c0 - 6];
} CustomizeSlot;

typedef struct CustomizeHead {
    u8 pad_1c[0x1c];
    s16 unk_1c;
    u8 pad_1e[0x28];
    u8 unk_46;
    u8 pad_47[0x21];
} CustomizeHead;

/* file-scope objects of the retail TU, in retail order: MWCC addresses them off one section base */
CustomizeSlot *fzgx_obj_lbl_3_bss_7EDC0;
u32 lbl_3_bss_7EDC0__fzgx_offset_4;
u32 lbl_3_bss_7EDC0__fzgx_offset_8;
u32 lbl_3_bss_7EDCC__fzgx_offset_0;
u32 lbl_3_bss_7EDCC__fzgx_offset_4;
u32 lbl_3_bss_7EDCC__fzgx_offset_8;
CustomizeHead lbl_3_bss_7EDD8__fzgx_offset_0;

#pragma section code_type ".fzgxpool"
__declspec(section ".fzgxpool") static void fzgx_bss_prime(void) {
    volatile u32 s;  /* fzgx-allow: S2 primer sink */
    s = (u32)fzgx_obj_lbl_3_bss_7EDC0;
    s = lbl_3_bss_7EDC0__fzgx_offset_4;
    s = lbl_3_bss_7EDC0__fzgx_offset_8;
    s = lbl_3_bss_7EDCC__fzgx_offset_0;
    s = lbl_3_bss_7EDCC__fzgx_offset_4;
    s = lbl_3_bss_7EDCC__fzgx_offset_8;
    s = lbl_3_bss_7EDD8__fzgx_offset_0.unk_46;
}
#pragma section code_type ".text"

extern s16 fn_3_F948(void *arg0);
extern void fn_1_87238(u32 arg0, u32 arg1, f32 arg2);

void fn_3_E5D4(void) {
    u8 work[0x440] __attribute__((aligned(32)));

    if (fzgx_obj_lbl_3_bss_7EDC0[lbl_3_bss_7EDD8__fzgx_offset_0.unk_46].field5 < 0x29) {
        fn_1_870BC(lbl_3_bss_7EDCC__fzgx_offset_0, 0, lbl_3_bss_7EDCC__fzgx_offset_0, 0, 1, ((0)[lbl_3_rodata_378]));
        if (fn_3_F948((*(u8 (*)[33216])&lbl_3_bss_7EE40) + 0x20) && lbl_3_bss_7EDD8__fzgx_offset_0.unk_1c == 0) {
            fn_1_87238(lbl_3_bss_7EDCC__fzgx_offset_0, 0, lbl_3_rodata_378[0]);
        }
    } else {
        fn_80008BEC(work, 0, 0x440);
        *(u32 *)(work + 0x390) |= 0x4000000;
        *(u32 *)(work + 0x3a0) = lbl_3_bss_7EDC0__fzgx_offset_8;
        *(u32 *)(work + 0x3a4) = lbl_3_bss_7EDCC__fzgx_offset_4;
        *(u16 *)(work + 0x3ba) = 0;
        fn_1_151BDC((*(u8 (*)[33216])&lbl_3_bss_7EE40));
        fn_1_14E2DC(lbl_3_bss_7EDC0__fzgx_offset_8, 0, lbl_3_rodata_378[0]);
    }
}
/* fzgx:end fn_3_E5D4 */

/* fzgx:begin fn_3_E6F8 noprologue */
#include "types.h"
#include "font.h"

/* fzgx:begin fn_3_E6F8 noprologue */
typedef struct {
    u32 unk_0;  // 1 loads, 0 stores
    u8 pad_4[0x3];
    u8 unk_7;  // 0 loads, 5 stores
    u8 unk_8;  // 4 loads, 3 stores
    u8 pad_9[0x17];
    s16 unk_20;  // 1 loads, 0 stores
    u8 pad_22[0x2];
    u32 unk_24;  // 14 loads, 2 stores
    u32 unk_28;  // 1 loads, 0 stores
    u16 unk_2C;  // 1 loads, 0 stores
    u8 pad_2E[0x2];
    f32 unk_30;  // 0 loads, 1 stores
    f32 unk_34;  // 0 loads, 1 stores
    u8 pad_38[0x28];
    f32 unk_60;  // 0 loads, 1 stores
    f32 unk_64;  // 0 loads, 1 stores
    u8 pad_68[0x8158];
} Obj_3_bss_7EE40;
typedef struct {
    u32 unk_0;  // 0 loads, 1 stores
    u32 unk_4;  // 2 loads, 1 stores
    u8 pad_8[0x2];
    s16 unk_A;  // 1 loads, 1 stores
    u32 unk_C;  // 14 loads, 8 stores
    u32 unk_10;  // 2 loads, 4 stores
    u8 unk_14;  // 23 loads, 0 stores
    u8 unk_15;  // 11 loads, 0 stores
    u8 pad_16[0x2];
    u32 unk_18;  // 6 loads, 6 stores
    s16 unk_1C;  // 4 loads, 0 stores
    u8 unk_1E;  // 9 loads, 3 stores
    u8 unk_1F;  // 9 loads, 2 stores
    u8 unk_20;  // 2 loads, 3 stores
    u8 unk_21;  // 2 loads, 3 stores
    s16 unk_22;  // 2 loads, 2 stores
    s16 unk_24;  // 13 loads, 5 stores
    s16 unk_26;  // 3 loads, 2 stores
    s16 unk_28;  // 2 loads, 2 stores
    u16 unk_2A;  // 1 loads, 0 stores
    u32 unk_2C;  // 0 loads, 3 stores
    u32 unk_30;  // 0 loads, 1 stores
    u32 unk_34;  // 0 loads, 1 stores
    u32 unk_38;  // 0 loads, 1 stores
    u8 unk_3C;  // 12 loads, 2 stores
    u8 pad_3D[0x9];
    u8 unk_46;  // 2 loads, 1 stores
    u8 unk_47;  // 0 loads, 1 stores
    s16 unk_48;  // 2 loads, 2 stores
    u8 pad_4A[0x2];
    s16 unk_4C;  // 2 loads, 2 stores
    s16 unk_4E;  // 2 loads, 2 stores
    u8 pad_50[0x1];
    u8 unk_51;  // 1 loads, 2 stores
    u8 pad_52[0x16];
} Obj_3_bss_7EDD8;
typedef struct {
    u8 pad_0[0x5];
    u8 unk_5;  // 1 loads, 0 stores
    u8 pad_6[0x1];
    u8 unk_7;  // 0 loads, 1 stores
    u8 unk_8;  // 1 loads, 0 stores
} Obj_3_bss_7EDC0_At0;
typedef struct {
    Obj_3_bss_7EDC0_At0 *unk_0;  // 20 loads, 1 stores
    u8 pad_4[0x4];
    u32 unk_8;  // 4 loads, 2 stores
} Obj_3_bss_7EDC0;
typedef struct { u8 pad0[0x24]; u32 flags; u16 unk28; s16 rotation;
    u8 pad2c[0x60-0x2c]; f32 x, y; u8 pad68[0x2060-0x68]; } Slot2060;
extern Slot2060 lbl_3_bss_7EE40[];
extern u16 lbl_3_data_1A40;


typedef void (*Callback)(void);
typedef struct { f32 x, y, z; } Vec;
typedef struct { s16 x, y, z; } Rot;
typedef struct { u32 unk0; Vec eye, target; f32 unk1c; s16 roll; u16 unk22; } Cam;
typedef struct { f32 v[4][4]; } Matrix44;
typedef struct { f32 v[3][4]; } Matrix34;
typedef struct { void **parts; u32 unk4, unk8; } PartSlot;
typedef struct { u8 pad0[0x328]; s8 type; u8 pad329[0xb]; PartSlot slots[7]; u8 pad388[8]; u32 flags; u8 pad394[0xc]; void *model; u8 pad3a4[0x16]; s16 field3ba; } Car;
extern const FontDrawPacket lbl_1_rodata_26F8;
extern u8 lbl_3_rodata_288[];
extern Cam lbl_3_bss_9F640;
extern s32 lbl_801A66B4;
extern f32 fn_1_A6FE8(void);
extern void C_MTXPerspective(void *, f32, f32, f32, f32);
extern void fn_800737E4(void *, s32);
extern void fn_3_F878(void);
extern void fn_1_FD844(void *, void *);
extern void fn_1_FD1D4(void);
extern void fn_1_FD27C(void);
extern void fn_1_133DBC(void *);
extern void fn_1_134AD4(void);
extern s32 fn_3_11930(void);
extern void fn_1_13ABA8(u32);
extern char *fn_3_11FD0(s32, u32);
extern void fn_1_138120(char *);
extern void camera_update_state(void *);
extern void lbl_8006DCA4(void);
extern void mathutil_mtxA_rotate_x(s16);
extern void mathutil_mtxA_rotate_y(s16);
extern void fn_80072558(void);
extern void lbl_8006DB74(void *);
extern void lbl_8006DBAC(void *);
extern void fn_1_14DE80(void *, void **, void **, s32, f32);
extern void fn_1_14E054(void *, Vec *, s32, f32);
extern void fn_1_14E198(void *, Vec *, s32, f32);
extern void fn_1_87238(Car *, s32, f32);
extern void fn_1_55210(void *);
extern void fn_1_FCFA4(void *);
extern void fn_1_FD388(void *, f32);
extern void fn_3_2C73C(void *, void *, Vec *, Vec *, Rot *, f32, f32);
extern void fn_3_E5D4(void *);
extern void fn_3_C400(void);
extern void fn_3_CE94(s16);
extern void fn_3_D9A0(void);
extern void fn_3_F044(void);
extern void fn_1_50A90(void *, s32, s32, s32, s32);
extern void fn_1_4955C(f32, f32);
extern void fn_1_495C8(u8);
extern void fn_1_496FC(f32, f32);
extern void fn_1_4954C(f32);

/* Native objects and their first-use order reproduce the retail BSS base. */
Obj_3_bss_7EDC0 fzgx_obj_lbl_3_bss_7EDC0;
Car *lbl_3_bss_7EDCC__fzgx_offset_0;
u32 lbl_3_bss_7EDCC__fzgx_offset_4;
u32 lbl_3_bss_7EDCC__fzgx_offset_8;
Obj_3_bss_7EDD8 fzgx_obj_lbl_3_bss_7EDD8;
Obj_3_bss_7EE40 fzgx_obj_lbl_3_bss_7EE40;
u32 fzgx_obj_lbl_3_bss_87000[16];
u32 fzgx_obj_lbl_3_bss_87040[0x81c0/4];
typedef struct { u8 bytes[0x1042c]; Callback draw; u8 tail[0x10]; } Context;
Context fzgx_obj_lbl_3_bss_8F200;

extern u8 fn_3_10260__fzgx_offset_0[];
extern u8 fn_3_104C4__fzgx_offset_0[];
extern u8 fn_3_106FC__fzgx_offset_0[];
extern u8 fn_3_10B68__fzgx_offset_0[];
extern u8 fn_3_10CB8__fzgx_offset_0[];
extern u8 fn_3_113AC__fzgx_offset_0[];
extern u8 fn_3_1180C__fzgx_offset_0[];
extern u8 fn_3_118BC__fzgx_offset_0[];
extern u8 fn_3_F984__fzgx_offset_0[];
extern u8 fn_3_FD30__fzgx_offset_0[];
extern u8 lbl_3_data_1A44__fzgx_offset_0[];
extern u8 lbl_3_data_1A6C__fzgx_offset_0[];
extern u8 lbl_3_data_1A70__fzgx_offset_0[];
extern u8 lbl_3_data_1ACC__fzgx_offset_0[];
extern u8 lbl_3_data_1B24__fzgx_offset_0[];
extern u8 lbl_3_data_1BB4__fzgx_offset_0[];
extern u8 lbl_3_data_1C04__fzgx_offset_0[];
extern u8 lbl_3_data_1C64__fzgx_offset_0[];
extern u8 lbl_3_data_1C70__fzgx_offset_0[];
extern u8 lbl_3_data_1C98__fzgx_offset_0[];
extern u8 lbl_3_data_1CA8__fzgx_offset_0[];
extern u8 lbl_3_data_1CD4__fzgx_offset_0[];
extern u8 lbl_3_data_1CE4__fzgx_offset_0[];
extern u8 lbl_3_data_1D10__fzgx_offset_0[];
extern u8 lbl_3_data_1D24__fzgx_offset_0[];
extern u8 lbl_3_data_1D5C__fzgx_offset_0[];
extern u8 lbl_3_data_1D74__fzgx_offset_0[];
extern u8 lbl_3_data_1DAC__fzgx_offset_0[];
extern u8 lbl_3_data_1DC4__fzgx_offset_0[];
extern u8 lbl_3_data_1DFC__fzgx_offset_0[];
extern u8 lbl_3_data_1E14__fzgx_offset_0[];
extern u8 lbl_3_data_1E50__fzgx_offset_0[];
extern u8 lbl_3_data_1E68__fzgx_offset_0[];
extern u8 lbl_3_data_1EA4__fzgx_offset_0[];
extern u8 lbl_3_data_1EA8__fzgx_offset_0[];
extern u8 lbl_3_data_1EB0__fzgx_offset_0[];
extern u8 lbl_3_data_1EB4__fzgx_offset_0[];
extern u8 lbl_3_data_2DCC__fzgx_offset_0[];
extern u8 lbl_3_data_2DE0__fzgx_offset_0[];
extern u8 lbl_3_data_2DFC__fzgx_offset_0[];
extern u8 lbl_3_data_2E24__fzgx_offset_0[];
extern u8 lbl_3_data_2E54__fzgx_offset_0[];
extern u8 lbl_3_data_2E64__fzgx_offset_0[];
extern u8 lbl_3_data_2E80__fzgx_offset_0[];
extern u8 lbl_3_data_2E90__fzgx_offset_0[];
extern u8 lbl_3_data_2EAC__fzgx_offset_0[];
extern u8 lbl_3_data_2EC0__fzgx_offset_0[];
extern u8 lbl_3_data_2EE0__fzgx_offset_0[];
extern u8 lbl_3_data_2EF4__fzgx_offset_0[];
extern u8 lbl_3_data_2F04__fzgx_offset_0[];
extern u8 lbl_3_data_2F20__fzgx_offset_0[];
extern u8 lbl_3_data_2F3C__fzgx_offset_0[];
extern u8 lbl_3_data_2F50__fzgx_offset_0[];
extern u8 lbl_3_data_2F64__fzgx_offset_0[];
extern u8 lbl_3_data_3068__fzgx_offset_0[];
extern u8 lbl_3_data_307C__fzgx_offset_0[];
extern u8 lbl_3_data_309C__fzgx_offset_0[];
extern u8 lbl_3_data_30AC__fzgx_offset_0[];
extern u8 lbl_3_data_30C8__fzgx_offset_0[];
extern u8 lbl_3_data_30D4__fzgx_offset_0[];
extern u8 lbl_3_data_30E0__fzgx_offset_0[];
extern u8 lbl_3_data_30EC__fzgx_offset_0[];
extern u8 lbl_3_data_30FC__fzgx_offset_0[];
extern u8 lbl_3_data_3120__fzgx_offset_0[];
extern u8 lbl_3_data_315C__fzgx_offset_0[];
extern u8 lbl_3_data_3168__fzgx_offset_0[];
extern u8 lbl_3_data_3174__fzgx_offset_0[];
extern u8 lbl_3_data_3180__fzgx_offset_0[];
static u32 fzgx_pool_native_lbl_3_data_1A40_gap0[287] = {0xFFFF0000, 0x53617669, 0x6E672063, 0x75727265, 0x6E742063, 0x68616E67, 0x65732E0A, 0x20497320, 0x74686973, 0x204F4B3F, 0x20000000, 0x00000000, 0x8CBB5B82, 0xB082F15D, 0x8DDD5B82, 0xB482A25D, 0x82CC95CF, 0x5B82D682, 0xF15D8D58, 0x5B82B182, 0xA45D82F0, 0x835A815B, 0x837582B5, 0x82DC82B7, 0x81420A82, 0xE682EB82, 0xB582A282, 0xC582B782, 0xA93F0000, (u32)lbl_3_data_1A44__fzgx_offset_0, (u32)lbl_3_data_1A6C__fzgx_offset_0, (u32)lbl_3_data_1A6C__fzgx_offset_0, (u32)lbl_3_data_1A6C__fzgx_offset_0, (u32)lbl_3_data_1A6C__fzgx_offset_0, (u32)lbl_3_data_1A70__fzgx_offset_0, 0x50617374, 0x6564206F, 0x626A6563, 0x74732068, 0x61766520, 0x6368616E, 0x6765642E, 0x0A205072, 0x65706172, 0x696E6720, 0x746F2073, 0x61766520, 0x616E6420, 0x72657475, 0x726E2074, 0x6F207468, 0x65204761, 0x72616765, 0x2E0A4973, 0x20746869, 0x73204F4B, 0x3F200000, 0x935C5B82, 0xCD5D82E8, 0x95745B82, 0xC25D82AF, 0x82AA95CF, 0x5B82D682, 0xF15D8D58, 0x5B82B182, 0xA45D82B3, 0x82EA82C4, 0x82A282DC, 0x82B78142, 0x0A835A81, 0x5B837582, 0xB582C491, 0x4F5B82DC, 0x82A65D82, 0xCC89E65B, 0x82AA5D96, 0xCA5B82DF, 0x82F15D82, 0xC996DF5B, 0x82E082C7, 0x5D82E882, 0xDC82B781, 0x420A82E6, 0x82EB82B5, 0x82A282C5, 0x82B782A9, 0x3F000000, (u32)lbl_3_data_1ACC__fzgx_offset_0, (u32)lbl_3_data_1A6C__fzgx_offset_0, (u32)lbl_3_data_1A6C__fzgx_offset_0, (u32)lbl_3_data_1A6C__fzgx_offset_0, (u32)lbl_3_data_1A6C__fzgx_offset_0, (u32)lbl_3_data_1B24__fzgx_offset_0, 0x52657475, 0x726E696E, 0x6720746F, 0x20746865, 0x20707265, 0x76696F75, 0x73207363, 0x7265656E, 0x0A207769, 0x74686F75, 0x74207361, 0x76696E67, 0x20637572, 0x72656E74, 0x20636861, 0x6E676573, 0x2E0A2049, 0x73207468, 0x6973204F, 0x4B3F2000, 0x835A815B, 0x837582B9, 0x82B882C9, 0x914F5B82, 0xDC82A65D, 0x82CC89E6, 0x5B82AA5D, 0x96CA5B82, 0xDF82F15D, 0x82C996DF, 0x5B82E082, 0xC75D82E8, 0x82DC82B7, 0x81420A82, 0xE682EB82, 0xB582A282, 0xC582B782, 0xA93F0000, (u32)lbl_3_data_1BB4__fzgx_offset_0, (u32)lbl_3_data_1A6C__fzgx_offset_0, (u32)lbl_3_data_1A6C__fzgx_offset_0, (u32)lbl_3_data_1A6C__fzgx_offset_0, (u32)lbl_3_data_1A6C__fzgx_offset_0, (u32)lbl_3_data_1C04__fzgx_offset_0, 0x426F6479, 0x20506172, 0x74730000, 0x837B8366, 0x83428370, 0x815B8363, 0x00000000, (u32)lbl_3_data_1C64__fzgx_offset_0, (u32)lbl_3_data_1A6C__fzgx_offset_0, (u32)lbl_3_data_1A6C__fzgx_offset_0, (u32)lbl_3_data_1A6C__fzgx_offset_0, (u32)lbl_3_data_1A6C__fzgx_offset_0, (u32)lbl_3_data_1C70__fzgx_offset_0, 0x436F636B, 0x70697420, 0x50617274, 0x73000000, 0x8352834E, 0x83728362, 0x83678370, 0x815B8363, 0x00000000, (u32)lbl_3_data_1C98__fzgx_offset_0, (u32)lbl_3_data_1A6C__fzgx_offset_0, (u32)lbl_3_data_1A6C__fzgx_offset_0, (u32)lbl_3_data_1A6C__fzgx_offset_0, (u32)lbl_3_data_1A6C__fzgx_offset_0, (u32)lbl_3_data_1CA8__fzgx_offset_0, 0x426F6F73, 0x74657220, 0x50617274, 0x73000000, 0x8375815B, 0x8358835E, 0x815B8370, 0x815B8363, 0x00000000, (u32)lbl_3_data_1CD4__fzgx_offset_0, (u32)lbl_3_data_1A6C__fzgx_offset_0, (u32)lbl_3_data_1A6C__fzgx_offset_0, (u32)lbl_3_data_1A6C__fzgx_offset_0, (u32)lbl_3_data_1A6C__fzgx_offset_0, (u32)lbl_3_data_1CE4__fzgx_offset_0, 0x46697265, 0x20537469, 0x6E677261, 0x7920426F, 0x64790000, 0x83748340, 0x83438341, 0x83588365, 0x83428393, 0x834F838C, 0x834382CC, 0x837B8366, 0x83420000, (u32)lbl_3_data_1D10__fzgx_offset_0, (u32)lbl_3_data_1A6C__fzgx_offset_0, (u32)lbl_3_data_1A6C__fzgx_offset_0, (u32)lbl_3_data_1A6C__fzgx_offset_0, (u32)lbl_3_data_1A6C__fzgx_offset_0, (u32)lbl_3_data_1D24__fzgx_offset_0, 0x46697265, 0x20537469, 0x6E677261, 0x79205061, 0x72747320, 0x31000000, 0x83748340, 0x83438341, 0x83588365, 0x83428393, 0x834F838C, 0x834382CC, 0x8370815B, 0x83630000, (u32)lbl_3_data_1D5C__fzgx_offset_0, (u32)lbl_3_data_1A6C__fzgx_offset_0, (u32)lbl_3_data_1A6C__fzgx_offset_0, (u32)lbl_3_data_1A6C__fzgx_offset_0, (u32)lbl_3_data_1A6C__fzgx_offset_0, (u32)lbl_3_data_1D74__fzgx_offset_0, 0x5261696E, 0x626F7720, 0x50686F65, 0x6E697820, 0x426F6479, 0x00000000, 0x838C8343, 0x8393837B, 0x815B8374, 0x8346836A, 0x8362834E, 0x835882CC, 0x837B8366, 0x83420000, (u32)lbl_3_data_1DAC__fzgx_offset_0, (u32)lbl_3_data_1A6C__fzgx_offset_0, (u32)lbl_3_data_1A6C__fzgx_offset_0, (u32)lbl_3_data_1A6C__fzgx_offset_0, (u32)lbl_3_data_1A6C__fzgx_offset_0, (u32)lbl_3_data_1DC4__fzgx_offset_0, 0x5261696E, 0x626F7720, 0x50686F65, 0x6E697820, 0x50617274, 0x73203100, 0x838C8343, 0x8393837B, 0x815B8374, 0x8346836A, 0x8362834E, 0x835882CC, 0x8370815B, 0x83638250, 0x00000000, (u32)lbl_3_data_1DFC__fzgx_offset_0, (u32)lbl_3_data_1A6C__fzgx_offset_0, (u32)lbl_3_data_1A6C__fzgx_offset_0, (u32)lbl_3_data_1A6C__fzgx_offset_0, (u32)lbl_3_data_1A6C__fzgx_offset_0, (u32)lbl_3_data_1E14__fzgx_offset_0, 0x5261696E, 0x626F7720, 0x50686F65, 0x6E697820, 0x50617274, 0x73203200, 0x838C8343, 0x8393837B, 0x815B8374, 0x8346836A, 0x8362834E, 0x835882CC, 0x8370815B, 0x83638251, 0x00000000, (u32)lbl_3_data_1E50__fzgx_offset_0, (u32)lbl_3_data_1A6C__fzgx_offset_0, (u32)lbl_3_data_1A6C__fzgx_offset_0, (u32)lbl_3_data_1A6C__fzgx_offset_0, (u32)lbl_3_data_1A6C__fzgx_offset_0, (u32)lbl_3_data_1E68__fzgx_offset_0, 0x4E4F0000, 0x82A282A2, 0x82A60000, 0x59455300, 0x82CD82A2, 0x00000000}; /* fzgx-allow: A1 measured retail data and symbolic pointer bindings */
typedef struct { u32 first[6]; u32 second[6]; } TextTable;
static TextTable fzgx_pool_native_lbl_3_data_1A40_texts = {{(u32)lbl_3_data_1EA4__fzgx_offset_0, (u32)lbl_3_data_1A6C__fzgx_offset_0, (u32)lbl_3_data_1A6C__fzgx_offset_0, (u32)lbl_3_data_1A6C__fzgx_offset_0, (u32)lbl_3_data_1A6C__fzgx_offset_0, (u32)lbl_3_data_1EA8__fzgx_offset_0}, {(u32)lbl_3_data_1EB0__fzgx_offset_0, (u32)lbl_3_data_1A6C__fzgx_offset_0, (u32)lbl_3_data_1A6C__fzgx_offset_0, (u32)lbl_3_data_1A6C__fzgx_offset_0, (u32)lbl_3_data_1A6C__fzgx_offset_0, (u32)lbl_3_data_1EB4__fzgx_offset_0}}; /* fzgx-allow: A1 measured retail data and symbolic pointer bindings */
static u32 fzgx_pool_native_lbl_3_data_1A40_gap4ac[1264] = {0x3F000000, 0x3ECCCCCD, 0xC0200000, 0xBF800000, 0xC0400000, 0x40200000, 0x40000000, 0x40600000, 0x3F19999A, 0x3ECCCCCD, 0xBFCCCCCD, 0xBF4CCCCD, 0xC02CCCCD, 0x3FCCCCCD, 0x3FCCCCCD, 0x4019999A, 0x3F19999A, 0x3ECCCCCD, 0xBFE66666, 0xBF4CCCCD, 0xC02CCCCD, 0x3FE66666, 0x3FCCCCCD, 0x402CCCCD, 0x3F000000, 0x3ED70A3D, 0xBFE66666, 0xBF4CCCCD, 0xC0400000, 0x3FE66666, 0x3FCCCCCD, 0x40400000, 0x3F000000, 0x3E800000, 0xBFE66666, 0xBF4CCCCD, 0xC0266666, 0x3FE66666, 0x3FCCCCCD, 0x40400000, 0x3F19999A, 0x3ED70A3D, 0xC0200000, 0xBF4CCCCD, 0xC0266666, 0x40200000, 0x40000000, 0x40266666, 0x3F266666, 0x3F000000, 0xBFE66666, 0xBF4CCCCD, 0xC0266666, 0x3FE66666, 0x40000000, 0x40266666, 0x3F19999A, 0x3ECCCCCD, 0xBFE66666, 0xBF4CCCCD, 0xC0266666, 0x3FE66666, 0x3FCCCCCD, 0x40266666, 0x3F000000, 0x3ECCCCCD, 0xBFE66666, 0xBF4CCCCD, 0xC0266666, 0x3FE66666, 0x40000000, 0x40266666, 0x3F000000, 0x3F000000, 0xC0000000, 0xBF4CCCCD, 0xC0333333, 0x40000000, 0x400CCCCD, 0x40333333, 0x3F19999A, 0x3ECCCCCD, 0xC0000000, 0xBF4CCCCD, 0xC0333333, 0x40000000, 0x400CCCCD, 0x40333333, 0x3F000000, 0x3EE66666, 0xC0000000, 0xBF4CCCCD, 0xC00CCCCD, 0x40000000, 0x40000000, 0x40333333, 0x3F000000, 0x3F000000, 0xBFE66666, 0xBF4CCCCD, 0xC0333333, 0x3FE66666, 0x40200000, 0x404CCCCD, 0x3F19999A, 0x3ECCCCCD, 0xBFE66666, 0xBF4CCCCD, 0xC0333333, 0x3FE66666, 0x3FE66666, 0x40333333, 0x3F19999A, 0x3EB33333, 0xBFE66666, 0xBF4CCCCD, 0xC0333333, 0x3FE66666, 0x3FE66666, 0x40333333, 0x3F19999A, 0x3EB33333, 0xBFE66666, 0xBF4CCCCD, 0xC0333333, 0x3FE66666, 0x3FCCCCCD, 0x40333333, 0x3F000000, 0x3F000000, 0xBFE66666, 0xBF4CCCCD, 0xC02CCCCD, 0x3FE66666, 0x3FCCCCCD, 0x402CCCCD, 0x3F000000, 0x3F000000, 0xBFE66666, 0xBF4CCCCD, 0xC02CCCCD, 0x3FE66666, 0x3FCCCCCD, 0x40400000, 0x3F000000, 0x3EC28F5C, 0xBFE66666, 0xBF4CCCCD, 0xC02CCCCD, 0x3FE66666, 0x40133333, 0x40400000, 0x3F266666, 0x3EF5C28F, 0xBFE66666, 0xBF4CCCCD, 0xC02CCCCD, 0x3FE66666, 0x400CCCCD, 0x40400000, 0x3F000000, 0x3F000000, 0xBFE66666, 0xBF4CCCCD, 0xC02CCCCD, 0x3FE66666, 0x400CCCCD, 0x40400000, 0x3F19999A, 0x3ECCCCCD, 0xBFE66666, 0xBF4CCCCD, 0xC02CCCCD, 0x3FE66666, 0x40000000, 0x40400000, 0x3F000000, 0x3E0F5C29, 0xBFE66666, 0xBF4CCCCD, 0xC02CCCCD, 0x3FE66666, 0x3FE66666, 0x40400000, 0x3F19999A, 0x3F000000, 0xC0000000, 0xBF4CCCCD, 0xC02CCCCD, 0x40000000, 0x4019999A, 0x40400000, 0x3F000000, 0x3E4CCCCD, 0xC0000000, 0xBF4CCCCD, 0xC02CCCCD, 0x40000000, 0x40000000, 0x40400000, 0x3F000000, 0x3E99999A, 0xC0000000, 0xBF4CCCCD, 0xC02CCCCD, 0x40000000, 0x40000000, 0x402CCCCD, 0x3F000000, 0x3EB33333, 0xC0000000, 0xBF4CCCCD, 0xC02CCCCD, 0x40000000, 0x40000000, 0x402CCCCD, 0x3F000000, 0x3EB33333, 0xC0000000, 0xBF4CCCCD, 0xC02CCCCD, 0x40000000, 0x40000000, 0x402CCCCD, 0x3F000000, 0x3E99999A, 0xC0000000, 0xBF4CCCCD, 0xC02CCCCD, 0x40000000, 0x400CCCCD, 0x40400000, 0x3F19999A, 0x3E99999A, 0xC0133333, 0xBF4CCCCD, 0xC0533333, 0x40133333, 0x40333333, 0x40400000, 0x3F19999A, 0x3E99999A, 0xC0133333, 0xBF4CCCCD, 0xC0400000, 0x40133333, 0x40133333, 0x40400000, 0x3F000000, 0x3E19999A, 0xC0133333, 0xBF4CCCCD, 0xC0200000, 0x4019999A, 0x40133333, 0x40333333, 0x3F19999A, 0x3E4CCCCD, 0xBFF33333, 0xBF4CCCCD, 0xC0200000, 0x3FF33333, 0x40333333, 0x40533333, 0x3ECCCCCD, 0x3E19999A, 0xC0200000, 0xBF4CCCCD, 0xC039999A, 0x40200000, 0x40133333, 0x40533333, 0x3F000000, 0x3E4CCCCD, 0xC0200000, 0xBF4CCCCD, 0xC039999A, 0x40200000, 0x40133333, 0x40533333, 0x3F000000, 0x3E19999A, 0xBFCCCCCD, 0xBF4CCCCD, 0xBFE66666, 0x3FCCCCCD, 0x3FE66666, 0x40000000, 0x3F000000, 0x3E99999A, 0xC0000000, 0xBF4CCCCD, 0xC0200000, 0x40000000, 0x40000000, 0x40200000, 0x3F000000, 0x3EB33333, 0xC0000000, 0xBF4CCCCD, 0xC0133333, 0x40000000, 0x400CCCCD, 0x4019999A, 0x3F000000, 0x3F000000, 0xC0000000, 0xBF4CCCCD, 0xC0400000, 0x40000000, 0x400CCCCD, 0x404CCCCD, 0x3F000000, 0x3ECCCCCD, 0xC0000000, 0xBF4CCCCD, 0xC039999A, 0x40000000, 0x40200000, 0x40333333, 0x3F266666, 0x3E99999A, 0xC0200000, 0xBF4CCCCD, 0xC0400000, 0x40200000, 0x400CCCCD, 0x40333333, 0x3F000000, 0x3F000000, 0xBF4CCCCD, 0xBF800000, 0xC0000000, 0x3FF33333, 0x3F4CCCCD, 0x3F800000, 0x3F000000, 0x3F000000, 0xBFF33333, 0xBF800000, 0xC0000000, 0x3F4CCCCD, 0x3F4CCCCD, 0x3F800000, 0x3F000000, 0x3F000000, 0xBF000000, 0xBF4CCCCD, 0xBFE66666, 0x3F000000, 0x3FE66666, 0x3F666666, 0x3F000000, 0x3EAE147B, 0xC0133333, 0xBF333333, 0xC0000000, 0x40133333, 0x3FF33333, 0x3FC00000, 0x3F000000, 0x3ECCCCCD, 0xC0266666, 0xBF333333, 0xBFC00000, 0x40266666, 0x3FA66666, 0x40133333, 0x3F000000, 0x3F000000, 0xC0133333, 0xBF800000, 0xC0133333, 0x40133333, 0x40000000, 0x40133333, 0x3F000000, 0x3F000000, 0xBFB33333, 0xBF800000, 0xC0133333, 0x3FB33333, 0x3FC00000, 0x40266666, 0x3F000000, 0x3E99999A, 0xC0000000, 0xBF4CCCCD, 0xC0000000, 0x40000000, 0x3F99999A, 0x40266666, 0x3F000000, 0x3E99999A, 0xC0200000, 0xBF666666, 0xC00CCCCD, 0x40200000, 0x3FE66666, 0x40000000, 0x3F000000, 0x3E99999A, 0xC0066666, 0xBF8CCCCD, 0xBFB33333, 0x40066666, 0x40066666, 0x40200000, 0x3EE66666, 0x3F000000, 0xC0133333, 0xBF800000, 0xC0200000, 0x40133333, 0x40000000, 0x40200000, 0x3F000000, 0x3E99999A, 0xC0000000, 0xBF4CCCCD, 0xC0133333, 0x40000000, 0x3FC00000, 0x402CCCCD, 0x3F000000, 0x3E4CCCCD, 0xC0333333, 0xBF000000, 0xBFE66666, 0x40266666, 0x3FC00000, 0x3FE66666, 0x3F000000, 0x3DCCCCCD, 0xC0333333, 0xBF4CCCCD, 0xBFD9999A, 0x40333333, 0x3FD9999A, 0x40133333, 0x3F000000, 0x3E800000, 0xC0000000, 0xBF4CCCCD, 0xC0200000, 0x40000000, 0x3FC00000, 0x40200000, 0x3F000000, 0x3E4CCCCD, 0xC0000000, 0xBF4CCCCD, 0xBFE66666, 0x3FE66666, 0x3FE66666, 0x40133333, 0x3F000000, 0x3E800000, 0xC0200000, 0xBF333333, 0xC0133333, 0x40200000, 0x40000000, 0x40333333, 0x3F000000, 0x3E800000, 0xC019999A, 0xBF666666, 0xC0333333, 0x4019999A, 0x3FCCCCCD, 0x40333333, 0x3F000000, 0x3E4CCCCD, 0xBFC00000, 0xBF99999A, 0xC019999A, 0x3FC00000, 0x40200000, 0x4019999A, 0x3F000000, 0x3E4CCCCD, 0xBFF33333, 0xBF333333, 0xC0000000, 0x3FF33333, 0x400CCCCD, 0x40800000, 0x3F000000, 0x3E4CCCCD, 0xC0066666, 0xBF333333, 0xC0000000, 0x40066666, 0x3FE66666, 0x40400000, 0x3F000000, 0x3DCCCCCD, 0xBFD9999A, 0xBF000000, 0xC019999A, 0x3FD9999A, 0x40200000, 0x40400000, 0x3F000000, 0x3EB851EC, 0xC0000000, 0xBF4CCCCD, 0xBFC00000, 0x40000000, 0x3FF33333, 0x40333333, 0x3F000000, 0x3E19999A, 0xC0000000, 0xBF4CCCCD, 0xC0200000, 0x40000000, 0x3FF33333, 0x400CCCCD, 0x3F000000, 0x3E4CCCCD, 0xC019999A, 0xBF666666, 0xC019999A, 0x4019999A, 0x40000000, 0x4019999A, 0x3F000000, 0x3E4CCCCD, 0xC00CCCCD, 0xBF800000, 0xBFE66666, 0x400CCCCD, 0x40000000, 0x402CCCCD, 0x3F000000, 0x3E19999A, 0xC0466666, 0xBF333333, 0xC00CCCCD, 0x40466666, 0x40000000, 0x4079999A, 0x3F000000, 0x3E99999A, 0xC0466666, 0xBF19999A, 0xC0000000, 0x40466666, 0x40000000, 0x40266666, 0x3F000000, 0x3ECCCCCD, 0xBFA66666, 0xBF333333, 0xBFB33333, 0x3FA66666, 0x3FC00000, 0x3FB33333, 0x3F4CCCCD, 0x3C23D70A, 0xBFA66666, 0xBF333333, 0xBFC00000, 0x3FA66666, 0x3FA66666, 0x3FC00000, 0x3F000000, 0x3F000000, 0xBFB33333, 0xBF666666, 0xC0000000, 0x3FB33333, 0x3FC00000, 0x40200000, 0x3F000000, 0x3E4CCCCD, 0xBFB33333, 0xBF800000, 0xBFC00000, 0x3FB33333, 0x3FC00000, 0x3FC00000, 0x3F000000, 0x3E99999A, 0xBFC00000, 0xBF4CCCCD, 0xBFC00000, 0x3FC00000, 0x3FCCCCCD, 0x3FC00000, 0x3F000000, 0x3E99999A, 0xBFA66666, 0xBECCCCCD, 0xBFC00000, 0x3FA66666, 0x3FA66666, 0x3FCCCCCD, 0x3F000000, 0x3E99999A, 0xC0066666, 0xBF4CCCCD, 0xBFA66666, 0x40066666, 0x3F8CCCCD, 0x3FC00000, 0x3F19999A, 0x3ECCCCCD, 0xBFC00000, 0xBF800000, 0xBFCCCCCD, 0x3FC00000, 0x3FC00000, 0x3FCCCCCD, 0x3F000000, 0x3E99999A, 0xC02CCCCD, 0xBF666666, 0xBFE66666, 0x402CCCCD, 0x3FB33333, 0x3FCCCCCD, 0x3F000000, 0x3E4CCCCD, 0xC0000000, 0xBF4CCCCD, 0xBFCCCCCD, 0x40000000, 0x3FC00000, 0x3FCCCCCD, 0x3F000000, 0x3DCCCCCD, 0xC0000000, 0xBF4CCCCD, 0xBFCCCCCD, 0x40000000, 0x40000000, 0x400CCCCD, 0x3F000000, 0x3E800000, 0xC019999A, 0xBF4CCCCD, 0xBFCCCCCD, 0x4019999A, 0x3FB33333, 0x3FCCCCCD, 0x3F000000, 0x3EE66666, 0xBFD9999A, 0xBF666666, 0xBFD9999A, 0x3FD9999A, 0x3FCCCCCD, 0x40400000, 0x3F000000, 0x3E800000, 0xBFD9999A, 0xBF666666, 0xBFCCCCCD, 0x3FCCCCCD, 0x3FB33333, 0x3FCCCCCD, 0x3F000000, 0x3E800000, 0xBFB33333, 0xBF4CCCCD, 0xBFCCCCCD, 0x3FB33333, 0x3FB33333, 0x40000000, 0x3F000000, 0x3E4CCCCD, 0xBFB33333, 0xBF4CCCCD, 0xBFCCCCCD, 0x3FB33333, 0x3F99999A, 0x3FCCCCCD, 0x3F000000, 0x3E4CCCCD, 0xBFB33333, 0xBF4CCCCD, 0xBFCCCCCD, 0x3FB33333, 0x3F99999A, 0x3FCCCCCD, 0x3F000000, 0x3E4CCCCD, 0xBFF33333, 0xBF4CCCCD, 0xBFCCCCCD, 0x3FF33333, 0x3FB33333, 0x3FCCCCCD, 0x3F000000, 0x3E99999A, 0xBFD9999A, 0xBF4CCCCD, 0xBFCCCCCD, 0x3FD9999A, 0x3FB33333, 0x3FF33333, 0x3F000000, 0x3E800000, 0xBFF33333, 0xBF4CCCCD, 0xBFCCCCCD, 0x3FF33333, 0x3FCCCCCD, 0x3FCCCCCD, 0x3F000000, 0x3E99999A, 0xBFB33333, 0xBF4CCCCD, 0xBFCCCCCD, 0x3FB33333, 0x3FC00000, 0x3FCCCCCD, 0x3F000000, 0x3E4CCCCD, 0xBFB33333, 0xBF4CCCCD, 0xBFCCCCCD, 0x3FB33333, 0x40000000, 0x3FCCCCCD, 0x3F000000, 0x3E4CCCCD, 0xBFB33333, 0xBF4CCCCD, 0xBFCCCCCD, 0x3FB33333, 0x3FD9999A, 0x3FCCCCCD, 0x3F000000, 0x3E99999A, 0xBFCCCCCD, 0xBF4CCCCD, 0xBFCCCCCD, 0x3FCCCCCD, 0x3FD9999A, 0x3FCCCCCD, 0x3F000000, 0x3EAE147B, 0xBFC00000, 0xBF4CCCCD, 0xBFCCCCCD, 0x3FC00000, 0x3FD9999A, 0x3FCCCCCD, 0x3F000000, 0x3F000000, 0xBFE66666, 0xBF333333, 0xBFC00000, 0x3FE66666, 0x3F4CCCCD, 0x3F666666, 0x3F000000, 0x3EE66666, 0xBFA66666, 0xBF800000, 0xBF4CCCCD, 0x3FA66666, 0x3F99999A, 0x3F4CCCCD, 0x3F000000, 0x3EE66666, 0xBFB33333, 0xBF800000, 0xBFCCCCCD, 0x3FB33333, 0x3FC00000, 0x3F333333, 0x3F000000, 0x3E99999A, 0xBFB33333, 0xBFC00000, 0xBFCCCCCD, 0x3FB33333, 0x3FC00000, 0x3F19999A, 0x3F000000, 0x3ECCCCCD, 0xBF99999A, 0xBF666666, 0xBFC00000, 0x3F99999A, 0x3FC00000, 0x3F666666, 0x3F000000, 0x3E99999A, 0xBFA66666, 0xBF8CCCCD, 0xBFB33333, 0x3FA66666, 0x3F8CCCCD, 0x3F4CCCCD, 0x3F000000, 0x3E99999A, 0xBFC00000, 0xBF4CCCCD, 0xBFA66666, 0x3FC00000, 0x3F8CCCCD, 0x3FC00000, 0x3F19999A, 0x3ECCCCCD, 0xBFB33333, 0xBFA66666, 0xC019999A, 0x3FB33333, 0x3FA66666, 0x3F800000, 0x3F000000, 0x3E4CCCCD, 0xBFCCCCCD, 0xBFB33333, 0xBF4CCCCD, 0x3FCCCCCD, 0x3FCCCCCD, 0x3FC00000, 0x3F000000, 0x3E4CCCCD, 0xBFD9999A, 0xBF99999A, 0xBF99999A, 0x3FD9999A, 0x3F99999A, 0x3F4CCCCD, 0x3F000000, 0x3DCCCCCD, 0xC0066666, 0xBF4CCCCD, 0xC0000000, 0x40066666, 0x3FC00000, 0x3F4CCCCD, 0x3F000000, 0x3E800000, 0xBFE66666, 0xBF8CCCCD, 0xBFE66666, 0x3FE66666, 0x3FE66666, 0x3F666666, 0x3F000000, 0x3E99999A, 0xBFF33333, 0xBF8CCCCD, 0xBFD9999A, 0x3FF33333, 0x3F8CCCCD, 0x3F4CCCCD, 0x3F000000, 0x3EE66666, 0xC00CCCCD, 0xBFA66666, 0xBFE66666, 0x400CCCCD, 0x3F8CCCCD, 0x3F333333, 0x3F000000, 0x3E4CCCCD, 0xBF99999A, 0xBF4CCCCD, 0xC0200000, 0x3F99999A, 0x3FCCCCCD, 0x3F666666, 0x3F000000, 0x3E4CCCCD, 0xC00CCCCD, 0xBF99999A, 0xC0000000, 0x400CCCCD, 0x3F800000, 0x3F4CCCCD, 0x3F000000, 0x3E4CCCCD, 0xC00CCCCD, 0xBF99999A, 0xBFCCCCCD, 0x400CCCCD, 0x3F8CCCCD, 0x3F4CCCCD, 0x3F000000, 0x3E99999A, 0xC00CCCCD, 0xBF99999A, 0xBFCCCCCD, 0x400CCCCD, 0x3F8CCCCD, 0x3F4CCCCD, 0x3F000000, 0x3E99999A, 0xBFCCCCCD, 0xBFC00000, 0xC0000000, 0x3FCCCCCD, 0x3F8CCCCD, 0x3F4CCCCD, 0x3F000000, 0x3E800000, 0xBFCCCCCD, 0xBF8CCCCD, 0xBFF33333, 0x3FCCCCCD, 0x3F8CCCCD, 0x3F4CCCCD, 0x3F000000, 0x3E99999A, 0xC0000000, 0xBF8CCCCD, 0xBFC00000, 0x40000000, 0x3FB33333, 0x3F4CCCCD, 0x3F000000, 0x3E4CCCCD, 0xBFC00000, 0xBF99999A, 0xBFC00000, 0x3FC00000, 0x40066666, 0x3F4CCCCD, 0x3F000000, 0x3E4CCCCD, 0xBFCCCCCD, 0xBFB33333, 0xBFC00000, 0x3FCCCCCD, 0x3FA66666, 0x3F4CCCCD, 0x3F000000, 0x3E19999A, 0xBFF33333, 0xBF99999A, 0xC0000000, 0x3FF33333, 0x3F99999A, 0x3F800000, 0x3F000000, 0x3EAE147B, 0xBFF33333, 0xBF800000, 0xBFD9999A, 0x3FF33333, 0x3F800000, 0x3F333333, 0x4C6F6164, 0x696E6720, 0x456D626C, 0x656D2E2E, 0x2E000000, 0x83478393, 0x8375838C, 0x838082F0, 0x838D815B, 0x83689286, 0x82C582B7, 0x81420000, 0x53656C65, 0x63742061, 0x20506C61, 0x63652074, 0x6F205265, 0x67697374, 0x65722074, 0x68652045, 0x6D626C65, 0x6D2E2000, 0x83478393, 0x8375838C, 0x838082F0, 0x936F985E, 0x82B782E9, 0x8FEA8F8A, 0x82F09149, 0x91F082B5, 0x82C482AD, 0x82BE82B3, 0x82A28142, 0x00000000, 0x52656D6F, 0x76652045, 0x6D626C65, 0x6D3F0000, 0x83478393, 0x8375838C, 0x838082F0, 0x82CD82AA, 0x82B582DC, 0x82B782A9, 0x81480000, 0x53656C65, 0x63742050, 0x61727473, 0x2E200000, 0x8370815B, 0x836382F0, 0x914991F0, 0x82B582C4, 0x82AD82BE, 0x82B382A2, 0x81420000, 0x53656C65, 0x63742061, 0x6E20456D, 0x626C656D, 0x2E200000, 0x83478393, 0x8375838C, 0x838082F0, 0x914991F0, 0x82B582C4, 0x82AD82BE, 0x82B382A2, 0x81420000, 0x8FE38F91, 0x82AB8A6D, 0x94469286, 0x82C582B7, 0x81420000, 0x4170706C, 0x7920456D, 0x626C656D, 0x2E200000, 0x83478393, 0x8375838C, 0x838082F0, 0x935C82E8, 0x957482AF, 0x82DC82B7, 0x81420000, 0x436F6D70, 0x6C657469, 0x6E672070, 0x726F6365, 0x7373696E, 0x672E2E2E, 0x00000000, 0x8F4997B9, 0x8F88979D, 0x928682C5, 0x82B78142, 0x00000000, 0x436F6E66, 0x69726D69, 0x6E672073, 0x6176652E, 0x2E2E0000, 0x835A815B, 0x83758A6D, 0x94469286, 0x82C582B7, 0x81420000, (u32)lbl_3_data_2DCC__fzgx_offset_0, (u32)lbl_3_data_1A6C__fzgx_offset_0, (u32)lbl_3_data_1A6C__fzgx_offset_0, (u32)lbl_3_data_1A6C__fzgx_offset_0, (u32)lbl_3_data_1A6C__fzgx_offset_0, (u32)lbl_3_data_2DE0__fzgx_offset_0, (u32)lbl_3_data_2DFC__fzgx_offset_0, (u32)lbl_3_data_1A6C__fzgx_offset_0, (u32)lbl_3_data_1A6C__fzgx_offset_0, (u32)lbl_3_data_1A6C__fzgx_offset_0, (u32)lbl_3_data_1A6C__fzgx_offset_0, (u32)lbl_3_data_2E24__fzgx_offset_0, (u32)lbl_3_data_2E54__fzgx_offset_0, (u32)lbl_3_data_1A6C__fzgx_offset_0, (u32)lbl_3_data_1A6C__fzgx_offset_0, (u32)lbl_3_data_1A6C__fzgx_offset_0, (u32)lbl_3_data_1A6C__fzgx_offset_0, (u32)lbl_3_data_2E64__fzgx_offset_0, (u32)lbl_3_data_2E80__fzgx_offset_0, (u32)lbl_3_data_1A6C__fzgx_offset_0, (u32)lbl_3_data_1A6C__fzgx_offset_0, (u32)lbl_3_data_1A6C__fzgx_offset_0, (u32)lbl_3_data_1A6C__fzgx_offset_0, (u32)lbl_3_data_2E90__fzgx_offset_0, (u32)lbl_3_data_2EAC__fzgx_offset_0, (u32)lbl_3_data_1A6C__fzgx_offset_0, (u32)lbl_3_data_1A6C__fzgx_offset_0, (u32)lbl_3_data_1A6C__fzgx_offset_0, (u32)lbl_3_data_1A6C__fzgx_offset_0, (u32)lbl_3_data_2EC0__fzgx_offset_0, (u32)lbl_3_data_1A6C__fzgx_offset_0, (u32)lbl_3_data_1A6C__fzgx_offset_0, (u32)lbl_3_data_1A6C__fzgx_offset_0, (u32)lbl_3_data_1A6C__fzgx_offset_0, (u32)lbl_3_data_1A6C__fzgx_offset_0, (u32)lbl_3_data_2EE0__fzgx_offset_0, (u32)lbl_3_data_2EF4__fzgx_offset_0, (u32)lbl_3_data_1A6C__fzgx_offset_0, (u32)lbl_3_data_1A6C__fzgx_offset_0, (u32)lbl_3_data_1A6C__fzgx_offset_0, (u32)lbl_3_data_1A6C__fzgx_offset_0, (u32)lbl_3_data_2F04__fzgx_offset_0, (u32)lbl_3_data_1A6C__fzgx_offset_0, (u32)lbl_3_data_1A6C__fzgx_offset_0, (u32)lbl_3_data_1A6C__fzgx_offset_0, (u32)lbl_3_data_1A6C__fzgx_offset_0, (u32)lbl_3_data_1A6C__fzgx_offset_0, (u32)lbl_3_data_1A6C__fzgx_offset_0, (u32)lbl_3_data_2F20__fzgx_offset_0, (u32)lbl_3_data_1A6C__fzgx_offset_0, (u32)lbl_3_data_1A6C__fzgx_offset_0, (u32)lbl_3_data_1A6C__fzgx_offset_0, (u32)lbl_3_data_1A6C__fzgx_offset_0, (u32)lbl_3_data_2F3C__fzgx_offset_0, (u32)lbl_3_data_2F50__fzgx_offset_0, (u32)lbl_3_data_1A6C__fzgx_offset_0, (u32)lbl_3_data_1A6C__fzgx_offset_0, (u32)lbl_3_data_1A6C__fzgx_offset_0, (u32)lbl_3_data_1A6C__fzgx_offset_0, (u32)lbl_3_data_2F64__fzgx_offset_0, 0x83AD2052, 0x6F746174, 0x65204D61, 0x6368696E, 0x65000000, 0x83AD208E, 0xD45B82AD, 0x82E982DC, 0x5D82CC89, 0xF15B82A9, 0x82A25D93, 0x5D5B82C4, 0x82F15D00, 0x83A6204D, 0x6F766520, 0x43616D65, 0x72610000, 0x83A62083, 0x4A838183, 0x8982CC88, 0xDA5B82A2, 0x5D93AE5B, 0x82C782A4, 0x5D000000, 0x83A183AF, 0x205A6F6F, 0x6D000000, 0x83A183AF, 0x20835981, 0x5B838000, 0x83A42050, 0x72657669, 0x65770000, 0x83A42083, 0x76838C83, 0x72838581, 0x5B000000, 0x83B283B4, 0x20496E63, 0x72656173, 0x652F5265, 0x64756365, 0x20456D62, 0x6C656D20, 0x53697A65, 0x00000000, 0x83B283B4, 0x20834783, 0x93837583, 0x8C838082, 0xCC8A675B, 0x82A982AD, 0x5D91E55B, 0x82BE82A2, 0x5D81458F, 0x6B5B82B5, 0x82E382AD, 0x205D8FAC, 0x5B2082B5, 0x82E582A4, 0x5D000000, 0x839F2050, 0x61737465, 0x00000000, 0x839F2093, 0x5C5B82CD, 0x5D82E900, 0x839F2050, 0x65656C20, 0x6F666600, 0x839F2082, 0xCD82AA82, 0xB7000000, (u32)lbl_3_data_3068__fzgx_offset_0, (u32)lbl_3_data_1A6C__fzgx_offset_0, (u32)lbl_3_data_1A6C__fzgx_offset_0, (u32)lbl_3_data_1A6C__fzgx_offset_0, (u32)lbl_3_data_1A6C__fzgx_offset_0, (u32)lbl_3_data_307C__fzgx_offset_0, (u32)lbl_3_data_309C__fzgx_offset_0, (u32)lbl_3_data_1A6C__fzgx_offset_0, (u32)lbl_3_data_1A6C__fzgx_offset_0, (u32)lbl_3_data_1A6C__fzgx_offset_0, (u32)lbl_3_data_1A6C__fzgx_offset_0, (u32)lbl_3_data_30AC__fzgx_offset_0, (u32)lbl_3_data_30C8__fzgx_offset_0, (u32)lbl_3_data_1A6C__fzgx_offset_0, (u32)lbl_3_data_1A6C__fzgx_offset_0, (u32)lbl_3_data_1A6C__fzgx_offset_0, (u32)lbl_3_data_1A6C__fzgx_offset_0, (u32)lbl_3_data_30D4__fzgx_offset_0, (u32)lbl_3_data_30E0__fzgx_offset_0, (u32)lbl_3_data_1A6C__fzgx_offset_0, (u32)lbl_3_data_1A6C__fzgx_offset_0, (u32)lbl_3_data_1A6C__fzgx_offset_0, (u32)lbl_3_data_1A6C__fzgx_offset_0, (u32)lbl_3_data_30EC__fzgx_offset_0, (u32)lbl_3_data_30FC__fzgx_offset_0, (u32)lbl_3_data_1A6C__fzgx_offset_0, (u32)lbl_3_data_1A6C__fzgx_offset_0, (u32)lbl_3_data_1A6C__fzgx_offset_0, (u32)lbl_3_data_1A6C__fzgx_offset_0, (u32)lbl_3_data_3120__fzgx_offset_0, (u32)lbl_3_data_315C__fzgx_offset_0, (u32)lbl_3_data_1A6C__fzgx_offset_0, (u32)lbl_3_data_1A6C__fzgx_offset_0, (u32)lbl_3_data_1A6C__fzgx_offset_0, (u32)lbl_3_data_1A6C__fzgx_offset_0, (u32)lbl_3_data_3168__fzgx_offset_0, (u32)lbl_3_data_3174__fzgx_offset_0, (u32)lbl_3_data_1A6C__fzgx_offset_0, (u32)lbl_3_data_1A6C__fzgx_offset_0, (u32)lbl_3_data_1A6C__fzgx_offset_0, (u32)lbl_3_data_1A6C__fzgx_offset_0, (u32)lbl_3_data_3180__fzgx_offset_0, 0x00000000, (u32)lbl_3_data_1A6C__fzgx_offset_0, (u32)fn_3_F984__fzgx_offset_0, 0x00000001, (u32)lbl_3_data_1A6C__fzgx_offset_0, (u32)fn_3_FD30__fzgx_offset_0, 0x00000002, (u32)lbl_3_data_1A6C__fzgx_offset_0, (u32)fn_3_104C4__fzgx_offset_0, 0x00000003, (u32)lbl_3_data_1A6C__fzgx_offset_0, (u32)fn_3_10260__fzgx_offset_0, 0x00000004, (u32)lbl_3_data_1A6C__fzgx_offset_0, (u32)fn_3_106FC__fzgx_offset_0, 0x00000005, (u32)lbl_3_data_1A6C__fzgx_offset_0, (u32)fn_3_10B68__fzgx_offset_0, 0x00000006, (u32)lbl_3_data_1A6C__fzgx_offset_0, (u32)fn_3_10CB8__fzgx_offset_0, 0x00000007, (u32)lbl_3_data_1A6C__fzgx_offset_0, (u32)fn_3_118BC__fzgx_offset_0, 0x00000008, (u32)lbl_3_data_1A6C__fzgx_offset_0, (u32)fn_3_1180C__fzgx_offset_0, 0x00000009, (u32)lbl_3_data_1A6C__fzgx_offset_0, (u32)fn_3_113AC__fzgx_offset_0}; /* fzgx-allow: A1 measured retail data and symbolic pointer bindings */
static u32 fzgx_pool_native_lbl_3_data_1A40_fmt1[1] = {0x25730A00}; /* fzgx-allow: A1 measured retail data and symbolic pointer bindings */
static u32 fzgx_pool_native_lbl_3_data_1A40_on[3] = {0x2F626366, 0x66666666, 0x662F0000}; /* fzgx-allow: A1 measured retail data and symbolic pointer bindings */
static u32 fzgx_pool_native_lbl_3_data_1A40_off[3] = {0x2F626366, 0x66663230, 0x302F0000}; /* fzgx-allow: A1 measured retail data and symbolic pointer bindings */
static u32 fzgx_pool_native_lbl_3_data_1A40_fmt2[5] = {0x25732573, 0x25732020, 0x20202573, 0x25732573, 0x0A000000}; /* fzgx-allow: A1 measured retail data and symbolic pointer bindings */
#pragma section code_type ".fzgxpool"
void fzgx_fn_3_F044_pool0(volatile f32 *f, volatile f64 *d) { /* fzgx-allow: S2 preserve retail literal-pool order */
    f[0] = 50.0f; f[1] = 500.0f; f[2] = 31.2f; f[3] = 312.0f;
    f[4] = 68.0f; f[5] = 20.0f; f[6] = 96.0f; f[7] = 1.36f;
    f[8] = 161.0f; f[9] = 1.015625f; f[10] = 129.0f; f[11] = 15.0f;
    f[12] = 10.0f; f[13] = 0.0f; f[14] = 86.0f; f[15] = 0.5f;
    f[16] = 139.0f; f[17] = 75.0f; d[0] = 4503601774854144.0;
}
#pragma section code_type ".text"
const u32 fzgx_pool_table_50[3] = {0xffff0000, 0xffff0000, 0xffffff00};
/* Volatile sinks preserve the shared retail literal-pool order. */
#pragma section code_type ".fzgxpool"
void fzgx_pool_primer_1(volatile f32 *f, volatile f64 *d) { /* fzgx-allow: S2 preserve retail literal-pool order */
    f[0] = 185.000000f;
    f[1] = 180.000000f;
    f[2] = 276.000000f;
    f[3] = 116.000000f;
    f[4] = 7.00000000f;
    f[5] = 205.000000f;
    f[6] = 11.3999996f;
    f[7] = 40.0000000f;
    f[8] = 65536.0000f;
    f[9] = 60.0000000f;
    f[10] = 80.0000000f;
    f[11] = 274.000000f;
    f[12] = 0.583333313f;
    f[13] = 0.541666687f;
    f[14] = 0.458333343f;
}
#pragma section code_type ".text"
/* Volatile sinks preserve the shared retail literal-pool order. */
#pragma section code_type ".fzgxpool"
void fzgx_pool_primer_2(volatile f32 *f, volatile f64 *d) { /* fzgx-allow: S2 preserve retail literal-pool order */
    d[0] = 4503599627370496.0;
    f[2] = 320.000000f;
    f[3] = 240.000000f;
    f[4] = 5.00000000f;
    f[5] = 6.09999990f;
    f[6] = 0.800000012f;
    f[7] = 228.000000f;
    f[8] = 252.000000f;
    f[9] = 0.100000001f;
    f[10] = -30.0000000f;
    f[11] = 750.000000f;
    f[12] = 48.0000000f;
    f[13] = 660.000000f;
    f[14] = 44.0000000f;
    f[15] = 24.0000000f;
    f[16] = 302.000000f;
    f[17] = 70.0000000f;
    f[18] = 330.000000f;
    f[19] = 1.26999998f;
    f[20] = 390.000000f;
    f[21] = 308.000000f;
    f[22] = 1.00000000f;
    f[23] = 368.000000f;
    f[24] = 360.000000f;
    f[25] = 30.0000000f;
    f[26] = 0.400000006f;
    f[27] = 32768.0000f;
    f[28] = 0.906250000f;
    f[29] = 0.921875000f;
    f[30] = 0.937500000f;
}
#pragma section code_type ".text"
static const Vec pool_origin = {0.0f,0.0f,0.0f};
static const Rot pool_rot1 = {0,0,0};
static const Vec pool_a1 = {0.0f,5.0f,-15.0f};
static const Vec pool_b1 = {0.0f,2.5f,-15.0f};
static const Vec pool_a2 = {0.0f,5.0f,-15.0f};
static const Vec pool_b2 = {0.0f,2.5f,-15.0f};
static const Rot pool_rot2 = {0,0,0};
static const Vec pool_a3 = {0.0f,5.0f,-15.0f};
static const Vec pool_b3 = {0.0f,2.5f,-15.0f};
/* Volatile sinks preserve the shared retail literal-pool order. */
#pragma section code_type ".fzgxpool"
void fzgx_pool_primer_3(volatile f32 *f, volatile f64 *d) { /* fzgx-allow: S2 preserve retail literal-pool order */
    f[0] = 55.0000000f;
    f[1] = 90000.0000f;
    f[2] = 95.0000000f;
    f[3] = 17.0000000f;
}
#pragma section code_type ".text"

#pragma section code_type ".fzgxpool"
static void data_prime(void) {
    const void *volatile sink; /* fzgx-allow: S2 preserve native data base ordering */
    sink = &fzgx_pool_native_lbl_3_data_1A40_gap0;
    sink = &fzgx_pool_native_lbl_3_data_1A40_texts;
    sink = &fzgx_pool_native_lbl_3_data_1A40_gap4ac;
    sink = &fzgx_pool_native_lbl_3_data_1A40_fmt1;
    sink = &fzgx_pool_native_lbl_3_data_1A40_on;
    sink = &fzgx_pool_native_lbl_3_data_1A40_off;
    sink = &fzgx_pool_native_lbl_3_data_1A40_fmt2;
}
#pragma section code_type ".text"
#pragma section code_type ".fzgxpool"
static void bss_prime(void) {
    volatile u32 sink; /* fzgx-allow: S2 preserve native BSS first-use layout */
    sink = (u32)&fzgx_obj_lbl_3_bss_7EDC0;
    sink = (u32)&lbl_3_bss_7EDCC__fzgx_offset_0;
    sink = (u32)&lbl_3_bss_7EDCC__fzgx_offset_4;
    sink = (u32)&lbl_3_bss_7EDCC__fzgx_offset_8;
    sink = (u32)&fzgx_obj_lbl_3_bss_7EDD8;
    sink = (u32)&fzgx_obj_lbl_3_bss_7EE40;
    sink = (u32)&fzgx_obj_lbl_3_bss_87000;
    sink = (u32)&fzgx_obj_lbl_3_bss_87040;
    sink = (u32)&fzgx_obj_lbl_3_bss_8F200;
}
#pragma section code_type ".text"
#define MEM(T,p,o) (*(T *)((u8 *)(p) + (o)))
#define F(o) MEM(f32,pool,o)
#define STATE (&fzgx_obj_lbl_3_bss_7EDD8)
#define CAR lbl_3_bss_7EDCC__fzgx_offset_0
#define SRC ((u8 *)fzgx_obj_lbl_3_bss_87040)
#define CTX ((u8 *)&fzgx_obj_lbl_3_bss_8F200)

#define SLOT(i) ((u8 *)&lbl_3_bss_7EE40[i])
#define BIT(v,n) __rlwnm(v,n,31,31)

#pragma opt_propagation off
#define clamp_fade(x) ((x) < 0 ? 0.0f : (f32)(x) > 10.0f ? 10.0f : (f32)(x))
#pragma opt_dead_assignments off
void fn_3_E6F8(void) {
    Obj_3_bss_7EDD8 *state;
    Obj_3_bss_7EDD8 *state3;
    Obj_3_bss_7EDD8 *state2;
    u8 *slot_flags;
    u32 flags;
    s16 phase;
    s32 tick;
    s16 fade;
    Obj_3_bss_7EDD8 * state3_2;
    f32 upper, lower;
    const char *on, *off;
    s32 choice;
    FontDrawPacket packet1;
    FontDrawPacket packet2;
    Matrix44 projection;
    Matrix34 matrix;
    Cam camera;
    Vec a1, b1, a2, b2, a3, b3, origin;
    Rot rot, rot1, rot2, rot3, rot_default;
    void *second;
    void *first;
    C_MTXPerspective(&projection, 55.0f, fn_1_A6FE8(), 0.10000000149011612f, 90000.0f);
    fn_800737E4(&projection, 0);
    fn_3_F878();
    state = STATE;
    if ((BIT(state->unk_C, 7) && state->unk_24 <= -15) ||
        (BIT(STATE->unk_10, 8) && BIT(state->unk_C, 7))) {
        fn_1_FD844(SRC, CTX);
        MEM(Callback, CTX, 0x1042c) = fn_1_FD1D4;
    } else {
        u8 *src;
        u8 *source_base;
        s32 off;
        f32 x;
        source_base = SRC;
        src = (u8 *)STATE;
        off = src[0x15] * 0x2060;
        src = source_base + off;
        x = MEM(f32, src, 0x60);
        if (0.0f != x) {
            f32 y = MEM(f32, src, 0x64);
            if (0.0f != y) {
                src = (u8 *)&lbl_3_bss_7EE40 + off;
                MEM(f32,src,0x60) = x;
                MEM(f32,src,0x64) = y;
            }
        }
        fn_1_FD844(&lbl_3_bss_7EE40, CTX);
        MEM(Callback, CTX, 0x1042c) = fn_1_FD27C;
    }
    fn_1_133DBC(0);
    if (!(state->unk_C & 0x01000000)) {
        fn_1_134AD4();
        if (state->unk_C & 0x40000000) {
            flags = 0x28000000;
            if (fn_3_11930()) flags |= 0x100000;
            if (BIT(lbl_3_bss_7EE40[STATE->unk_15].flags,1)) flags |= 0x20000;
            fn_1_13ABA8(flags);
        } else if (state->unk_C & 0x02000000) {
            fn_1_13ABA8(0x20000000);
        } else if (state->unk_C & 0x08000000) {
            fn_1_13ABA8(0x28040000);
        } else {
            fn_1_13ABA8(0x28000000);
        }
        fn_1_138120(fn_3_11FD0(lbl_801A66B4, state->unk_C));
        packet1 = lbl_1_rodata_26F8;
        packet1.image = 0x890c;
        packet1.flags = 5;
        packet1.x = 95.0f;
        packet1.y = 17.0f;
        packet1.z = 10.0f;
        fn_1_4F734(&packet1);
    }
    state2 = STATE;
    if (state2->unk_24 <= -15 || (state->unk_C & 0x01000000) || (state->unk_C & 0x02000000)) {
        state3 = STATE;
        rot = pool_rot1;
        slot_flags = (u8 *)&lbl_3_bss_7EE40 + 0x24;
        if (BIT(MEM(u32,slot_flags,state3->unk_15 * 0x2060),1))
            rot.y = MEM(s16,SLOT(state3->unk_15),0x2a);
        camera_update_state(&lbl_3_bss_9F640);
        lbl_8006DCA4();
        mathutil_mtxA_rotate_x(STATE->unk_26);
        mathutil_mtxA_rotate_y(STATE->unk_28);
        fn_80072558();
        lbl_8006DB74(&matrix);
        if (BIT(state->unk_C,7)) {
            phase = state2->unk_24;
            if (phase <= -15 || (STATE->unk_10 & 0x01000000)) {
                s32 index = 0;
                CAR->field3ba = index;
                if (CAR->flags & 0x04000000) {
                    first = (void *)index;
                    second = (void *)index;
                    origin = pool_origin;
                    switch (STATE->unk_1C) {
                    case 0: fn_1_14DE80(CAR->model,&first,&second,0,1.0f); break;
                    case 1: fn_1_14E054(CAR->model,&origin,0,1.0f); break;
                    case 2: fn_1_14E198(CAR->model,&origin,0,1.0f); break;
                    }
                } else {
                    s16 mode = STATE->unk_1C;
                    if (mode == 0) fn_1_87238(CAR,0,1.0f);
                    else if (CAR->type == 4) {
                        fn_1_55210(CAR->slots[index].parts[mode]);
                    } else if (CAR->type == 0x28) {
                        fn_1_55210(((index)[CAR->slots]).parts[mode + 2]);
                    }
                }
                lbl_8006DBAC(&matrix);
                fn_80072558();
                fn_1_FCFA4(CTX);
                if (!BIT(MEM(u32,slot_flags,state3->unk_15 * 0x2060),1)) {
                    f32 zero = 0.0f;
                    f32 depth = 5.0f;
                    camera.eye.x = zero;
                    camera.eye.y = zero;
                    camera.eye.z = depth;
                    camera.target.x = zero;
                    camera.target.y = zero;
                    camera.target.z = zero;
                    camera.roll = 0;
                    camera_update_state(&camera);
                    fn_80072558();
                    fn_1_FD388(((state3->unk_15 * 0x2060) + ((0x20) + (SRC))), 5.0f / lbl_3_bss_9F640.eye.z);
                }
            } else {
                rot1 = rot;
                b1 = pool_b1;
                a1 = pool_a1;
                fn_3_2C73C(&lbl_3_bss_7EE40,CTX,&a1,&b1,&rot1,(f32)phase,10.0f);
            }
        } else {
            tick = state2->unk_24 - 15;
            if (tick >= 0 && !(state->unk_C & 0x02000000)) {
                rot2 = rot;
                b2 = pool_b2;
                a2 = pool_a2;
                fn_3_2C73C(&lbl_3_bss_7EE40,CTX,&a2,&b2,&rot2,(f32)tick,10.0f);
            } else {
                fn_3_E5D4(&lbl_3_bss_9F640);
                lbl_8006DBAC(&matrix);
                fn_80072558();
                fn_1_FCFA4(CTX);
            }
        }
    } else {
        rot_default = pool_rot2;
        lbl_8006DBAC(&matrix);
        fn_80072558();
        if (BIT(lbl_3_bss_7EE40[state2->unk_15].flags,1))
            rot_default.y = lbl_3_bss_7EE40[state2->unk_15].rotation;
        rot3 = rot_default;
        b3 = pool_b3;
        a3 = pool_a3;
        fn_3_2C73C(&lbl_3_bss_7EE40,CTX,&a3,&b3,&rot3,(f32)state2->unk_24,10.0f);
    }
    if (!(state->unk_C & 0x80000000)) {
        u8 *slots;
        s32 selected_offset;
        fn_3_C400();
        tick = STATE->unk_46 * 0x81c0;
        selected_offset = tick;
        slots = (u8 *)fzgx_obj_lbl_3_bss_7EDC0.unk_0;
        if (MEM(u32,slots,selected_offset) & 0x40000000) fn_3_CE94((s16)lbl_801A66B4);
        else if (*(u8 *)((u32)slots + 0x10000 + selected_offset - 0x7e60) == 4 || *(u8 *)((u32)slots + 0x10000 + selected_offset - 0x7e60) == 0x28) fn_3_CE94((s16)lbl_801A66B4);
        fn_3_D9A0();
        fn_3_F044();
        state3_2 = STATE;
        fade = state3_2->unk_22;
        if (fade > 0) {
            packet2 = lbl_1_rodata_26F8;
            packet2.image = 12;
            packet2.x = 320.0f;
            packet2.y = 240.0f;
            packet2.z = 5.0f;
            packet2.flags = 10;
            fn_1_50A90(&packet2,7,7,(s32)(31.200000762939453f*clamp_fade(fade)),(s32)(6.099999904632568f*clamp_fade(fade)));
            if (state3_2->unk_22 == 10) {
                fn_1_4955C(0.800000011920929f,0.800000011920929f);
                fn_1_495C8(9);
                fn_1_496FC(320.0f,228.0f);
                fn_1_4AE0C((char *)fzgx_pool_native_lbl_3_data_1A40_fmt1,fn_3_11FD0(lbl_801A66B4,0x20000000));
                fn_1_496FC(320.0f,252.0f);
                fn_1_495C8(9);
                fn_1_4954C(0.10000000149011612f);
                choice = STATE->unk_18;
                off = (char *)fzgx_pool_native_lbl_3_data_1A40_off;
                if (choice) off = (char *)fzgx_pool_native_lbl_3_data_1A40_on;
                on = (char *)fzgx_pool_native_lbl_3_data_1A40_on;
                if (choice) on = (char *)fzgx_pool_native_lbl_3_data_1A40_off;
                fn_1_4AE0C((char *)fzgx_pool_native_lbl_3_data_1A40_fmt2,on,(char *)fzgx_pool_native_lbl_3_data_1A40_texts.second[lbl_801A66B4],(char *)fzgx_pool_native_lbl_3_data_1A40_on,off,(char *)fzgx_pool_native_lbl_3_data_1A40_texts.first[lbl_801A66B4],(char *)fzgx_pool_native_lbl_3_data_1A40_on);
            }
        }
    }
}
#pragma opt_dead_assignments reset
/* fzgx:end fn_3_E6F8 */

/* fzgx:begin fn_3_F044 */
#include "font.h"

extern u32 lbl_3_bss_7ED58[18];
extern u32 lbl_801A6410;
extern u32 lbl_3_data_1A18;
extern u8 fn_1_B7C00(void);
extern void fn_1_46B4(u32 arg0, u32 arg1, char *arg2, u32 arg3);
extern u32 lbl_3_rodata_288[60];
extern void lbl_8006DCA4(void);
extern void lbl_8006E1D8(struct Vec3 *, f32, f32, f32);
extern void fn_1_7BCCC(struct Vec3 *);
extern void fn_80035680(struct GXLightObj *, f32, f32, f32);
extern void fn_80035690(struct GXLightObj *, f32, f32, f32);
extern void fn_80035420(struct GXLightObj *, f32, int);
extern void fn_800356AC(struct GXLightObj *, u32 *);
extern void GXInitLightDistAttn(struct GXLightObj *, f32, f32, int);
extern void fn_1_7BB80(struct GXLightObj *, int);
extern void fn_1_7BD6C(int);
extern void fn_80074CF4(f32, f32, f32);

struct fn_3_F044_Copy88 { u32 a[22]; };
struct fn_3_F044_Packet {
    u32 id;
    f32 x, y, z;
    f32 sx, sy;
    u8 pad_18[0x18];
    u32 flags;
    u8 pad_34[0x24];
};
extern u32 lbl_1_rodata_26F8;

extern s32 lbl_801A66B4;
extern u32 fn_1_50A90(void *, u32, u32, u32, u32);
extern int fn_1_4F734(FontDrawPacket *);
extern s32 fn_1_4FC50(void *, u32, u16, u16, void *);
extern void fn_1_51678(FontDrawPacket *, u32, s16, s16, s16, s16);
extern void fn_1_4954C(f32);
extern void fn_1_495C8(u8);
extern void fn_1_495B0(u32);
extern void fn_1_49590(f32);
extern void fn_1_4955C(f32, f32);
extern void fn_1_496FC(f32, f32);
#define F(off) ((off) == 0x14 ? 20.0f : (off) == 0x3c ? 0.5f : (off) == 0xf8 ? 360.0f : (off) == 0xfc ? 30.0f : (off) == 0x108 ? 0.90625f : (off) == 0x110 ? 0.9375f : (off) == 0x188 ? 354.0f : (off) == 0x18c ? 310.0f : (off) == 0x190 ? 365.0f : (off) == 0x194 ? 143.0f : (off) == 0x198 ? 19.2999f : (off) == 0x19c ? 0.01f : (off) == 0x1a0 ? 0.75f : (off) == 0x1a4 ? 351.0f : (off) == 0x1a8 ? 387.0f : (off) == 0x1ac ? 0.6f : (off) == 0x1b0 ? 0.7f : (off) == 0x1b4 ? 348.0f : 384.0f)
#define COPY() (*(struct fn_3_F044_Copy88 *)&packet = *(struct fn_3_F044_Copy88 *)&lbl_1_rodata_26F8)
struct fn_3_F044_TextEntry {
    const char *t0;
    u8 pad4[20]; const char *t0x18;
    u8 pad1c[20]; const char *t0x30;
    u8 pad34[20]; const char *t0x48;
    u8 pad4c[20]; const char *t0x60;
    u8 pad64[20]; const char *t0x78;
    u8 pad7c[20]; const char *t0x90;
};
#define TEXT(off) ((const char *)(&lbl_3_data_318C.unk_0)[lbl_801A66B4 + (off) / 4])
static inline Obj_3_bss_7EE40 *fn_3_F044_slot(u32 index) {
    u32 slot;
    slot = (u32)&lbl_3_bss_7EE40;
    slot += index * 0x2060;
    return (Obj_3_bss_7EE40 *)slot;
}
#define SLOT() fn_3_F044_slot(lbl_3_bss_7EDD8.unk_15)

#pragma section code_type ".fzgxpool"
void fzgx_fn_3_F044_pool0(volatile f32 *f, volatile f64 *d) { /* volatile: sinks keep the retail literal-pool order */
    f[0] = 50.0f; f[1] = 500.0f; f[2] = 31.2f; f[3] = 312.0f;
    f[4] = 68.0f; f[5] = 20.0f; f[6] = 96.0f; f[7] = 1.36f;
    f[8] = 161.0f; f[9] = 1.015625f; f[10] = 129.0f; f[11] = 15.0f;
    f[12] = 10.0f; f[13] = 0.0f; f[14] = 86.0f; f[15] = 0.5f;
    f[16] = 139.0f; f[17] = 75.0f; d[0] = 4503601774854144.0;
}
#pragma section code_type ".text"
const u32 fzgx_pool_table_50[3] = {0xffff0000, 0xffff0000, 0xffffff00};
/* Volatile sinks preserve the shared retail literal-pool order. */
#pragma section code_type ".fzgxpool"
void fzgx_pool_primer_1(volatile f32 *f, volatile f64 *d) { /* volatile: sinks keep the retail literal-pool order */
    f[0] = 185.000000f;
    f[1] = 180.000000f;
    f[2] = 276.000000f;
    f[3] = 116.000000f;
    f[4] = 7.00000000f;
    f[5] = 205.000000f;
    f[6] = 11.3999996f;
    f[7] = 40.0000000f;
    f[8] = 65536.0000f;
    f[9] = 60.0000000f;
    f[10] = 80.0000000f;
    f[11] = 274.000000f;
    f[12] = 0.583333313f;
    f[13] = 0.541666687f;
    f[14] = 0.458333343f;
}
#pragma section code_type ".text"
/* Volatile sinks preserve the shared retail literal-pool order. */
#pragma section code_type ".fzgxpool"
void fzgx_pool_primer_2(volatile f32 *f, volatile f64 *d) { /* volatile: sinks keep the retail literal-pool order */
    d[0] = 4503599627370496.0;
    f[2] = 320.000000f;
    f[3] = 240.000000f;
    f[4] = 5.00000000f;
    f[5] = 6.09999990f;
    f[6] = 0.800000012f;
    f[7] = 228.000000f;
    f[8] = 252.000000f;
    f[9] = 0.100000001f;
    f[10] = -30.0000000f;
    f[11] = 750.000000f;
    f[12] = 48.0000000f;
    f[13] = 660.000000f;
    f[14] = 44.0000000f;
    f[15] = 24.0000000f;
    f[16] = 302.000000f;
    f[17] = 70.0000000f;
    f[18] = 330.000000f;
    f[19] = 1.26999998f;
    f[20] = 390.000000f;
    f[21] = 308.000000f;
    f[22] = 1.00000000f;
    f[23] = 368.000000f;
    f[24] = 360.000000f;
    f[25] = 30.0000000f;
    f[26] = 0.400000006f;
    f[27] = 32768.0000f;
    f[28] = 0.906250000f;
    f[29] = 0.921875000f;
    f[30] = 0.937500000f;
}
#pragma section code_type ".text"
const u32 fzgx_pool_table_114[25] = {0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x40a00000, 0xc1700000, 0x0, 0x40200000, 0xc1700000, 0x0, 0x40a00000, 0xc1700000, 0x0, 0x40200000, 0xc1700000, 0x0, 0x0, 0x0, 0x40a00000, 0xc1700000, 0x0, 0x40200000, 0xc1700000};  /* fzgx-allow: A1 retail pool bytes */
/* Volatile sinks preserve the shared retail literal-pool order. */
#pragma section code_type ".fzgxpool"
void fzgx_pool_primer_3(volatile f32 *f, volatile f64 *d) { /* volatile: sinks keep the retail literal-pool order */
    f[0] = 55.0000000f;
    f[1] = 90000.0000f;
    f[2] = 95.0000000f;
    f[3] = 17.0000000f;
    f[4] = 354.000000f;
    f[5] = 310.000000f;
    f[6] = 365.000000f;
    f[7] = 143.000000f;
    f[8] = 19.2999001f;
    f[9] = 0.00999999978f;
    f[10] = 0.750000000f;
    f[11] = 351.000000f;
    f[12] = 387.000000f;
    f[13] = 0.600000024f;
    f[14] = 0.699999988f;
    f[15] = 348.000000f;
    f[16] = 384.000000f;
}
#pragma section code_type ".text"
#pragma opt_pointer_analysis on
void fn_3_F044(void) {
    u8 *p_lbl_3_rodata_288;
    s16 v0;
    s32 v1;
    s32 v3;
    s16 v2;
    u32 v4;
    struct fn_3_F044_Packet packet;
    p_lbl_3_rodata_288 = (u8 *)&lbl_3_rodata_288;
    v0 = lbl_3_bss_7EDD8.unk_24;
    if (v0 < -15) {
        v1 = -15;
    } else {
        v1 = v0 > 0 ? 0 : v0;
    }
    v2 = (s16)(-(v1 * 62 + 930));
    COPY();
    v3 = v2 + 82;
    packet.id = 0x8927;
    packet.x = v3;
    packet.y = F(0x188);
    packet.z = F(0xfc);
    packet.flags = 10;
    fn_1_50A90(&packet, 7, 0, 104, 104);
    v4 = lbl_3_bss_7EDD8.unk_3C;
    if (v4 < 3) {
        COPY();
        if (v4 == 0) packet.id = 0x891c;
        else if (v4 == 1) packet.id = 0x891d;
        else if (v4 == 2) packet.id = 0x891b;
        packet.x = v2 + 38;
        packet.y = F(0x18c);
        packet.z = F(0x14);
        packet.flags = 5;
        fn_1_4F734((FontDrawPacket *)&packet);
    }
    if (lbl_3_bss_7EDD8.unk_C & 0x03000000) {
        COPY();
        packet.x = v3;
        packet.y = F(0xf8);
        packet.z = F(0x14);
        packet.flags = 10;
        packet.sx = F(0x108);
        packet.sy = F(0x110);
        fn_1_4FC50(&packet, 5, 64, 64, lbl_3_bss_87040 + lbl_3_bss_7EDD8.unk_15 * 0x2060 + 0x80);
    }
    COPY();
    packet.id = 12;
    packet.x = v2 + 375;
    packet.y = F(0x190);
    packet.z = F(0xfc);
    packet.flags = 10;
    fn_1_50A90(&packet, 7, 7, 468, 74);
    COPY();
    packet.id = 12;
    packet.x = F(0x194) + (f32)v2;
    packet.y = F(0x190);
    packet.z = F(0x14);
    fn_1_51678((FontDrawPacket *)&packet, 12, 7, 22, 2, 2);
    packet.sx = F(0x198);
    packet.flags = 5;
    fn_1_4F734((FontDrawPacket *)&packet);
    if (lbl_801A66B4 == 5) {
        fn_1_4AEC0(1);
        fn_1_4954C(F(0x19c));
        fn_1_495C8(8);
        fn_1_495B0(0x80000000);
        fn_1_49590(F(0x3c));
        fn_1_4955C(F(0x1a0), F(0x1a0));
        fn_1_496FC(v2 + 178, F(0x1a4));
        fn_1_4A0D8(TEXT(0));
        fn_1_496FC(v2 + 312, F(0x1a4));
        fn_1_4A0D8(TEXT(0x18));
        fn_1_496FC(v2 + 492, F(0x1a8));
        fn_1_4A0D8(TEXT(0x30));
        fn_1_496FC(v2 + 362, F(0x1a8));
        fn_1_4A0D8(TEXT(0x48));
        fn_1_496FC(v2 + 158, F(0x1a8));
        fn_1_4955C(F(0x1ac), F(0x1b0));
        fn_1_4A0D8(TEXT(0x60));
        fn_1_496FC(v2 + 481, F(0x1a4));
        fn_1_4955C(F(0x1a0), F(0x1a0));
        if (SLOT()->unk_24 & 0x80000000)
            fn_1_4A0D8(TEXT(0x90));
        else
            fn_1_4A0D8(TEXT(0x78));
        fn_1_4AEC0(0);
    } else {
        fn_1_4954C(F(0x19c));
        fn_1_495C8(8);
        fn_1_495B0(0x80000000);
        fn_1_49590(F(0x3c));
        fn_1_4955C(F(0x1ac), F(0x1ac));
        fn_1_496FC(v2 + 163, F(0x1b4));
        fn_1_4A0D8(TEXT(0));
        fn_1_496FC(v2 + 340, F(0x1b4));
        fn_1_4A0D8(TEXT(0x18));
        fn_1_496FC(v2 + 521, F(0x1b8));
        fn_1_4A0D8(TEXT(0x30));
        fn_1_496FC(v2 + 432, F(0x1b8));
        fn_1_4A0D8(TEXT(0x48));
        fn_1_496FC(v2 + 150, F(0x1b8));
        fn_1_4A0D8(TEXT(0x60));
        fn_1_496FC(v2 + 500, F(0x1b4));
        if (SLOT()->unk_24 & 0x80000000)
            fn_1_4A0D8(TEXT(0x90));
        else
            fn_1_4A0D8(TEXT(0x78));
    }
}
/* fzgx:end fn_3_F044 */

/* fzgx:begin fn_3_F878 */
struct Vec3 {
    f32 x;
    f32 y;
    f32 z;
};

struct GXLightObj {
    u32 dummy[16];
};

struct CustomizeData {
    u8 pad34[0x34];
    f32 value34;
    u8 pad1ac[0x174];
    f32 value1ac;
    u8 pad1bc[0xc];
    u32 value1bc;
    f32 value1c0;
};

void fn_3_F878(void) {
    struct GXLightObj second;
    struct Vec3 first;
    u32 value;
    f32 scale;
    struct CustomizeData *data;

    data = (struct CustomizeData *)lbl_3_rodata_288;
    lbl_8006DCA4();
    scale = data->value1c0;
    lbl_8006E1D8(&first, scale, scale, scale);
    fn_1_7BCCC(&first);
    fn_80035680(&second, first.x, first.y, first.z);
    fn_80035690(&second, first.x, first.y, first.z);
    fn_80035420(&second, data->value34, 0);
    value = data->value1bc;
    fn_800356AC(&second, &value);
    GXInitLightDistAttn(&second, data->value34, data->value34, 0);
    fn_1_7BB80(&second, 1);
    fn_1_7BD6C(1);
    scale = data->value1ac;
    fn_80074CF4(scale, scale, scale);
}
/* fzgx:end fn_3_F878 */

/* fzgx:begin fn_3_F948 */
typedef struct MemCardSlot {
    u32 unk0;
    u32 flags;
    u8 pad[0x2058];
} MemCardSlot;

s16 fn_3_F948(MemCardSlot *slot) {
    s16 i;
    s16 count = 0;
    i = 0;

    while (i < 4) {
        if (slot->flags & (1u << 31)) {
            count++;
        }
        slot++;
        i++;
    }
    return count;
}
/* fzgx:end fn_3_F948 */
