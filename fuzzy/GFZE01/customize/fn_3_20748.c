/* Non-matching: best partial attempt (97.23% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"
#include "rel/customize/globals.h"
#include "rel/customize/toolkit.h"
#include "font.h"
#include "types.h"

/* begin game/vec3.h (deltawave784/fzgx, CC0) */
#ifndef GAME_VEC3_H
#define GAME_VEC3_H

// Three-float vector shared by the main_rel type headers (camera, car, font, ghost,
// live_camera each carried an identical private copy); Vec3f likewise (car, screen_effect,
// stcoli). Hand-owned (librarian).


typedef struct Vec3 {
    f32 x;
    f32 y;
    f32 z;
} Vec3;

typedef struct Vec3f {
    f32 x, y, z;
} Vec3f;

#endif  // GAME_VEC3_H

/* end game/vec3.h */





struct QView {
    u8 unk_0;
    u8 pad_1[0x3];
    u32 unk_4;
    u32 unk_8;
    u8 pad_C[0x2];
    u8 unk_E;
    u8 pad_F[0x1];
    u8 unk_10;
};

typedef struct CustomizeData {
    u32 unk_00[2];
    u32 unk_08;
    u8 pad_0c[0x14];
    void *unk_20;
} CustomizeData;

struct fn_3_1A1D8_lbl_1_bss_9F8_0_E20 {
    u8 pad_0[0x10];
    u16 unk_10;
    u8 pad_12[0x2];
};

struct fn_3_1A1D8_lbl_1_bss_9F8 {
    struct fn_3_1A1D8_lbl_1_bss_9F8_0_E20 unk_0[1];
};

struct fn_3_1A264_lbl_1_bss_9F8_10_E20 {
    u16 unk_0;
    u8 pad_2[0x12];
};

struct fn_3_1A264_lbl_1_bss_9F8 {
    u8 pad_0[0x10];
    struct fn_3_1A264_lbl_1_bss_9F8_10_E20 unk_10[1];
};

typedef struct {
    u8 r, g, b, a;
} QColor;

typedef struct { u32 id; f32 x,y,z; u32 rest[18]; } Packet23524;

struct fn_3_1D338_sprite {
    u32 unk0;
    f32 x;
    f32 y;
    f32 z;
    u8 pad10[0x1C];
    f32 unk2C;
    u32 unk30;
    u8 pad34[4];
    u8 color[4];
    u8 pad3C[0x14];
    void (*draw)(void *, void *);
    u8 pad54[4];
};

struct fn_3_23724_Copy88 {
    u32 flags;
    f32 x, y, z;
    u32 pad[8];
    u32 mode;
    u32 tail[9];
};

typedef struct {
    u32 flags;
    u8 pad[0x1c];
} fn_3_1F81C_CustomizeEntry;

typedef struct CustomizeObject CustomizeObject;

struct CustomizeObject {
    u8 pad0[0x18];
    u16 count;
    u8 pad1[0x26];
    fn_3_1F81C_CustomizeEntry entries[1];
    u8 pad2[0xc];
    f32 value;
};

typedef struct {
    CustomizeObject *object;
} CustomizeSlot;

typedef struct {
    u8 pad0[8];
    CustomizeSlot *slot;
} CustomizeManager;

typedef struct {
    u8 pad0[0xc];
    CustomizeManager *manager;
} CustomizeRoot;

struct fn_3_20374_lbl_1_data_1E5C0 {
u32 unk_0,unk_4,unk_8; f32 unk_C,unk_10,unk_14; u32 unk_18,unk_1C,unk_20,unk_24,unk_28,unk_2C,unk_30;
};

struct fn_3_23724_lbl_3_rodata_768 {
    u8 pad_0[0x78];
    f32 seven;
    u8 pad_7C[0x10C];
    f32 one;
    f32 half;
    u8 pad_190[0x40];
    f32 zero;
    u8 pad_1D4[0x180];
    f32 twentythree;
    u8 pad_358[0xC];
    f32 twelve;
    u8 pad_368[0x40];
    f32 unk_3A8;
    f32 unk_3AC;
    f32 five;
};

