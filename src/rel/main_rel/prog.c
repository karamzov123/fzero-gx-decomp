#include "types.h"
#include "rel/main_rel/globals.h"
#include "rel/main_rel/prog.h"

extern u32 lbl_1_bss_6F5F4;
extern void fn_1_4A00(s32, s32, u32);
extern s8 fn_1_A5DC4(void);
extern const f32 lbl_1_rodata_49F8;
extern f32 lbl_1_rodata_49FC[11];
extern f32 fn_1_A6FE8(void);
extern void fn_1_A714C(f32 *, f32 *, f32 *, f32 *);
extern u32 lbl_1_bss_6F5F0;

/* fzgx:begin fn_1_A6870 */
typedef enum {
    Sig_GXAdjustForOverscan_VI_TVMODE_NTSC_INT = ((((0)) << 2) + ((0))),
    Sig_GXAdjustForOverscan_VI_TVMODE_NTSC_DS = ((((0)) << 2) + ((1))),
    Sig_GXAdjustForOverscan_VI_TVMODE_NTSC_PROG = ((((0)) << 2) + ((2))),
    Sig_GXAdjustForOverscan_VI_TVMODE_NTSC_3D = ((((0)) << 2) + ((3))),
    Sig_GXAdjustForOverscan_VI_TVMODE_PAL_INT = ((((1)) << 2) + ((0))),
    Sig_GXAdjustForOverscan_VI_TVMODE_PAL_DS = ((((1)) << 2) + ((1))),
    Sig_GXAdjustForOverscan_VI_TVMODE_MPAL_INT = ((((2)) << 2) + ((0))),
    Sig_GXAdjustForOverscan_VI_TVMODE_MPAL_DS = ((((2)) << 2) + ((1))),
    Sig_GXAdjustForOverscan_VI_TVMODE_DEBUG_INT = ((((3)) << 2) + ((0))),
    Sig_GXAdjustForOverscan_VI_TVMODE_DEBUG_PAL_INT = ((((4)) << 2) + ((0))),
    Sig_GXAdjustForOverscan_VI_TVMODE_DEBUG_PAL_DS = ((((4)) << 2) + ((1))),
    Sig_GXAdjustForOverscan_VI_TVMODE_EURGB60_INT = ((((5)) << 2) + ((0))),
    Sig_GXAdjustForOverscan_VI_TVMODE_EURGB60_DS = ((((5)) << 2) + ((1))),
    Sig_GXAdjustForOverscan_VI_TVMODE_GCA_INT = ((((6)) << 2) + ((0))),
    Sig_GXAdjustForOverscan_VI_TVMODE_GCA_DS = ((((6)) << 2) + ((1))),
    Sig_GXAdjustForOverscan_VI_TVMODE_GCA_PROG = ((((6)) << 2) + ((2))),
} Sig_GXAdjustForOverscan_VITVMode;
typedef enum {
    Sig_GXAdjustForOverscan_VI_XFBMODE_SF = 0,
    Sig_GXAdjustForOverscan_VI_XFBMODE_DF = 1,
} Sig_GXAdjustForOverscan_VIXFBMode;
typedef struct Sig_GXAdjustForOverscan__GXRenderModeObj {
    Sig_GXAdjustForOverscan_VITVMode viTVmode;
    u16 fbWidth;
    u16 efbHeight;
    u16 xfbHeight;
    u16 viXOrigin;
    u16 viYOrigin;
    u16 viWidth;
    u16 viHeight;
    Sig_GXAdjustForOverscan_VIXFBMode xFBmode;
    u8 field_rendering;
    u8 aa;
    u8 sample_pattern[12][2];
    u8 vfilter[7];
} Sig_GXAdjustForOverscan_GXRenderModeObj;
typedef u8 Sig_fn_80035110_GXBool;
typedef u8 Sig_fn_80034ECC_GXBool;

extern Sig_GXAdjustForOverscan_GXRenderModeObj *lbl_801A6CF4;
extern Sig_GXAdjustForOverscan_GXRenderModeObj lbl_8012B030;
extern Sig_GXAdjustForOverscan_GXRenderModeObj lbl_8012AFB8;
extern Sig_GXAdjustForOverscan_GXRenderModeObj lbl_8012B0A8;
extern Sig_GXAdjustForOverscan_GXRenderModeObj lbl_8012B06C;
extern Sig_GXAdjustForOverscan_GXRenderModeObj lbl_8019E150;

