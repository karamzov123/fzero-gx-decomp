/* Retained Japan/PAL compiler inputs pending a verified whole-TU regional build. */
#include "types.h"
#include "game/pad.h"
#include "rel/main_rel/globals.h"
#include "rel/main_rel/sel_static_disp.h"
#include "font.h"

typedef struct {
    u32 v[8];
} Word8;

typedef struct {
    u8 pad0[0x4];
    f32 unk_4;
    f32 unk_8;
    f32 unk_C;
    f32 unk_10;
    f32 unk_14;
    u8 pad18[0x18];
    s32 unk_30;
    u8 pad34[0x24];
} Sp8;

typedef struct {
    u32 value[22];
} Fn139F18Data;

typedef struct StaticDispParams {
    s32 id;
    f32 x;
    f32 y;
    f32 z;
    u32 unk1[8];
    s32 count;
    u32 unk2[9];
} StaticDispParams;

struct Struct_26F8 {
    u32 unk00;
    f32 unk04;
    f32 unk08;
    f32 unk0C;
    u8 pad10[0x1C];
    f32 unk2C;
    u32 unk30;
    u8 pad34[4];
    u32 unk38;
    u8 pad3C[0x1C];
};

typedef struct {
    const char *p[9];
} PtrTab;

struct fn_1_13F8C4_lbl_801A6410 {
    u32 unk_0;
};

struct fn_1_149C64_lbl_1_bss_8E43C {
    u32 unk_0;
};

struct fn_1_149C64_lbl_1_bss_8E440 {
    u32 unk_0;
};

typedef struct {
    s16 indices[2];
    u8 pad8[4];
    u32 flags;
} Source;

typedef struct {
    s16 index;
    u8 pad2[0x1e];
    char text[0x320];
    void *object;
    void *handle[4];
} Display;

struct Sig_fn_80071718_fn_80071718_Arg0 {
    u8 pad_0[0xC];
    u32 unk_C;
};

struct Sig_fn_800711A8_fn_800711A8_Entry {
    u8 pad_00[0x24];
    void *field_24;
};

struct Sig_fn_800711A8_fn_800711A8_Arg0 {
    s32 count;
    u8 pad_04[4];
    struct Sig_fn_800711A8_fn_800711A8_Entry **entries;
    u8 pad_0C[4];
    u32 field_10;
    void *field_14;
};

typedef struct {
    u8 data[4];
    f32 value;
    u8 tail[8];
} Fn1_14E9E4Entry;

typedef struct fn_1_150C8C_Entry {
    u8 pad[0x68];
    u32 active;
    u8 tail[0x40];
} fn_1_150C8C_Entry;

typedef struct fn_1_150C8C_Object {
    u8 pad_84[0x84];
    s32 count;
    fn_1_150C8C_Entry entries[1];
} fn_1_150C8C_Object;

typedef struct fn_1_150F30_StaticDisp {
    u8 pad_2728[0x2728];
    s32 unk_2728;
    s32 unk_272c;
} fn_1_150F30_StaticDisp;

typedef struct Fn14E09CValue {
    void *value;
} Fn14E09CValue;

typedef struct Fn14E09CRef {
    u8 pad8[8];
    Fn14E09CValue *value;
} Fn14E09CRef;

typedef struct Fn14E09CObj {
    u8 pad344[0x344];
    Fn14E09CRef *ref;
} Fn14E09CObj;

typedef struct DispNode {
    u8 pad[4];
    f32 value;
} DispNode;

typedef struct DispChildList {
    DispNode *child[3];
} DispChildList;

typedef struct DispObject {
    u32 flags;
    u8 pad0[12];
    f32 value;
    u8 pad1[32];
    DispChildList *children;
} DispObject;

typedef struct fn_1_151668_StaticDispEntry {
    f32 first;
    u8 pad0[0x18];
    f32 values[3];
    DispObject *object;
    u8 active;
    u8 scale_first;
    u8 scale_second;
    u8 clear_flag;
    u8 pad2[0x0c];
} fn_1_151668_StaticDispEntry;

typedef struct fn_1_151668_StaticDisp {
    u8 pad0[0x1830];
    fn_1_151668_StaticDispEntry entries[63];
    u8 pad1[0x30];
    s32 entry_count;
    s32 value_2728;
    s32 value_272c;
} fn_1_151668_StaticDisp;
extern f32 lbl_1_rodata_26F8[22];
extern void OSPanic(const char *file, int line, const char *msg, ...);
extern u16 fn_1_486C4(u32 value);
extern u16 fn_1_48690(u32 unused);
extern void fn_1_52070(u32 value);
extern void fn_1_49410(void);
extern void fn_1_495B0(u32 value);
extern void fn_1_496FC(f32 value1, f32 value2);
extern void fn_1_4954C(f32 value);
extern void fn_1_4955C(f32 value1, f32 value2);
extern void fn_1_49738(void* arg0);
extern void fn_1_49590(f32 value);
extern u32 lbl_801A66B4;
extern void fn_1_49748(f32 value);
extern void fn_1_49514(u32 *value);
extern void fn_1_51564(u16 first, u16 second, u16 third, u16 fourth, u16 fifth, u16 sixth);
extern void fn_1_5158C(FontDrawPacket *, u32, s16, s16);
extern void fn_1_5233C(void* arg0, void* arg1);
extern f32 fn_1_4B068(const char*);
extern u16 fn_1_A5DB0(void);
extern u32 __cvt_fp2unsigned(f32);
extern int sprintf(char *s, const char *format, ...);
extern void fn_1_494DC(s16 index);
extern void fn_1_4966C(f32 value1, f32 value2);
extern f32 lbl_1_rodata_93F0[15];
extern f32 lbl_1_rodata_92C0[22];
extern f32 lbl_1_rodata_970C[71];
extern const f32 lbl_1_rodata_946C;
extern void fn_1_149C2C();
extern struct fn_1_149C64_lbl_1_bss_8E43C lbl_1_bss_8E43C;
extern struct fn_1_149C64_lbl_1_bss_8E440 lbl_1_bss_8E440;
extern void fn_1_149CA4(u32, u32, u32, u32);
extern void fn_1_520A0(void);
extern f32 lbl_1_rodata_942C[16];
extern f32 fn_1_521B8(s32 value);
extern f32 fn_1_520F8(s32 value);
extern u32 fn_80074188(u32 arg0, u32 arg1, u32 arg2, u32 arg3);
extern void fn_1_520CC(void);
extern u8 fn_1_149FB4(s32 index);
extern u32 lbl_801A66A4;
extern size_t strlen(const char *str);
extern void qsort(void *arg0, u32 arg1, s32 arg2, void *callback);
extern void fn_1_144F40(u32 arg0, u32 arg1);
extern u8 fn_1_155F8C(void);

/* fzgx:begin fn_1_1421D8 noprologue */
#include "types.h"
#include "rel/main_rel/sel_static_disp.h"