struct fn_3_2BFB4_lbl_3_rodata_768 {
    u8 pad_0[0x22C];
    f32 unk_22C;
    u8 pad_230[0x1E8];
    f32 unk_418;
    u8 pad_41C[0x25C];
    f32 unk_678;
};

struct fn_3_2C164_lbl_3_rodata_768 {
    u8 pad_0[0x22C];
    f32 unk_22C;
    u8 pad_230[0x1E8];
    f32 unk_418;
    u8 pad_41C[0x25C];
    f32 unk_678;
};

struct fn_3_20374_lbl_3_rodata_768 {
f32 unk_0; u8 pad_4[0x94]; f64 unk_98; u8 pad_A0[0xE8]; f32 unk_188;
u8 pad_18C[0x6C]; f64 unk_1F8; u8 pad_200[0x28]; f32 unk_228;
u8 pad_22C[0x5C]; f32 unk_288,unk_28C,unk_290,unk_294,unk_298,unk_29C,unk_2A0,unk_2A4,unk_2A8;
};

typedef struct Sig_fn_1_87610_Fn187610Data {
u8 pad_000[2]; s8 field_002; u8 pad_003[0x205]; u8 field_208[0x120];
} Sig_fn_1_87610_Fn187610Data;

typedef struct Sig_fn_8006F038_Vec3 { f32 x,y,z; } Sig_fn_8006F038_Vec3;

struct fn_3_2B268_lbl_1_bss_7F0C0 {
    u8 pad_0[0x48F8];
    u32 unk_48F8;
};

typedef struct Sig_fn_1_8D210_fn_1_8D210_car {
    f32 position[6];
    f32 scale_z;
    f32 scale_y;
    f32 scale_x;
    f32 field_24;
    u16 field_28;
    u16 field_2a;
    u16 field_2c;
    u16 field_2e;
    u16 field_30;
    u16 field_32;
    u32 field_34;
    u8 field_38;
    u8 field_39;
    u8 field_3a;
    u8 pad_3b;
    u32 field_3c;
    u8 field_40;
    u8 pad_41[3];
    f32 field_44;
    f32 field_48;
    f32 field_4c;
    f32 field_50;
    s16 field_54;
    u8 pad_56[2];
    s32 field_58;
    u8 field_5c[4];
    u32 field_60;
} Sig_fn_1_8D210_fn_1_8D210_car;

typedef s32 (*Sig_fn_1_8D210_fn_1_8D210_callback)(u32);

struct fn_3_2BFB4_lbl_801A66B4 {
    u32 unk_0;
};

typedef struct Rgba {
    u8 r, g, b, a;
} Rgba;

typedef struct {
    u32 unk_0;
    u32 unk_4;
    u32 unk_8;
    Vec3 pos;
    u32 unk_18[7];
} Fn3_1FF7C_Camera;

typedef struct {
    u8 pad_0[0x60];
    Vec3 pos;
    f32 unk_6C;
} Fn3_1FF7C_Mtx;

typedef struct {
    u32 flags;
    u8 pad_4[0x1C];
} Fn3_1FF7C_Entry;

typedef struct {
    u8 pad_0[0x18];
    u16 count;
    u8 pad_1A[0x26];
    Fn3_1FF7C_Entry entries[1];
} Fn3_1FF7C_Model;


typedef struct {
    u8 pad_0[0x8];
    u16 unk_8;
    u8 pad_A[0x6];
    u16 unk_10;
    u16 unk_12;
} fn_3_1A648_Pad;