struct fn_1_A6870_lbl_801A6D30_obj {
    u32 unk_0;
    u32 unk_4;
    u32 unk_8;
};
struct fn_1_A6870_lbl_801A6D30 {
    struct fn_1_A6870_lbl_801A6D30_obj *unk_0;
};
extern struct fn_1_A6870_lbl_801A6D30 lbl_801A6D30;

extern const f32 lbl_1_rodata_49D8;
extern const f32 lbl_1_rodata_49DC;
extern const f64 lbl_1_rodata_49E0;

extern void fn_1_54DCC(u8 *);
extern void fn_1_549F4(void *, void *, f32, f32, f32, f32);
extern void fn_1_A7024(f32, f32, f32, f32);
extern u32 VIGetTvFormat(void);
extern u32 OSGetProgressiveMode(void);
extern void OSPanic(const char *, int, const char *, ...);
extern void GXAdjustForOverscan(Sig_GXAdjustForOverscan_GXRenderModeObj *, Sig_GXAdjustForOverscan_GXRenderModeObj *, u16, u16);
extern s32 VIConfigure(u32);
extern void VIWaitForRetrace(void);
extern void VIFlush(void);
extern void fn_8007423C(u32, u32, u32, u32);
extern void fn_800743C4(s32, u32);
extern void fn_80035110(void *, Sig_fn_80035110_GXBool);
extern u32 fn_80038EEC(f32, f32, f32, f32, f32, f32);
extern void fn_80074188(u32, u32, u32, u32);
extern void fn_80034ECC(Sig_fn_80034ECC_GXBool, void *, Sig_fn_80034ECC_GXBool, void *);
extern u32 lbl_1_data_3431C;
extern u8 lbl_1_data_34324[0x20];
extern u8 lbl_801A66B0[];

void fn_1_A6870(u32 *arg0) {
    Sig_GXAdjustForOverscan_GXRenderModeObj *rmode;
    s32 tv;
    s8 flag;
    struct {
        u8 unk_0[0x6c];
        f32 unk_6c[6];
    } loc_18;
    f32 loc_14;
    f32 loc_10;
    f32 loc_C;
    f32 loc_8;

    switch (VIGetTvFormat()) {
    case 0:
        if (OSGetProgressiveMode() != 0) {
            *lbl_801A6CF4 = lbl_8012B030;
        } else {
            *lbl_801A6CF4 = lbl_8012AFB8;
        }
        break;
    case 1:
        *lbl_801A6CF4 = lbl_8012B0A8;
        break;
    case 2:
        *lbl_801A6CF4 = lbl_8012B06C;
        break;
    default:
        OSPanic((const char *)&lbl_1_data_3431C, 557, (const char *)&lbl_1_data_34324);
        break;
    }

    switch (*arg0) {
    case 0:
        GXAdjustForOverscan(lbl_801A6CF4, &lbl_8019E150, 0, 16);
        lbl_801A6CF4 = &lbl_8019E150;
        VIConfigure((u32)&lbl_8019E150);
        VIWaitForRetrace();
        VIWaitForRetrace();
        VIFlush();
        *arg0 = 0;
        break;
    case 1:
        GXAdjustForOverscan(lbl_801A6CF4, &lbl_8019E150, 0, 16);
        lbl_801A6CF4 = &lbl_8019E150;
        VIConfigure((u32)&lbl_8019E150);
        VIWaitForRetrace();
        VIWaitForRetrace();
        VIFlush();
        *arg0 = 1;
        break;
    case 2:
        lbl_801A6CF4->xfbHeight = 360;
        lbl_801A6CF4->viHeight = 360;
        lbl_801A6CF4->viXOrigin = 40;
        lbl_801A6CF4->viYOrigin = 60;
        GXAdjustForOverscan(lbl_801A6CF4, &lbl_8019E150, 0, 12);
        lbl_801A6CF4 = &lbl_8019E150;
        VIConfigure((u32)&lbl_8019E150);
        VIWaitForRetrace();
        VIWaitForRetrace();
        VIFlush();
        *arg0 = 2;
        break;
    case 3:
        GXAdjustForOverscan(lbl_801A6CF4, &lbl_8019E150, 0, 0);
        lbl_801A6CF4 = &lbl_8019E150;
        VIConfigure((u32)&lbl_8019E150);
        VIWaitForRetrace();
        VIWaitForRetrace();
        VIFlush();
        *arg0 = 3;
        break;
    }

    fn_8007423C(0, 0, lbl_801A6CF4->fbWidth, lbl_801A6CF4->efbHeight);
    fn_800743C4(lbl_801A6CF4->fbWidth, lbl_801A6CF4->xfbHeight);
    fn_80035110((void *)lbl_801A6D30.unk_0->unk_4, 1);
    fn_80035110((void *)lbl_801A6D30.unk_0->unk_8, 0);
    fn_80035110((void *)lbl_801A6D30.unk_0->unk_4, 0);

    fn_1_54DCC(loc_18.unk_0);
    fn_1_549F4(loc_18.unk_0, loc_18.unk_6c, loc_18.unk_6c[2], fn_1_A6FE8(), loc_18.unk_6c[4], loc_18.unk_6c[5]);
    fn_1_A714C(&loc_14, &loc_10, &loc_C, &loc_8);
    fn_1_A7024(loc_14, fn_1_A6FE8(), loc_C, loc_8);

    rmode = lbl_801A6CF4;
    fn_80038EEC(0.0f, 0.0f, (f32)rmode->fbWidth, (f32)rmode->efbHeight, 0.0f, 1.0f);
    fn_80074188(0, 0, lbl_801A6CF4->fbWidth, lbl_801A6CF4->efbHeight);
    fn_80034ECC(lbl_801A6CF4->aa, lbl_801A6CF4->sample_pattern, 1, lbl_801A6CF4->vfilter);

    tv = lbl_1_bss_6F5F0;
    if (tv == 1 || tv == 2) {
        flag = 1;
    } else {
        flag = 0;
    }
    if (flag) {
        lbl_801A66B0[3] = 1;
    } else {
        lbl_801A66B0[3] = 0;
    }
}
/* fzgx:end fn_1_A6870 */