#pragma section code_type ".fzgxpool"
static const unsigned long fzgx_pool_table1[3] = {0x00000000, 0x00000000, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep1(void) { const unsigned long *volatile cp; cp = fzgx_pool_table1; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime2(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    s = 0.10000000149011612f;
    s = 1.0f;
}
static const unsigned long fzgx_pool_table3[61] = {0x3F800000, 0x00000000, 0x00000000, 0x3F800000, 0x3F800000, 0x00000000, 0x3F800000, 0x04000000, 0x00000000, 0xFFFFFFFF, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x3DCCCCCD, 0x3F800000, 0x3F800000, 0x00000000, 0x00000000, 0x3F800000, 0x3F800000, 0x00000000, 0x3F800000, 0x04000000, 0x00000000, 0xFFFFFFFF, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x3DCCCCCD, 0x3F800000, 0x3F800000, 0x00000000, 0x00000000, 0x3F800000, 0x3F800000, 0x00000000, 0x3F800000, 0x04000000, 0x00000000, 0xFFFFFFFF, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep3(void) { const unsigned long *volatile cp; cp = fzgx_pool_table3; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime4(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    s = 0.0f;
    s = 0.9583333134651184f;
    s = 23.0f;
    s = 2.0f;
    s = 0.6666666865348816f;
    s = 0.5f;
    s = 0.5833333134651184f;
}
static const unsigned long fzgx_pool_table5[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep5(void) { const unsigned long *volatile cp; cp = fzgx_pool_table5; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime6(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    d = 4503601774854144.0;
}
#pragma section code_type ".text"

extern f32 fn_1_4B068(s32);
extern u32 fn_1_5233C(void *, void *);
extern u32 lbl_801A66B4;
extern void fn_1_13D460(s32, s32, s32, s32);
extern void fn_1_49410(void);
extern void fn_1_494DC(s16);
extern void fn_1_4955C(f32, f32);
extern void fn_1_49590(f32);
extern void fn_1_495B0(u32);
extern void fn_1_495C8(void *);
extern void fn_1_4966C(f32, f32);
extern void fn_1_496FC(f32, f32);
extern void fn_1_49738(void *);
extern void fn_1_49748(f32);
extern void fn_1_4A0D8(const char *);
extern void fn_1_4AE0C(const char *, ...);

void fn_1_1421D8(u32 arg0, u32 arg1) {
    u32 v8;
    Obj_1_bss_3C30 *p_lbl_1_bss_3C30;
    f32 v0;
    s32 v3;
    u32 v2;
    f32 v4;
    s32 v7;
    f32 v10;
    f32 v11;
    f32 v15;
    f32 t15;
    f32 t23;
    fn_1_49410();
    fn_1_494DC(8);
    fn_1_495B0(0x80000000);
    fn_1_49738(fn_1_5233C);
    fn_1_49748(0.0f);
    fn_1_495C8((void *)8);
    v0 = 0.9583333134651184f;
    fn_1_4955C(v0, v0);
    fn_1_496FC((s32)arg0, (s32)arg1);
    fn_1_4AE0C((const char *)&lbl_1_data_42478);
    p_lbl_1_bss_3C30 = &lbl_1_bss_3C30;
    v2 = ((u32 *)lbl_1_data_2AA24)[((u8 *)&lbl_1_data_2B0D4)[p_lbl_1_bss_3C30->unk_6]];
    v3 = arg0;
    v3 += 23.0f;
    fn_1_4966C(2.0f, 0.0f);
    v4 = 0.6666666865348816f;
    fn_1_4955C(v4, v4);
    fn_1_496FC(v3, (s32)arg1);
    fn_1_495B0(0x80000000);
    fn_1_49590(0.5f);
    fn_1_4A0D8((const char *)v2);
    t15 = fn_1_4B068(v2);
    v3 += t15;
    v3 += 14;
    v7 = p_lbl_1_bss_3C30->unk_6 * 24;
    v8 = ((u32 (*)[6])lbl_1_data_2BD54)[p_lbl_1_bss_3C30->unk_6][lbl_801A66B4];
    fn_1_494DC(42);
    v10 = 0.0f;
    fn_1_4966C(v10, v10);
    v11 = 0.5833333134651184f;
    fn_1_4955C(v11, v11);
    fn_1_496FC(v3, (s32)arg1);
    fn_1_495B0(0x80000000);
    fn_1_49590(0.5f);
    fn_1_4A0D8((const char *)v8);
    t23 = fn_1_4B068(v8);
    v3 += t23;
    fn_1_494DC(8);
    v15 = 0.9583333134651184f;
    fn_1_4955C(v15, v15);
    fn_1_496FC(v3, (s32)arg1);
    fn_1_4AE0C((const char *)&lbl_1_data_4247C);
    v3 += 23.0f;
    fn_1_13D460(v3, arg1 + 8, 596 - v3, 0);
}
/* fzgx:end fn_1_1421D8 */

/* fzgx:begin fn_1_1424E8 */
void fn_1_1424E8(u32 unused, s32 arg1) {
    FontDrawPacket loc_8;
    s32 mode;

    if (lbl_1_bss_3C30.unk_0 & 0x04000000) {
        mode = 7;
    } else {
        switch (lbl_1_bss_3C30.unk_5) {
        case 1:
            switch (lbl_1_bss_3C30.unk_A6) {
            case 1: mode = 0; break;
            case 2: mode = 1; break;
            case 3: mode = 2; break;
            case 4: mode = 3; break;
            case 5: mode = 4; break;
            default: mode = 0; break;
            }
            break;
        case 0:
        case 6:
            mode = 5;
            break;
        case 2:
            mode = 6;
            break;
        default:
            mode = 7;
            break;
        }
    }

    loc_8 = *(FontDrawPacket *)&lbl_1_rodata_26F8;
    loc_8.image = 0x9901;
    fn_1_51564(0, 0, 0xA0, 0x10, 1, 8);
    fn_1_5158C(&loc_8, loc_8.image, 0, mode);
    loc_8.x = lbl_1_rodata_93F0[0];
    loc_8.y = (arg1 - 8);
    loc_8.flags = 7;
    fn_1_4F734(&loc_8);
}
/* fzgx:end fn_1_1424E8 */

/* fzgx:begin fn_1_142BDC noprologue */
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
    u32 v6 = arg0;
    u32 arg0_local = arg0;
    s32 v7;
    s32 v9;
    s32 v13;
    s32 v12;
    s32 v15;
    u32 v18;
    u32 v23;
    f32 v25;
    u32 v36;
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
            fn_1_496FC((s32)v6, v7);
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
            v40 = (s32)(v6 - 4);
            v41 = (v7 + 8);
            loc_18.x = v40;
            loc_18.y = v41;
            loc_18.z = (5.0f);
            fn_1_5158C((FontDrawPacket *)&loc_18, loc_18.image,
                       ((s32)v18 % 2),
                       ((v18 >> 1) & 0x7F));
            fn_1_4F734((FontDrawPacket *)&loc_18);
            loc_18 = *(FontDrawPacket *)&lbl_1_rodata_26F8;
            v23 = 0x9730;
            loc_18.image = v23;
            fn_1_51678((FontDrawPacket *)&loc_18, v23, 116, 0, 44, 32);
            v25 = (s32)(v6 + 26);
            loc_18.x = v25;
            loc_18.y = (v7 + 6);
            fn_1_4F734((FontDrawPacket *)&loc_18);
        } else {
            fn_1_49410();
            fn_1_494DC(19);
            fn_1_4966C((-6.0f), (0.0f));
            fn_1_4954C((5.0f));
            fn_1_496FC((s32)arg0_local, (s32)arg1);
            sprintf((char *)&loc_8, (const char *)&lbl_1_data_42488, (t0 + 1));
            fn_1_4A0D8((const char *)&loc_8);
            t27 = fn_1_4B068((s32)&loc_8);
            v9 = t0 + 1;
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
            loc_18.x = (s32)v6 + t27 - 4.0f;
            loc_18.y = (s32)(arg1 + 7);
            loc_18.z = 5.0f;
            fn_1_5158C((FontDrawPacket *)&loc_18, loc_18.image,
                       ((s32)v36 % 2),
                       ((v36 >> 1) & 0x7F));
            fn_1_4F734((FontDrawPacket *)&loc_18);
        }
    }
}
/* fzgx:end fn_1_142BDC */

/* fzgx:begin fn_1_14328C */
typedef struct {
    u32 v[8];
} Word8_fn_1_14328C;

typedef struct {
    u8 pad0[0x4];
    f32 unk_4;
    f32 unk_8;
    f32 unk_C;
    f32 unk_10;
    f32 unk_14;
    u8 pad18[0x18];
    s32 unk_30;
    u8 pad34[0x24];
} Sp8_fn_1_14328C;

typedef struct {
    u32 value[22];
} Fn139F18Data_fn_1_14328C;

typedef struct StaticDispParams_fn_1_14328C {
    s32 id;
    f32 x;
    f32 y;
    f32 z;
    u32 unk1[8];
    s32 count;
    u32 unk2[9];
} StaticDispParams_fn_1_14328C;

struct Struct_26F8_fn_1_14328C {
    u32 unk00;
    f32 unk04;
    f32 unk08;
    f32 unk0C;
    u8 pad10[0x1C];
    f32 unk2C;
    u32 unk30;
    u8 pad34[4];
    u32 unk38;
    u8 pad3C[0x1C];
};

typedef struct {
    const char *p[9];
} PtrTab_fn_1_14328C;

struct fn_1_13F8C4_lbl_801A6410_fn_1_14328C {
    u32 unk_0;
};

struct fn_1_149C64_lbl_1_bss_8E43C_fn_1_14328C {
    u32 unk_0;
};

struct fn_1_149C64_lbl_1_bss_8E440_fn_1_14328C {
    u32 unk_0;
};

typedef struct {
    s16 indices[2];
    u8 pad8[4];
    u32 flags;
} Source_fn_1_14328C;

typedef struct {
    s16 index;
    u8 pad2[0x1e];
    char text[0x320];
    void *object;
    void *handle[4];
} Display_fn_1_14328C;

struct Sig_fn_80071718_fn_80071718_Arg0_fn_1_14328C {
    u8 pad_0[0xC];
    u32 unk_C;
};

struct Sig_fn_800711A8_fn_800711A8_Entry_fn_1_14328C {
    u8 pad_00[0x24];
    void *field_24;
};

struct Sig_fn_800711A8_fn_800711A8_Arg0_fn_1_14328C {
    s32 count;
    u8 pad_04[4];
    struct Sig_fn_800711A8_fn_800711A8_Entry_fn_1_14328C **entries;
    u8 pad_0C[4];
    u32 field_10;
    void *field_14;
};

typedef struct {
    u8 data[4];
    f32 value;
    u8 tail[8];
} Fn1_14E9E4Entry_fn_1_14328C;

typedef struct fn_1_150C8C_Entry_fn_1_14328C {
    u8 pad[0x68];
    u32 active;
    u8 tail[0x40];
} fn_1_150C8C_Entry_fn_1_14328C;

typedef struct fn_1_150C8C_Object_fn_1_14328C {
    u8 pad_84[0x84];
    s32 count;
    fn_1_150C8C_Entry_fn_1_14328C entries[1];
} fn_1_150C8C_Object_fn_1_14328C;

typedef struct fn_1_150F30_StaticDisp_fn_1_14328C {
    u8 pad_2728[0x2728];
    s32 unk_2728;
    s32 unk_272c;
} fn_1_150F30_StaticDisp_fn_1_14328C;

typedef struct Fn14E09CValue_fn_1_14328C {
    void *value;
} Fn14E09CValue_fn_1_14328C;

typedef struct Fn14E09CRef_fn_1_14328C {
    u8 pad8[8];
    Fn14E09CValue_fn_1_14328C *value;
} Fn14E09CRef_fn_1_14328C;

typedef struct Fn14E09CObj_fn_1_14328C {
    u8 pad344[0x344];
    Fn14E09CRef_fn_1_14328C *ref;
} Fn14E09CObj_fn_1_14328C;

typedef struct DispNode_fn_1_14328C {
    u8 pad[4];
    f32 value;
} DispNode_fn_1_14328C;

typedef struct DispChildList_fn_1_14328C {
    DispNode_fn_1_14328C *child[3];
} DispChildList_fn_1_14328C;

typedef struct DispObject_fn_1_14328C {
    u32 flags;
    u8 pad0[12];
    f32 value;
    u8 pad1[32];
    DispChildList_fn_1_14328C *children;
} DispObject_fn_1_14328C;

typedef struct fn_1_151668_StaticDispEntry_fn_1_14328C {
    f32 first;
    u8 pad0[0x18];
    f32 values[3];
    DispObject_fn_1_14328C *object;
    u8 active;
    u8 scale_first;
    u8 scale_second;
    u8 clear_flag;
    u8 pad2[0x0c];
} fn_1_151668_StaticDispEntry_fn_1_14328C;

typedef struct fn_1_151668_StaticDisp_fn_1_14328C {
    u8 pad0[0x1830];
    fn_1_151668_StaticDispEntry_fn_1_14328C entries[63];
    u8 pad1[0x30];
    s32 entry_count;
    s32 value_2728;
    s32 value_272c;
} fn_1_151668_StaticDisp_fn_1_14328C;
extern void OSPanic(const char *file, int line, const char *msg, ...);
extern u32 __cvt_fp2unsigned(f32);
extern int sprintf(char *s, const char *format, ...);
extern size_t strlen(const char *str);
extern void qsort(void *arg0, u32 arg1, s32 arg2, void *callback);


struct fn_1_14328C_Copy88 { u32 a[22]; };
struct fn_1_14328C_lbl_1_bss_26B04 {
    u8 unk_0[1];
};

extern u8 lbl_1_bss_26B04[20];
extern const f32 lbl_1_rodata_9474;
extern const f32 lbl_1_rodata_9478;

void fn_1_14328C(u32 arg0, u32 arg1, u32 arg2) {
    s32 v0;
    s32 v5;
    s32 j;
    s32 i;
    s32 v6;
    struct fn_1_14328C_Copy88 packet;
    v0 = lbl_1_bss_26B04[arg2];
    v6 = v0 % 10;
    v5 = v0 / 10;
    packet = *(struct fn_1_14328C_Copy88 *)lbl_1_rodata_26F8;
    *(f32 *)&packet.a[2] = (f32)(s32)arg1;
    if (v6 >= 6) {
        for (i = 6; i <= v6; i++) {
            packet = *(struct fn_1_14328C_Copy88 *)lbl_1_rodata_26F8;
            packet.a[0] = 0x9713;
            *(f32 *)&packet.a[1] = (f32)(s32)arg0 - (f32)((f32)((i - 1) % 5) * lbl_1_rodata_9474);
            *(f32 *)&packet.a[2] = (f32)(s32)arg1;
            packet.a[12] = 15;
            *(f32 *)&packet.a[4] *= lbl_1_rodata_9474 / (f32)fn_1_48690(packet.a[0]);
            *(f32 *)&packet.a[5] *= lbl_1_rodata_9474 / (f32)fn_1_48690(packet.a[0]);
            fn_1_4F734((FontDrawPacket *)&packet);
        }
        arg1 = (s32)((s32)arg1 - lbl_1_rodata_9478);
    }
    if (v6 >= 1) {
        for (j = 1; j <= v6; j++) {
            packet = *(struct fn_1_14328C_Copy88 *)lbl_1_rodata_26F8;
            packet.a[0] = 0x9713;
            *(f32 *)&packet.a[1] = (f32)(s32)arg0 - (f32)((f32)((j - 1) % 5) * lbl_1_rodata_9474);
            *(f32 *)&packet.a[2] = (f32)(s32)arg1;
            packet.a[12] = 15;
            *(f32 *)&packet.a[4] *= lbl_1_rodata_9474 / (f32)fn_1_48690(packet.a[0]);
            *(f32 *)&packet.a[5] *= lbl_1_rodata_9474 / (f32)fn_1_48690(packet.a[0]);
            fn_1_4F734((FontDrawPacket *)&packet);
        }
        arg1 = (s32)((s32)arg1 - lbl_1_rodata_9478);
    }
    if (v5 >= 1) {
        for (i = 0; i < v5; i++) {
            packet = *(struct fn_1_14328C_Copy88 *)lbl_1_rodata_26F8;
            packet.a[0] = 0x9712;
            *(f32 *)&packet.a[1] = (f32)((s32)arg0 - i * 12);
            *(f32 *)&packet.a[2] = (f32)(s32)arg1;
            packet.a[12] = 15;
            *(f32 *)&packet.a[4] *= lbl_1_rodata_9474 / (f32)fn_1_48690(packet.a[0]);
            *(f32 *)&packet.a[5] *= lbl_1_rodata_9474 / (f32)fn_1_48690(packet.a[0]);
            fn_1_4F734((FontDrawPacket *)&packet);
        }
    }
}
/* fzgx:end fn_1_14328C */

/* fzgx:begin fn_1_143780 */
struct fn_1_143780_lbl_801A66A4 { s32 unk_0; };
struct fn_1_143780_entry { u32 unk_0; f32 unk_4; u8 unk_8, unk_9; u16 unk_A; };
struct fn_1_143780_view { u8 pad_0[0x16C]; struct fn_1_143780_entry entries[10]; };

typedef struct fn_1_143780_Color { u8 c[4]; } Color;
extern f32 lbl_8006D188(u32);
extern u32 fn_1_144A5C(void *);
extern u8 fn_1_3F114(void);
extern void fn_1_143E7C(u32, u32, u32, u32, u32, u32, void *);

#pragma section code_type ".fzgxpool"
static void fzgx_pool_primer_a(void) {
    struct { u32 a[66]; } p = {{0,0,0,0x3dcccccd,0x3f800000,0x3f800000,0,0,0x3f800000,0x3f800000,0,0x3f800000,0x04000000,0,0xffffffff,0,0,0,0,0,0,0,0,0,0,0x3dcccccd,0x3f800000,0x3f800000,0,0,0x3f800000,0x3f800000,0,0x3f800000,0x04000000,0,0xffffffff,0,0,0,0,0,0,0,0,0,0,0x3dcccccd,0x3f800000,0x3f800000,0,0,0x3f800000,0x3f800000,0,0x3f800000,0x04000000,0,0xffffffff,0,0,0,0,0,0,0}};
    volatile f32 f; /* Preserve literal-pool primer order. */
    volatile f64 d; /* Preserve conversion constants in the pool. */
    fn_1_144A5C(&p);
    f = 0.0f;
    f = 0.9583333134651184f;
    f = 23.0f;
    f = 2.0f;
    f = 0.6666666865348816f;
    f = 0.5f;
    f = 0.5833333134651184f;
    d = 4503601774854144.0;
    f = 596.0f;
    f = 528.0f;
}
static void fzgx_pool_primer_b(void) {
    struct { u32 a[11]; } p = {{0x1a,0x23,0x9c,0xa5,0x18,0x21,0x85,0x8e,0xf2,0xfb,3233857536U /* RGBA */}};
    volatile f32 f; /* Preserve literal-pool primer order. */
    volatile f64 d; /* Preserve conversion constants in the pool. */
    fn_1_144A5C(&p);
    f = -4.0f;
    f = 40.0f;
    f = 480.0f;
    f = 640.0f;
    f = 90000.0f;
    f = 0.3f;
    f = 0.7f;
    f = -1.0f;
    f = 208.0f;
    f = -1000.0f;
    f = -50.0f;
    f = 1.0f;
    f = 10.0f;
    f = 140.0f;
    f = 224.0f;
    f = 254.0f;
    f = 256.0f;
    f = -6.0f;
    f = 5.0f;
    f = 4.0f;
    f = 12.0f;
    f = 15.0f;
    d = 4503599627370496.0;
}
static void fzgx_pool_primer_c(void) {
    struct { u32 a[4]; } p = {{0x4e4f204e,0x414d4500,0x4e4f2044,0x41544100}};
    volatile f32 f; /* Preserve literal-pool primer order. */
    fn_1_144A5C(&p);
    f = 100.0f;
    f = 350.0f;
    f = 44.0f;
    f = 8.0f;
}
#pragma section code_type ".text"

static inline void draw_color(u32 a,u32 b,u32 c,u32 d,u32 e,u32 f,Color color) {
    fn_1_143E7C(a,b,c,d,e,f,&color);
}
static inline void set_color(Color color) {
    fn_1_49514((u32 *)&color);
}

#pragma opt_loop_invariants off
void fn_1_143780(u32 arg0, u32 arg1, u32 arg2) {
    u32 count;
    u32 y1;
    u32 y0;
    s32 last;
    struct fn_1_143780_entry *cur;
    s32 i;
    Obj_1_bss_26314 *obj;
    struct fn_1_143780_entry *e;
    u32 image;
    f32 scale;
    s32 frame;
    s32 rem;
    u32 a0, b0, a1, b1, a2, b2;
    f32 one;
    f32 t;
    Color loc_40;
    Color loc_3C;
    Color loc_38;
    Color loc_34;
    Color loc_30;
    Color loc_2C;
    Color loc_28;
    Color loc_24;
    Color loc_10;
    Color loc_C;
    Color loc_8;
    struct { u32 a[10]; } loc_6C;
    FontDrawPacket loc_94;
    loc_10 = (Color){{255,255,255,255}};
    loc_40 = loc_2C = loc_10;
    loc_C = (Color){{0,240,230,255}};
    loc_3C = loc_28 = loc_C;
    loc_38 = (Color){{0,120,115,255}};
    loc_8 = (Color){{160,255,0,255}};
    loc_34 = loc_24 = loc_8;
    {
    struct { u32 a[4]; } loc_44 = {{26, 35, 316, 325}};
    struct { u32 a[6]; } loc_54 = {{24, 33, 101, 110, 178, 187}};
    loc_6C.a[0] = arg0;
    loc_6C.a[1] = arg1;
    loc_6C.a[2] = 354;
    loc_6C.a[3] = 222;
    loc_6C.a[4] = 340;
    loc_6C.a[5] = 208;
    loc_6C.a[6] = (u32)&loc_44;
    loc_6C.a[7] = 4;
    loc_6C.a[8] = (u32)&loc_54;
    loc_6C.a[9] = 6;
    fn_1_144A5C(&loc_6C);
    loc_94 = *(FontDrawPacket *)lbl_1_rodata_26F8;
    image = 0x9903;
    loc_94.image = image;
    fn_1_51678(&loc_94, image, 0, 108, 96, 36);
    loc_94.x = (s32)(arg0 + 22);
    loc_94.y = (s32)(arg1 + 179);
    loc_94.z = 30.0f;
    loc_94.scale_x *= 0.75f;
    loc_94.scale_y *= 0.75f;
    fn_1_4F734(&loc_94);
    obj = (Obj_1_bss_26314 *)((u8 *)&lbl_1_bss_26314 + arg2 * 508);
    count = fn_1_3F114() & 0xFF;
    if (count <= 5) {
        y1 = arg1 + 18;
        y0 = arg1 + 16;
        last = count - 1;
        for (i = 0; i < (s32)count; i++) {
            if (i < 5) {
                e = &((struct fn_1_143780_view *)obj)->entries[last - i];
                if (e->unk_0 == obj->unk_1CC && e->unk_4 == obj->unk_1D0) {
                    loc_30 = loc_34;
                } else {
                    loc_30 = loc_40;
                }
                draw_color(arg0 + 332, y1, arg2, e->unk_8, e->unk_9, e->unk_A, loc_30);
                loc_94 = *(FontDrawPacket *)lbl_1_rodata_26F8;
                image = 0x9903;
                loc_94.image = image;
                fn_1_51678(&loc_94, image, 0, 36, 96, 36);
                loc_94.x = ((s32)arg0 + 22);
                loc_94.y = (s32)y0;
                loc_94.z = 30.0f;
                loc_94.scale_x *= 0.75f;
                loc_94.scale_y *= 0.75f;
                *(Color *)loc_94.color = loc_30;
                fn_1_4F734(&loc_94);
                fn_1_49410();
                fn_1_494DC(19);
                fn_1_496FC((s32)(arg0 + 80), (s32)y1);
                set_color(loc_30);
                scale = 0.75f;
                fn_1_4955C(scale, scale);
                fn_1_4AE0C((const char *)lbl_1_data_424A0, i + 1);
            }
            y1 += 32;
            y0 += 32;
        }
    } else {
        cur = &((struct fn_1_143780_view *)obj)->entries[8];
        loc_94 = *(FontDrawPacket *)lbl_1_rodata_26F8;
        image = 0x9900;
        loc_94.image = image;
        loc_94.x = ((s32)arg0 + 22);
        loc_94.y = ((s32)arg1 + 7);
        loc_94.z = 30.0f;
        fn_1_4F734(&loc_94);
        draw_color(arg0 + 332, arg1 + 18, arg2, cur->unk_8, cur->unk_9, cur->unk_A, loc_24);
    }
    e = (struct fn_1_143780_entry *)((u32)obj + 0x1d8);
    draw_color(arg0 + 332, arg1 + 179, arg2, e->unk_8, e->unk_9, e->unk_A, loc_2C);
    loc_94 = *(FontDrawPacket *)lbl_1_rodata_26F8;
    loc_94.image = 18;
    loc_94.x = ((s32)arg0 + 1);
    loc_94.y = ((s32)arg1 + 176);
    loc_94.z = 54.0f;
    *(Color *)loc_94.color = loc_28;
    loc_94.scale_x *= 343.0f / fn_1_48690(18);
    loc_94.scale_y *= 30.0f / fn_1_486C4(loc_94.image);
    frame = ((struct fn_1_143780_lbl_801A66A4 *)&lbl_801A66A4)->unk_0;
    scale = 65536.0f;
    rem = frame % 120;
    scale = (f32)(scale * rem);
    one = 1.0f;
    t = (one + lbl_8006D188((s32)(scale / 120.0f))) / 2.0f;
    loc_94.color[0] = (loc_3C.c[0] * (one - t)) + (loc_38.c[0] * t);
    loc_94.color[1] = (loc_3C.c[1] * (one - t)) + (loc_38.c[1] * t);
    loc_94.color[2] = (loc_3C.c[2] * (one - t)) + (loc_38.c[2] * t);
    loc_94.alpha = 0.35f;
    fn_1_4F734(&loc_94);
    }
}
/* fzgx:end fn_1_143780 */

/* fzgx:begin fn_1_143E7C noprologue */
#include "types.h"

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
    s = 15.0f;
}
static const u32 fzgx_pool_table11[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep11(void) { const u32 *volatile cp; cp = fzgx_pool_table11; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime12(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 4503599627370496.0;
}
static const u32 fzgx_pool_table13[1] = {0x4E4F204E};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep13(void) { const u32 *volatile cp; cp = fzgx_pool_table13; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime14(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 12.829345703125f;
}
static const u32 fzgx_pool_table15[1] = {0x4E4F2044};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep15(void) { const u32 *volatile cp; cp = fzgx_pool_table15; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime16(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 13.265869140625f;
    s = 100.0f;
    s = 350.0f;
    s = 44.0f;
    s = 8.0f;
}
static const u32 fzgx_pool_table17[14] = {0xFFFFFFFF, 0x00F0E6FF, 0x007873FF, 0xA0FF00FF, 0x0000001A, 0x00000023, 0x0000013C, 0x00000145, 0x00000018, 0x00000021, 0x00000065, 0x0000006E, 0x000000B2, 0x000000BB};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep17(void) { const u32 *volatile cp; cp = fzgx_pool_table17; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime18(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 30.0f;
    s = 0.75f;
    s = 54.0f;
    s = 343.0f;
    s = 65536.0f;
    s = 120.0f;
    s = 0.3499999940395355f;
}
static const u32 fzgx_pool_table19[25] = {0xFFFFFFFF, 0x00F0E6FF, 0x007873FF, 0xFFFF00FF, 0xFFFF00FF, 0x8080FFFF, 0x0000001A, 0x00000023, 0x0000013C, 0x00000145, 0x00000018, 0x00000021, 0x00000065, 0x0000006E, 0x000000B2, 0x000000BB, 0x19FF1900, 0x19FF1900, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep19(void) { const u32 *volatile cp; cp = fzgx_pool_table19; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime20(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 3.748046875f;
}
static const u32 fzgx_pool_table21[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep21(void) { const u32 *volatile cp; cp = fzgx_pool_table21; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime22(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 20.0f;
}
static const u32 fzgx_pool_table23[14] = {0x0000001A, 0x00000023, 0x0000013C, 0x00000145, 0xFFFFFF00, 0x19FF1900, 0x0000001A, 0x00000023, 0x0000013C, 0x00000145, 0x19FF1900, 0x00FFFFFF, 0x00FFFFFF, 0xFFFFFF00};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep23(void) { const u32 *volatile cp; cp = fzgx_pool_table23; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime24(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 0.800000011920929f;
    s = -2.0f;
}
static const u32 fzgx_pool_table25[1] = {0x0000001A};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep25(void) { const u32 *volatile cp; cp = fzgx_pool_table25; }  /* fzgx-allow: S2 pool primer sink */
#pragma section code_type ".text"

extern void fn_1_49410(void);
extern void fn_1_494DC(int arg0);
extern void fn_1_495B0(u32 arg0);
extern void fn_1_495C8(int arg0);
extern void fn_1_49514(void* arg0);
extern void fn_1_4966C(f32 arg0, f32 arg1);
extern void fn_1_4955C(f32 arg0, f32 arg1);
extern void fn_1_496FC(f32 arg0, f32 arg1);
extern u8 lbl_1_data_424AC[32];
extern void fn_1_4AE0C(u8* arg0, ...);

void fn_1_143E7C(u32 arg0, u32 arg1, u32 arg2, u32 arg3, u32 arg4, u32 arg5, void* arg6) {
    u32 local;
    f32 value;

    fn_1_49410();
    fn_1_494DC(0x13);
    fn_1_495B0((u32)0x8000 << 16);
    fn_1_495C8(2);
    local = *(u32*)arg6;
    fn_1_49514(&local);
    fn_1_4966C(-2.0f, 0.0f);
    value = 0.75f;
    fn_1_4955C(value, value);
    fn_1_496FC((s32)arg0, (s32)arg1);
    fn_1_4AE0C(lbl_1_data_424AC, arg3 & 0xFF, arg4 & 0xFF, arg5 & 0xFFFF);
}
/* fzgx:end fn_1_143E7C */

/* fzgx:begin fn_1_143F5C noprologue */
#include "types.h"
#include "font.h"
#include "rel/main_rel/sel_static_disp.h"

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
    s = 15.0f;
}
static const u32 fzgx_pool_table11[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep11(void) { const u32 *volatile cp; cp = fzgx_pool_table11; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime12(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 4503599627370496.0;
}
static const u32 fzgx_pool_table13[1] = {0x4E4F204E};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep13(void) { const u32 *volatile cp; cp = fzgx_pool_table13; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime14(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 12.829345703125f;
}
static const u32 fzgx_pool_table15[1] = {0x4E4F2044};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep15(void) { const u32 *volatile cp; cp = fzgx_pool_table15; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime16(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 13.265869140625f;
    s = 100.0f;
    s = 350.0f;
    s = 44.0f;
    s = 8.0f;
}
static const u32 fzgx_pool_table17[14] = {0xFFFFFFFF, 0x00F0E6FF, 0x007873FF, 0xA0FF00FF, 0x0000001A, 0x00000023, 0x0000013C, 0x00000145, 0x00000018, 0x00000021, 0x00000065, 0x0000006E, 0x000000B2, 0x000000BB};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep17(void) { const u32 *volatile cp; cp = fzgx_pool_table17; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime18(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 30.0f;
    s = 0.75f;
    s = 54.0f;
    s = 343.0f;
    s = 65536.0f;
    s = 120.0f;
    s = 0.3499999940395355f;
}
static const u32 fzgx_pool_table19[25] = {0xFFFFFFFF, 0x00F0E6FF, 0x007873FF, 0xFFFF00FF, 0xFFFF00FF, 0x8080FFFF, 0x0000001A, 0x00000023, 0x0000013C, 0x00000145, 0x00000018, 0x00000021, 0x00000065, 0x0000006E, 0x000000B2, 0x000000BB, 0x19FF1900, 0x19FF1900, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep19(void) { const u32 *volatile cp; cp = fzgx_pool_table19; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime20(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 3.748046875f;
}
static const u32 fzgx_pool_table21[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep21(void) { const u32 *volatile cp; cp = fzgx_pool_table21; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime22(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 20.0f;
}
static const u32 fzgx_pool_table23[14] = {0x0000001A, 0x00000023, 0x0000013C, 0x00000145, 0xFFFFFF00, 0x19FF1900, 0x0000001A, 0x00000023, 0x0000013C, 0x00000145, 0x19FF1900, 0x00FFFFFF, 0x00FFFFFF, 0xFFFFFF00};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep23(void) { const u32 *volatile cp; cp = fzgx_pool_table23; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime24(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 0.800000011920929f;
    s = -2.0f;
}
#pragma section code_type ".text"

typedef struct fn_1_143F5C_Args {
    s32 x;
    s32 y;
    s32 w0;
    s32 h0;
    s32 w1;
    s32 h1;
    u32 *list0;
    s32 count0;
    u32 *list1;
    s32 count1;
} fn_1_143F5C_Args;

extern FontDrawPacket lbl_1_rodata_26F8;
extern f32 lbl_1_bss_26304[4];
extern u32 fn_1_144A5C(fn_1_143F5C_Args *args);
extern void fn_1_49410(void);
extern void fn_1_494DC(s16 index);
extern void fn_1_495B0(u32 value);
extern void fn_1_495C8(u8 value);
extern u16 fn_1_48690(u32 id);
extern void fn_1_496FC(f32 value1, f32 value2);
extern void fn_1_49514(u32 *value);
extern void fn_1_4955C(f32 value1, f32 value2);

void fn_1_143F5C(s32 x, s32 y, s32 idx) {
    u8 color[4];
    u32 colorCopy;
    u32 list0[4] = {0x1a, 0x23, 0x13c, 0x145};
    u32 list1[2] = {0x18, 0x21};
    fn_1_143F5C_Args args;
    FontDrawPacket packet;

    args.x = x;
    args.y = y;
    args.w0 = 0x162;
    args.h0 = 0x34;
    args.w1 = 0x154;
    args.h1 = 0x2a;
    args.list0 = list0;
    args.count0 = 4;
    args.list1 = list1;
    args.count1 = 2;
    fn_1_144A5C(&args);

    color[0] = 0xa0;
    color[1] = 0xff;
    color[2] = 0;
    color[3] = 0xff;

    packet = lbl_1_rodata_26F8;
    packet.image = 0x9903;
    fn_1_51678(&packet, 0x9903, 0, 0x90, 0x60, 0x24);
    packet.x = (x + 0x1a);
    packet.y = (y + 0xe);
    packet.z = 30.0f;
    packet.scale_x *= 0.75f;
    packet.scale_y *= 0.75f;
    fn_1_4F734(&packet);

    fn_1_49410();
    fn_1_494DC(0x13);
    fn_1_495B0(0x80000000);
    fn_1_495C8(2);
    fn_1_496FC((x + 0x14c - fn_1_48690(0x9904)), (y + 0x10));
    colorCopy = *(u32 *)color;
    fn_1_49514(&colorCopy);
    fn_1_4955C(0.75f, 0.75f);
    fn_1_4AE0C((const char *)&lbl_1_data_424CC, (s32)lbl_1_bss_26304[idx]);

    packet = lbl_1_rodata_26F8;
    packet.image = 0x9904;
    packet.x = (x + 0x14c);
    packet.y = (y + 0x17);
    packet.z = 30.0f;
    packet.flags = 7;
    packet.scale_x *= 0.75f;
    packet.scale_y *= 0.75f;
    fn_1_4F734(&packet);
}
/* fzgx:end fn_1_143F5C */

/* fzgx:begin fn_1_144A5C */
#pragma section code_type ".fzgxpool"
static const u32 fzgx_pool_rodata_92C0[74] = {0x00000000, 0x00000000, 0x00000000, 0x3DCCCCCD, 0x3F800000, 0x3F800000, 0x00000000, 0x00000000, 0x3F800000, 0x3F800000, 0x00000000, 0x3F800000, 0x04000000, 0x00000000, 0xFFFFFFFF, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x3DCCCCCD, 0x3F800000, 0x3F800000, 0x00000000, 0x00000000, 0x3F800000, 0x3F800000, 0x00000000, 0x3F800000, 0x04000000, 0x00000000, 0xFFFFFFFF, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x3DCCCCCD, 0x3F800000, 0x3F800000, 0x00000000, 0x00000000, 0x3F800000, 0x3F800000, 0x00000000, 0x3F800000, 0x04000000, 0x00000000, 0xFFFFFFFF, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x3F755555, 0x41B80000, 0x40000000, 0x3F2AAAAB, 0x3F000000, 0x3F155555, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep_92C0(void) { const u32 *volatile cp; cp = fzgx_pool_rodata_92C0; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime_93E8(void) {
    volatile f64 d;  /* fzgx-allow: S2 pool primer sink */
    d = 4503601774854144.0;
}
static const u32 fzgx_pool_rodata_93F0[182] = {0x44150000, 0x44040000, 0x0000001A, 0x00000023, 0x0000009C, 0x000000A5, 0x00000018, 0x00000021, 0x00000085, 0x0000008E, 0x000000F2, 0x000000FB, 0xC0C0C000, 0xC0800000, 0x42200000, 0x43F00000, 0x44200000, 0x47AFC800, 0x3E99999A, 0x3F333333, 0xBF800000, 0x43500000, 0xC47A0000, 0xC2480000, 0x3F800000, 0x41200000, 0x430C0000, 0x43600000, 0x437E0000, 0x43800000, 0xC0C00000, 0x40A00000, 0x40800000, 0x41400000, 0x41700000, 0x00000000, 0x43300000, 0x00000000, 0x4E4F204E, 0x414D4500, 0x4E4F2044, 0x41544100, 0x42C80000, 0x43AF0000, 0x42300000, 0x41000000, 0xFFFFFFFF, 0x00F0E6FF, 0x007873FF, 0xA0FF00FF, 0x0000001A, 0x00000023, 0x0000013C, 0x00000145, 0x00000018, 0x00000021, 0x00000065, 0x0000006E, 0x000000B2, 0x000000BB, 0x41F00000, 0x3F400000, 0x42580000, 0x43AB8000, 0x47800000, 0x42F00000, 0x3EB33333, 0xFFFFFFFF, 0x00F0E6FF, 0x007873FF, 0xFFFF00FF, 0xFFFF00FF, 0x8080FFFF, 0x0000001A, 0x00000023, 0x0000013C, 0x00000145, 0x00000018, 0x00000021, 0x00000065, 0x0000006E, 0x000000B2, 0x000000BB, 0x19FF1900, 0x19FF1900, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x406FE000, 0x00000000, 0x41A00000, 0x0000001A, 0x00000023, 0x0000013C, 0x00000145, 0xFFFFFF00, 0x19FF1900, 0x0000001A, 0x00000023, 0x0000013C, 0x00000145, 0x19FF1900, 0x00FFFFFF, 0x00FFFFFF, 0xFFFFFF00, 0x3F4CCCCD, 0xC0000000, 0x0000001A, 0x00000023, 0x0000013C, 0x00000145, 0x00000018, 0x00000021, 0x0000001A, 0x00000023, 0x0000013C, 0x00000145, 0x00000018, 0x00000021, 0xFFFF00FF, 0x19FF1900, 0x00000000, 0x0000001A, 0x00000023, 0x0000013C, 0x00000145, 0x19FF1900, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x42880000, 0x42AC0000, 0x3EC00000, 0x42A00000, 0x41600000, 0x41A80000, 0x3F8CCCCD, 0x43C78000, 0x440F8000, 0x3F59999A, 0x43FF0000, 0x19FF1900, 0x19FF1900, 0xF4962800, 0xF4962800, 0xFFFF0000, 0x00000000, 0xFFFFFF00, 0xF4962800, 0xF4962800, 0xFFFF0000, 0x00000000, 0xFFFFFF00, 0xF4962800, 0xFFFF00FF, 0x00000000, 0x19FF1900, 0x19FF1900, 0xF4962800, 0xF4962800, 0x8080FF00, 0x00000000, 0xFFFFFF00, 0xF4962800, 0xF4962800, 0x8080FF00, 0x00000000, 0xFFFFFF00, 0x43B10000, 0x42A80000, 0x41B00000, 0x3F266666, 0x43400000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep_93F0(void) { const u32 *volatile cp; cp = fzgx_pool_rodata_93F0; }  /* fzgx-allow: S2 pool primer sink */
#pragma section code_type ".text"

typedef struct fn_1_144A5C_Args {
    s32 x;
    s32 y;
    s32 w0;
    s32 h0;
    s32 w1;
    s32 h1;
} fn_1_144A5C_Args;

extern void fn_1_50A90(FontDrawPacket *packet, u32 arg1, u32 arg2, u32 arg3, u32 arg4);
extern void fn_1_508C4(FontDrawPacket *packet, f32 dx, f32 dy);

void fn_1_144A5C(const fn_1_144A5C_Args *args) {
    FontDrawPacket packet;

    packet = (*(FontDrawPacket *)&lbl_1_rodata_26F8);
    packet.image = 0x970C;
    packet.x = args->x;
    packet.y = args->y;
    packet.z = 48.0f;
    fn_1_50A90(&packet, 0x28, 0x10, args->w0, args->h0);
    if (args->h0 > 0x38) {
        packet = (*(FontDrawPacket *)&lbl_1_rodata_26F8);
        packet.image = 0x970F;
        packet.z = 46.0f;
        packet.flags = 10;
        packet.x = (args->x + 5);
        packet.y = (args->y + 0x1C);
        fn_1_4F734(&packet);
        packet.x = (args->x + 5);
        packet.y = (args->y + args->h0 - 0x1C);
        fn_1_4F734(&packet);
        packet.x = (args->x + 5);
        packet.y = (args->y + args->h0 / 2);
        fn_1_4F734(&packet);
        packet.x = (args->x + args->w0 - 5);
        packet.y = (args->y + 0x1C);
        fn_1_4F734(&packet);
        packet.x = (args->x + args->w0 - 5);
        packet.y = (args->y + args->h0 - 0x1C);
        fn_1_4F734(&packet);
        packet.x = (args->x + args->w0 - 5);
        packet.y = (args->y + args->h0 / 2);
        fn_1_4F734(&packet);
    }
    packet = (*(FontDrawPacket *)&lbl_1_rodata_26F8);
    packet.image = 0x970D;
    packet.x = (args->x + (args->w0 - args->w1) / 2);
    packet.y = (args->y + (args->h0 - args->h1) / 2);
    packet.z = 55.0f;
    fn_1_508C4(&packet, args->w1, args->h1);
}
/* fzgx:end fn_1_144A5C */

/* fzgx:begin fn_1_144E90 */
void fn_1_144E90(void) {
    lbl_1_bss_8E428.unk_0 = (u32)&lbl_1_bss_3C30.unk_E;
    if (lbl_1_bss_8E51D == lbl_1_bss_8E524) {
        fn_1_144F40(0, 0);
    }
}
/* fzgx:end fn_1_144E90 */

/* fzgx:begin fn_1_144EE8 */
void fn_1_144EE8(void) {
    lbl_1_bss_8E428.unk_0 = (u32)((u8*)&lbl_1_bss_3C30 + 0x1394);
    if (lbl_1_bss_8E51D == lbl_1_bss_8E524) {
        fn_1_144F40(1, 0);
    }
}
/* fzgx:end fn_1_144EE8 */

/* fzgx:begin fn_1_145B58 noprologue */
#include "types.h"
#include "rel/main_rel/sel_static_disp.h"

extern u32 fn_1_155F7C(void);
extern u32 fn_1_155F8C(void);

static inline s32 fn_1_145B58_test(s32 arg0, s32 range, s32 one) {
    s32 d, c, b, a;
    b = one; c = one; d = one; a = one;
    if (range == 0) a = 0;
    if (a == 0 && arg0 != 9) d = 0;
    if (d == 0 && arg0 != 10) c = 0;
    if (c == 0 && arg0 != 6) b = 0;
    return b;
}

u32 fn_1_145B58(s32 arg0, s32 *arg1) {
    u32 r;
    if (arg0 == 10 || arg0 == 6) {
        return arg1[8] == 0;
    }
    if (fn_1_145B58_test(arg0, (u32)(arg0 - 4) <= 1, 1) != 0) {
        r = 0;
        if ((s32)fn_1_155F7C() != 0) {
            if (arg1[8] == (s32)fn_1_155F8C()) {
                r = 1;
            }
        }
        return r;
    }
    return lbl_1_bss_3C30.unk_8 > arg1[19];
}
/* fzgx:end fn_1_145B58 */

/* fzgx:begin fn_1_146550 */
/* one results row (layout shared with fn_1_144F40's Row) */
typedef struct {
    u8 pad_0[0x64];
    s32 unk_64;
    s32 unk_68;
    s32 unk_6C;
    s32 unk_70;
    s32 unk_74;
    s32 unk_78;
    FontDrawPacket packet[3]; /* 0x7C */
} fn_1_146550_Row;

extern const f32 lbl_1_rodata_9700[3];

static inline BOOL fn_1_146550_isC(s32 mode) {
    BOOL r = FALSE;
    if (mode == 1 || mode == 3) {
        r = TRUE;
    }
    return r;
}

#pragma opt_lifetimes off
void fn_1_146550(s32 mode, fn_1_146550_Row *__restrict row) {
    FontDrawPacket packet;
    FontDrawPacket sub;
    s32 j;
    s32 x;
    s32 n;
    s32 dx;
    s32 dx2;
    s32 i;

    packet = row->packet[0];
    packet.image = 0x9723;
    packet.x = (32 + row->unk_68 + row->unk_70);
    packet.y = row->unk_64;
    packet.z = lbl_1_rodata_9700[0];
    fn_1_51678(&packet, 0x9723, 0, 0, 18, 48);
    fn_1_4F734(&packet);

    packet = row->packet[1];
    packet.image = 0x9723;
    packet.x = (row->unk_74 + 590);
    packet.y = row->unk_64;
    packet.z = lbl_1_rodata_9700[0];
    fn_1_51678(&packet, 0x9723, 18, 0, 18, 48);
    fn_1_4F734(&packet);

    packet = row->packet[0];
    n = row->unk_70;
    x = row->unk_68;
    packet.image = 0x9709;
    packet.y = row->unk_64;
    packet.z = lbl_1_rodata_9700[0];
    for (i = 0, dx = 0; i < 3; i++, dx += 20) {
        packet.x = (50 + x + dx + n);
        fn_1_4F734(&packet);
    }

    packet = row->packet[1];
    packet.image = 0x9709;
    packet.y = row->unk_64;
    packet.z = lbl_1_rodata_9700[0];
    for (j = 3; j < 10; j++) {
        packet.x = (50 + row->unk_68 + j * 20 + row->unk_74);
        if (j == 9 && fn_1_146550_isC(mode)) {
            sub = packet;
            fn_1_51678(&sub, packet.image, 0, 0, 10, 48);
            fn_1_4F734(&sub);
        } else {
            fn_1_4F734(&packet);
        }
    }

    x = row->unk_74;
    for (n = 0, dx2 = 270; n < 5; n++, dx2 += 20) {
        packet.x = (x + dx2);
        fn_1_4F734(&packet);
    }
    x = row->unk_74;
    for (n = 0, dx2 = 390; n < 5; n++, dx2 += 20) {
        packet.x = (x + dx2);
        fn_1_4F734(&packet);
    }
    x = row->unk_74;
    for (n = 0, dx2 = 510; n < 4; n++, dx2 += 20) {
        packet.x = (x + dx2);
        fn_1_4F734(&packet);
    }

    packet = row->packet[1];
    packet.image = 0x970A;
    packet.x = (row->unk_74 + 250);
    packet.y = row->unk_64;
    packet.z = lbl_1_rodata_9700[0];
    fn_1_4F734(&packet);

    packet = row->packet[1];
    packet.image = 0x970A;
    packet.x = (row->unk_74 + 370);
    packet.y = row->unk_64;
    packet.z = lbl_1_rodata_9700[0];
    fn_1_4F734(&packet);

    packet = row->packet[1];
    packet.image = 0x970A;
    packet.x = (row->unk_74 + 490);
    packet.y = row->unk_64;
    packet.z = lbl_1_rodata_9700[0];
    fn_1_4F734(&packet);
}
#pragma opt_lifetimes reset
/* fzgx:end fn_1_146550 */

/* fzgx:begin fn_1_146B5C */
#pragma opt_propagation off
void fn_1_146B5C(u32 unused, u8 *arg1) {
    s32 pos;
    s32 c;
    s32 b;
    s32 a;
    s32 v;
    FontDrawPacket pkt;

    fn_1_51564(0, 0, 0x24, 0x28, 0xa, 4);

    pkt = *(FontDrawPacket *)lbl_1_rodata_92C0;

    v = *(s32 *)(arg1 + 0x20);
    a = *(s32 *)(arg1 + 0x68);
    b = *(s32 *)(arg1 + 0x70);
    c = *(s32 *)(arg1 + 0x64);
    pos = a + b;

    pkt.image = 0x973E;
    pkt.x = (pos + 0x37);
    pkt.y = (c + 4);
    pkt.z = lbl_1_rodata_970C[0];

    fn_1_5158C(&pkt, 0x973E, (v % 10), (v / 10));
    fn_1_4F734(&pkt);
}
#pragma opt_propagation reset
/* fzgx:end fn_1_146B5C */

/* fzgx:begin fn_1_147188 noprologue */
#include "types.h"
#include "rel/main_rel/globals.h"
#include "rel/main_rel/sel_static_disp.h"
#include "font.h"

/* local view of the results row this function reads (fn_1_144F40 builds the rows) */
typedef struct {
    u8 pad_0[0x20];
    s32 unk_20;
    u8 pad_24[0x28];
    s32 unk_4C;
    u8 pad_50[0x14];
    s32 unk_64;
    u8 pad_68[0x4];
    s32 unk_6C;
    u8 pad_70[0xBC];
    FontDrawPacket unk_12C;
} fn_1_147188_Row;

typedef struct {
    u8 r, g, b, a;
} fn_1_147188_Color;

extern void fn_1_51564(u16 first, u16 second, u16 third, u16 fourth, u16 fifth, u16 sixth);
extern void fn_1_5158C(FontDrawPacket *, u32, s16, s16);
extern s32 fn_1_155F7C(void);
extern s32 fn_1_155F8C(void);

/* retail .rodata (lbl_1_rodata_92C0) up to this function's own colours at 0x47C: the three font packet
 * templates (the badge copies the third, at 0xB0), the int-to-float constant (0x128) and 33.0f */
#pragma section code_type ".fzgxpool"
static const u32 fzgx_pool_rodata_0[44] = {0x00000000, 0x00000000, 0x00000000, 0x3DCCCCCD, 0x3F800000, 0x3F800000, 0x00000000, 0x00000000, 0x3F800000, 0x3F800000, 0x00000000, 0x3F800000, 0x04000000, 0x00000000, 0xFFFFFFFF, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x3DCCCCCD, 0x3F800000, 0x3F800000, 0x00000000, 0x00000000, 0x3F800000, 0x3F800000, 0x00000000, 0x3F800000, 0x04000000, 0x00000000, 0xFFFFFFFF, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep_0(void) { const u32 *volatile cp; cp = fzgx_pool_rodata_0; }  /* fzgx-allow: S2 pool primer sink */
static const u32 fzgx_pool_rodata_B0[30] = {0x00000000, 0x00000000, 0x00000000, 0x3DCCCCCD, 0x3F800000, 0x3F800000, 0x00000000, 0x00000000, 0x3F800000, 0x3F800000, 0x00000000, 0x3F800000, 0x04000000, 0x00000000, 0xFFFFFFFF, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x3F755555, 0x41B80000, 0x40000000, 0x3F2AAAAB, 0x3F000000, 0x3F155555, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep_B0(void) { const u32 *volatile cp; cp = fzgx_pool_rodata_B0; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime_128(s32 n) { volatile f32 s; s = (f32)n; }  /* fzgx-allow: S2 pool primer sink */
static const u32 fzgx_pool_rodata_130[193] = {0x44150000, 0x44040000, 0x0000001A, 0x00000023, 0x0000009C, 0x000000A5, 0x00000018, 0x00000021, 0x00000085, 0x0000008E, 0x000000F2, 0x000000FB, 0xC0C0C000, 0xC0800000, 0x42200000, 0x43F00000, 0x44200000, 0x47AFC800, 0x3E99999A, 0x3F333333, 0xBF800000, 0x43500000, 0xC47A0000, 0xC2480000, 0x3F800000, 0x41200000, 0x430C0000, 0x43600000, 0x437E0000, 0x43800000, 0xC0C00000, 0x40A00000, 0x40800000, 0x41400000, 0x41700000, 0x00000000, 0x43300000, 0x00000000, 0x4E4F204E, 0x414D4500, 0x4E4F2044, 0x41544100, 0x42C80000, 0x43AF0000, 0x42300000, 0x41000000, 0xFFFFFFFF, 0x00F0E6FF, 0x007873FF, 0xA0FF00FF, 0x0000001A, 0x00000023, 0x0000013C, 0x00000145, 0x00000018, 0x00000021, 0x00000065, 0x0000006E, 0x000000B2, 0x000000BB, 0x41F00000, 0x3F400000, 0x42580000, 0x43AB8000, 0x47800000, 0x42F00000, 0x3EB33333, 0xFFFFFFFF, 0x00F0E6FF, 0x007873FF, 0xFFFF00FF, 0xFFFF00FF, 0x8080FFFF, 0x0000001A, 0x00000023, 0x0000013C, 0x00000145, 0x00000018, 0x00000021, 0x00000065, 0x0000006E, 0x000000B2, 0x000000BB, 0x19FF1900, 0x19FF1900, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x406FE000, 0x00000000, 0x41A00000, 0x0000001A, 0x00000023, 0x0000013C, 0x00000145, 0xFFFFFF00, 0x19FF1900, 0x0000001A, 0x00000023, 0x0000013C, 0x00000145, 0x19FF1900, 0x00FFFFFF, 0x00FFFFFF, 0xFFFFFF00, 0x3F4CCCCD, 0xC0000000, 0x0000001A, 0x00000023, 0x0000013C, 0x00000145, 0x00000018, 0x00000021, 0x0000001A, 0x00000023, 0x0000013C, 0x00000145, 0x00000018, 0x00000021, 0xFFFF00FF, 0x19FF1900, 0x00000000, 0x0000001A, 0x00000023, 0x0000013C, 0x00000145, 0x19FF1900, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x42880000, 0x42AC0000, 0x3EC00000, 0x42A00000, 0x41600000, 0x41A80000, 0x3F8CCCCD, 0x43C78000, 0x440F8000, 0x3F59999A, 0x43FF0000, 0x19FF1900, 0x19FF1900, 0xF4962800, 0xF4962800, 0xFFFF0000, 0x00000000, 0xFFFFFF00, 0xF4962800, 0xF4962800, 0xFFFF0000, 0x00000000, 0xFFFFFF00, 0xF4962800, 0xFFFF00FF, 0x00000000, 0x19FF1900, 0x19FF1900, 0xF4962800, 0xF4962800, 0x8080FF00, 0x00000000, 0xFFFFFF00, 0xF4962800, 0xF4962800, 0x8080FF00, 0x00000000, 0xFFFFFF00, 0x43B10000, 0x42A80000, 0x41B00000, 0x3F266666, 0x43400000, 0x42400000, 0x42380000, 0x425C0000, 0xFADC82FF, 0x00000000, 0x441FC000, 0x43EF8000, 0x43A00000, 0x428C0000, 0x42E00000, 0x43F60000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep_130(void) { const u32 *volatile cp; cp = fzgx_pool_rodata_130; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime_434(void) { volatile f32 s; s = 33.0f; }  /* fzgx-allow: S2 pool primer sink */
static const u32 fzgx_pool_rodata_438[17] = {0x41980000, 0x41C00000, 0x42480000, 0x41E80000, 0x42900000, 0x423C0000, 0x00009736, 0x00009737, 0x00009738, 0x00009739, 0x0000973A, 0x0000973B, 0x0000973C, 0x0000973D, 0x42340000, 0x42280000, 0x42180000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep_438(void) { const u32 *volatile cp; cp = fzgx_pool_rodata_438; }  /* fzgx-allow: S2 pool primer sink */
/* the badge's colours (black, colour_add 0xC0 grey), retail's 8 bytes at 0x47C */
static const fn_1_147188_Color fzgx_pool_rodata_47C = {0, 0, 0, 0};
static const fn_1_147188_Color fzgx_pool_rodata_480 = {0xC0, 0xC0, 0xC0, 0};
#pragma section code_type ".text"

/* retail tests the mode as this chain of flags, each set to TRUE then cleared (as in fn_1_148738) */
static inline BOOL fn_1_147188_mode_8_9(s32 mode) {
    BOOL r = TRUE;
    if (!((u32)(mode - 8) <= 1)) r = FALSE;
    return r;
}
static inline BOOL fn_1_147188_mode_8_9_10(s32 mode) {
    BOOL r = TRUE;
    if (!fn_1_147188_mode_8_9(mode) && mode != 10) r = FALSE;
    return r;
}
static inline BOOL fn_1_147188_mode_4_5(s32 mode) {
    BOOL r = TRUE;
    if (!((u32)(mode - 4) <= 1)) r = FALSE;
    return r;
}
static inline BOOL fn_1_147188_mode_4_5_9(s32 mode) {
    BOOL r = TRUE;
    if (!fn_1_147188_mode_4_5(mode) && mode != 9) r = FALSE;
    return r;
}
static inline BOOL fn_1_147188_mode_4_5_9_10(s32 mode) {
    BOOL r = TRUE;
    if (!fn_1_147188_mode_4_5_9(mode) && mode != 10) r = FALSE;
    return r;
}
static inline BOOL fn_1_147188_mode_4_5_6_9_10(s32 mode) {
    BOOL r = TRUE;
    if (!fn_1_147188_mode_4_5_9_10(mode) && mode != 6) r = FALSE;
    return r;
}

void fn_1_147188(s32 mode, const fn_1_147188_Row *row) {
    FontDrawPacket packet;
    s32 show;
    show = FALSE;
    if (mode == 8 || mode == 2 || mode == 3) {
        show = TRUE;
    }
    if (!show) {
        return;
    }
    if (fn_1_147188_mode_8_9_10(mode)) {
        return;
    }
    packet = row->unk_12C;
    packet.image = 0x9907;
    packet.x = (row->unk_6C + 0x8A);
    packet.y = (row->unk_64 + 3);
    packet.z = 41.0f;
    fn_1_4F734(&packet);

    packet = *(const FontDrawPacket *)fzgx_pool_rodata_B0;
    if (mode == 10 || mode == 6) {
        show = row->unk_20 == 0;
    } else if (fn_1_147188_mode_4_5_6_9_10(mode)) {
        show = 0;
        if (fn_1_155F7C() != 0 && row->unk_20 == fn_1_155F8C()) {
            show = 1;
        }
    } else {
        show = lbl_1_bss_3C30.unk_8 > row->unk_4C;
    }
    if (show) {
        packet.image = 0x971E;
        fn_1_51564(0, 0, 0x18, 0x14, 2, 2);
        fn_1_5158C(&packet, packet.image, (row->unk_4C % 2), (row->unk_4C / 2));
    } else {
        packet.image = 0x971F;
        fn_1_51564(0, 0, 0x18, 0x14, 2, 2);
        fn_1_5158C(&packet, packet.image, (row->unk_20 % 2), (row->unk_20 / 2 % 2));
        if (lbl_1_bss_8E548 > 4) {
            *(fn_1_147188_Color *)packet.color = fzgx_pool_rodata_47C;
            *(fn_1_147188_Color *)packet.color_add = fzgx_pool_rodata_480;
        }
    }
    packet.x = (row->unk_6C + 0xA4);
    packet.y = (row->unk_64 + 0x15);
    packet.z = 33.0f;
    fn_1_4F734(&packet);
}
/* fzgx:end fn_1_147188 */

/* fzgx:begin fn_1_147508 noprologue */
#include "types.h"
#include "font.h"
#include "rel/main_rel/sel_static_disp.h"

/* Raw retail literal-pool bits. Volatile stores keep the shared-pool literals emitted. */
#pragma section code_type ".fzgxpool"
static const u32 fzgx_pool_table_0[71] = {
    0x00000000, 0x00000000, 0x00000000, 0x3DCCCCCD,
    0x3F800000, 0x3F800000, 0x00000000, 0x00000000,
    0x3F800000, 0x3F800000, 0x00000000, 0x3F800000,
    0x04000000, 0x00000000, 0xFFFFFFFF, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0 /* unused relocation addend */, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x3DCCCCCD, 0x3F800000, 0x3F800000,
    0x00000000, 0x00000000, 0x3F800000, 0x3F800000,
    0x00000000, 0x3F800000, 0x04000000, 0x00000000,
    0xFFFFFFFF, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0 /* unused relocation addend */, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x3DCCCCCD,
    0x3F800000, 0x3F800000, 0x00000000, 0x00000000,
    0x3F800000, 0x3F800000, 0x00000000, 0x3F800000,
    0x04000000, 0x00000000, 0xFFFFFFFF, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0 /* unused relocation addend */, 0x00000000, 0x00000000, 0x3F755555,
    0x41B80000, 0x40000000, 0x3F2AAAAB,
};

/* Volatile sink preserves the shared literal pool. */
void fzgx_pool_primer_11C(volatile f32 *out) { *out = 0.5f; }

static const u32 fzgx_pool_table_120[2] = {
    0x3F155555, 0x00000000,
};

/* Volatile sink preserves the shared literal pool. */
void fzgx_pool_primer_128(volatile f64 *out) { *out = 4503601774854144.0; }

static const u32 fzgx_pool_table_130[24] = {
    0x44150000, 0x44040000, 0x0000001A, 0x00000023,
    0x0000009C, 0x000000A5, 0x00000018, 0x00000021,
    0x00000085, 0x0000008E, 0x000000F2, 0x000000FB,
    3233857536U, 3229614080U, 0x42200000, 0x43F00000,
    0x44200000, 0x47AFC800, 0x3E99999A, 0x3F333333,
    0xBF800000, 0x43500000, 0xC47A0000, 0xC2480000,
};

/* Volatile sink preserves the shared literal pool. */
void fzgx_pool_primer_190(volatile f32 *out) { *out = 1.0f; }

static const u32 fzgx_pool_table_194[11] = {
    0x41200000, 0x430C0000, 0x43600000, 0x437E0000,
    0x43800000, 3233808384U, 0x40A00000, 0x40800000,
    0x41400000, 0x41700000, 0x00000000,
};

/* Volatile sink preserves the shared literal pool. */
void fzgx_pool_primer_1C0(volatile f64 *out) { *out = 4503599627370496.0; }

static const u32 fzgx_pool_table_1C8[26] = {
    0x4E4F204E, 0x414D4500, 0x4E4F2044, 0x41544100,
    0x42C80000, 0x43AF0000, 0x42300000, 0x41000000,
    0xFFFFFFFF, 0x00F0E6FF, 0x007873FF, 0xA0FF00FF,
    0x0000001A, 0x00000023, 0x0000013C, 0x00000145,
    0x00000018, 0x00000021, 0x00000065, 0x0000006E,
    0x000000B2, 0x000000BB, 0x41F00000, 0x3F400000,
    0x42580000, 0x43AB8000,
};

/* Volatile sink preserves the shared literal pool. */
void fzgx_pool_primer_230(volatile f32 *out) { *out = 65536.0f; }

static const u32 fzgx_pool_table_234[117] = {
    0x42F00000, 0x3EB33333, 0xFFFFFFFF, 0x00F0E6FF,
    0x007873FF, 0xFFFF00FF, 0xFFFF00FF, 2155937791U,
    0x0000001A, 0x00000023, 0x0000013C, 0x00000145,
    0x00000018, 0x00000021, 0x00000065, 0x0000006E,
    0x000000B2, 0x000000BB, 0x19FF1900, 0x19FF1900,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x406FE000,
    0x00000000, 0x41A00000, 0x0000001A, 0x00000023,
    0x0000013C, 0x00000145, 0xFFFFFF00, 0x19FF1900,
    0x0000001A, 0x00000023, 0x0000013C, 0x00000145,
    0x19FF1900, 0x00FFFFFF, 0x00FFFFFF, 0xFFFFFF00,
    0x3F4CCCCD, 3221225472U, 0x0000001A, 0x00000023,
    0x0000013C, 0x00000145, 0x00000018, 0x00000021,
    0x0000001A, 0x00000023, 0x0000013C, 0x00000145,
    0x00000018, 0x00000021, 0xFFFF00FF, 0x19FF1900,
    0x00000000, 0x0000001A, 0x00000023, 0x0000013C,
    0x00000145, 0x19FF1900, 0 /* unused relocation addend */, 0 /* unused relocation addend */,
    0 /* unused relocation addend */, 0 /* unused relocation addend */, 0 /* unused relocation addend */, 0 /* unused relocation addend */,
    0 /* unused relocation addend */, 0 /* unused relocation addend */, 0x42880000, 0x42AC0000,
    0x3EC00000, 0x42A00000, 0x41600000, 0x41A80000,
    0x3F8CCCCD, 0x43C78000, 0x440F8000, 0x3F59999A,
    0x43FF0000, 0x19FF1900, 0x19FF1900, 0xF4962800,
    0xF4962800, 0xFFFF0000, 0x00000000, 0xFFFFFF00,
    0xF4962800, 0xF4962800, 0xFFFF0000, 0x00000000,
    0xFFFFFF00, 0xF4962800, 0xFFFF00FF, 0x00000000,
    0x19FF1900, 0x19FF1900, 0xF4962800, 0xF4962800,
    2155937536U, 0x00000000, 0xFFFFFF00, 0xF4962800,
    0xF4962800, 2155937536U, 0x00000000, 0xFFFFFF00,
    0x43B10000, 0x42A80000, 0x41B00000, 0x3F266666,
    0x43400000,
};

/* Volatile sink preserves the shared literal pool. */
void fzgx_pool_primer_408(volatile f32 *out) { *out = 48.0f; }

static const u32 fzgx_pool_table_40C[16] = {
    0x42380000, 0x425C0000, 0xFADC82FF, 0x00000000,
    0x441FC000, 0x43EF8000, 0x43A00000, 0x428C0000,
    0x42E00000, 0x43F60000, 0x42040000, 0x41980000,
    0x41C00000, 0x42480000, 0x41E80000, 0x42900000,
};

/* Volatile sink preserves the shared literal pool. */
void fzgx_pool_primer_44C(volatile f32 *out) { *out = 47.0f; }

static const u32 fzgx_pool_table_450[14] = {
    0x00009736, 0x00009737, 0x00009738, 0x00009739,
    0x0000973A, 0x0000973B, 0x0000973C, 0x0000973D,
    0x42340000, 0x42280000, 0x42180000, 0x00000000,
    3233857536U, 0x42240000,
};

/* Volatile sink preserves the shared literal pool. */
void fzgx_pool_primer_488(volatile f32 *out) { *out = 255.0f; }

/* Volatile sink preserves the shared literal pool. */
void fzgx_pool_primer_48C(volatile f32 *out) { *out = 60.0f; }
#pragma section code_type ".text"

typedef struct fn_1_147508_Color {
    u8 r, g, b, a;
} fn_1_147508_Color;

typedef struct fn_1_147508_Entry {
    u8 pad_0[0x20];
    s32 unk_20;
    s32 unk_24;
    u8 pad_28[0xD];
    u8 unk_35;
    u8 pad_36;
    u8 unk_37;
    u8 unk_38;
    u8 unk_39;
    u8 pad_3A[0x12];
    s32 unk_4C;
    u8 pad_50[0x14];
    s32 unk_64;
    u8 pad_68[0xC];
    s32 unk_74;
    u8 pad_78[0x5C];
    FontDrawPacket packet;
} fn_1_147508_Entry;


extern f32 lbl_8006D188(s32);
extern s16 fn_1_12C930(s16);
extern s32 fn_8006FC1C(const char *, const char *);
extern s32 lbl_801A66A4;
extern char *fn_1_14FEAC(u8, u8, u8, char *, void *);
extern s32 fn_1_155F7C(void);
extern s32 fn_1_155F8C(void);

extern char *fn_1_7F49C(u8, void *, char *);
extern void fn_1_149C2C(void);
extern void fn_1_49410(void);
extern void fn_1_494DC(s16);
extern void fn_1_49514(fn_1_147508_Color);
extern void fn_1_4954C(f32);
extern void fn_1_49590(f32);
extern void fn_1_495B0(u32);
extern void fn_1_4962C(void);
extern void fn_1_496FC(f32, f32);
extern void fn_1_49738(void (*)(void));

#pragma opt_propagation off

static inline BOOL fn_1_147508_inRange(s32 m, s32 lo, s32 hi) {
    return m == lo || m == hi;
}

static inline BOOL fn_1_147508_isModeA(s32 m) {
    return fn_1_147508_inRange(m, 8, 9) || m == 10;
}

static inline BOOL fn_1_147508_isModeB2(s32 m) {
    return fn_1_147508_inRange(m, 4, 5) || m == 9;
}

static inline BOOL fn_1_147508_isModeB1(s32 m) {
    return fn_1_147508_isModeB2(m) || m == 10;
}

static inline BOOL fn_1_147508_isModeB(s32 m) {
    return fn_1_147508_isModeB1(m) || m == 6;
}

static inline BOOL fn_1_147508_isValidChar(u32 c) {
    BOOL valid = c <= 74;
    return valid;
}


#define IS_MODE_A(m) fn_1_147508_isModeA(m)
#define IS_MODE_B(m) fn_1_147508_isModeB(m)
#define IS_VALID_CHAR(c) fn_1_147508_isValidChar(c)

static inline void fn_1_147508_setPacket(FontDrawPacket *p, u32 image, f32 x, f32 y) {
    p->image = image;
    p->x = x;
    p->y = y;
    p->z = 48.0f;
}

void fn_1_147508(s32 mode, fn_1_147508_Entry *entry) {
    u32 x;
    u32 y;
    s32 show;
    f32 px, py;
    s32 iy, ix;
    u32 image;
    FontDrawPacket packet;
    fn_1_147508_Color color;
    char buf[0x100];

    x = entry->unk_74 + 160;
    y = entry->unk_64 + 37;
    if (IS_MODE_A(mode) || IS_MODE_B(mode)) {
        s32 packetIY, packetIX;
        u32 packetImage;
        packet = entry->packet;
        packetImage = 0x9724;
        packetIX = entry->unk_74 + 126;
        packetIY = entry->unk_64 + 32;
        fn_1_147508_setPacket(&packet, packetImage, packetIX, packetIY);
        fn_1_4F734(&packet);
    }
    if (!IS_MODE_B(mode)) {
        return;
    }
    fn_1_49410();
    fn_1_494DC(22);
    fn_1_495B0(0x80000000);
    fn_1_49738(fn_1_149C2C);
    fn_1_4954C(47.0f);
    fn_1_4962C();
    fn_1_49590(0.5f);
    fn_1_496FC(x, y);
    if (mode == 10 || mode == 6) {
        show = entry->unk_20 == 0;
    } else if (IS_MODE_B(mode)) {
        show = 0;
        if (fn_1_155F7C() != 0 && entry->unk_20 == fn_1_155F8C()) {
            show = 1;
        }
    } else {
        show = lbl_1_bss_3C30.unk_8 > entry->unk_4C;
    }
    if (show) {
        color.a = 255;
        color.b = 255;
        color.r = 255;
        px = 1.0f - lbl_8006D188((65536.0f * (lbl_801A66A4 % 60) / 60.0f));
        {
            f32 half = 0.5f;
            py = px * half;
        }
        color.g = 255.0f * py;
        fn_1_49514(color);
    }
    if (lbl_1_bss_8E52C != 0) {
        if (fn_8006FC1C(((char **)&lbl_1_data_212A8)[fn_1_12C930(entry->unk_24)], (char *)lbl_1_data_425C8)) {
            fn_1_4A0D8((char *)lbl_1_data_425D8);
        } else {
            fn_1_4A0D8(((char **)&lbl_1_data_212A8)[fn_1_12C930(entry->unk_24)]);
        }
    } else if (entry->unk_35 < 41) {
        fn_1_4A0D8(fn_1_7F49C(entry->unk_35, 0, buf));
    } else if (IS_VALID_CHAR(entry->unk_37) && IS_VALID_CHAR(entry->unk_38) && IS_VALID_CHAR(entry->unk_39)) {
        fn_1_4A0D8(fn_1_14FEAC(entry->unk_37, entry->unk_38, entry->unk_39, buf, 0));
    }
}
/* fzgx:end fn_1_147508 */

/* fzgx:begin fn_1_148444 noprologue */
#include "types.h"
#include "font.h"
#include "rel/main_rel/sel_static_disp.h"

extern void fn_1_49410(void);
extern void fn_1_494DC(s16);
extern void fn_1_149C2C(void);
extern void fn_1_49738(void *);
extern void fn_1_496FC(f32, f32);
extern void fn_1_4954C(f32);
extern void fn_1_495C8(s32);
extern f32 fn_1_4B068(char *);
extern u8 lbl_1_rodata_9318[208];
extern int sprintf(char *, const char *, ...);

typedef struct {
    u8 pad_0[0x56];
    u8 unk_56[6];
    s32 unk_5C;
    u8 pad_60[0x4];
    s32 unk_64;
    s32 unk_68;
    u8 pad_6C[0x8];
    s32 unk_74;
} fn_1_148444_Obj;

static inline BOOL fn_1_148444_isA(s32 mode) {
    BOOL r = FALSE;
    if (mode == 8 || mode == 2 || mode == 3) {
        r = TRUE;
    }
    return r;
}

static inline BOOL fn_1_148444_isB(s32 mode) {
    BOOL r = TRUE;
    if (!((u32)mode <= 1)) {
        r = FALSE;
    }
    return r;
}

static inline BOOL fn_1_148444_isC(s32 mode) {
    BOOL r = FALSE;
    if (mode == 1 || mode == 3) {
        r = TRUE;
    }
    return r;
}

void fn_1_148444(s32 mode, fn_1_148444_Obj *obj) {
    s32 x;
    s32 y;
    s32 value;
    s32 width;
    FontDrawPacket packet;
    char buf[0x100];

    if (!fn_1_148444_isA(mode) && !fn_1_148444_isB(mode)) {
        return;
    }
    if (!fn_1_148444_isC(mode)) {
        return;
    }
    if (obj->unk_5C == 0xFF) {
        return;
    }
    x = obj->unk_68 + obj->unk_74;
    y = obj->unk_64 + 14;
    x += 0x1A7;
    if (mode == 3) {
        x -= 10;
    }
    fn_1_49410();
    fn_1_494DC(0x1B);
    fn_1_49738(fn_1_149C2C);
    fn_1_496FC(x, y);
    fn_1_4954C(47.0f);
    fn_1_495C8(2);
    if (fn_1_148444_isB(mode)) {
        value = obj->unk_56[lbl_1_bss_3C30.unk_A7];
    } else {
        value = obj->unk_56[0];
    }
    if (fn_1_148444_isA(mode)) {
        sprintf(buf, (const char *)&lbl_1_data_42808, value < 0 ? 0 : (value > 99 ? 99 : value));
    } else {
        sprintf(buf, (const char *)lbl_1_data_42810, value < 0 ? 0 : (value > 999 ? 999 : value));
    }
    fn_1_4A0D8(buf);
    width = fn_1_4B068(buf);
    packet = *(FontDrawPacket *)lbl_1_rodata_9318;
    packet.image = 0x9905;
    fn_1_51678(&packet, 0x9905, 100, 0, 10, 16);
    packet.x = (x - width);
    packet.y = y;
    packet.z = 47.0f;
    packet.flags |= 7;
    fn_1_4F734(&packet);
}
/* fzgx:end fn_1_148444 */

/* fzgx:begin fn_1_148738 */
/* local view of the results row this function reads (fn_1_144F40 builds the rows) */
typedef struct {
    u8 pad_0[0x36];
    u8 unk_36;
    u8 pad_37[0x2D];
    s32 unk_64;
    s32 unk_68;
    u8 pad_6C[0x8];
    s32 unk_74;
} fn_1_148738_Row;

extern u16 fn_1_48690(u32);

/* retail .rodata (lbl_1_rodata_92C0) up to this function's constants, so the font packet template (0x58), the
 * int-to-float constants (0x128 signed, 0x1C0 unsigned) and 100.0f, 46.0f, 45.0f land at their retail offsets */
#pragma section code_type ".fzgxpool"
static const u32 fzgx_pool_rodata_0[22] = {0x00000000, 0x00000000, 0x00000000, 0x3DCCCCCD, 0x3F800000, 0x3F800000, 0x00000000, 0x00000000, 0x3F800000, 0x3F800000, 0x00000000, 0x3F800000, 0x04000000, 0x00000000, 0xFFFFFFFF, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep_0(void) { const u32 *volatile cp; cp = fzgx_pool_rodata_0; }  /* fzgx-allow: S2 pool primer sink */
static const u32 fzgx_pool_rodata_58[52] = {0x00000000, 0x00000000, 0x00000000, 0x3DCCCCCD, 0x3F800000, 0x3F800000, 0x00000000, 0x00000000, 0x3F800000, 0x3F800000, 0x00000000, 0x3F800000, 0x04000000, 0x00000000, 0xFFFFFFFF, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x3DCCCCCD, 0x3F800000, 0x3F800000, 0x00000000, 0x00000000, 0x3F800000, 0x3F800000, 0x00000000, 0x3F800000, 0x04000000, 0x00000000, 0xFFFFFFFF, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x3F755555, 0x41B80000, 0x40000000, 0x3F2AAAAB, 0x3F000000, 0x3F155555, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep_58(void) { const u32 *volatile cp; cp = fzgx_pool_rodata_58; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime_128(s32 n) { volatile f32 s; s = (f32)n; }  /* fzgx-allow: S2 pool primer sink */
static const u32 fzgx_pool_rodata_130[36] = {0x44150000, 0x44040000, 0x0000001A, 0x00000023, 0x0000009C, 0x000000A5, 0x00000018, 0x00000021, 0x00000085, 0x0000008E, 0x000000F2, 0x000000FB, 0xC0C0C000, 0xC0800000, 0x42200000, 0x43F00000, 0x44200000, 0x47AFC800, 0x3E99999A, 0x3F333333, 0xBF800000, 0x43500000, 0xC47A0000, 0xC2480000, 0x3F800000, 0x41200000, 0x430C0000, 0x43600000, 0x437E0000, 0x43800000, 0xC0C00000, 0x40A00000, 0x40800000, 0x41400000, 0x41700000, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep_130(void) { const u32 *volatile cp; cp = fzgx_pool_rodata_130; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime_1C0(u32 n) { volatile f32 s; s = (f32)n; }  /* fzgx-allow: S2 pool primer sink */
static const u32 fzgx_pool_rodata_1C8[4] = {0x4E4F204E, 0x414D4500, 0x4E4F2044, 0x41544100};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep_1C8(void) { const u32 *volatile cp; cp = fzgx_pool_rodata_1C8; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime_1D8(void) { volatile f32 s; s = 100.0f; }  /* fzgx-allow: S2 pool primer sink */
static const u32 fzgx_pool_rodata_1DC[140] = {0x43AF0000, 0x42300000, 0x41000000, 0xFFFFFFFF, 0x00F0E6FF, 0x007873FF, 0xA0FF00FF, 0x0000001A, 0x00000023, 0x0000013C, 0x00000145, 0x00000018, 0x00000021, 0x00000065, 0x0000006E, 0x000000B2, 0x000000BB, 0x41F00000, 0x3F400000, 0x42580000, 0x43AB8000, 0x47800000, 0x42F00000, 0x3EB33333, 0xFFFFFFFF, 0x00F0E6FF, 0x007873FF, 0xFFFF00FF, 0xFFFF00FF, 0x8080FFFF, 0x0000001A, 0x00000023, 0x0000013C, 0x00000145, 0x00000018, 0x00000021, 0x00000065, 0x0000006E, 0x000000B2, 0x000000BB, 0x19FF1900, 0x19FF1900, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x406FE000, 0x00000000, 0x41A00000, 0x0000001A, 0x00000023, 0x0000013C, 0x00000145, 0xFFFFFF00, 0x19FF1900, 0x0000001A, 0x00000023, 0x0000013C, 0x00000145, 0x19FF1900, 0x00FFFFFF, 0x00FFFFFF, 0xFFFFFF00, 0x3F4CCCCD, 0xC0000000, 0x0000001A, 0x00000023, 0x0000013C, 0x00000145, 0x00000018, 0x00000021, 0x0000001A, 0x00000023, 0x0000013C, 0x00000145, 0x00000018, 0x00000021, 0xFFFF00FF, 0x19FF1900, 0x00000000, 0x0000001A, 0x00000023, 0x0000013C, 0x00000145, 0x19FF1900, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x42880000, 0x42AC0000, 0x3EC00000, 0x42A00000, 0x41600000, 0x41A80000, 0x3F8CCCCD, 0x43C78000, 0x440F8000, 0x3F59999A, 0x43FF0000, 0x19FF1900, 0x19FF1900, 0xF4962800, 0xF4962800, 0xFFFF0000, 0x00000000, 0xFFFFFF00, 0xF4962800, 0xF4962800, 0xFFFF0000, 0x00000000, 0xFFFFFF00, 0xF4962800, 0xFFFF00FF, 0x00000000, 0x19FF1900, 0x19FF1900, 0xF4962800, 0xF4962800, 0x8080FF00, 0x00000000, 0xFFFFFF00, 0xF4962800, 0xF4962800, 0x8080FF00, 0x00000000, 0xFFFFFF00, 0x43B10000, 0x42A80000, 0x41B00000, 0x3F266666, 0x43400000, 0x42400000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep_1DC(void) { const u32 *volatile cp; cp = fzgx_pool_rodata_1DC; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime_40C(void) { volatile f32 s; s = 46.0f; }  /* fzgx-allow: S2 pool primer sink */
static const u32 fzgx_pool_rodata_410[24] = {0x425C0000, 0xFADC82FF, 0x00000000, 0x441FC000, 0x43EF8000, 0x43A00000, 0x428C0000, 0x42E00000, 0x43F60000, 0x42040000, 0x41980000, 0x41C00000, 0x42480000, 0x41E80000, 0x42900000, 0x423C0000, 0x00009736, 0x00009737, 0x00009738, 0x00009739, 0x0000973A, 0x0000973B, 0x0000973C, 0x0000973D};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep_410(void) { const u32 *volatile cp; cp = fzgx_pool_rodata_410; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime_470(void) { volatile f32 s; s = 45.0f; }  /* fzgx-allow: S2 pool primer sink */
#pragma section code_type ".text"

/* retail tests the mode as this chain of flags, each set to TRUE then cleared (the same chain as fn_1_148950) */
static inline BOOL fn_1_148738_mode_4_5(s32 mode) {
    BOOL r = TRUE;
    if (!((u32)(mode - 4) <= 1)) r = FALSE;
    return r;
}
static inline BOOL fn_1_148738_mode_4_5_9(s32 mode) {
    BOOL r = TRUE;
    if (!fn_1_148738_mode_4_5(mode) && mode != 9) r = FALSE;
    return r;
}
static inline BOOL fn_1_148738_mode_4_5_9_10(s32 mode) {
    BOOL r = TRUE;
    if (!fn_1_148738_mode_4_5_9(mode) && mode != 10) r = FALSE;
    return r;
}
static inline BOOL fn_1_148738_mode_4_5_6_9_10(s32 mode) {
    BOOL r = TRUE;
    if (!fn_1_148738_mode_4_5_9_10(mode) && mode != 6) r = FALSE;
    return r;
}

/* GC/2.5 (2.0 also matches): 1.3.2 schedules the three row loads after the mode test's first steps; the row
 * must be const for 2.x to keep retail's order */
void fn_1_148738(s32 mode, const fn_1_148738_Row *row) {
    s32 x = 0x17F + row->unk_68 + row->unk_74;
    s32 y = row->unk_64 + 0x10;
    FontDrawPacket packet;

    if (fn_1_148738_mode_4_5_6_9_10(mode)) {
        packet = *(const FontDrawPacket *)fzgx_pool_rodata_58;
        packet.image = 0x971D;
        packet.x = x;
        packet.y = y;
        packet.z = 46.0f;
        fn_1_4F734(&packet);
        packet = *(const FontDrawPacket *)fzgx_pool_rodata_58;
        packet.image = 0x970B;
        packet.x = (x - 4) + (f32)row->unk_36 * (fn_1_48690(0x971D) - 2) / 100.0f;
        packet.y = (y - 10);
        packet.z = 45.0f;
        fn_1_4F734(&packet);
    }
}
/* fzgx:end fn_1_148738 */

/* fzgx:begin fn_1_1490FC noprologue */
#include "types.h"
#include "rel/main_rel/globals.h"
#include "rel/main_rel/sel_static_disp.h"
#include "font.h"

/* local view of the results row this function reads (fn_1_144F40 builds the rows) */
typedef struct {
    u8 pad_0[0x62];
    u16 unk_62;
    s32 unk_64;
    u8 pad_68[0xC];
    s32 unk_74;
} fn_1_1490FC_Row;

extern void fn_1_49410(void);
extern void fn_1_494DC(s16);
extern void fn_1_495C8(u8);
extern void fn_1_496FC(f32, f32);
extern void fn_1_4954C(f32);
extern void fn_1_49738(void *);
extern void fn_1_149C2C(void);

/* retail .rodata (lbl_1_rodata_92C0) up to this function's constants, so the font packet template (0x58),
 * the int-to-float constant (0x128) and 44.0f, 46.0f, 45.0f land at their retail offsets */
#pragma section code_type ".fzgxpool"
static const u32 fzgx_pool_rodata_0[22] = {0x00000000, 0x00000000, 0x00000000, 0x3DCCCCCD, 0x3F800000, 0x3F800000, 0x00000000, 0x00000000, 0x3F800000, 0x3F800000, 0x00000000, 0x3F800000, 0x04000000, 0x00000000, 0xFFFFFFFF, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep_0(void) { const u32 *volatile cp; cp = fzgx_pool_rodata_0; }  /* fzgx-allow: S2 pool primer sink */
static const u32 fzgx_pool_rodata_58[52] = {0x00000000, 0x00000000, 0x00000000, 0x3DCCCCCD, 0x3F800000, 0x3F800000, 0x00000000, 0x00000000, 0x3F800000, 0x3F800000, 0x00000000, 0x3F800000, 0x04000000, 0x00000000, 0xFFFFFFFF, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x3DCCCCCD, 0x3F800000, 0x3F800000, 0x00000000, 0x00000000, 0x3F800000, 0x3F800000, 0x00000000, 0x3F800000, 0x04000000, 0x00000000, 0xFFFFFFFF, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x3F755555, 0x41B80000, 0x40000000, 0x3F2AAAAB, 0x3F000000, 0x3F155555, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep_58(void) { const u32 *volatile cp; cp = fzgx_pool_rodata_58; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime_128(s32 n) { volatile f32 s; s = (f32)n; }  /* fzgx-allow: S2 pool primer sink */
static const u32 fzgx_pool_rodata_130[44] = {0x44150000, 0x44040000, 0x0000001A, 0x00000023, 0x0000009C, 0x000000A5, 0x00000018, 0x00000021, 0x00000085, 0x0000008E, 0x000000F2, 0x000000FB, 0xC0C0C000, 0xC0800000, 0x42200000, 0x43F00000, 0x44200000, 0x47AFC800, 0x3E99999A, 0x3F333333, 0xBF800000, 0x43500000, 0xC47A0000, 0xC2480000, 0x3F800000, 0x41200000, 0x430C0000, 0x43600000, 0x437E0000, 0x43800000, 0xC0C00000, 0x40A00000, 0x40800000, 0x41400000, 0x41700000, 0x00000000, 0x43300000, 0x00000000, 0x4E4F204E, 0x414D4500, 0x4E4F2044, 0x41544100, 0x42C80000, 0x43AF0000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep_130(void) { const u32 *volatile cp; cp = fzgx_pool_rodata_130; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime_1E0(void) { volatile f32 s; s = 44.0f; }  /* fzgx-allow: S2 pool primer sink */
static const u32 fzgx_pool_rodata_1E4[138] = {0x41000000, 0xFFFFFFFF, 0x00F0E6FF, 0x007873FF, 0xA0FF00FF, 0x0000001A, 0x00000023, 0x0000013C, 0x00000145, 0x00000018, 0x00000021, 0x00000065, 0x0000006E, 0x000000B2, 0x000000BB, 0x41F00000, 0x3F400000, 0x42580000, 0x43AB8000, 0x47800000, 0x42F00000, 0x3EB33333, 0xFFFFFFFF, 0x00F0E6FF, 0x007873FF, 0xFFFF00FF, 0xFFFF00FF, 0x8080FFFF, 0x0000001A, 0x00000023, 0x0000013C, 0x00000145, 0x00000018, 0x00000021, 0x00000065, 0x0000006E, 0x000000B2, 0x000000BB, 0x19FF1900, 0x19FF1900, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x406FE000, 0x00000000, 0x41A00000, 0x0000001A, 0x00000023, 0x0000013C, 0x00000145, 0xFFFFFF00, 0x19FF1900, 0x0000001A, 0x00000023, 0x0000013C, 0x00000145, 0x19FF1900, 0x00FFFFFF, 0x00FFFFFF, 0xFFFFFF00, 0x3F4CCCCD, 0xC0000000, 0x0000001A, 0x00000023, 0x0000013C, 0x00000145, 0x00000018, 0x00000021, 0x0000001A, 0x00000023, 0x0000013C, 0x00000145, 0x00000018, 0x00000021, 0xFFFF00FF, 0x19FF1900, 0x00000000, 0x0000001A, 0x00000023, 0x0000013C, 0x00000145, 0x19FF1900, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x42880000, 0x42AC0000, 0x3EC00000, 0x42A00000, 0x41600000, 0x41A80000, 0x3F8CCCCD, 0x43C78000, 0x440F8000, 0x3F59999A, 0x43FF0000, 0x19FF1900, 0x19FF1900, 0xF4962800, 0xF4962800, 0xFFFF0000, 0x00000000, 0xFFFFFF00, 0xF4962800, 0xF4962800, 0xFFFF0000, 0x00000000, 0xFFFFFF00, 0xF4962800, 0xFFFF00FF, 0x00000000, 0x19FF1900, 0x19FF1900, 0xF4962800, 0xF4962800, 0x8080FF00, 0x00000000, 0xFFFFFF00, 0xF4962800, 0xF4962800, 0x8080FF00, 0x00000000, 0xFFFFFF00, 0x43B10000, 0x42A80000, 0x41B00000, 0x3F266666, 0x43400000, 0x42400000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep_1E4(void) { const u32 *volatile cp; cp = fzgx_pool_rodata_1E4; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime_40C(void) { volatile f32 s; s = 46.0f; }  /* fzgx-allow: S2 pool primer sink */
static const u32 fzgx_pool_rodata_410[24] = {0x425C0000, 0xFADC82FF, 0x00000000, 0x441FC000, 0x43EF8000, 0x43A00000, 0x428C0000, 0x42E00000, 0x43F60000, 0x42040000, 0x41980000, 0x41C00000, 0x42480000, 0x41E80000, 0x42900000, 0x423C0000, 0x00009736, 0x00009737, 0x00009738, 0x00009739, 0x0000973A, 0x0000973B, 0x0000973C, 0x0000973D};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep_410(void) { const u32 *volatile cp; cp = fzgx_pool_rodata_410; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime_470(void) { volatile f32 s; s = 45.0f; }  /* fzgx-allow: S2 pool primer sink */
#pragma section code_type ".text"

/* GC/2.5: retail loads row->unk_74 between `mflr` and the LR save, which 1.3.2 never schedules; 2.5 does for
 * a __restrict parameter */
void fn_1_1490FC(s32 mode, fn_1_1490FC_Row *__restrict row) {
    s32 n;
    s32 x = row->unk_74 + 0x21D;
    s32 y = row->unk_64 - 4;
    FontDrawPacket packet;

    if (mode == 3 && (n = row->unk_62) >= 1) {
        packet = *(const FontDrawPacket *)fzgx_pool_rodata_58;
        packet.image = 0x9908;
        packet.x = x;
        packet.y = y;
        packet.z = 46.0f;
        fn_1_4F734(&packet);
        packet = *(const FontDrawPacket *)fzgx_pool_rodata_58;
        packet.image = 0x990C;
        packet.x = (x + 11);
        packet.y = (y + 12);
        packet.z = 45.0f;
        fn_1_4F734(&packet);
        fn_1_49410();
        fn_1_494DC(0x1F);
        fn_1_495C8(1);
        fn_1_496FC((x + 0x22), (y + 0x18));
        fn_1_4954C(44.0f);
        fn_1_49738(fn_1_149C2C);
        fn_1_4AE0C((const char *)lbl_1_data_42488, n >= 99 ? 99 : n);
    }
}
/* fzgx:end fn_1_1490FC */

/* fzgx:begin fn_1_149B64 noprologue */
#include "types.h"
#include "rel/main_rel/globals.h"
#include "rel/main_rel/sel_static_disp.h"

extern void fn_1_5233C(void* arg0, void* arg1);
extern void fn_1_149CA4(u32 arg0, u32 arg1, u32 arg2, u32 arg3);
extern u32 fn_1_A5DB0(void);
extern u32 fn_1_A5D88(void);
extern void fn_80074188(u32 arg0, u32 arg1, u32 arg2, u32 arg3);
extern void fn_1_149C2C(void);
extern void fn_1_149C2C();

// Rebuild the display state and publish the current display and effect IDs.
void fn_1_149B64(void* display_state, void* display_context) {
    u32 display_id;
    u32 effect_id;

    fn_1_149CA4(lbl_1_bss_8E428.unk_C,
                 *(u32*)((u8*)&lbl_1_bss_8E428 + 0x14),
                 lbl_1_bss_8E428.unk_10,
                 *(u32*)((u8*)&lbl_1_bss_8E428 + 0x18));
    fn_1_5233C(display_state, display_context);

    display_id = fn_1_A5DB0() & 0xffff;
    effect_id = fn_1_A5D88() & 0xffff;
    fn_80074188(0, 0, effect_id, display_id);

    fn_1_149C2C(display_state, display_context);
}
/* fzgx:end fn_1_149B64 */

/* fzgx:begin fn_1_149BF4 */
// Load four values from BSS table and pass to fn_1_149CA4.
void fn_1_149BF4(void) {
    u8* base = (u8*)&lbl_1_bss_8E428;
    u32 arg0 = *(u32*)(base + 0x4);
    u32 arg1 = *(u32*)(base + 0x14);
    u32 arg2 = *(u32*)(base + 0x8);
    u32 arg3 = *(u32*)(base + 0x18);
    fn_1_149CA4(arg0, arg1, arg2, arg3);
}
/* fzgx:end fn_1_149BF4 */

/* fzgx:begin fn_1_149C2C */
// Forward the four current static-display values to the display-update routine.
void fn_1_149C2C(void) {
    u8* table = (u8*)&lbl_1_bss_8E428;
    u32 position = *(u32*)(table + 0xC);
    u32 direction = *(u32*)(table + 0x14);
    u32 scale = *(u32*)(table + 0x10);
    u32 flags = *(u32*)(table + 0x18);

    fn_1_149CA4(position, direction, scale, flags);
}
/* fzgx:end fn_1_149C2C */

/* fzgx:begin fn_1_149C64 */
// Initialize the static display state with the default viewport dimensions.
void fn_1_149C64(void) {
    struct fn_1_149C64_lbl_1_bss_8E43C *display_state = &lbl_1_bss_8E43C;
    struct fn_1_149C64_lbl_1_bss_8E440 *display_config = &lbl_1_bss_8E440;

    fn_1_149CA4(0, display_state->unk_0, 0x280, display_config->unk_0);
}
/* fzgx:end fn_1_149C64 */

/* fzgx:begin fn_1_149CA4 */
void fn_1_149CA4(u32 arg0, u32 arg1, u32 arg2, u32 arg3) {
    fn_1_520A0();
    fn_1_52070(0x140);
    fn_80074188(__cvt_fp2unsigned(fn_1_520F8(arg0)),
                __cvt_fp2unsigned((arg1 * (fn_1_A5DB0() & 0xffff)) / lbl_1_rodata_942C[0]),
                __cvt_fp2unsigned(fn_1_521B8(arg2)),
                __cvt_fp2unsigned((arg3 * (fn_1_A5DB0() & 0xffff)) / lbl_1_rodata_942C[0]));
    fn_1_520CC();
}
/* fzgx:end fn_1_149CA4 */

/* fzgx:begin fn_1_149DA4 */
void fn_1_149DA4(void) {
    if (lbl_1_bss_8E51D == lbl_1_bss_8E524) {
        fn_1_144F40(4, 0);
    }
}
/* fzgx:end fn_1_149DA4 */

/* fzgx:begin fn_1_149DE8 */
void fn_1_149DE8(void) {
    if (lbl_1_bss_8E51D == lbl_1_bss_8E524) {
        fn_1_144F40(5, 0);
    }
}
/* fzgx:end fn_1_149DE8 */

/* fzgx:begin fn_1_149E2C noprologue */
#include "types.h"
#include "rel/main_rel/globals.h"
#include "rel/main_rel/sel_static_disp.h"
#include "font.h"

typedef struct fn_1_149E2C_Racer {
    u8 pad_0[0xE];
    u8 unk_E;
    u8 pad_F[0x9];
    u16 unk_18;
    u8 pad_1A[0x1E];
    u32 unk_38;
    u8 pad_3C[0x64];
} fn_1_149E2C_Racer;

typedef struct fn_1_149E2C_Sel {
    u8 pad_0[0x9];
    u8 count;
    u8 pad_A[0x4];
    u8 order[0xC6];
    fn_1_149E2C_Racer racers[1];
} fn_1_149E2C_Sel;

extern void fn_1_144F40(u32 arg0, u32 arg1);
extern void fn_1_49410(void);
extern void fn_1_495FC(void);
extern void fn_1_495C8(s32 arg0);
extern void fn_1_49614(void);

void fn_1_149E2C(void) {
    u32 best;
    u32 most;
    u32 i;
    fn_1_149E2C_Racer *racer;

    lbl_1_bss_8E428.unk_0 = (u32)&lbl_1_bss_3C30 + 0xe;
    if (lbl_1_bss_8E51D == lbl_1_bss_8E524) {
        fn_1_144F40(2, 0);
    }
    fn_1_49410();
    fn_1_495FC();
    fn_1_495C8(9);
    best = 0x0633B063;
    most = 0;
    for (i = 0; i < ((fn_1_149E2C_Sel *)&lbl_1_bss_3C30)->count; i++) {
        racer = &((fn_1_149E2C_Sel *)&lbl_1_bss_3C30)->racers[((fn_1_149E2C_Sel *)&lbl_1_bss_3C30)->order[i]];
        if (racer->unk_E != 0xFE) {
            if (best > racer->unk_38) {
                best = racer->unk_38;
            }
            if (most < racer->unk_18) {
                most = racer->unk_18;
            }
        }
    }
    fn_1_49614();
}
/* fzgx:end fn_1_149E2C */