typedef struct fn_3_273F4_Pool {
    u8 pad_0[0x1c];
    f32 unk_1C;
    u8 pad_20[0x40];
    f32 unk_60;
    u8 pad_64[0x11c];
    f32 unk_180;
    u8 pad_184[0x4];
    f32 unk_188;
    u8 pad_18C[0x44];
    f32 unk_1D0;
    u8 pad_1D4[0x58];
    f32 unk_22C;
    u8 pad_230[0x14c];
    f32 unk_37C;
    u8 pad_380[0x74];
    f32 unk_3F4;
    u8 pad_3F8[0xc];
    f32 unk_404;
    u8 pad_408[0x10];
    f32 unk_418;
    u8 pad_41C[0xf8];
    f32 unk_514;
    u8 pad_518[0x4];
    f32 unk_51C;
    u8 pad_520[0x24];
    f32 unk_544;
    u8 pad_548[0x1c];
    f32 unk_564;
    u8 pad_568[0x34];
    u32 unk_59C;
    u32 unk_5A0;
    u32 unk_5A4;
    u32 unk_5A8;
    f32 unk_5AC;
    f32 unk_5B0;
    f32 unk_5B4;
    f32 unk_5B8;
    f32 unk_5BC;
    f32 unk_5C0;
    f32 unk_5C4;
    f32 unk_5C8;
    f32 unk_5CC;
} fn_3_273F4_Pool;
extern const f32 lbl_3_rodata_740;
extern void fn_3_1B130(void *data, s16 x, s16 y, Rgba color);
extern void fn_3_BE10(void);
extern void fn_3_BEF0(void);
extern void fn_3_1445C(void);
extern void fn_3_BE88(void);
extern void fn_80008BA8(u32 *, void *, s32);
extern s32 fn_8008023C(u32 arg0, u32 arg1, u32 arg2);
extern struct fn_3_1A1D8_lbl_1_bss_9F8 lbl_1_bss_9F8;
extern u32 fn_3_141A8(u32);
extern u8 fn_3_1443C(void);
extern u32 fn_3_14064(void);
extern u32 fn_3_1401C(void);
extern u32 fn_3_1402C(u8 index);
extern void fn_1_A2D84(u32 arg0);
extern void fn_80008BEC(void *dest, int value, u32 size);
extern void fn_3_1B4BC(void *, s16, s16, s16, s16, u32 *);
extern void fn_3_149AC();
extern void fn_3_14794(void *, u32, u32, u32 *);
extern void fn_3_146C0(void *arg0, s16 x, s16 y, s16 delta, u32 *arg4);
extern u32 lbl_1_rodata_26F8;
extern u32 lbl_801A66A8;
extern u16 fn_1_A5DB0(void);
extern s32 fn_1_A5DC4(void);
extern f32 lbl_8006D188(s32);
extern void fn_1_50164();
extern void fn_1_49410(void);
extern void fn_1_4954C(f32 value);
extern void fn_1_4955C(f32 value1, f32 value2);
extern void fn_1_49590(f32 value);
extern void fn_1_495A0(f32 value);
extern void fn_1_495C8(u8 value);
extern void fn_1_4966C(f32 value1, f32 value2);
extern void fn_1_496FC(f32 value1, f32 value2);
extern void fn_1_49738(u32 value);
extern u32 fn_3_2B750(s16, s16);
extern void fn_3_2406C(void);
extern void fn_3_240DC(void *, void *);
extern void fn_1_5233C(void *arg0, void *arg1);
extern struct fn_3_20374_lbl_1_data_1E5C0 lbl_1_data_1E5C0;
extern u32 lbl_801A66A0;
extern CustomizeObject *lbl_801A6D00;
extern void fn_8006F038(Vec3 *arg0, Vec3 *arg1, s16 arg2);
extern void lbl_8006DCDC(void);
extern void fn_1_F7870(u32 value);
extern void lbl_8006DCA4(void);
extern void lbl_8006E0B4(f32, f32, f32);
extern void mathutil_mtxA_rotate_x(s32);
extern void mathutil_mtxA_rotate_y(s32);
extern u32 fn_1_56018(s32 value);
extern void lbl_8006D784(void *);
extern void fn_1_560F0(s32 index, void *arg);
extern void fn_80072558(void);
extern void fn_1_55210(CustomizeObject *);
extern void lbl_8006DB74(void*);
extern void fn_1_151BDC(u32 value);
extern void fn_1_14E2DC(void *, s16, f32);
extern void lbl_8006DBAC(Vec3 *);
extern void fn_1_FCFA4(void *);
extern void fn_1_50190(void *arg0, f32 farg0, f32 farg1, f32 farg2, f32 farg3, f32 farg4, f32 farg5);
extern f32 lbl_3_rodata_768[];
extern s32 fn_3_1FF7C(void);
extern s32 fn_3_837C(s16 arg0);
extern u32 fn_3_23A1C(u32, u32, u32, u32, u32);
extern u32 fn_3_26A34(u32, u32, u32);
extern u32 fn_3_1C278(s16, u8, u8, u8, u32, f32);
extern void fn_1_133DBC(void* arg0);
extern void fn_1_8D1EC(void *, s32 (*)(u32), void *);
extern void fn_1_134AD4(void);
extern u32 fn_1_13ABA8(u32);
extern void fn_1_138120(void *);
extern void fn_1_495B0(u32 value);
extern void fn_1_4965C(u8 value);
extern void fn_1_49748(f32 value);
extern void fn_1_49514(u32 *value);
extern void *fn_1_14EEC4(s16 index, void *obj, s16 subindex);
extern char *fn_1_14EA74(s32, char *, s16);
extern int fn_1_14EE00(s16 arg0, void *arg1, s16 arg2);
extern f32 fn_1_A6FE8(void);
extern u8 lbl_1_bss_7F0C0[];
extern u32 fn_3_1EFE4(void);
extern u32 lbl_801A66C0[1];
extern void fn_3_2A2F8(s16, s16, s16, s16, s32);
extern void fn_3_7A08(s16 *arg0, s16 *arg1, int arg2);
extern u32 fn_3_225F8(u32, u32, u32);
extern void fn_1_54278(u32 arg0, u32 arg1);
extern void fn_1_5428C(f32 value);
extern void fn_1_53BD8(void *, f32, f32, f32, f32, f32);
extern void fn_1_495FC(void);
extern u32 fn_3_2B778(s16, u32, u32, u32, u32);
extern f32 lbl_8006D118(f32 *, f32);
extern void fzgx_usef(f32);
extern void fzgx_used(f64);
extern void fzgx_usep(void *);
extern s32 fzgx_sink_s;
extern u32 fzgx_sink_u;
extern void fn_3_1AB34(void *obj, s16 start, s16 base, u32 *items);
extern u32 fn_3_17820();
extern void fn_3_1ADA4(void *, int, int, int, int);
extern void fn_3_1AE40(void *data, u32 x1, u32 y1, s16 x2, s16 y2);
extern void fn_3_1AEE4(void *data, u32 x1, u32 y1, u32 x2, u32 y2);
extern void fn_3_1B008(void *data, u32 x1, u32 y1, u32 x2, u32 y2);
extern u8 lbl_3_bss_A2458[8];
extern void fn_3_BD98(void);
extern u8 fn_3_1441C(void);
extern void fn_3_14008(void);
extern const QColor lbl_3_rodata_744[9];
extern void fn_3_152BC(u32, s32, s32, s32, s32, QColor);
extern void fn_3_14E18(void *arg0, u32 arg1, u32 arg2, s16 arg3, u32 arg4);
extern const f32 lbl_3_rodata_8F0;
extern const f32 lbl_3_rodata_990[297];
extern CustomizeRoot lbl_1_bss_38460;
extern u32 fn_1_870BC(u32,u32,Sig_fn_1_87610_Fn187610Data*,u32,u32,f32);
extern void fn_1_5621C(f32 value0, f32 value1, f32 value2, f32 value3);
extern void lbl_8006D7DC(void*);
extern void lbl_8006DFE8(void*);
extern void lbl_8006E14C(f32);
extern s32 fn_3_1EC2C(u32);
extern void fn_3_23724(u32 arg0, u32 arg1, u32 arg2, f32 arg3, f32 arg4, f32 arg5, f32 arg6);
extern u32 fn_3_21300(u32,u32,u32);
extern u32 fn_80074188(u32 arg0, u32 arg1, u32 arg2, u32 arg3);
extern u32 fn_1_151E20(u32 value, s16 index);
extern void fn_1_A9868();
extern void fn_1_AA188(s32, s32, s32, s32, void *, void *, void *, void *);
extern void fn_1_AA538(void);
extern void fn_1_4E0F4(void);
extern s32 lbl_3_bss_24370;
extern f64 lbl_3_rodata_800;
extern void fn_1_51564(u16 first, u16 second, u16 third, u16 fourth, u16 fifth, u16 sixth);
extern void fn_1_5158C(FontDrawPacket *, u32, s16, s16);
extern int sprintf(char *s, const char *format, ...);
extern struct fn_3_2BFB4_lbl_801A66B4 lbl_801A66B4;
extern u8 fn_1_B7C00(void);
extern u32 lbl_801A6410;
extern void fn_1_46B4(u32 arg0, u32 arg1, const char *arg2, int arg3);
extern void fn_3_1ABD8(void *arg0, s16 x1, s16 y1, s16 x2, s16 y2, u32 *value);
extern void fn_3_1BA20(void *arg0, s16 arg1, s16 arg2, s16 arg3, s16 arg4, s32 *arg5);
extern void fn_3_1BF08(void *data, s16 x1, s16 y1, s16 x2, s16 y2, u32 *color);
extern void fn_3_156A8(void);
extern void fn_3_1ACE4(void *data, s32 first_a, s32 second_a, s32 first_b, s32 second_b, u32 *values);