/* fzgx:begin fn_1_A6E68 */
#pragma section code_type ".fzgxpool"
static const u32 fzgx_pool_table1[61] = {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0xFFFFFF00};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep1(void) { const u32 *volatile cp; cp = fzgx_pool_table1; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime2(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 0.10000000149011612f;
    s = 320.0f;
    s = 184.0f;
    s = 221.0f;
    s = 256.0f;
    s = 258.0f;
    s = 384.0f;
    s = 0.0f;
    s = 1.0f;
    d = 4503599627370496.0;
}
static const u32 fzgx_pool_table3[1] = {0xFF0000FF};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep3(void) { const u32 *volatile cp; cp = fzgx_pool_table3; }  /* fzgx-allow: S2 pool primer sink */
static const u32 fzgx_pool_table4[1] = {0xFF0000FF};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep4(void) { const u32 *volatile cp; cp = fzgx_pool_table4; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime5(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 448.0f;
}
static const u32 fzgx_pool_table6[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep6(void) { const u32 *volatile cp; cp = fzgx_pool_table6; }  /* fzgx-allow: S2 pool primer sink */
#pragma section code_type ".text"

extern u32 lbl_801A6CF4;
extern u8 lbl_1_rodata_48C8[];
extern void fn_1_A9868(void);
extern void fn_1_A9A28(int, int, int, int, u32 *);
extern void fn_1_AA538(void);

void fn_1_A6E68(void) {
    u8 *rodata;
    u8 *state;
    u32 first;
    u32 second;
    u16 value;

    rodata = lbl_1_rodata_48C8;
    state = *(u8 **)&lbl_801A6CF4;
    value = *(u16 *)(state + 8);
    if ((448.0f) == (f32)value) {
        fn_1_A9868();
        first = fzgx_pool_table3[0];
        fn_1_A9A28(0, 25, 640, 25, &first);
        second = fzgx_pool_table4[0];
        fn_1_A9A28(0, 454, 640, 454, &second);
        fn_1_AA538();
    }
}
/* fzgx:end fn_1_A6E68 */

/* fzgx:begin fn_1_A6F10 */
u32 *fn_1_A6F10(void) {
    return &lbl_1_bss_6F5F0;
}
/* fzgx:end fn_1_A6F10 */

/* fzgx:begin fn_1_A6F1C */
u32 fn_1_A6F1C(void) {
    return lbl_1_bss_6F5F0;
}
/* fzgx:end fn_1_A6F1C */

/* fzgx:begin fn_1_A6F2C */
s32 fn_1_A6F2C(void) {
    s32 result = 0;
    s32 state;

    if (lbl_1_bss_962 == 0x99) {
        state = lbl_1_data_341B8->unk_4;
        if ((s8)state == 0 || (s8)state == 5) {
            result = 1;
        }
    }

    return result;
}
/* fzgx:end fn_1_A6F2C */

/* fzgx:begin fn_1_A6F6C */
s32 fn_1_A6F6C(void) {
    s32 result = 0;

    if (lbl_1_bss_962 == 0x99) {
        if (*(s8 *)((u8 *)lbl_1_data_341B8 + 4) == 5) {
            result = 1;
        }
    }

    return result;
}
/* fzgx:end fn_1_A6F6C */

/* fzgx:begin fn_1_A6FA0 */
void fn_1_A6FA0(void) {
    fn_1_4A00(0, 0x3c, lbl_1_bss_6F5F4);
    lbl_1_data_341B8->unk_4 = 5;
}
/* fzgx:end fn_1_A6FA0 */

/* fzgx:begin fn_1_A6FE8 */
f32 fn_1_A6FE8(void) {
    if (fn_1_A5DC4()) {
        return lbl_1_rodata_49F8;
    }

    return lbl_1_rodata_49FC[0];
}
/* fzgx:end fn_1_A6FE8 */

/* fzgx:begin fn_1_A714C */
void fn_1_A714C(f32 *a, f32 *b, f32 *c, f32 *d) {
    if (a != 0) {
        *a = *(f32 *)&lbl_1_bss_6F608.unk_0;
    }
    if (b != 0) {
        *b = *(f32 *)&lbl_1_bss_6F608.unk_4;
    }
    if (c != 0) {
        *c = *(f32 *)&lbl_1_bss_6F608.unk_8;
    }
    if (d != 0) {
        *d = *(f32 *)&lbl_1_bss_6F608.unk_C;
    }
}
/* fzgx:end fn_1_A714C */

/* fzgx:begin fn_1_A71AC */
f32 fn_1_A71AC(void) {
    return *(f32 *)&lbl_1_bss_6F608.unk_10;
}
/* fzgx:end fn_1_A71AC */

/* fzgx:begin fn_1_A71BC */
f32 fn_1_A71BC(void) {
    return *(f32 *)((u8 *)&lbl_1_bss_6F608 + 0x14);
}
/* fzgx:end fn_1_A71BC */

/* fzgx:begin fn_1_A71CC */
extern void fn_80072344(void);

typedef struct {
    u32 unk_0;
    u32 unk_4;
    u32 unk_8;
    u32 unk_C;
    u32 unk_10;
    u32 unk_14;
} Copy_1_A71CC;

void fn_1_A71CC(void) {
    fn_80072344();

    *(Copy_1_A71CC *)&lbl_1_bss_6F620 =
        *(Copy_1_A71CC *)&lbl_1_bss_6F608;
}
/* fzgx:end fn_1_A71CC */

/* fzgx:begin fn_1_A722C */
#include "types.h"




extern void fn_80072378(void);

typedef struct {
    u32 unk_0;
    u32 unk_4;
    u32 unk_8;
    u32 unk_C;
    u32 unk_10;
    u32 unk_14;
} Copy_1_A722C;

void fn_1_A722C(void) {
    fn_80072378();

    *(Copy_1_A722C *)&(*(u32 (*)[6])&lbl_1_bss_6F608) =
        *(Copy_1_A722C *)&(*(u32 (*)[6])&lbl_1_bss_6F620);
}
/* fzgx:end fn_1_A722C */

/* fzgx:begin fn_1_A728C */
// fn_1_A728C: returns a constant.
int fn_1_A728C(void) {
    return 0;
}
/* fzgx:end fn_1_A728C */