#pragma section code_type ".fzgxpool"
__declspec(section ".fzgxpool") static void fzgx_pool_prime1(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    s = 0.699999988079071f;
}
static const unsigned long fzgx_pool_table2[6] = {0xFFFFFF00, 0xFFFF0000, 0xFF000000, 0x0000FF00, 0xFFF200FF, 0xFFFF0000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep2(void) { const unsigned long *volatile cp; cp = fzgx_pool_table2; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime3(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    s = 0.4583333432674408f;
    s = 284.0f;
    s = 329.0f;
    s = 100.0f;
    s = 0.9166666865348816f;
    s = 360.0f;
    s = 0.5416666865348816f;
    s = 441.0f;
    s = 332.0f;
    s = 345.0f;
    s = 358.0f;
    s = 0.48749998211860657f;
    s = 395.0f;
    s = 331.0f;
    s = 359.0f;
    s = 320.0f;
    s = 362.0f;
    s = 200.0f;
    s = 323.0f;
    s = 381.0f;
    s = 13.0f;
    s = 0.007843137718737125f;
    s = 6.0f;
    s = 7.0f;
    s = 0.14901961386203766f;
    s = 0.12941177189350128f;
    s = 132.0f;
    s = 150.0f;
    s = 0.800000011920929f;
    s = 0.30000001192092896f;
    s = 0.0f;
    d = 4503601774854144.0;
}
static const unsigned long fzgx_pool_table4[43] = {0x00004A00, 0x00005400, 0x00003800, 0x00003E00, 0x00003700, 0x00005500, 0x00003000, 0x00003500, 0x00003A00, 0x00004000, 0x00004400, 0x00005000, 0x00003300, 0x00002E00, 0x00003100, 0x00004F00, 0x00003900, 0x00003D00, 0x00004C00, 0x00003F00, 0x00004800, 0x00005200, 0x00004500, 0x00005300, 0x00003C00, 0x00005600, 0x00004300, 0x00004200, 0x00003200, 0x00002F00, 0x00003400, 0x00003600, 0x00004D00, 0x00004600, 0x00004100, 0x00005100, 0x00004E00, 0x00004700, 0x00003B00, 0x00004B00, 0x00004900, 0xFFF200FF, 0xFFFF0000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep4(void) { const unsigned long *volatile cp; cp = fzgx_pool_table4; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime5(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    s = 380.0f;
    s = 334.0f;
    s = 0.40625f;
}
static const unsigned long fzgx_pool_table6[6] = {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep6(void) { const unsigned long *volatile cp; cp = fzgx_pool_table6; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime7(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    s = 480.0f;
    s = 640.0f;
    s = 62.0f;
    s = 1.3411765098571777f;
    s = 8.0f;
    s = 0.125f;
    s = 1.0f;
    s = 0.5f;
    s = 215.0f;
    s = 3.0f;
    s = 180.0f;
    s = 90.0f;
    s = 240.0f;
    s = 44.0f;
    s = 89.9000015258789f;
    s = 40.0f;
    s = 16384.0f;
    s = 65536.0f;
    s = 60.0f;
    s = 80.0f;
    s = 460.0f;
    s = 0.6666666865348816f;
    s = 0.6078431606292725f;
    s = -3.0f;
}
static const unsigned long fzgx_pool_table8[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep8(void) { const unsigned long *volatile cp; cp = fzgx_pool_table8; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime9(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    s = 0.6196078658103943f;
    s = 0.5058823823928833f;
    s = 216.0f;
    s = 0.20000000298023224f;
    s = 140.0f;
    s = 250.0f;
    s = 400.0f;
    s = 550.0f;
    s = 0.46666666865348816f;
    d = 4503599627370496.0;
}
static const unsigned long fzgx_pool_table10[9] = {0x00000000, 0x41200000, 0xC0A00000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep10(void) { const unsigned long *volatile cp; cp = fzgx_pool_table10; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime11(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    s = -0.5f;
    s = 182.04444885253906f;
    s = 10.0f;
}
static const unsigned long fzgx_pool_table12[6] = {0x00000000, 0x41200000, 0xC0A00000, 0x00000000, 0x00000000, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep12(void) { const unsigned long *volatile cp; cp = fzgx_pool_table12; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime13(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    s = 3.75f;
    s = 3.5f;
    s = 0.05000000074505806f;
}
static const unsigned long fzgx_pool_table14[6] = {0x00000000, 0x41200000, 0xC0A00000, 0x00000000, 0x00000000, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep14(void) { const unsigned long *volatile cp; cp = fzgx_pool_table14; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime15(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    s = 0.25f;
}
static const unsigned long fzgx_pool_table16[6] = {0x00000000, 0x41200000, 0xC0A00000, 0x00000000, 0x00000000, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep16(void) { const unsigned long *volatile cp; cp = fzgx_pool_table16; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime17(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    s = 3.5176470279693604f;
    s = 8.79411792755127f;
    s = 10.55294132232666f;
    s = 315.0f;
    s = 2.0f;
    s = 1.2999999523162842f;
    s = 0.6000000238418579f;
    s = 0.6274510025978088f;
    s = 0.7529411911964417f;
    s = 3.5999999046325684f;
}
#pragma section code_type ".text"
struct fn_3_20374_Arg0 { u32 unk_0, unk_4, unk_8; };
typedef struct { s16 unk_0; u16 pad; u32 unk_4; } Entry;
s32 fn_3_20748(struct fn_3_20374_Arg0 *arg0) {
const struct fn_3_20374_lbl_3_rodata_768 *p_lbl_3_rodata_768;
struct fn_3_20374_lbl_1_data_1E5C0 *p_lbl_1_data_1E5C0;
Entry *v16;
s32 row_index;
Entry *v14;
s16 v13;
s16 v15;
s16 v17;
s32 v20;
u32 v19,v28,v25;
s16 first,last;
f32 v1,v2,v3,v18;

f32 loc_54[12];
struct fn_3_20374_lbl_1_data_1E5C0 loc_20;
struct fn_3_20374_Arg0 loc_14;
f32 loc_8[3];
loc_14=*arg0;
p_lbl_3_rodata_768=&(*((const struct fn_3_20374_lbl_3_rodata_768 *)&lbl_3_rodata_768));
fn_80008BEC(&lbl_3_bss_A2468.pad_0[4],0,12);
fn_80008BEC(&lbl_3_bss_A2468.pad_0[16],0,12);
lbl_3_bss_A2468.unk_14=*(f32*)&loc_14.unk_4;
fn_8006F038( (Vec3 *)((Sig_fn_8006F038_Vec3*)&lbl_3_bss_A2468.pad_0[4]), (Vec3 *)((Sig_fn_8006F038_Vec3*)&lbl_3_bss_A2468.pad_0[16]),0);
lbl_8006DCDC();
v1=0.7f;
p_lbl_1_data_1E5C0=&lbl_1_data_1E5C0;
v2=(f32)(p_lbl_1_data_1E5C0->unk_C*v1);
v3=(f32)(p_lbl_1_data_1E5C0->unk_10*v1);
loc_20=*p_lbl_1_data_1E5C0;
loc_20.unk_C=v2-v3;
loc_20.unk_10=v2+v3;
loc_20.unk_14=p_lbl_1_data_1E5C0->unk_14;
fn_1_F7870( (u32)(void*)(&loc_20));
for(v13=0;v13<7;v13++) {
f32 row;
f32 index;
f32 spacing=3.5999999046325684f;
row_index = v13;
index=(f32)row_index;
row=(f32)(index*spacing)-9.0f;
v14=(Entry*)((u8*)&lbl_3_bss_2C584+v13*56);
for(v15=0;v15<7;v15++) {
v16=&v14[v15];
v17=v16->unk_0;
v20=0;
if(v17==-1) continue;
v19=v16->unk_4;
if(v19&0x40000000) continue;
if(v19&0x80000000) continue;
fn_3_7A08(&first, &last, 3);
if ((lbl_3_bss_F0.unk_24 & 0x80000000) &&
    (lbl_3_bss_F0.unk_24 & 0x800000)) {
    if (row_index < first - 1 || row_index > last + 1) continue;
} else {
    if (v13 < first || v13 > last) continue;
}
fn_80008BA8( (u32 *)(void*)(loc_8),&loc_14,12);
{
f32 step, column;
step=3.5176470279693604f;
v18=10.55294132232666f;
column=(f32)v15;
loc_8[0]+=(f32)(column*step)-v18;
loc_8[2]+=row;
}
lbl_8006D7DC(loc_8);
mathutil_mtxA_rotate_x((s32)(182.04444885253906f*(315.0f-(f32)(2.0f*loc_8[2]))));
if(lbl_3_data_C4==v17) {
v25=lbl_801A66A0;
mathutil_mtxA_rotate_y((s32)(182.04444885253906f*(f32)(v25%360)));
lbl_8006E14C(1.2999999523162842f);
} else mathutil_mtxA_rotate_y(0x6000);
lbl_8006E14C(0.6000000238418579f);
lbl_8006DB74(loc_54);
lbl_8006DFE8(loc_54);
fn_80072558();
v28=lbl_3_bss_20854.unk_0+v17*0x440;
if(v28==0) return 0;
v18=1.0f;
fn_1_870BC(v28,1,(Sig_fn_1_87610_Fn187610Data*)v28,0,4,v18);
}
}
return 0;
}
