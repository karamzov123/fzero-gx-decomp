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

/* fzgx:begin fn_1_1420E0 noprologue */
#include "types.h"
#include "rel/main_rel/sel_static_disp.h"

extern int fn_1_5910(void);
extern u32 fn_1_58C4(void);
extern void fn_1_52070(int);
extern void fn_1_52088(void);
extern u8 lbl_1_bss_26B18__fzgx_offset_6[46];
extern void fn_1_1421D8(u32, u32, u32);
extern void fn_1_1424E8(u32, u32, u32);
extern void fn_1_14267C(u32, u32, u32);
extern void fn_1_142BDC(u32, u32, u32);
extern void fn_1_14328C(u32, u32, u32);
extern void fn_1_143780(u32, u32, u32);
extern void fn_1_143F5C(u32, u32, u32);
extern void fn_1_144254(u32, u32, u32);

void fn_1_1420E0(void) {
    u32 v;
    u8 flag;
    u8 mask;

    v = fn_1_5910();
    flag = lbl_1_bss_3C30.unk_8;
    mask = (1 << v);
    if (flag < 1 || !(lbl_1_bss_26B18__fzgx_offset_6[0] & mask)) {
        return;
    }
    fn_1_52070(0x140);
    if (fn_1_58C4() == 1) {
        fn_1_1421D8(0x25, 0x31, v);
        fn_1_14267C(0x2c, 0x40, v);
        fn_1_14328C(0xdb, 0x14a, v);
        fn_1_142BDC(0x39, 0x128, v);
        fn_1_1424E8(0x25, 0x31, v);
        fn_1_143780(0xf2, 0x40, v);
        fn_1_143F5C(0xf2, 0x122, v);
        fn_1_144254(0x2c, 0x15a, v);
    }
    fn_1_52088();
}
/* fzgx:end fn_1_1420E0 */

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

/* fzgx:begin fn_1_14267C noprologue */
#include "types.h"
#include "types.h"
#include "rel/main_rel/globals.h"
#include "rel/main_rel/shadowmap.h"
#include "psvec.h"
#include "rel/main_rel/sel_static_disp.h"

/* begin game/main_rel/shadowmap_types.h (deltawave784/fzgx, CC0) */
#ifndef GAME_MAIN_REL_SHADOWMAP_TYPES_H
#define GAME_MAIN_REL_SHADOWMAP_TYPES_H

// Types (and the externs that name them) of shadowmap.c, hoisted out of its prologue so that
// a block can compile standalone and under the prologue. Hand-owned (librarian).


typedef struct fn_1_568F8_Color {
    u8 r;
    u8 g;
    u8 b;
    u8 a;
} fn_1_568F8_Color;

typedef struct fn_1_568F8_Vec3 {
    f32 x;
    f32 y;
    f32 z;
} fn_1_568F8_Vec3;

typedef struct fn_1_568F8_Pool {
    fn_1_568F8_Color tev_color;  // 0x00
    f32 zero;                    // 0x04
    fn_1_568F8_Vec3 axis_x;      // 0x08
    fn_1_568F8_Vec3 axis_y;      // 0x14
    fn_1_568F8_Vec3 axis_z;      // 0x20
    fn_1_568F8_Vec3 up;          // 0x2c
    fn_1_568F8_Color clear_color;  // 0x38
    fn_1_568F8_Color chan_color;   // 0x3c
    f32 neg_three;               // 0x40
    f32 one;                     // 0x44
    f32 twenty;                  // 0x48
    f32 three;                   // 0x4c
    f32 hundred;                 // 0x50
    f32 size;                    // 0x54
} fn_1_568F8_Pool;

typedef struct fn_1_568F8_Data {
    u8 pad_0[0x38c];
    u8 light_mask;               // 0x38c
    u8 pad_38d[0x2b];
    s16 light_param;             // 0x3b8
} fn_1_568F8_Data;

typedef struct fn_1_568F8_Mtx44 {
    f32 m[4][4];
} fn_1_568F8_Mtx44;

extern fn_1_568F8_Pool lbl_1_rodata_28B0;
extern void fn_1_870BC(fn_1_568F8_Data *, s8, fn_1_568F8_Data *, s32, u8, f32);
extern void C_MTXOrtho(fn_1_568F8_Mtx44 *, f32, f32, f32, f32, f32, f32);
extern void fn_800737E4(fn_1_568F8_Mtx44 *, s32);
extern void fn_800744F8(fn_1_568F8_Color, u32);
extern void fn_800725DC(fn_1_568F8_Color);
extern void fn_80072614(fn_1_568F8_Color);

#endif  // GAME_MAIN_REL_SHADOWMAP_TYPES_H

/* end game/main_rel/shadowmap_types.h */

typedef struct Sig_fn_1_144A5C_fn_1_143F5C_Args {
 s32 x,y,w0,h0,w1,h1; u32 *list0; s32 count0; u32 *list1; s32 count1;
} Sig_fn_1_144A5C_fn_1_143F5C_Args;
typedef struct { u8 _pad[6]; s16 field_6; } Sig_fn_1_8472C_Fn18472CObject;
typedef struct Sig_fn_80015EE8_Fn80015EE8Out { f32 f[16]; } Sig_fn_80015EE8_Fn80015EE8Out;
struct Sig_fn_800737E4_fn_800737E4_Arg0 { f32 unk_0; u8 pad_4[4]; f32 unk_8,unk_C; u8 pad_10[4]; f32 unk_14,unk_18,unk_1C; u8 pad_20[8]; f32 unk_28,unk_2C; };
struct Sig_fn_80072270_fn_80072270_Arg0 { f32 unk_0,unk_4,unk_8,unk_c,unk_10,unk_14,unk_18; };
struct fn_1_14267C_Copy88 { u32 a[22]; };
struct fn_1_14267C_lbl_1_rodata_92C0 {
 u8 pad_0[0x108]; f32 unk_108; u8 pad_10C[0x1C]; f64 unk_128; u8 pad_130[8];
 u32 unk_138,unk_13C,unk_140,unk_144,unk_148,unk_14C,unk_150,unk_154,unk_158,unk_15C,unk_160;
 f32 unk_164,unk_168,unk_16C,unk_170,unk_174,unk_178,unk_17C,unk_180,unk_184,unk_188,unk_18C,unk_190,unk_194;
};
struct fn_1_14267C_lbl_1_data_1E5C0 { u32 unk_0,unk_4,unk_8,unk_C,unk_10,unk_14,unk_18,unk_1C,unk_20,unk_24,unk_28,unk_2C,unk_30; };
extern struct fn_1_14267C_lbl_1_data_1E5C0 lbl_1_data_1E5C0;
struct PanelPoolU32 { u32 v; };
struct PanelPoolF32 { f32 v; };
extern u8 fn_1_149BF4__fzgx_offset_0[], fn_1_149C2C__fzgx_offset_0[], fn_1_149C64__fzgx_offset_0[];
static const union { u32 w[66]; u32 v[66]; } fzgx_pool_prefix = {{ /* fzgx-allow: A1 retail data bytes and bindings */
0x0,0x0,0x0,0x3DCCCCCD,0x3F800000,0x3F800000,0x0,0x0,0x3F800000,0x3F800000,0x0,0x3F800000,0x4000000,0x0,0xFFFFFFFF,0x0,0x0,0x0,0x0,0x0,(u32)fn_1_149BF4__fzgx_offset_0,0x0,0x0,0x0,0x0,0x3DCCCCCD,0x3F800000,0x3F800000,0x0,0x0,0x3F800000,0x3F800000,0x0,0x3F800000,0x4000000,0x0,0xFFFFFFFF,0x0,0x0,0x0,0x0,0x0,(u32)fn_1_149C2C__fzgx_offset_0,0x0,0x0,0x0,0x0,0x3DCCCCCD,0x3F800000,0x3F800000,0x0,0x0,0x3F800000,0x3F800000,0x0,0x3F800000,0x4000000,0x0,0xFFFFFFFF,0x0,0x0,0x0,0x0,0x0,(u32)fn_1_149C64__fzgx_offset_0,0x0
}};
const struct PanelPoolF32 fzgx_pool_108 = {0.0f};
const u32 fzgx_pool_table_10C[7] = {0x3F755555,0x41B80000,0x40000000,0x3F2AAAAB,0x3F000000,0x3F155555,0};
#define lbl_1_rodata_92C0 ((const u32 *)((const u8 *)&fzgx_pool_108 - 0x108))
#define fn_1_14267C_pool_primer fzgx_panel_pool_primer
#pragma section code_type ".fzgxpool"
f32 fzgx_panel_pool_primer(s32 v) { return (f32)v; }
#pragma section code_type ".text"
const u32 fzgx_pool_table_130[2] = {0x44150000,0x44040000};
const struct PanelPoolU32 fzgx_pool_138 = {26};
const struct PanelPoolU32 fzgx_pool_13C = {35};
const struct PanelPoolU32 fzgx_pool_140 = {156};
const struct PanelPoolU32 fzgx_pool_144 = {165};
const struct PanelPoolU32 fzgx_pool_148 = {24};
const struct PanelPoolU32 fzgx_pool_14C = {33};
const struct PanelPoolU32 fzgx_pool_150 = {133};
const struct PanelPoolU32 fzgx_pool_154 = {142};
const struct PanelPoolU32 fzgx_pool_158 = {242};
const struct PanelPoolU32 fzgx_pool_15C = {251};
const struct PanelPoolU32 fzgx_pool_160 = {0xC0C0C000}; /* fzgx-allow: A1 retail RGBA data bytes */
const struct PanelPoolF32 fzgx_pool_164 = {-4.0f};
const struct PanelPoolF32 fzgx_pool_168 = {40.0f};
const struct PanelPoolF32 fzgx_pool_16C = {480.0f};
const struct PanelPoolF32 fzgx_pool_170 = {640.0f};
const struct PanelPoolF32 fzgx_pool_174 = {90000.0f};
const struct PanelPoolF32 fzgx_pool_178 = {0.3f};
const struct PanelPoolF32 fzgx_pool_17C = {0.7f};
const struct PanelPoolF32 fzgx_pool_180 = {-1.0f};
const struct PanelPoolF32 fzgx_pool_184 = {208.0f};
const struct PanelPoolF32 fzgx_pool_188 = {-1000.0f};
const struct PanelPoolF32 fzgx_pool_18C = {-50.0f};
const struct PanelPoolF32 fzgx_pool_190 = {1.0f};
const struct PanelPoolF32 fzgx_pool_194 = {10.0f};
extern struct fn_1_14267C_Copy88 lbl_1_rodata_26F8;
extern u8 lbl_1_data_1A2B4[176];
extern u32 fn_1_144A5C(void *);
extern u32 fn_1_86900(u32);
extern s16 fn_1_12C930(void *);
extern void fn_1_49410(void),fn_1_4962C(void);
extern void fn_1_494DC(s16);
extern void fn_1_4966C(f32,f32),fn_1_496FC(f32,f32);
extern void fn_1_49514(u32 *);
extern void fn_1_4954C(f32);
extern void fn_1_4AE0C(const char *,...);
extern void fn_1_4A0D8(const char *);
extern void *fn_1_8472C(Sig_fn_1_8472C_Fn18472CObject *);
extern char *fn_1_14FEAC(void *,void *,void *,char *,void *);
extern void *fn_1_7F49C(s16,void *,void *);
extern s8 fn_1_8421C(u32,u32);
extern void GXGetProjectionv(f32 *);
extern u32 GXGetScissor(void *,void *,void *,void *);


extern void fn_1_F7870(u32);
extern void fn_1_149CA4(u32,u32,u32,u32);
extern f32 fn_1_520F8(s32),fn_1_521B8(s32);
extern u32 lbl_8006D7F4(f32,f32,f32);
extern void lbl_8006E14C(f32),lbl_8006E15C(f32,f32,f32);
extern u32 mathutil_mtxA_rotate_z(u32),mathutil_mtxA_rotate_x(u32);
extern void fn_80072558(void),fn_80074918(u8,s32,u8);
extern void fn_1_151BDC(void *);
extern void fn_1_870BC(fn_1_568F8_Data *,s8,fn_1_568F8_Data *,s32,u8,f32);
extern f64 fn_80074188(u32,u32,u32,u32);
extern void fn_80072270(struct Sig_fn_80072270_fn_80072270_Arg0 *);
extern int fn_1_4F734(void *);

#pragma opt_common_subs off
void fn_1_14267C(u32 arg0,u32 arg1,u32 arg2,f32 arg3,f32 arg4) {
 u32 v2;
 s32 v3;
 s32 v5;
 s16 t3;
 u32 v8;
 s8 t24;
 u8 *t19;
 struct fn_1_14267C_lbl_1_data_1E5C0 *q;
 struct fn_1_14267C_Copy88 packet;
 Sig_fn_1_144A5C_fn_1_143F5C_Args loc_114;
 Sig_fn_80015EE8_Fn80015EE8Out loc_D4;
 struct fn_1_14267C_lbl_1_data_1E5C0 loc_A0;
 struct { u32 a[6]; } loc_88;
 char loc_68[32],loc_48[32];
 struct Sig_fn_80072270_fn_80072270_Arg0 loc_2C;
 struct { u32 a[4]; } loc_1C;
 u32 loc_18,loc_14,loc_10,loc_C,loc_8;
 s32 level;
 loc_1C.a[0]=fzgx_pool_138.v; loc_1C.a[1]=fzgx_pool_13C.v; loc_1C.a[2]=fzgx_pool_140.v; loc_1C.a[3]=fzgx_pool_144.v;
 loc_88.a[0]=fzgx_pool_148.v; loc_88.a[1]=fzgx_pool_14C.v; loc_88.a[2]=fzgx_pool_150.v; loc_88.a[3]=fzgx_pool_154.v; loc_88.a[4]=fzgx_pool_158.v; loc_88.a[5]=fzgx_pool_15C.v;
 loc_114.x=arg0; loc_114.y=arg1; loc_114.w0=192; loc_114.h0=278; loc_114.w1=180; loc_114.h1=270;
 loc_114.list0=loc_1C.a; loc_114.count0=4; loc_114.list1=loc_88.a; loc_114.count1=6;
 fn_1_144A5C(&loc_114);
 v2=fn_1_86900((s8)arg2);
 if (!v2) {
  for(v3=0;v3<4;v3++) { v2=fn_1_86900((s8)v3); if(v2) break; }
  if(!v2) return;
 }
 v5=*(s8 *)(v2+0x328);
 t3=fn_1_12C930((void *)v5);
 fn_1_49410(); fn_1_494DC(4); fn_1_4962C();
 fn_1_4966C(fzgx_pool_164.v,((const f32 *)lbl_1_rodata_92C0)[66]);
 loc_8=fzgx_pool_160.v; fn_1_49514(&loc_8);
 fn_1_496FC(fn_1_14267C_pool_primer(arg0+15),(f32)(s32)(arg1+16));
 fn_1_4954C(fzgx_pool_168.v);
 fn_1_4AE0C((char *)&lbl_1_data_42480);
 fn_1_496FC((s32)(arg0+15),(s32)(arg1+32));
 v8=t3<<2;
 fn_1_4A0D8((char *)*(u32 *)((u8 *)&lbl_1_data_212A8.unk_0+v8));
 fn_1_496FC((s32)(arg0+15),(s32)(arg1+54));
 fn_1_4AE0C((char *)&lbl_1_data_422B0);
 fn_1_496FC((s32)(arg0+15),(s32)(arg1+70));
 fn_1_4962C();
 if(v5>40) {
  fn_1_8472C(*(Sig_fn_1_8472C_Fn18472CObject **)(v2+812));
  if(v2) {
   t19=fn_1_8472C(*(Sig_fn_1_8472C_Fn18472CObject **)(v2+812));
   if(t19) fn_1_4A0D8(fn_1_14FEAC((void *)t19[0x81A4],(void *)t19[0x81AC],(void *)t19[0x81B4],loc_48,0));
  }
 } else fn_1_4A0D8(fn_1_7F49C(v5,0,loc_68));
 if(v2) {
  t24=fn_1_8421C(v2,0);
  GXGetProjectionv((f32 *)&loc_2C);
  GXGetScissor(&loc_18,&loc_14,&loc_10,&loc_C);
  C_MTXOrtho((void *)&loc_D4,((const f32 *)lbl_1_rodata_92C0)[66],fzgx_pool_16C.v,((const f32 *)lbl_1_rodata_92C0)[66],fzgx_pool_170.v,((const f32 *)lbl_1_rodata_92C0)[66],fzgx_pool_174.v);
  fn_800737E4((void *)&loc_D4,1);
  q=&lbl_1_data_1E5C0;
  loc_A0=*q;
  *(f32 *)&loc_A0.unk_C=fzgx_pool_178.v;
  *(f32 *)&loc_A0.unk_10=fzgx_pool_17C.v;
  *(f32 *)&loc_A0.unk_14=fzgx_pool_180.v;
  fn_1_F7870((u32)&loc_A0);
  fn_1_149CA4(48,69,180,270);
  lbl_8006D7F4(fn_1_520F8(138),fzgx_pool_184.v,fzgx_pool_188.v);
  lbl_8006E14C(fzgx_pool_18C.v);
  { f32 t34=fn_1_521B8(1); lbl_8006E15C(t34,fzgx_pool_190.v,fzgx_pool_190.v); }
  mathutil_mtxA_rotate_z(32768); mathutil_mtxA_rotate_x(-16384);
  fn_80072558(); fn_80074918(1,3,0);
  fn_1_151BDC(fn_1_8472C(*(Sig_fn_1_8472C_Fn18472CObject **)(v2+812)));
  fn_1_870BC((void *)v2,t24,(void *)v2,0,*(s16 *)(v2+952),fzgx_pool_190.v);
  fn_80074188(loc_18,loc_14,loc_10,loc_C);
  fn_80072270(&loc_2C);
 }
 { s16 rawLevel = *(s16 *)(v2+952);
 if(rawLevel<0) level=0; else { level=3; if(rawLevel<=3) level=rawLevel; }
 }
 packet=lbl_1_rodata_26F8;
 packet.a[0]=(s16)level|(*(u32 *)(lbl_1_data_1A2B4+v8)<<8);
 *(f32 *)&packet.a[1]=(f32)(s32)(arg0+96);
 *(f32 *)&packet.a[2]=(f32)(s32)(arg1+11);
 *(f32 *)&packet.a[3]=fzgx_pool_194.v;
 *(f32 *)&packet.a[11]=fzgx_pool_190.v;
 packet.a[12]=6;
 fn_1_4F734(&packet);
}
/* fzgx:end fn_1_14267C */

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

/* fzgx:begin fn_1_144254 noprologue */
#include "types.h"
#include "font.h"
#include "rel/main_rel/globals.h"
#include "rel/main_rel/sel_static_disp.h"

#pragma section code_type ".fzgxpool"
__declspec(section ".fzgxpool") static void fzgx_pool_prime1(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    s = 0.0f;
}
extern u8 fn_1_149BF4__fzgx_offset_0[];
extern u8 fn_1_149C2C__fzgx_offset_0[];
extern u8 fn_1_149C64__fzgx_offset_0[];
extern u8 lbl_1_data_424D0__fzgx_offset_0[];
extern u8 lbl_1_data_424E4__fzgx_offset_0[];
extern u8 lbl_1_data_424F8__fzgx_offset_0[];
extern u8 lbl_1_data_4250C__fzgx_offset_0[];
extern u8 lbl_1_data_42520__fzgx_offset_0[];
extern u8 lbl_1_data_42534__fzgx_offset_0[];
extern u8 lbl_1_data_42548__fzgx_offset_0[];
extern u8 lbl_1_data_4255C__fzgx_offset_0[];
static const union { u32 w[2]; const unsigned long v[2]; } fzgx_pool_init_fzgx_pool_table2 = {{  /* fzgx-allow: A1 retail data bytes and bindings */
    0x0, 0x0
}};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep2(void) { const unsigned long *volatile cp; cp = fzgx_pool_init_fzgx_pool_table2.v; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime3(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    s = 0.10000000149011612f;
}
static const union { u32 w[63]; const unsigned long v[63]; } fzgx_pool_init_fzgx_pool_table4 = {{  /* fzgx-allow: A1 retail data bytes and bindings */
    0x3F800000, 0x3F800000, 0x0, 0x0, 0x3F800000, 0x3F800000, 0x0, 0x3F800000,
    0x4000000, 0x0, 0xFFFFFFFF, 0x0, 0x0, 0x0, 0x0, 0x0,
    (u32)fn_1_149BF4__fzgx_offset_0, 0x0, 0x0, 0x0, 0x0, 0x3DCCCCCD, 0x3F800000, 0x3F800000,
    0x0, 0x0, 0x3F800000, 0x3F800000, 0x0, 0x3F800000, 0x4000000, 0x0,
    0xFFFFFFFF, 0x0, 0x0, 0x0, 0x0, 0x0, (u32)fn_1_149C2C__fzgx_offset_0, 0x0,
    0x0, 0x0, 0x0, 0x3DCCCCCD, 0x3F800000, 0x3F800000, 0x0, 0x0,
    0x3F800000, 0x3F800000, 0x0, 0x3F800000, 0x4000000, 0x0, 0xFFFFFFFF, 0x0,
    0x0, 0x0, 0x0, 0x0, (u32)fn_1_149C64__fzgx_offset_0, 0x0, 0x0
}};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep4(void) { const unsigned long *volatile cp; cp = fzgx_pool_init_fzgx_pool_table4.v; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime5(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    s = 0.9583333134651184f;
    s = 23.0f;
    s = 2.0f;
    s = 0.6666666865348816f;
    s = 0.5f;
    s = 0.5833333134651184f;
}
static const union { u32 w[1]; const unsigned long v[1]; } fzgx_pool_init_fzgx_pool_table6 = {{  /* fzgx-allow: A1 retail data bytes and bindings */
    0x0
}};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep6(void) { const unsigned long *volatile cp; cp = fzgx_pool_init_fzgx_pool_table6.v; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime7(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    d = 4503601774854144.0;
    s = 596.0f;
    s = 528.0f;
}
static const union { u32 w[11]; const unsigned long v[11]; } fzgx_pool_init_fzgx_pool_table8 = {{  /* fzgx-allow: A1 retail data bytes and bindings */
    0x1A, 0x23, 0x9C, 0xA5, 0x18, 0x21, 0x85, 0x8E,
    0xF2, 0xFB, 0xC0C0C000  /* fzgx-allow: A1 retail data bytes */
}};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep8(void) { const unsigned long *volatile cp; cp = fzgx_pool_init_fzgx_pool_table8.v; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime9(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
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
    s = 1.0f;
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
static const unsigned long fzgx_pool_table10[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep10(void) { const unsigned long *volatile cp; cp = fzgx_pool_table10; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime11(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    d = 4503599627370496.0;
}
static const union { u32 w[1]; const unsigned long v[1]; } fzgx_pool_init_fzgx_pool_table12 = {{  /* fzgx-allow: A1 retail data bytes and bindings */
    0x4E4F204E
}};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep12(void) { const unsigned long *volatile cp; cp = fzgx_pool_init_fzgx_pool_table12.v; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime13(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    s = 12.829345703125f;
}
static const union { u32 w[1]; const unsigned long v[1]; } fzgx_pool_init_fzgx_pool_table14 = {{  /* fzgx-allow: A1 retail data bytes and bindings */
    0x4E4F2044
}};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep14(void) { const unsigned long *volatile cp; cp = fzgx_pool_init_fzgx_pool_table14.v; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime15(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    s = 13.265869140625f;
    s = 100.0f;
    s = 350.0f;
    s = 44.0f;
    s = 8.0f;
}
static const union { u32 w[14]; const unsigned long v[14]; } fzgx_pool_init_fzgx_pool_table16 = {{  /* fzgx-allow: A1 retail data bytes and bindings */
    0xFFFFFFFF, 0xF0E6FF, 0x7873FF, 0xA0FF00FF, 0x1A, 0x23, 0x13C, 0x145,
    0x18, 0x21, 0x65, 0x6E, 0xB2, 0xBB
}};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep16(void) { const unsigned long *volatile cp; cp = fzgx_pool_init_fzgx_pool_table16.v; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime17(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    s = 30.0f;
    s = 0.75f;
    s = 54.0f;
    s = 343.0f;
    s = 65536.0f;
    s = 120.0f;
    s = 0.3499999940395355f;
}
static const union { u32 w[25]; const unsigned long v[25]; } fzgx_pool_init_fzgx_pool_table18 = {{  /* fzgx-allow: A1 retail data bytes and bindings */
    0xFFFFFFFF, 0xF0E6FF, 0x7873FF, 0xFFFF00FF, 0xFFFF00FF, 0x8080FFFF, 0x1A, 0x23,  /* fzgx-allow: A1 retail data bytes */
    0x13C, 0x145, 0x18, 0x21, 0x65, 0x6E, 0xB2, 0xBB,
    0x19FF1900, 0x19FF1900, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0
}};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep18(void) { const unsigned long *volatile cp; cp = fzgx_pool_init_fzgx_pool_table18.v; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime19(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    s = 3.748046875f;
}
static const union { u32 w[1]; const unsigned long v[1]; } fzgx_pool_init_fzgx_pool_table20 = {{  /* fzgx-allow: A1 retail data bytes and bindings */
    0x0
}};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep20(void) { const unsigned long *volatile cp; cp = fzgx_pool_init_fzgx_pool_table20.v; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime21(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    s = 20.0f;
}
static const union { u32 w[14]; const unsigned long v[14]; } fzgx_pool_init_fzgx_pool_table22 = {{  /* fzgx-allow: A1 retail data bytes and bindings */
    0x1A, 0x23, 0x13C, 0x145, 0xFFFFFF00, 0x19FF1900, 0x1A, 0x23,
    0x13C, 0x145, 0x19FF1900, 0xFFFFFF, 0xFFFFFF, 0xFFFFFF00
}};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep22(void) { const unsigned long *volatile cp; cp = fzgx_pool_init_fzgx_pool_table22.v; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime23(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    s = 0.800000011920929f;
    s = -2.0f;
}
static const union { u32 w[20]; const unsigned long v[20]; } fzgx_pool_init_fzgx_pool_table24 = {{  /* fzgx-allow: A1 retail data bytes and bindings */
    0x1A, 0x23, 0x13C, 0x145, 0x18, 0x21, 0x1A, 0x23,
    0x13C, 0x145, 0x18, 0x21, 0xFFFF00FF, 0x19FF1900, 0x0, 0x1A,
    0x23, 0x13C, 0x145, 0x19FF1900
}};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep24(void) { const unsigned long *volatile cp; cp = fzgx_pool_init_fzgx_pool_table24.v; }  /* fzgx-allow: S2 pool primer sink */
extern u8 lbl_1_data_424D0[];
extern u8 lbl_1_data_424E4[];
extern u8 lbl_1_data_424F8[];
extern u8 lbl_1_data_4250C[];
extern u8 lbl_1_data_42520[];
extern u8 lbl_1_data_42534[];
extern u8 lbl_1_data_42548[];
extern u8 lbl_1_data_4255C[];
struct fn_1_144254_Copy16 { u32 a[4]; };
static const union { u32 w[4]; const struct fn_1_144254_Copy16 v; } fzgx_pool_init_fn_1_144254_names = {{  /* fzgx-allow: A1 retail data bytes and bindings */
    (u32)lbl_1_data_424D0__fzgx_offset_0, (u32)lbl_1_data_424E4__fzgx_offset_0, (u32)lbl_1_data_424F8__fzgx_offset_0, (u32)lbl_1_data_4250C__fzgx_offset_0
}};
static const union { u32 w[4]; const struct fn_1_144254_Copy16 v; } fzgx_pool_init_fn_1_144254_details = {{  /* fzgx-allow: A1 retail data bytes and bindings */
    (u32)lbl_1_data_42520__fzgx_offset_0, (u32)lbl_1_data_42534__fzgx_offset_0, (u32)lbl_1_data_42548__fzgx_offset_0, (u32)lbl_1_data_4255C__fzgx_offset_0
}};
__declspec(section ".fzgxpool") static void fzgx_pool_keep25(void) {
    const struct fn_1_144254_Copy16 *volatile cp;  /* fzgx-allow: S2 volatile keeps the verified access order */
    cp = &fzgx_pool_init_fn_1_144254_names.v;
    cp = &fzgx_pool_init_fn_1_144254_details.v;
}
__declspec(section ".fzgxpool") static void fzgx_pool_prime33(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    s = 68.0f;
    s = 86.0f;
    s = 0.375f;
    s = 80.0f;
    s = 14.0f;
    s = 21.0f;
    s = 1.100000023841858f;
    s = 399.0f;
    s = 574.0f;
    s = 0.8500000238418579f;
    s = 510.0f;
}
#pragma section code_type ".text"

struct fn_1_144254_Copy88 { u32 a[22]; };
struct fn_1_144254_Bounds { s16 x, y; f32 width; s16 x2, y2; };
struct fn_1_144254_lbl_1_rodata_92C0 {
    u8 pad_0[0x114]; f32 unk_114; u8 pad_118[4]; f32 unk_11C;
    u8 pad_120[8]; f64 unk_128; u8 pad_130[0x60];
    f32 unk_190, unk_194; u8 pad_198[0x14]; f32 unk_1AC;
    u8 pad_1B0[4]; f32 unk_1B4, unk_1B8; u8 pad_1BC[0x1C];
    f32 unk_1D8; u8 pad_1DC[4]; f32 unk_1E0, unk_1E4;
    u8 pad_1E8[0x38]; f32 unk_220; u8 pad_224[0x118];
    u32 unk_33C, unk_340, unk_344, unk_348, unk_34C, unk_350, unk_354, unk_358;
    f32 unk_35C, unk_360, unk_364, unk_368, unk_36C, unk_370, unk_374, unk_378, unk_37C, unk_380, unk_384;
};
extern const struct fn_1_144254_lbl_1_rodata_92C0 lbl_1_rodata_92C0;
extern f32 lbl_1_rodata_26F8[22];
extern char *strncpy(char *, const char *, size_t);
extern int fn_1_4F734(FontDrawPacket *);
extern u16 fn_1_486C4(u32);
extern u32 fn_1_53830(u32, u32, void *, void *, f32);
extern s16 fn_1_C8294(struct fn_1_144254_Bounds *, u8, s32);
extern s32 fn_1_D2D38(void);
extern u8 fn_1_D2D48(void);
extern void fn_1_13D460(s32, s32, s32, s32);
extern void fn_1_49410(void);
extern void fn_1_4955C(f32, f32);
extern void fn_1_49590(f32);
extern void fn_1_495B0(u32);
extern void fn_1_495C8(u32);
extern void fn_1_4965C(u8);
extern void fn_1_496FC(f32, f32);
extern void fn_1_4A0D8(const char *);
extern void fn_1_4CE48(Obj_1_bss_4B9CC *, f32);
extern void fn_1_50164(f32, f32, f32, f32, void *);
extern void fn_1_51678(FontDrawPacket *, u32, s16, s16, s16, s16);
extern void fn_80008BEC(void *, int, u32);

extern u8 lbl_1_data_424D0[];
extern u8 lbl_1_data_424E4[];
extern u8 lbl_1_data_424F8[];
extern u8 lbl_1_data_4250C[];
extern u8 lbl_1_data_42520[];
extern u8 lbl_1_data_42534[];
extern u8 lbl_1_data_42548[];
extern u8 lbl_1_data_4255C[];

void fn_1_144254(s32 arg0, s32 arg1) {
    struct fn_1_144254_Copy88 loc_84;
    struct fn_1_144254_Bounds loc_3C[6];
    u8 loc_28[17];
    s32 v9;
    u8 v14;
    f32 v26, v24;
    void *v10;
    u32 v27;
    s16 v29;
    u8 v31;
    s32 v34, v35;
    s32 v48, v52;

    if (lbl_1_bss_3C30.unk_5 == 1 || lbl_1_bss_3C30.unk_5 == 6) {
    if (lbl_1_bss_3C30.unk_9 > 1) {
    loc_84 = *(struct fn_1_144254_Copy88 *)lbl_1_rodata_26F8;
    loc_84.a[0] = fn_1_D2D38() ? 0x9707 : 0x9706;
    *(f32 *)((u8 *)&loc_84 + 4) = (f32)arg0;
    *(f32 *)((u8 *)&loc_84 + 8) = (f32)(arg1 + 2);
    *(f32 *)((u8 *)&loc_84 + 12) = 5.0f;
    fn_1_4F734((FontDrawPacket *)&loc_84);
    fn_1_13D460(arg0, arg1 + 18, 596 - arg0, 0);
    v14 = fn_1_D2D48();
    for (v9 = 0; v9 < v14; v9++) {
        loc_3C[v9].x = arg0 + 22 + v9 * 88;
        loc_3C[v9].y = arg1 + 30;
        loc_3C[v9].width = 68.0f;
        loc_3C[v9].x2 = arg0 + 22 + v9 * 88;
        loc_3C[v9].y2 = arg1 + 26;
        if (fn_1_D2D38() != 0) {
            u32 loc_18[4];
            u32 loc_8[4];
            *(struct fn_1_144254_Copy16 *)loc_18 = fzgx_pool_init_fn_1_144254_names.v;
            *(struct fn_1_144254_Copy16 *)loc_8 = fzgx_pool_init_fn_1_144254_details.v;
            v10 = loc_28;
            v26 = loc_3C[v9].x + loc_3C[v9].width / 2.0f;
            v24 = 10.0f + (loc_3C[v9].y + loc_3C[v9].width / 2.0f);
            fn_80008BEC(v10, 0, 17);
            strncpy(v10, (char *)loc_18[v9], 16);
            v27 = loc_8[v9];
            loc_84 = *(struct fn_1_144254_Copy88 *)lbl_1_rodata_26F8;
            loc_84.a[0] = 12;
            loc_84.a[12] = 6;
            *(f32 *)((u8 *)&loc_84 + 4) = v26;
            *(f32 *)((u8 *)&loc_84 + 8) = 10.0f + v24;
            *(f32 *)((u8 *)&loc_84 + 12) = 1.0f;
            loc_84.a[12] = 6;
            fn_1_50164(86.0f, 30.0f,
                8.0f, 8.0f, &loc_84);
            if (loc_28[0] != 0) {
                fn_1_49410();
                fn_1_496FC(v26, 15.0f + v24);
                fn_1_495C8(1);
                fn_1_4955C(0.375f, 0.375f);
                fn_1_4965C(2);
                fn_1_495B0(0x40000000);
                fn_1_49590(0.5f);
                fn_1_4CE48((Obj_1_bss_4B9CC *)v10, 80.0f);
                fn_1_49410();
                fn_1_496FC(v26, 12.0f + (14.0f + v24));
                fn_1_495C8(1);
                fn_1_4955C(0.375f, 0.375f);
                fn_1_4965C(2);
                fn_1_49590(0.5f);
                fn_1_495B0((3U << 30));
                fn_1_4CE48((Obj_1_bss_4B9CC *)v27, 80.0f);
            } else {
                fn_1_49410();
                fn_1_496FC(v26, 21.0f + v24);
                fn_1_495C8(1);
                fn_1_4955C(0.375f, 0.375f);
                fn_1_4965C(2);
                fn_1_49590(0.5f);
                fn_1_495B0((3U << 30));
                fn_1_4A0D8((char *)lbl_1_data_42570);
            }
        }
    }
    v29 = fn_1_C8294(loc_3C, v14, 0);
    v31 = fn_1_D2D38() ? 4 : 6;
    v9 = (u8)v14;
    if ((u32)v9 < v31) {
    for (; v9 < v31; v9++) {
            loc_84 = *(struct fn_1_144254_Copy88 *)lbl_1_rodata_26F8;
            loc_84.a[0] = 0x9735;
            *(f32 *)((u8 *)&loc_84 + 4) = (f32)(arg0 + 22 + v9 * 88);
            *(f32 *)((u8 *)&loc_84 + 8) = (f32)(arg1 + 30);
            *(f32 *)((u8 *)&loc_84 + 12) = 10.0f;
            fn_1_4F734((FontDrawPacket *)&loc_84);
            loc_84.a[0] = 0x9714;
            *(f32 *)((u8 *)&loc_84 + 4) = (f32)(arg0 + 18 + v9 * 88);
            *(f32 *)((u8 *)&loc_84 + 8) = (f32)(arg1 + 26);
            *(f32 *)((u8 *)&loc_84 + 12) = 2.0f;
            fn_1_4F734((FontDrawPacket *)&loc_84);
    }
    }
    loc_84 = *(struct fn_1_144254_Copy88 *)lbl_1_rodata_26F8;
    loc_84.a[0] = 0x9726;
    fn_1_51678((FontDrawPacket *)&loc_84, loc_84.a[0], 0, 0, 22, fn_1_486C4(loc_84.a[0]));
    *(f32 *)((u8 *)&loc_84 + 4) = 44.0f;
    *(f32 *)((u8 *)&loc_84 + 8) = (f32)(arg1 + 64);
    *(f32 *)((u8 *)&loc_84 + 12) = 100.0f;
    loc_84.a[12] = 9;
    fn_1_4F734((FontDrawPacket *)&loc_84);
    v48 = fn_1_D2D38() ? 3 : 5;
    for (v9 = 0; v9 < v48; v9++) {
        loc_84 = *(struct fn_1_144254_Copy88 *)lbl_1_rodata_26F8;
        loc_84.a[0] = 0x9709;
        fn_1_51678((FontDrawPacket *)&loc_84, loc_84.a[0], 0, 0, 20, fn_1_486C4(loc_84.a[0]));
        *(f32 *)((u8 *)&loc_84 + 4) = (f32)(144 + v9 * 88);
        *(f32 *)((u8 *)&loc_84 + 8) = (f32)(arg1 + 64);
        *(f32 *)((u8 *)&loc_84 + 12) = 100.0f;
        *(f32 *)((u8 *)&loc_84 + 16) *= 1.1f;
        loc_84.a[12] = 10;
        fn_1_4F734((FontDrawPacket *)&loc_84);
    }
    loc_84 = *(struct fn_1_144254_Copy88 *)lbl_1_rodata_26F8;
    loc_84.a[0] = 0x9726;
    fn_1_51678((FontDrawPacket *)&loc_84, loc_84.a[0], 110, 0, 22, fn_1_486C4(loc_84.a[0]));
    if (fn_1_D2D38() != 0)
        *(f32 *)((u8 *)&loc_84 + 4) = 399.0f;
    else
        *(f32 *)((u8 *)&loc_84 + 4) = 574.0f;
    *(f32 *)((u8 *)&loc_84 + 8) = (f32)(arg1 + 64);
    *(f32 *)((u8 *)&loc_84 + 12) = 100.0f;
    loc_84.a[12] = 9;
    fn_1_4F734((FontDrawPacket *)&loc_84);
    if (fn_1_D2D38() != 0) {
        loc_84 = *(struct fn_1_144254_Copy88 *)lbl_1_rodata_26F8;
        if (v29 == 0) {
            loc_84.a[0] = 0x980A;
            fn_1_53830(60, 50, (u8 *)&loc_84 + 0x3C, (u8 *)&loc_84 + 0x38, 0.85f);
        } else {
            loc_84.a[0] = 0x9808;
        }
        *(f32 *)((u8 *)&loc_84 + 4) = 510.0f;
        *(f32 *)((u8 *)&loc_84 + 8) = (f32)(arg1 + 64);
        *(f32 *)((u8 *)&loc_84 + 12) = 100.0f;
        loc_84.a[12] = 10;
        fn_1_4F734((FontDrawPacket *)&loc_84);
    }
    }
    }
}
/* fzgx:end fn_1_144254 */

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

/* fzgx:begin fn_1_144F40 noprologue */
#include "types.h"
#include "font.h"
#include "fpscr_trunc.h"

/* one results row: the layout fn_1_145C6C .. fn_1_1498B8 read */
typedef struct {
    u8 r, g, b, a;
} Color;

typedef struct {
    u32 image;
    f32 x, y, z;
    f32 scale_x, scale_y;
    f32 u0, v0, u1, v1;
    s16 rotation_z, rotation_y;
    f32 alpha;
    u32 flags;
    f32 depth;
    Color color, color_add;
    u32 format;
    u16 width, height;
    void *pixels;
    FontDrawPacket *secondary;
    void (*vertex_callback)(const FontDrawPacket *packet, FontVertex *vertices);
    u32 unk_54;
} Packet;

typedef struct {
    s32 x;          /* 0x00 */
    s32 y;          /* 0x04 */
    s32 unk_8;      /* 0x08 */
    s32 unk_C;      /* 0x0C */
    s32 unk_10;     /* 0x10 */
    s32 unk_14;     /* 0x14 */
    f32 unk_18;     /* 0x18 */
    f32 unk_1C;     /* 0x1C */
    s32 unk_20;     /* 0x20 */
    s32 unk_24;     /* 0x24 */
    void *unk_28;   /* 0x28 */
    u32 unk_2C;     /* 0x2C */
    u32 unk_30;     /* 0x30 */
    u8 unk_34;      /* 0x34 */
    u8 unk_35;      /* 0x35 */
    u8 unk_36;
    u8 unk_37;
    u8 unk_38;
    u8 unk_39;
    u8 pad_3A[2];
    u32 unk_3C;     /* 0x3C */
    u16 unk_40;     /* 0x40 */
    u16 unk_42[5];  /* 0x42 */
    s32 unk_4C;     /* 0x4C */
    u8 pad_50[4];
    u16 unk_54;     /* 0x54 */
    u8 unk_56[5];   /* 0x56 */
    u8 pad_5B;
    s32 unk_5C;     /* 0x5C */
    u8 unk_60;
    u8 unk_61;
    u16 unk_62;
    s32 unk_64;
    s32 unk_68;
    s32 unk_6C;
    s32 unk_70;
    s32 unk_74;
    s32 unk_78;
    Packet packet[3]; /* 0x7C */
} Row;

/* one 0x38-byte entry of lbl_1_bss_8EF68 */
typedef struct {
    u32 unk_0;
    u32 unk_4;
    u8 unk_8[0x10];
    u16 unk_18;
    u8 unk_1A;
    u8 unk_1B;
    u8 unk_1C;
    u8 unk_1D;
    u8 unk_1E;
    u8 unk_1F;
    u8 pad_20[0x18];
} Entry;

/* one seat's 0xA0-byte result record at lbl_1_bss_3C30+0xD4 */
typedef struct {
    u32 unk_0;
    u16 unk_4;
    u8 pad_6[2];
    u8 unk_8;
    u8 unk_9[5];
    u8 unk_E[0x16];
    u32 unk_24[10];
    u16 unk_4C[5];
    u8 pad_56[0x2A];
    u8 unk_80;
    u8 pad_81;
    u8 unk_82;
    u8 unk_83;
    u8 pad_84[0x1A];
    u16 unk_9E;
} Record;

typedef struct {
    u8 pad_0[6];
    u8 unk_6;
    u8 pad_7[2];
    u8 unk_9;
    u8 pad_A[0x9D];
    u8 unk_A7;
    u8 pad_A8[0x2C];
    Record unk_D4[30];
} Setup;


/* the viewport block: separate TU statics at the start of .bss (dtk splits at 8E43C/8E440): the
 * order table, then two horizontal spans and one vertical */
static u8 *lbl_1_bss_8E428;
static u32 view_x0;
static u32 view_w0;
static u32 view_x1;
static u32 view_w1;
static u32 lbl_1_bss_8E43C;
static u32 lbl_1_bss_8E440;
extern f32 lbl_1_bss_8E530;
extern f32 lbl_1_bss_8E534;
extern s32 lbl_1_bss_8E538;
extern s32 lbl_1_bss_8E53C;
extern u8 lbl_1_bss_8E548;
extern u32 lbl_1_bss_8E528;
extern Setup lbl_1_bss_3C30;
extern Entry lbl_1_bss_8EF68[];
extern s16 lbl_1_bss_960;
extern u32 lbl_801A66A4;
extern const FontDrawPacket lbl_1_rodata_26F8;
extern char lbl_1_data_424D0[];
extern char lbl_1_data_424E4[];
extern char lbl_1_data_424F8[];
extern char lbl_1_data_4250C[];
extern char lbl_1_data_42520[];
extern char lbl_1_data_42534[];
extern char lbl_1_data_42548[];
extern char lbl_1_data_4255C[];


extern void fn_1_52070(u32);
extern void fn_1_52088(void);
extern void *fn_80008BEC(void *, int, u32);
extern void fn_1_51914(FontDrawPacket *);
extern void fn_1_A2D84(u32);
extern u32 __cvt_fp2unsigned(f32);
extern void fn_1_145C6C(s32, Row *);
extern BOOL fn_1_145B58(s32, Row *);
extern void fn_1_146550(s32, Row *);
extern void fn_1_146B5C(s32, Row *);
extern void fn_1_146C88(s32, Row *);
extern void fn_1_147188(s32, Row *);
extern void fn_1_147508(s32, Row *);
extern void fn_1_147A04(s32, Row *);
extern void fn_1_148444(s32, Row *);
extern void fn_1_148738(s32, Row *);
extern void fn_1_148950(s32, Row *);
extern void fn_1_1490FC(s32, Row *);
extern void fn_1_1492E0(s32, Row *);
extern void fn_1_1498B8(s32, f32, s32, s32, s32, s32, s32);
extern void fn_1_149BF4(const FontDrawPacket *, FontVertex *);
extern void fn_1_149C2C(const FontDrawPacket *, FontVertex *);
extern void fn_1_149C64(const FontDrawPacket *, FontVertex *);

/* retail .rodata (lbl_1_rodata_92C0) up to this function's own constants at 0x414 */
#define FZGX_PACKET(cb) \
    { 0, 0.0f, 0.0f, 0.1f, 1.0f, 1.0f, 0.0f, 0.0f, 1.0f, 1.0f, 0, 0, 1.0f, 0x04000000, 0.0f, \
      { 0xFF, 0xFF, 0xFF, 0xFF }, { 0, 0, 0, 0 }, 0, 0, 0, NULL, NULL, cb, 0 }

#pragma section code_type ".fzgxpool"
static const Packet fzgx_pool_rodata_0 = FZGX_PACKET(fn_1_149BF4);
static const Packet fzgx_pool_rodata_58 = FZGX_PACKET(fn_1_149C2C);
static const Packet fzgx_pool_rodata_B0 = FZGX_PACKET(fn_1_149C64);
__declspec(section ".fzgxpool") static void fzgx_pool_keep_0(void) { const Packet *volatile cp; cp = &fzgx_pool_rodata_0; cp = &fzgx_pool_rodata_58; cp = &fzgx_pool_rodata_B0; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime_108(void) { volatile f32 s; s = 0.0f; }  /* fzgx-allow: S2 pool primer sink */
static const u32 fzgx_pool_rodata_10C[6] = {0x3F755555, 0x41B80000, 0x40000000, 0x3F2AAAAB, 0x3F000000, 0x3F155555};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep_10C(void) { const u32 *volatile cp; cp = fzgx_pool_rodata_10C; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime_128(s32 n) { volatile f32 s; s = (f32)n; }  /* fzgx-allow: S2 pool primer sink */
static const u32 fzgx_pool_rodata_130[36] = {0x44150000, 0x44040000, 0x0000001A, 0x00000023, 0x0000009C, 0x000000A5, 0x00000018, 0x00000021, 0x00000085, 0x0000008E, 0x000000F2, 0x000000FB, 0xC0C0C000, 0xC0800000, 0x42200000, 0x43F00000, 0x44200000, 0x47AFC800, 0x3E99999A, 0x3F333333, 0xBF800000, 0x43500000, 0xC47A0000, 0xC2480000, 0x3F800000, 0x41200000, 0x430C0000, 0x43600000, 0x437E0000, 0x43800000, 0xC0C00000, 0x40A00000, 0x40800000, 0x41400000, 0x41700000, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep_130(void) { const u32 *volatile cp; cp = fzgx_pool_rodata_130; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime_1C0(u32 n) { volatile f32 s; s = (f32)n; }  /* fzgx-allow: S2 pool primer sink */
static const u32 fzgx_pool_rodata_1C8[93] = {0x4E4F204E, 0x414D4500, 0x4E4F2044, 0x41544100, 0x42C80000, 0x43AF0000, 0x42300000, 0x41000000, 0xFFFFFFFF, 0x00F0E6FF, 0x007873FF, 0xA0FF00FF, 0x0000001A, 0x00000023, 0x0000013C, 0x00000145, 0x00000018, 0x00000021, 0x00000065, 0x0000006E, 0x000000B2, 0x000000BB, 0x41F00000, 0x3F400000, 0x42580000, 0x43AB8000, 0x47800000, 0x42F00000, 0x3EB33333, 0xFFFFFFFF, 0x00F0E6FF, 0x007873FF, 0xFFFF00FF, 0xFFFF00FF, 0x8080FFFF, 0x0000001A, 0x00000023, 0x0000013C, 0x00000145, 0x00000018, 0x00000021, 0x00000065, 0x0000006E, 0x000000B2, 0x000000BB, 0x19FF1900, 0x19FF1900, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x406FE000, 0x00000000, 0x41A00000, 0x0000001A, 0x00000023, 0x0000013C, 0x00000145, 0xFFFFFF00, 0x19FF1900, 0x0000001A, 0x00000023, 0x0000013C, 0x00000145, 0x19FF1900, 0x00FFFFFF, 0x00FFFFFF, 0xFFFFFF00, 0x3F4CCCCD, 0xC0000000, 0x0000001A, 0x00000023, 0x0000013C, 0x00000145, 0x00000018, 0x00000021, 0x0000001A, 0x00000023, 0x0000013C, 0x00000145, 0x00000018, 0x00000021, 0xFFFF00FF, 0x19FF1900, 0x00000000, 0x0000001A, 0x00000023, 0x0000013C, 0x00000145, 0x19FF1900};  /* fzgx-allow: A1 retail pool bytes */
static const char *const fzgx_pool_rodata_33C[8] = {lbl_1_data_424D0, lbl_1_data_424E4, lbl_1_data_424F8, lbl_1_data_4250C, lbl_1_data_42520, lbl_1_data_42534, lbl_1_data_42548, lbl_1_data_4255C};  /* fzgx-allow: A1 retail pool pointers */
static const u32 fzgx_pool_rodata_35C[46] = {0x42880000, 0x42AC0000, 0x3EC00000, 0x42A00000, 0x41600000, 0x41A80000, 0x3F8CCCCD, 0x43C78000, 0x440F8000, 0x3F59999A, 0x43FF0000, 0x19FF1900, 0x19FF1900, 0xF4962800, 0xF4962800, 0xFFFF0000, 0x00000000, 0xFFFFFF00, 0xF4962800, 0xF4962800, 0xFFFF0000, 0x00000000, 0xFFFFFF00, 0xF4962800, 0xFFFF00FF, 0x00000000, 0x19FF1900, 0x19FF1900, 0xF4962800, 0xF4962800, 0x8080FF00, 0x00000000, 0xFFFFFF00, 0xF4962800, 0xF4962800, 0x8080FF00, 0x00000000, 0xFFFFFF00, 0x43B10000, 0x42A80000, 0x41B00000, 0x3F266666, 0x43400000, 0x42400000, 0x42380000, 0x425C0000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep_1C8(void) { const u32 *volatile cp; cp = fzgx_pool_rodata_1C8; }
__declspec(section ".fzgxpool") static void fzgx_pool_keep_33C(void) { const char *const *volatile cp; cp = fzgx_pool_rodata_33C; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_keep_35C(void) { const u32 *volatile cp; cp = fzgx_pool_rodata_35C; }  /* fzgx-allow: S2 pool primer sink */  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_bss_order(void) {
    volatile u8 s;  /* fzgx-allow: S2 layout primer sink */
    s = *(u8 *)&lbl_1_bss_8E428;
    s = *(u8 *)&view_x0;
    s = *(u8 *)&view_w0;
    s = *(u8 *)&view_x1;
    s = *(u8 *)&view_w1;
    s = *(u8 *)&lbl_1_bss_8E43C;
    s = *(u8 *)&lbl_1_bss_8E440;
}
#pragma section code_type ".text"

static inline BOOL in_4_5(s32 mode) {
    BOOL r = TRUE;
    if (!((u32)(mode - 4) <= 1)) r = FALSE;
    return r;
}
static inline BOOL in_4_5_9(s32 mode) {
    BOOL r = TRUE;
    if (!in_4_5(mode) && mode != 9) r = FALSE;
    return r;
}
static inline BOOL in_4_5_9_10(s32 mode) {
    BOOL r = TRUE;
    if (!in_4_5_9(mode) && mode != 10) r = FALSE;
    return r;
}
static inline BOOL in_4_5_6_9_10(s32 mode) {
    BOOL r = TRUE;
    if (!in_4_5_9_10(mode) && mode != 6) r = FALSE;
    return r;
}
static inline BOOL in_8_9(s32 mode) {
    BOOL r = TRUE;
    if (!((u32)(mode - 8) <= 1)) r = FALSE;
    return r;
}
static inline BOOL in_8_9_10(s32 mode) {
    BOOL r = TRUE;
    if (!in_8_9(mode) && mode != 10) r = FALSE;
    return r;
}
static inline BOOL in_0_1(s32 mode) {
    BOOL r = TRUE;
    if (!((u32)mode <= 1)) r = FALSE;
    return r;
}
static inline BOOL in_0_2_7_8(s32 mode) {
    BOOL r = FALSE;
    if (mode == 0 || mode == 2 || mode == 8 || mode == 7) r = TRUE;
    return r;
}

static inline BOOL in_range(const Row *row, s32 hi) {
    return row->unk_20 > hi ? FALSE : row->unk_20 >= 0;
}

#define MIN(a, b) ((a) > (b) ? (b) : (a))
#define CLAMP(x, lo, hi) ((x) < (lo) ? (lo) : (x) > (hi) ? (hi) : (x))

#define CLIP(pos, size, x, w, max) \
    pos = MIN(x, max); \
    size = (MIN((pos + w), max) - pos)


static inline BOOL in_any(s32 mode) {
    BOOL r = TRUE;
    if (!in_0_2_7_8(mode) && !in_4_5_6_9_10(mode)) r = FALSE;
    return r;
}

void fn_1_144F40(s32 mode, u8 *arg1) {
    Row rowbuf;
    Row *row = &rowbuf;
    FontDrawPacket packet;
    s32 i;
    Entry *e;
    Record *rec;
    s32 idx;
    u32 left;
    s32 k;

    fn_1_52070(0x140);
    fn_80008BEC(row, 0, sizeof(*row));
    if (in_0_2_7_8(mode) || in_4_5_6_9_10(mode)) {
        row->unk_18 = lbl_1_bss_8E530;
        row->unk_1C = lbl_1_bss_8E538;
    } else {
        row->unk_18 = lbl_1_bss_8E534;
        row->unk_1C = lbl_1_bss_8E53C;
    }
    if (arg1 == NULL) {
        row->unk_34 = lbl_1_bss_3C30.unk_6;
    } else {
        row->unk_34 = arg1[0];
    }
    packet = lbl_1_rodata_26F8;
    packet.image = 0x9437;
    fn_1_51914(&packet);
    fn_1_145C6C(mode, row);

    row->unk_10 = 0;
    row->unk_14 = 0;
    if (in_4_5_6_9_10(mode)) {
        row->x = 0x9E;
        row->y = 0x48;
        row->unk_8 = 1;
        row->unk_C = 1;
        row->unk_10 = -2;
        row->unk_14 = -4;
    } else if (in_8_9_10(mode)) {
        row->x = 0x68;
        row->y = 0x41;
        row->unk_8 = 1;
        row->unk_C = 1;
    } else if (in_0_1(mode)) {
        row->x = 0x6C;
        row->y = 0x38;
        row->unk_8 = 1;
        row->unk_C = 1;
    } else if (lbl_1_bss_8E548 <= 4) {
        row->x = 0x77;
        row->y = 0x48;
        row->unk_8 = 0;
        row->unk_C = 0;
    } else {
        row->x = 0x6C;
        row->y = 0x38;
        row->unk_8 = 1;
        row->unk_C = 1;
    }
    row->unk_68 = in_any(mode) ? 0 : 10;
    row->unk_78 = lbl_801A66A4 - lbl_1_bss_8E528;
    if (row->unk_78 == 16) {
        fn_1_A2D84(0xA9010600);
    }

    for (i = -row->unk_8; i < lbl_1_bss_8E548 + row->unk_C; i++) {
        row->unk_20 = i + (s32)row->unk_18;
        if (in_4_5_6_9_10(mode)) {
            if (!in_range(row, 9)) {
                continue;
            }
            e = &lbl_1_bss_8EF68[row->unk_20];
            row->unk_24 = e->unk_1B;
            row->unk_28 = e->unk_8;
            row->unk_30 = e->unk_0;
            row->unk_3C = e->unk_4;
            row->unk_40 = e->unk_18;
            row->unk_35 = e->unk_1A;
            row->unk_36 = e->unk_1C;
            row->unk_37 = e->unk_1D;
            row->unk_38 = e->unk_1E;
            row->unk_39 = e->unk_1F;
        } else if (in_8_9_10(mode)) {
            if (!in_range(row, lbl_1_bss_3C30.unk_9 - 1)) {
                continue;
            }
            idx = lbl_1_bss_8E428[row->unk_20];
            row->unk_4C = idx;
            rec = &lbl_1_bss_3C30.unk_D4[idx];
            row->unk_5C = rec->unk_E[lbl_1_bss_3C30.unk_A7];
            row->unk_24 = rec->unk_80;
            row->unk_2C = rec->unk_0;
            row->unk_35 = rec->unk_82;
            row->unk_30 = rec->unk_24[lbl_1_bss_3C30.unk_A7];
        } else {
            if (!in_range(row, lbl_1_bss_3C30.unk_9 - 1)) {
                continue;
            }
            idx = lbl_1_bss_8E428[row->unk_20];
            row->unk_4C = idx;
            rec = &lbl_1_bss_3C30.unk_D4[idx];
            row->unk_5C = rec->unk_E[lbl_1_bss_3C30.unk_A7];
            row->unk_54 = rec->unk_4;
            row->unk_62 = rec->unk_9E;
            row->unk_24 = rec->unk_80;
            row->unk_35 = rec->unk_82;
            row->unk_2C = rec->unk_0;
            for (k = 0; k < 5; k++) {
                row->unk_56[k] = rec->unk_9[k];
                row->unk_42[k] = rec->unk_4C[k];
            }
            row->unk_30 = rec->unk_24[lbl_1_bss_3C30.unk_A7];
            row->unk_60 = rec->unk_8;
            row->unk_61 = rec->unk_83;
        }
        row->packet[0] = fzgx_pool_rodata_0;
        row->packet[1] = fzgx_pool_rodata_58;
        row->packet[2] = fzgx_pool_rodata_B0;
        if (fn_1_145B58(mode, row)) {
            static const Color fzgx_pool_color = {0xFA, 0xDC, 0x82, 0xFF};
            Color color_add = {0, 0, 0, 0};
            row->packet[2].color = fzgx_pool_color;
            row->packet[1].color = fzgx_pool_color;
            row->packet[0].color = fzgx_pool_color;
            row->packet[2].color_add = color_add;
            row->packet[1].color_add = color_add;
            row->packet[0].color_add = color_add;
        }
        row->unk_6C = CLAMP(555 - row->unk_78 * 40, 0, 555);
        row->unk_70 = row->unk_6C + CLAMP(610 - row->unk_78 * 40, 0, 55);
        row->unk_74 = row->unk_6C + CLAMP(row->unk_78 * 60 - 1415, -455, 0);
        row->unk_64 = row->x + (row->y * (i - (row->unk_18 - fpscr_trunc(row->unk_18))));
        left = 0;
        view_x0 = left;
        view_x1 = view_w0 = 120 + row->unk_68 + row->unk_6C;
        view_w1 = 640;
        lbl_1_bss_8E43C = row->x - 6;
        lbl_1_bss_8E440 = lbl_1_bss_8E548 * row->y;
        CLIP(view_x0, view_w0, left, view_w0, 639.0f);
        CLIP(view_x1, view_w1, view_x1, 640, 639.0f);
        CLIP(lbl_1_bss_8E43C, lbl_1_bss_8E440, lbl_1_bss_8E43C, lbl_1_bss_8E440, 479.0f);
        fn_1_146550(mode, row);
        fn_1_146B5C(mode, row);
        fn_1_146C88(mode, row);
        fn_1_147188(mode, row);
        fn_1_147508(mode, row);
        fn_1_147A04(mode, row);
        fn_1_148444(mode, row);
        fn_1_148738(mode, row);
        fn_1_148950(mode, row);
        fn_1_1490FC(mode, row);
    }
    fn_1_1492E0(mode, row);
    if (lbl_1_bss_960 != 10) {
        fn_1_1498B8(mode, row->unk_1C, lbl_1_bss_8E548, row->y, row->x, row->unk_10, row->unk_14);
    }
    fn_1_52088();
}
/* fzgx:end fn_1_144F40 */

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

/* fzgx:begin fn_1_145C6C */
#pragma section code_type ".fzgxpool"
static const unsigned long fzgx_pool_table1[3] = {0x00000000, 0x00000000, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep1(void) { const unsigned long *volatile cp; cp = fzgx_pool_table1; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime2(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    s = 0.10000000149011612f;
}
static const unsigned long fzgx_pool_table3[62] = {0x3F800000, 0x3F800000, 0x00000000, 0x00000000, 0x3F800000, 0x3F800000, 0x00000000, 0x3F800000, 0x04000000, 0x00000000, 0xFFFFFFFF, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x3DCCCCCD, 0x3F800000, 0x3F800000, 0x00000000, 0x00000000, 0x3F800000, 0x3F800000, 0x00000000, 0x3F800000, 0x04000000, 0x00000000, 0xFFFFFFFF, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x3DCCCCCD, 0x3F800000, 0x3F800000, 0x00000000, 0x00000000, 0x3F800000, 0x3F800000, 0x00000000, 0x3F800000, 0x04000000, 0x00000000, 0xFFFFFFFF, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
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
    s = 596.0f;
    s = 528.0f;
}
static const unsigned long fzgx_pool_table7[11] = {0x0000001A, 0x00000023, 0x0000009C, 0x000000A5, 0x00000018, 0x00000021, 0x00000085, 0x0000008E, 0x000000F2, 0x000000FB, 0xC0C0C000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep7(void) { const unsigned long *volatile cp; cp = fzgx_pool_table7; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime8(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
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
    s = 1.0f;
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
static const unsigned long fzgx_pool_table9[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep9(void) { const unsigned long *volatile cp; cp = fzgx_pool_table9; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime10(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    d = 4503599627370496.0;
}
static const unsigned long fzgx_pool_table11[1] = {0x4E4F204E};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep11(void) { const unsigned long *volatile cp; cp = fzgx_pool_table11; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime12(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    s = 12.829345703125f;
}
static const unsigned long fzgx_pool_table13[1] = {0x4E4F2044};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep13(void) { const unsigned long *volatile cp; cp = fzgx_pool_table13; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime14(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    s = 13.265869140625f;
    s = 100.0f;
    s = 350.0f;
    s = 44.0f;
    s = 8.0f;
}
static const unsigned long fzgx_pool_table15[14] = {0xFFFFFFFF, 0x00F0E6FF, 0x007873FF, 0xA0FF00FF, 0x0000001A, 0x00000023, 0x0000013C, 0x00000145, 0x00000018, 0x00000021, 0x00000065, 0x0000006E, 0x000000B2, 0x000000BB};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep15(void) { const unsigned long *volatile cp; cp = fzgx_pool_table15; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime16(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    s = 30.0f;
    s = 0.75f;
    s = 54.0f;
    s = 343.0f;
    s = 65536.0f;
    s = 120.0f;
    s = 0.3499999940395355f;
}
static const unsigned long fzgx_pool_table17[25] = {0xFFFFFFFF, 0x00F0E6FF, 0x007873FF, 0xFFFF00FF, 0xFFFF00FF, 0x8080FFFF, 0x0000001A, 0x00000023, 0x0000013C, 0x00000145, 0x00000018, 0x00000021, 0x00000065, 0x0000006E, 0x000000B2, 0x000000BB, 0x19FF1900, 0x19FF1900, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep17(void) { const unsigned long *volatile cp; cp = fzgx_pool_table17; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime18(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    s = 3.748046875f;
}
static const unsigned long fzgx_pool_table19[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep19(void) { const unsigned long *volatile cp; cp = fzgx_pool_table19; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime20(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    s = 20.0f;
}
static const unsigned long fzgx_pool_table21[14] = {0x0000001A, 0x00000023, 0x0000013C, 0x00000145, 0xFFFFFF00, 0x19FF1900, 0x0000001A, 0x00000023, 0x0000013C, 0x00000145, 0x19FF1900, 0x00FFFFFF, 0x00FFFFFF, 0xFFFFFF00};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep21(void) { const unsigned long *volatile cp; cp = fzgx_pool_table21; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime22(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    s = 0.800000011920929f;
    s = -2.0f;
}
static const unsigned long fzgx_pool_table23[28] = {0x0000001A, 0x00000023, 0x0000013C, 0x00000145, 0x00000018, 0x00000021, 0x0000001A, 0x00000023, 0x0000013C, 0x00000145, 0x00000018, 0x00000021, 0xFFFF00FF, 0x19FF1900, 0x00000000, 0x0000001A, 0x00000023, 0x0000013C, 0x00000145, 0x19FF1900, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep23(void) { const unsigned long *volatile cp; cp = fzgx_pool_table23; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime24(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    s = 68.0f;
    s = 86.0f;
    s = 0.375f;
    s = 80.0f;
    s = 14.0f;
    s = 21.0f;
    s = 1.100000023841858f;
    s = 399.0f;
    s = 574.0f;
    s = 0.8500000238418579f;
    s = 510.0f;
}
static const unsigned long fzgx_pool_table25[27] = {0x19FF1900, 0x19FF1900, 0xF4962800, 0xF4962800, 0xFFFF0000, 0x00000000, 0xFFFFFF00, 0xF4962800, 0xF4962800, 0xFFFF0000, 0x00000000, 0xFFFFFF00, 0xF4962800, 0xFFFF00FF, 0x00000000, 0x19FF1900, 0x19FF1900, 0xF4962800, 0xF4962800, 0x8080FF00, 0x00000000, 0xFFFFFF00, 0xF4962800, 0xF4962800, 0x8080FF00, 0x00000000, 0xFFFFFF00};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep25(void) { const unsigned long *volatile cp; cp = fzgx_pool_table25; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime26(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    s = 354.0f;
    s = 84.0f;
    s = 22.0f;
    s = 0.6499999761581421f;
    s = 192.0f;
    s = 48.0f;
    s = 46.0f;
    s = 55.0f;
}
static const unsigned long fzgx_pool_table27[2] = {0xFADC82FF, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep27(void) { const unsigned long *volatile cp; cp = fzgx_pool_table27; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime28(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    s = 639.0f;
    s = 479.0f;
    s = 320.0f;
    s = 70.0f;
    s = 112.0f;
    s = 492.0f;
    s = 33.0f;
    s = 19.0f;
}

/* TU string-literal pool (lbl_1_data_42198): the TU's earlier functions emit these literals and
 * two local aggregate initializers in this order, so the function's own literals land at +0x3E0. */
__declspec(section ".fzgxpool") static void fzgx_strings_prime1(void) {
    fn_1_4A0D8("NON");
    fn_1_4A0D8("MASTER RECV");
    fn_1_4A0D8("MASTER SEND");
    fn_1_4A0D8("SLAVE SEND");
    fn_1_4A0D8("SLAVE RECV");
    fn_1_4A0D8("INIT");
    fn_1_4A0D8("TEST");
    fn_1_4A0D8("TESTEND");
    fn_1_4A0D8("SETUP");
    fn_1_4A0D8("SETUP_DONE");
    fn_1_4A0D8("SETUP_COUNTER");
    fn_1_4A0D8("SETUP_CNT_DONE");
    fn_1_4A0D8("UNLINK");
    fn_1_4A0D8("COIN");
    fn_1_4A0D8("ENTRY_WAIT");
    fn_1_4A0D8("CHALLENGER");
    fn_1_4A0D8("CHALLENGER_OK");
    fn_1_4A0D8("ENTRY");
    fn_1_4A0D8("ENTRY_OK");
    fn_1_4A0D8("SINGLECHECK");
    fn_1_4A0D8("SINGLECHECK_OK");
    fn_1_4A0D8("COURSE");
    fn_1_4A0D8("COURSE_OK");
    fn_1_4A0D8("COURSE_DATA");
    fn_1_4A0D8("COURSE_DATA_OK");
    fn_1_4A0D8("MACHINE");
    fn_1_4A0D8("MACHINE_OK");
    fn_1_4A0D8("CONFIG");
    fn_1_4A0D8("CONFIG_OK");
    fn_1_4A0D8("COUNTERADJUST");
    fn_1_4A0D8("LINKWAIT");
    fn_1_4A0D8("LINKWAITOK");
    fn_1_4A0D8("LINKSEL");
    fn_1_4A0D8("LINKDELIVERYSTART");
    fn_1_4A0D8("LINKDELIVERY");
    fn_1_4A0D8("LINKDELIVERYOK");
    fn_1_4A0D8("LINKSELOK");
    fn_1_4A0D8("COURSEVIEW");
    fn_1_4A0D8("COURSEVIEW_OK");
    fn_1_4A0D8("LINKREQ");
    fn_1_4A0D8("LINKSTANDBY");
    fn_1_4A0D8("LINKOK");
    fn_1_4A0D8("LINK");
    fn_1_4A0D8("PAUSE");
    fn_1_4A0D8("ERROR");
}
extern void fn_1_1420E0(void);
extern void fn_1_144E90(void);
extern void fn_1_144EE8(void);
extern void fn_1_149E2C(void);
extern void fn_1_149F04(void);
extern void fn_1_149DA4(void);
extern void fn_1_149DE8(void);
extern void fn_1_149F5C(void);
extern void fn_1_14A000(void);
extern void fn_1_14A004(void);
extern void fn_1_14A008(void);
/* two file-scope statics of the TU sit between the two literal groups (+0x200 and +0x2B4) */
static Obj_1_data_212A8 fzgx_pool_fzgx_data_zero_block = {0};
/* retail: a table of 11 handler pointers (fn_1_1420E0 ...); plain words keep the primer relocation-free */
static u32 fzgx_pool_fzgx_data_handlers[11] = {0};
__declspec(section ".fzgxpool") static void fzgx_strings_keep(void) { void *volatile p; p = &fzgx_pool_fzgx_data_zero_block; p = fzgx_pool_fzgx_data_handlers; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_strings_prime2(void) {
    fn_1_4A0D8("[");
    fn_1_4A0D8("]");
}
#pragma section code_type ".text"

typedef struct {
    u8 pad_0[0x34];
    u8 unk_34;
} Row;

extern void fn_1_12EF80(s16 value, s16 *row, s16 *column);

static inline BOOL in_4_5(s32 mode) {
    BOOL r = TRUE;
    if (!((u32)(mode - 4) <= 1)) r = FALSE;
    return r;
}
static inline BOOL in_4_5_9(s32 mode) {
    BOOL r = TRUE;
    if (!in_4_5(mode) && mode != 9) r = FALSE;
    return r;
}
static inline BOOL in_4_5_9_10(s32 mode) {
    BOOL r = TRUE;
    if (!in_4_5_9(mode) && mode != 10) r = FALSE;
    return r;
}
static inline BOOL in_4_5_6_9_10(s32 mode) {
    BOOL r = TRUE;
    if (!in_4_5_9_10(mode) && mode != 6) r = FALSE;
    return r;
}
static inline BOOL in_8_9(s32 mode) {
    BOOL r = TRUE;
    if (!((u32)(mode - 8) <= 1)) r = FALSE;
    return r;
}
static inline BOOL in_8_9_10(s32 mode) {
    BOOL r = TRUE;
    if (!in_8_9(mode) && mode != 10) r = FALSE;
    return r;
}

/* Results header: "[machine name] course text" centred in two passes (pass 0 measures, pass 1 draws),
 * then the four header sprites. Other modes go to fn_1_1461C8. */
#pragma opt_propagation off
#pragma opt_loop_invariants off
#pragma opt_lifetimes off
/* WARNING: compiler-diff device, not original code: opt_dead_assignments off keeps the dead store to
 * center_src inside the loop (see the two WARNING comments in the body). */
#pragma opt_dead_assignments off
void fn_1_145C6C(s32 mode, Row *row) {
    u32 index;
    u8 idx;
    s32 pass;
    s32 width;
    s32 left;
    f32 center_src;
    f32 center;
    const char *name;
    const char *text;
    s16 grid_row;
    s16 grid_col;
    FontDrawPacket packet;

    if (in_8_9_10(mode)) {
        width = 0;
        fn_1_49410();
        fn_1_495B0(0x80000000);
        fn_1_49738(fn_1_5233C);
        fn_1_49748(1.0f);
        index = row->unk_34;
        idx = index;
        /* WARNING: compiler-diff device, not original code: the screen centre goes through center_src
         * so that the loop preheader holds a float copy (fmr) of the 320.0f load when MWCC first schedules
         * it. Retail's preheader order needs that copy at the first schedule; the post-allocation peephole
         * then folds it into the load, so it emits no code. */
        center_src = 320.0f;
        center = center_src;
        for (pass = 0; pass <= 1; pass++) {
            left = (center - (width / 2));
            width = 0;
            fn_1_494DC(8);
            fn_1_4955C(0.5f, 0.5f);
            if (pass) {
                fn_1_496FC((left + width), 70.0f);
                fn_1_4AE0C("[");
            }
            name = (const char *)((u32 *)lbl_1_data_2AA24)[((u8 *)&lbl_1_data_2B0D4)[idx]];
            width += 12;
            fn_1_494DC(8);
            fn_1_4955C(0.5f, 0.5f);
            if (pass) {
                fn_1_496FC((left + width), 70.0f);
                /* WARNING: compiler-diff device, not original code: dead store. A second definition of
                 * center_src inside the loop stops backend copy propagation from forwarding the preheader
                 * copy above. The store is never read and is deleted at register colouring: no code. */
                center_src = 320.0f;
                fn_1_4A0D8(name);
            }
            width = (width + fn_1_4B068(name));
            fn_1_494DC(8);
            fn_1_4955C(0.5f, 0.5f);
            if (pass) {
                fn_1_496FC((left + width), 70.0f);
                fn_1_4AE0C("]");
            }
            text = (const char *)((u32 *)(lbl_1_data_2BD54 + idx * 0x18))[lbl_801A66B4];
            width += 18;
            fn_1_494DC(0x2a);
            fn_1_4955C(0.5f, 0.5f);
            if (pass) {
                fn_1_496FC((left + width), 70.0f);
                fn_1_4A0D8(text);
            }
            width = (width + fn_1_4B068(text));
        }
        fn_1_12EF80(row->unk_34, &grid_row, &grid_col);
        packet = (*(const FontDrawPacket *)&lbl_1_rodata_26F8);
        packet.image = 0x9800;
        fn_1_51564(0, 0, 36, 36, 6, 1);
        fn_1_5158C(&packet, packet.image, grid_col, 0);
        packet.x = 112.0f;
        packet.y = 30.0f;
        packet.z = 5.0f;
        fn_1_4F734(&packet);
        packet = (*(const FontDrawPacket *)&lbl_1_rodata_26F8);
        packet.image = 0x9806;
        fn_1_51564(0, 0, 36, 36, 6, 1);
        fn_1_5158C(&packet, packet.image, grid_col, 0);
        packet.x = 492.0f;
        packet.y = 30.0f;
        packet.z = 5.0f;
        fn_1_4F734(&packet);
        packet = (*(const FontDrawPacket *)&lbl_1_rodata_26F8);
        packet.image = in_4_5_6_9_10(mode) ? 0x9803 : 0x9804;
        packet.x = 320.0f;
        packet.y = 33.0f;
        packet.z = 10.0f;
        packet.flags = 6;
        fn_1_4F734(&packet);
        packet = (*(const FontDrawPacket *)&lbl_1_rodata_26F8);
        packet.image = 0x980B;
        packet.x = 320.0f;
        packet.y = 19.0f;
        packet.z = 20.0f;
        packet.flags = 6;
        fn_1_4F734(&packet);
    } else {
        fn_1_1461C8(mode, row->unk_34);
    }
}
#pragma opt_dead_assignments reset
#pragma opt_lifetimes reset
#pragma opt_loop_invariants reset
#pragma opt_propagation reset
/* fzgx:end fn_1_145C6C */

/* fzgx:begin fn_1_1461C8 noprologue */
#include "types.h"
#include "font.h"
#include "rel/main_rel/sel_static_disp.h"

#pragma section code_type ".fzgxpool"
static const unsigned long fzgx_pool_table1[3] = {0x00000000, 0x00000000, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep1(void) { const unsigned long *volatile cp; cp = fzgx_pool_table1; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime2(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    s = 0.10000000149011612f;
}
static const unsigned long fzgx_pool_table3[62] = {0x3F800000, 0x3F800000, 0x00000000, 0x00000000, 0x3F800000, 0x3F800000, 0x00000000, 0x3F800000, 0x04000000, 0x00000000, 0xFFFFFFFF, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x3DCCCCCD, 0x3F800000, 0x3F800000, 0x00000000, 0x00000000, 0x3F800000, 0x3F800000, 0x00000000, 0x3F800000, 0x04000000, 0x00000000, 0xFFFFFFFF, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x3DCCCCCD, 0x3F800000, 0x3F800000, 0x00000000, 0x00000000, 0x3F800000, 0x3F800000, 0x00000000, 0x3F800000, 0x04000000, 0x00000000, 0xFFFFFFFF, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
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
    s = 596.0f;
    s = 528.0f;
}
static const unsigned long fzgx_pool_table7[11] = {0x0000001A, 0x00000023, 0x0000009C, 0x000000A5, 0x00000018, 0x00000021, 0x00000085, 0x0000008E, 0x000000F2, 0x000000FB, 0xC0C0C000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep7(void) { const unsigned long *volatile cp; cp = fzgx_pool_table7; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime8(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
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
    s = 1.0f;
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
static const unsigned long fzgx_pool_table9[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep9(void) { const unsigned long *volatile cp; cp = fzgx_pool_table9; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime10(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    d = 4503599627370496.0;
}
static const unsigned long fzgx_pool_table11[1] = {0x4E4F204E};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep11(void) { const unsigned long *volatile cp; cp = fzgx_pool_table11; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime12(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    s = 12.829345703125f;
}
static const unsigned long fzgx_pool_table13[1] = {0x4E4F2044};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep13(void) { const unsigned long *volatile cp; cp = fzgx_pool_table13; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime14(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    s = 13.265869140625f;
    s = 100.0f;
    s = 350.0f;
    s = 44.0f;
    s = 8.0f;
}
static const unsigned long fzgx_pool_table15[14] = {0xFFFFFFFF, 0x00F0E6FF, 0x007873FF, 0xA0FF00FF, 0x0000001A, 0x00000023, 0x0000013C, 0x00000145, 0x00000018, 0x00000021, 0x00000065, 0x0000006E, 0x000000B2, 0x000000BB};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep15(void) { const unsigned long *volatile cp; cp = fzgx_pool_table15; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime16(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    s = 30.0f;
    s = 0.75f;
    s = 54.0f;
    s = 343.0f;
    s = 65536.0f;
    s = 120.0f;
    s = 0.3499999940395355f;
}
static const unsigned long fzgx_pool_table17[25] = {0xFFFFFFFF, 0x00F0E6FF, 0x007873FF, 0xFFFF00FF, 0xFFFF00FF, 0x8080FFFF, 0x0000001A, 0x00000023, 0x0000013C, 0x00000145, 0x00000018, 0x00000021, 0x00000065, 0x0000006E, 0x000000B2, 0x000000BB, 0x19FF1900, 0x19FF1900, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep17(void) { const unsigned long *volatile cp; cp = fzgx_pool_table17; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime18(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    s = 3.748046875f;
}
static const unsigned long fzgx_pool_table19[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep19(void) { const unsigned long *volatile cp; cp = fzgx_pool_table19; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime20(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    s = 20.0f;
}
static const unsigned long fzgx_pool_table21[14] = {0x0000001A, 0x00000023, 0x0000013C, 0x00000145, 0xFFFFFF00, 0x19FF1900, 0x0000001A, 0x00000023, 0x0000013C, 0x00000145, 0x19FF1900, 0x00FFFFFF, 0x00FFFFFF, 0xFFFFFF00};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep21(void) { const unsigned long *volatile cp; cp = fzgx_pool_table21; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime22(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    s = 0.800000011920929f;
    s = -2.0f;
}
static const unsigned long fzgx_pool_table23[28] = {0x0000001A, 0x00000023, 0x0000013C, 0x00000145, 0x00000018, 0x00000021, 0x0000001A, 0x00000023, 0x0000013C, 0x00000145, 0x00000018, 0x00000021, 0xFFFF00FF, 0x19FF1900, 0x00000000, 0x0000001A, 0x00000023, 0x0000013C, 0x00000145, 0x19FF1900, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep23(void) { const unsigned long *volatile cp; cp = fzgx_pool_table23; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime24(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    s = 68.0f;
    s = 86.0f;
    s = 0.375f;
    s = 80.0f;
    s = 14.0f;
    s = 21.0f;
    s = 1.100000023841858f;
    s = 399.0f;
    s = 574.0f;
    s = 0.8500000238418579f;
    s = 510.0f;
}
static const unsigned long fzgx_pool_table25[27] = {0x19FF1900, 0x19FF1900, 0xF4962800, 0xF4962800, 0xFFFF0000, 0x00000000, 0xFFFFFF00, 0xF4962800, 0xF4962800, 0xFFFF0000, 0x00000000, 0xFFFFFF00, 0xF4962800, 0xFFFF00FF, 0x00000000, 0x19FF1900, 0x19FF1900, 0xF4962800, 0xF4962800, 0x8080FF00, 0x00000000, 0xFFFFFF00, 0xF4962800, 0xF4962800, 0x8080FF00, 0x00000000, 0xFFFFFF00};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep25(void) { const unsigned long *volatile cp; cp = fzgx_pool_table25; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime26(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    s = 354.0f;
    s = 84.0f;
    s = 22.0f;
    s = 0.6499999761581421f;
    s = 192.0f;
    s = 48.0f;
    s = 46.0f;
    s = 55.0f;
}
static const unsigned long fzgx_pool_table27[2] = {0xFADC82FF, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep27(void) { const unsigned long *volatile cp; cp = fzgx_pool_table27; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime28(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    s = 639.0f;
    s = 479.0f;
    s = 320.0f;
    s = 70.0f;
    s = 112.0f;
    s = 492.0f;
    s = 33.0f;
    s = 19.0f;
    s = 24.0f;
    s = 50.0f;
    s = 29.0f;
    s = 72.0f;
}

/* TU string-literal pool (lbl_1_data_42198): the TU's earlier functions emit these literals and
 * two local aggregate initializers in this order, so the function's own literals land at +0x3E0. */
__declspec(section ".fzgxpool") static void fzgx_strings_prime1(void) {
    fn_1_4A0D8("NON");
    fn_1_4A0D8("MASTER RECV");
    fn_1_4A0D8("MASTER SEND");
    fn_1_4A0D8("SLAVE SEND");
    fn_1_4A0D8("SLAVE RECV");
    fn_1_4A0D8("INIT");
    fn_1_4A0D8("TEST");
    fn_1_4A0D8("TESTEND");
    fn_1_4A0D8("SETUP");
    fn_1_4A0D8("SETUP_DONE");
    fn_1_4A0D8("SETUP_COUNTER");
    fn_1_4A0D8("SETUP_CNT_DONE");
    fn_1_4A0D8("UNLINK");
    fn_1_4A0D8("COIN");
    fn_1_4A0D8("ENTRY_WAIT");
    fn_1_4A0D8("CHALLENGER");
    fn_1_4A0D8("CHALLENGER_OK");
    fn_1_4A0D8("ENTRY");
    fn_1_4A0D8("ENTRY_OK");
    fn_1_4A0D8("SINGLECHECK");
    fn_1_4A0D8("SINGLECHECK_OK");
    fn_1_4A0D8("COURSE");
    fn_1_4A0D8("COURSE_OK");
    fn_1_4A0D8("COURSE_DATA");
    fn_1_4A0D8("COURSE_DATA_OK");
    fn_1_4A0D8("MACHINE");
    fn_1_4A0D8("MACHINE_OK");
    fn_1_4A0D8("CONFIG");
    fn_1_4A0D8("CONFIG_OK");
    fn_1_4A0D8("COUNTERADJUST");
    fn_1_4A0D8("LINKWAIT");
    fn_1_4A0D8("LINKWAITOK");
    fn_1_4A0D8("LINKSEL");
    fn_1_4A0D8("LINKDELIVERYSTART");
    fn_1_4A0D8("LINKDELIVERY");
    fn_1_4A0D8("LINKDELIVERYOK");
    fn_1_4A0D8("LINKSELOK");
    fn_1_4A0D8("COURSEVIEW");
    fn_1_4A0D8("COURSEVIEW_OK");
    fn_1_4A0D8("LINKREQ");
    fn_1_4A0D8("LINKSTANDBY");
    fn_1_4A0D8("LINKOK");
    fn_1_4A0D8("LINK");
    fn_1_4A0D8("PAUSE");
    fn_1_4A0D8("ERROR");
}
extern void fn_1_1420E0(void);
extern void fn_1_144E90(void);
extern void fn_1_144EE8(void);
extern void fn_1_149E2C(void);
extern void fn_1_149F04(void);
extern void fn_1_149DA4(void);
extern void fn_1_149DE8(void);
extern void fn_1_149F5C(void);
extern void fn_1_14A000(void);
extern void fn_1_14A004(void);
extern void fn_1_14A008(void);
extern void fn_1_5233C(void *, void *);
/* two file-scope statics of the TU sit between the two literal groups (+0x200 and +0x2B4) */
static Obj_1_data_212A8 fzgx_pool_fzgx_data_zero_block = {0};
/* retail: a table of 11 handler pointers (fn_1_1420E0 ...); plain words keep the primer relocation-free */
static u32 fzgx_pool_fzgx_data_handlers[11] = {0};
__declspec(section ".fzgxpool") static void fzgx_strings_keep(void) { void *volatile p; p = &fzgx_pool_fzgx_data_zero_block; p = fzgx_pool_fzgx_data_handlers; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_strings_prime2(void) {
    fn_1_4A0D8("[");
    fn_1_4A0D8("]");
    fn_1_4A0D8("NAME:");
    fn_1_4A0D8("%d");
    fn_1_4A0D8("NAME");
    fn_1_4A0D8("PILOT RANK");
    fn_1_4A0D8("%1d");
    fn_1_4A0D8("%-2d");
    fn_1_4A0D8("%02d<%02d=%03d");
    fn_1_4A0D8("%02d;%02d<%03d");
    fn_1_4A0D8("%4d");
    fn_1_4A0D8("\203\101\203\103\203\213\203\147\203\223\201\100\203\132\203\151");
    fn_1_4A0D8("\202\140\201\104\203\140\203\106\203\125\203\212\203\130\201\100");
    fn_1_4A0D8("\203\154\203\213\203\134\203\223\201\100\203\163\203\120\201\100");
    fn_1_4A0D8("\203\101\203\211\203\223\201\100\203\166\203\215\203\130\203\147");
    fn_1_4A0D8("\203\175\203\130\203\136\201\133\203\211\203\103\203\132\203\223\203\130");
    fn_1_4A0D8("\202\122\202\121\213\211\203\211\203\103\203\132\203\223\203\130");
    fn_1_4A0D8("\203\160\203\103\203\215\203\142\203\147\214\363\225\342\220\266");
    fn_1_4A0D8("\202\162\202\162\213\211\203\211\203\103\203\132\203\223\203\130");
    fn_1_4A0D8("NO DATA");
}
#pragma section code_type ".text"

extern u32 lbl_801A66B4;
extern f32 lbl_1_rodata_26F8[22];
extern void fn_1_49410(void);
extern void fn_1_494DC(s16 index);
extern void fn_1_496FC(f32 value1, f32 value2);
extern void fn_1_495C8(u8 value);
extern void fn_1_495B0(u32 value);
extern void fn_1_4954C(f32 value);
extern void fn_1_49590(f32 value);
extern void fn_1_4966C(f32 value1, f32 value2);
extern void fn_1_4955C(f32 value1, f32 value2);
extern void fn_1_49738(void *value);
extern void fn_1_49748(f32 value);
extern f32 fn_1_4B068(const char *);

#pragma opt_propagation off
void fn_1_1461C8(s32 mode, u32 index) {
    u8 idx;
    u8 pass;
    s32 width;
    s32 total;
    FontDrawPacket packet;
    s32 left;
    const char *text;

    total = 0;
    packet = *(FontDrawPacket *)lbl_1_rodata_26F8;
    packet.image = 0x9909;
    packet.x = 320.0f;
    packet.y = 24.0f;
    packet.z = 50.0f;
    packet.flags = 6;
    fn_1_4F734(&packet);

    fn_1_49410();
    fn_1_494DC(0x1d);
    fn_1_496FC(320.0f, 29.0f);
    fn_1_495C8(1);
    fn_1_495B0(0x80000000);
    fn_1_4954C(40.0f);
    fn_1_49590(0.5f);
    switch (mode) {
    case 0:
        fn_1_4AE0C("RESULTS");
        break;
    case 1:
        fn_1_4AE0C("TOTAL RANKING");
        break;
    case 2:
        fn_1_4AE0C("VS RESULTS");
        break;
    case 3:
        fn_1_4AE0C("VS TOTAL RANKING");
        break;
    case 4:
    case 5:
    case 6:
        fn_1_4AE0C("TIME ATTACK");
        break;
    case 7:
        fn_1_4AE0C("PRACTICE");
        break;
    }

    idx = index;
    /* pass 0 measures the line, pass 1 draws it centred */
    for (pass = 0; pass <= 1; pass++) {
        left = (320.0f - (total / 2));
        width = 0;
        text = (const char *)((u32 *)lbl_1_data_2AA24)[((u8 *)&lbl_1_data_2B0D4)[idx]];
        fn_1_49410();
        fn_1_494DC(0x1e);
        fn_1_495B0(0x80000000);
        fn_1_4954C(40.0f);
        fn_1_495C8(8);
        fn_1_49590(0.5f);
        fn_1_4966C(-1.0f, 0.0f);
        if (pass) {
            fn_1_496FC(left, 72.0f);
            fn_1_4A0D8(text);
        }
        width += fn_1_4B068(text);
        width += 10;

        text = (const char *)((u32 *)(lbl_1_data_2BD54 + idx * 0x18))[lbl_801A66B4];
        fn_1_49410();
        fn_1_494DC(0x2a);
        fn_1_4955C(0.5833333134651184f, 0.5833333134651184f);
        fn_1_495B0(0x80000000);
        fn_1_4954C(40.0f);
        fn_1_495C8(8);
        fn_1_49590(0.5f);
        fn_1_4966C(-1.0f, 0.0f);
        fn_1_49738(fn_1_5233C);
        fn_1_49748(1.0f);
        if (pass) {
            fn_1_496FC((left + width), 72.0f);
            fn_1_4A0D8(text);
        }
        width = (width + fn_1_4B068(text));
        total = width;
    }
}
/* fzgx:end fn_1_1461C8 */

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

/* fzgx:begin fn_1_146C88 */
typedef struct {
    u8 pad_0[0x24];
    s32 unk_24;
    u8 pad_28[0xD];
    u8 unk_35;
    u8 pad_36[0x16];
    s32 unk_4C;
    u8 pad_50[0x14];
    s32 unk_64;
    s32 unk_68;
    s32 unk_6C;
    u8 pad_70[0xBC];
    FontDrawPacket unk_12C;
} fn_1_146C88_Obj;

typedef struct {
    u32 a[4];
} fn_1_146C88_Tbl;

extern int fn_1_4F734(FontDrawPacket *);
extern void *fn_1_868C0(s8);
extern void fn_1_51564(u16, u16, u16, u16, u16, u16);
extern void fn_1_5158C(FontDrawPacket *, u32, s16, s16);
extern void fn_1_149BF4(const FontDrawPacket *, FontVertex *);
extern void fn_1_149C2C(const FontDrawPacket *, FontVertex *);
extern void fn_1_149C64(const FontDrawPacket *, FontVertex *);
extern u8 lbl_1_data_424D0[];
extern u8 lbl_1_data_424E4[];
extern u8 lbl_1_data_424F8[];
extern u8 lbl_1_data_4250C[];
extern u8 lbl_1_data_42520[];
extern u8 lbl_1_data_42534[];
extern u8 lbl_1_data_42548[];
extern u8 lbl_1_data_4255C[];

/* sel_static_disp.c's .rodata, laid out as retail (base lbl_1_rodata_92C0) */
#define FZGX_PACKET(cb) \
    { 0, 0.0f, 0.0f, 0.1f, 1.0f, 1.0f, 0.0f, 0.0f, 1.0f, 1.0f, 0, 0, 1.0f, 0x04000000, 0.0f, \
      { 0xFF, 0xFF, 0xFF, 0xFF }, { 0, 0, 0, 0 }, 0, 0, 0, NULL, NULL, cb, 0 }

static const FontDrawPacket fzgx_pool_000 = FZGX_PACKET(fn_1_149BF4);
static const FontDrawPacket fzgx_pool_058 = FZGX_PACKET(fn_1_149C2C);
static const FontDrawPacket fzgx_pool_0B0 = FZGX_PACKET(fn_1_149C64);
static const u32 fzgx_pool_108[7] = {
    0x00000000, 0x3F755555, 0x41B80000, 0x40000000, 0x3F2AAAAB, 0x3F000000, 0x3F155555,
};

#pragma section RX ".fzgxpool"
__declspec(section ".fzgxpool") const void *fzgx_primer_0(s32 i, f32 *o) {
    *o = (f32)i;
    return &fzgx_pool_108;
}

static const u32 fzgx_pool_130[14] = {
    0x44150000, 0x44040000, 0x0000001A, 0x00000023, 0x0000009C, 0x000000A5, 0x00000018,
    0x00000021, 0x00000085, 0x0000008E, 0x000000F2, 0x000000FB, 0xC0C0C000, 0xC0800000,  /* fzgx-allow: A1 retail pool bytes */
};

__declspec(section ".fzgxpool") const void *fzgx_primer_1(f32 *o) {
    *o = 40.0f;
    return &fzgx_pool_130;
}

static const u32 fzgx_pool_16C[116] = {
    0x43F00000,
    0x44200000, 0x47AFC800, 0x3E99999A, 0x3F333333,
    0xBF800000, 0x43500000, 0xC47A0000, 0xC2480000,
    0x3F800000, 0x41200000, 0x430C0000, 0x43600000,
    0x437E0000, 0x43800000, 0xC0C00000, 0x40A00000,  /* fzgx-allow: A1 retail pool bytes */
    0x40800000, 0x41400000, 0x41700000, 0x00000000,
    0x43300000, 0x00000000, 0x4E4F204E, 0x414D4500,
    0x4E4F2044, 0x41544100, 0x42C80000, 0x43AF0000,
    0x42300000, 0x41000000, 0xFFFFFFFF, 0x00F0E6FF,
    0x007873FF, 0xA0FF00FF, 0x0000001A, 0x00000023,
    0x0000013C, 0x00000145, 0x00000018, 0x00000021,
    0x00000065, 0x0000006E, 0x000000B2, 0x000000BB,
    0x41F00000, 0x3F400000, 0x42580000, 0x43AB8000,
    0x47800000, 0x42F00000, 0x3EB33333, 0xFFFFFFFF,
    0x00F0E6FF, 0x007873FF, 0xFFFF00FF, 0xFFFF00FF,
    0x8080FFFF, 0x0000001A, 0x00000023, 0x0000013C,  /* fzgx-allow: A1 retail pool bytes */
    0x00000145, 0x00000018, 0x00000021, 0x00000065,
    0x0000006E, 0x000000B2, 0x000000BB, 0x19FF1900,
    0x19FF1900, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x406FE000, 0x00000000, 0x41A00000, 0x0000001A,
    0x00000023, 0x0000013C, 0x00000145, 0xFFFFFF00,
    0x19FF1900, 0x0000001A, 0x00000023, 0x0000013C,
    0x00000145, 0x19FF1900, 0x00FFFFFF, 0x00FFFFFF,
    0xFFFFFF00, 0x3F4CCCCD, 0xC0000000, 0x0000001A,  /* fzgx-allow: A1 retail pool bytes */
    0x00000023, 0x0000013C, 0x00000145, 0x00000018,
    0x00000021, 0x0000001A, 0x00000023, 0x0000013C,
    0x00000145, 0x00000018, 0x00000021, 0xFFFF00FF,
    0x19FF1900, 0x00000000, 0x0000001A, 0x00000023,
    0x0000013C, 0x00000145, 0x19FF1900,
};
static void *const fzgx_pool_33C[8] = {
    lbl_1_data_424D0, lbl_1_data_424E4, lbl_1_data_424F8, lbl_1_data_4250C,
    lbl_1_data_42520, lbl_1_data_42534, lbl_1_data_42548, lbl_1_data_4255C,
};
static const u32 fzgx_pool_35C[44] = {
    0x42880000,
    0x42AC0000, 0x3EC00000, 0x42A00000, 0x41600000,
    0x41A80000, 0x3F8CCCCD, 0x43C78000, 0x440F8000,
    0x3F59999A, 0x43FF0000, 0x19FF1900, 0x19FF1900,
    0xF4962800, 0xF4962800, 0xFFFF0000, 0x00000000,
    0xFFFFFF00, 0xF4962800, 0xF4962800, 0xFFFF0000,
    0x00000000, 0xFFFFFF00, 0xF4962800, 0xFFFF00FF,
    0x00000000, 0x19FF1900, 0x19FF1900, 0xF4962800,
    0xF4962800, 0x8080FF00, 0x00000000, 0xFFFFFF00,  /* fzgx-allow: A1 retail pool bytes */
    0xF4962800, 0xF4962800, 0x8080FF00, 0x00000000,  /* fzgx-allow: A1 retail pool bytes */
    0xFFFFFF00, 0x43B10000, 0x42A80000, 0x41B00000,
    0x3F266666, 0x43400000, 0x42400000,
};

__declspec(section ".fzgxpool") const void *fzgx_primer_2(f32 *o) {
    *o = 46.0f;
    return &fzgx_pool_16C[0] + (u32)&fzgx_pool_33C + (u32)&fzgx_pool_35C;
}

static const u32 fzgx_pool_410[16] = {
    0x425C0000, 0xFADC82FF, 0x00000000, 0x441FC000,
    0x43EF8000, 0x43A00000, 0x428C0000, 0x42E00000,
    0x43F60000, 0x42040000, 0x41980000, 0x41C00000,
    0x42480000, 0x41E80000, 0x42900000, 0x423C0000,
};
static const fn_1_146C88_Tbl fzgx_pool_450 = {{0x9736, 0x9737, 0x9738, 0x9739}};
static const fn_1_146C88_Tbl fzgx_pool_460 = {{0x973A, 0x973B, 0x973C, 0x973D}};

__declspec(section ".fzgxpool") const void *fzgx_primer_3(void) {
    return (u8 *)&fzgx_pool_000 + (u32)&fzgx_pool_058 + (u32)&fzgx_pool_410;
}
#pragma section RX ".text"

static inline BOOL fn_1_146C88_in8(s32 mode) {
    BOOL r = TRUE;
    if (!((u32)(mode - 8) <= 1)) {
        r = FALSE;
    }
    return r;
}

static inline BOOL fn_1_146C88_isA(s32 mode) {
    BOOL r = TRUE;
    if (!fn_1_146C88_in8(mode) && mode != 10) {
        r = FALSE;
    }
    return r;
}

static inline BOOL fn_1_146C88_in4(s32 mode) {
    BOOL r = TRUE;
    if (!((u32)(mode - 4) <= 1)) {
        r = FALSE;
    }
    return r;
}

static inline BOOL fn_1_146C88_isB1(s32 mode) {
    BOOL r = TRUE;
    if (!fn_1_146C88_in4(mode) && mode != 9) {
        r = FALSE;
    }
    return r;
}

static inline BOOL fn_1_146C88_isB2(s32 mode) {
    BOOL r = TRUE;
    if (!fn_1_146C88_isB1(mode) && mode != 10) {
        r = FALSE;
    }
    return r;
}

static inline BOOL fn_1_146C88_isB(s32 mode) {
    BOOL r = TRUE;
    if (!fn_1_146C88_isB2(mode) && mode != 6) {
        r = FALSE;
    }
    return r;
}

void fn_1_146C88(s32 mode, fn_1_146C88_Obj *__restrict obj) {
    s32 x;
    s32 y;
    u8 idx;
    s32 n;
    void *p;
    FontDrawPacket packet;
    fn_1_146C88_Tbl tblA;
    fn_1_146C88_Tbl tblB;

    x = (obj->unk_68 + 0x78) + obj->unk_6C;
    y = obj->unk_64 + 0x17;

    if (fn_1_146C88_isA(mode) || fn_1_146C88_isB(mode)) {
        packet = obj->unk_12C;
        packet.image = 0x9718;
        packet.x = x;
        packet.y = y;
        packet.z = 46.0f;
        packet.flags |= 10;
        fn_1_4F734(&packet);
    }

    packet = obj->unk_12C;
    packet.image = 0x9719;
    packet.x = x;
    packet.y = y;
    packet.z = 45.0f;
    packet.flags |= 10;
    fn_1_4F734(&packet);

    packet = obj->unk_12C;
    packet.image = 0x9717;
    packet.x = x;
    packet.y = y;
    packet.z = 40.0f;
    packet.flags |= 10;
    fn_1_4F734(&packet);

    tblA = fzgx_pool_450;
    tblB = fzgx_pool_460;
    if (fn_1_146C88_isB(mode)) {
        idx = 0;
    } else {
        p = fn_1_868C0(obj->unk_4C);
        if (p != NULL) {
            idx = *(s16 *)((u8 *)p + 0x3B8) % 4;
        } else {
            idx = 0;
        }
    }

    packet = fzgx_pool_0B0;
    if (lbl_1_bss_8E52C != 0) {
        packet.image = tblA.a[idx];
        fn_1_51564(0, 0, 36, 36, 6, 7);
        packet.x = x;
        packet.y = y;
        packet.z = 42.0f;
        n = obj->unk_24;
    } else {
        packet.image = tblB.a[idx];
        fn_1_51564(0, 0, 64, 64, 6, 7);
        n = obj->unk_35 > 41 ? 41 : obj->unk_35;
        packet.x = x;
        packet.y = (y - 2);
        packet.z = 38.0f;
    }
    fn_1_5158C(&packet, packet.image, n % 6, n / 6);
    packet.flags |= 10;
    fn_1_4F734(&packet);
}
/* fzgx:end fn_1_146C88 */

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

/* fzgx:begin fn_1_147A04 noprologue */
#include "types.h"
#include "rel/main_rel/globals.h"
#include "rel/main_rel/sel_static_disp.h"

#pragma section code_type ".fzgxpool"
static const unsigned long fzgx_pool_table1[3] = {0x00000000, 0x00000000, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep1(void) { const unsigned long *volatile cp; cp = fzgx_pool_table1; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime2(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    s = 0.10000000149011612f;
}
static const unsigned long fzgx_pool_table3[62] = {0x3F800000, 0x3F800000, 0x00000000, 0x00000000, 0x3F800000, 0x3F800000, 0x00000000, 0x3F800000, 0x04000000, 0x00000000, 0xFFFFFFFF, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x3DCCCCCD, 0x3F800000, 0x3F800000, 0x00000000, 0x00000000, 0x3F800000, 0x3F800000, 0x00000000, 0x3F800000, 0x04000000, 0x00000000, 0xFFFFFFFF, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x3DCCCCCD, 0x3F800000, 0x3F800000, 0x00000000, 0x00000000, 0x3F800000, 0x3F800000, 0x00000000, 0x3F800000, 0x04000000, 0x00000000, 0xFFFFFFFF, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
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
    s = 596.0f;
    s = 528.0f;
}
static const unsigned long fzgx_pool_table7[11] = {0x0000001A, 0x00000023, 0x0000009C, 0x000000A5, 0x00000018, 0x00000021, 0x00000085, 0x0000008E, 0x000000F2, 0x000000FB, 0xC0C0C000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep7(void) { const unsigned long *volatile cp; cp = fzgx_pool_table7; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime8(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
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
    s = 1.0f;
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
static const unsigned long fzgx_pool_table9[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep9(void) { const unsigned long *volatile cp; cp = fzgx_pool_table9; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime10(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    d = 4503599627370496.0;
}
static const unsigned long fzgx_pool_table11[1] = {0x4E4F204E};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep11(void) { const unsigned long *volatile cp; cp = fzgx_pool_table11; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime12(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    s = 12.829345703125f;
}
static const unsigned long fzgx_pool_table13[1] = {0x4E4F2044};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep13(void) { const unsigned long *volatile cp; cp = fzgx_pool_table13; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime14(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    s = 13.265869140625f;
    s = 100.0f;
    s = 350.0f;
    s = 44.0f;
    s = 8.0f;
}
static const unsigned long fzgx_pool_table15[14] = {0xFFFFFFFF, 0x00F0E6FF, 0x007873FF, 0xA0FF00FF, 0x0000001A, 0x00000023, 0x0000013C, 0x00000145, 0x00000018, 0x00000021, 0x00000065, 0x0000006E, 0x000000B2, 0x000000BB};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep15(void) { const unsigned long *volatile cp; cp = fzgx_pool_table15; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime16(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    s = 30.0f;
    s = 0.75f;
    s = 54.0f;
    s = 343.0f;
    s = 65536.0f;
    s = 120.0f;
    s = 0.3499999940395355f;
}
static const unsigned long fzgx_pool_table17[25] = {0xFFFFFFFF, 0x00F0E6FF, 0x007873FF, 0xFFFF00FF, 0xFFFF00FF, 0x8080FFFF, 0x0000001A, 0x00000023, 0x0000013C, 0x00000145, 0x00000018, 0x00000021, 0x00000065, 0x0000006E, 0x000000B2, 0x000000BB, 0x19FF1900, 0x19FF1900, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep17(void) { const unsigned long *volatile cp; cp = fzgx_pool_table17; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime18(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    s = 3.748046875f;
}
static const unsigned long fzgx_pool_table19[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep19(void) { const unsigned long *volatile cp; cp = fzgx_pool_table19; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime20(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    s = 20.0f;
}
static const unsigned long fzgx_pool_table21[14] = {0x0000001A, 0x00000023, 0x0000013C, 0x00000145, 0xFFFFFF00, 0x19FF1900, 0x0000001A, 0x00000023, 0x0000013C, 0x00000145, 0x19FF1900, 0x00FFFFFF, 0x00FFFFFF, 0xFFFFFF00};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep21(void) { const unsigned long *volatile cp; cp = fzgx_pool_table21; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime22(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    s = 0.800000011920929f;
    s = -2.0f;
}
static const unsigned long fzgx_pool_table23[28] = {0x0000001A, 0x00000023, 0x0000013C, 0x00000145, 0x00000018, 0x00000021, 0x0000001A, 0x00000023, 0x0000013C, 0x00000145, 0x00000018, 0x00000021, 0xFFFF00FF, 0x19FF1900, 0x00000000, 0x0000001A, 0x00000023, 0x0000013C, 0x00000145, 0x19FF1900, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep23(void) { const unsigned long *volatile cp; cp = fzgx_pool_table23; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime24(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    s = 68.0f;
    s = 86.0f;
    s = 0.375f;
    s = 80.0f;
    s = 14.0f;
    s = 21.0f;
    s = 1.100000023841858f;
    s = 399.0f;
    s = 574.0f;
    s = 0.8500000238418579f;
    s = 510.0f;
}
static const unsigned long fzgx_pool_table25[27] = {0x19FF1900, 0x19FF1900, 0xF4962800, 0xF4962800, 0xFFFF0000, 0x00000000, 0xFFFFFF00, 0xF4962800, 0xF4962800, 0xFFFF0000, 0x00000000, 0xFFFFFF00, 0xF4962800, 0xFFFF00FF, 0x00000000, 0x19FF1900, 0x19FF1900, 0xF4962800, 0xF4962800, 0x8080FF00, 0x00000000, 0xFFFFFF00, 0xF4962800, 0xF4962800, 0x8080FF00, 0x00000000, 0xFFFFFF00};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep25(void) { const unsigned long *volatile cp; cp = fzgx_pool_table25; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime26(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    s = 354.0f;
    s = 84.0f;
    s = 22.0f;
    s = 0.6499999761581421f;
    s = 192.0f;
    s = 48.0f;
    s = 46.0f;
    s = 55.0f;
}
static const unsigned long fzgx_pool_table27[2] = {0xFADC82FF, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep27(void) { const unsigned long *volatile cp; cp = fzgx_pool_table27; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime28(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    s = 639.0f;
    s = 479.0f;
    s = 320.0f;
    s = 70.0f;
    s = 112.0f;
    s = 492.0f;
    s = 33.0f;
    s = 19.0f;
    s = 24.0f;
    s = 50.0f;
    s = 29.0f;
    s = 72.0f;
    s = 47.0f;
}
static const unsigned long fzgx_pool_table29[8] = {0x00009736, 0x00009737, 0x00009738, 0x00009739, 0x0000973A, 0x0000973B, 0x0000973C, 0x0000973D};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep29(void) { const unsigned long *volatile cp; cp = fzgx_pool_table29; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime30(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    s = 45.0f;
    s = 42.0f;
    s = 38.0f;
}
static const unsigned long fzgx_pool_table31[2] = {0x00000000, 0xC0C0C000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep31(void) { const unsigned long *volatile cp; cp = fzgx_pool_table31; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime32(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    s = 41.0f;
    s = 255.0f;
    s = 60.0f;
}
static const unsigned long fzgx_pool_table33[1] = {0xFFFF00FF};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep33(void) { const unsigned long *volatile cp; cp = fzgx_pool_table33; }  /* fzgx-allow: S2 pool primer sink */
static const unsigned long fzgx_pool_table34[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep34(void) { const unsigned long *volatile cp; cp = fzgx_pool_table34; }  /* fzgx-allow: S2 pool primer sink */
static const unsigned long fzgx_pool_table35[24] = {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep35(void) { const unsigned long *volatile cp; cp = fzgx_pool_table35; }  /* fzgx-allow: S2 pool primer sink */
static const unsigned long fzgx_pool_table36[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep36(void) { const unsigned long *volatile cp; cp = fzgx_pool_table36; }  /* fzgx-allow: S2 pool primer sink */
static const unsigned long fzgx_pool_table37[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep37(void) { const unsigned long *volatile cp; cp = fzgx_pool_table37; }  /* fzgx-allow: S2 pool primer sink */
static const unsigned long fzgx_pool_table38[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep38(void) { const unsigned long *volatile cp; cp = fzgx_pool_table38; }  /* fzgx-allow: S2 pool primer sink */
static const unsigned long fzgx_pool_table39[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep39(void) { const unsigned long *volatile cp; cp = fzgx_pool_table39; }  /* fzgx-allow: S2 pool primer sink */
static const unsigned long fzgx_pool_table40[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep40(void) { const unsigned long *volatile cp; cp = fzgx_pool_table40; }  /* fzgx-allow: S2 pool primer sink */
static const unsigned long fzgx_pool_table41[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep41(void) { const unsigned long *volatile cp; cp = fzgx_pool_table41; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime42(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    s = 0.009999999776482582f;
}
static const unsigned long fzgx_pool_table43[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep43(void) { const unsigned long *volatile cp; cp = fzgx_pool_table43; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime44(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    d = 0.0005;
    s = 13.333333969116211f;
    s = 166.0f;
    s = 348.3333435058594f;
    s = 9.0f;
    s = 7.0f;
    s = 170.0f;
}
/* Retail .data layout of this TU up to the strings this function uses:
 * state-name strings, a zeroed 0xB4-byte object, a handler table, more
 * strings; the five literals used below land on retail's offsets. */
extern void fn_1_1420E0(void);
extern void fn_1_144E90(void);
extern void fn_1_144EE8(void);
extern void fn_1_149E2C(void);
extern void fn_1_149F04(void);
extern void fn_1_149DA4(void);
extern void fn_1_149DE8(void);
extern void fn_1_149F5C(void);
extern void fn_1_14A000(void);
extern void fn_1_14A004(void);
extern void fn_1_14A008(void);
/* +0x000: the 45 state-name strings, then their pointer table at +0x200 */
static char fzgx_obj_lbl_1_data_42198[4] = "NON";
static const char *fzgx_pool_fzgx_data_names[45] = {
    fzgx_obj_lbl_1_data_42198, "MASTER RECV", "MASTER SEND", "SLAVE SEND", "SLAVE RECV", "INIT", "TEST", "TESTEND",
    "SETUP", "SETUP_DONE", "SETUP_COUNTER", "SETUP_CNT_DONE", "UNLINK", "COIN", "ENTRY_WAIT",
    "CHALLENGER", "CHALLENGER_OK", "ENTRY", "ENTRY_OK", "SINGLECHECK", "SINGLECHECK_OK",
    "COURSE", "COURSE_OK", "COURSE_DATA", "COURSE_DATA_OK", "MACHINE", "MACHINE_OK",
    "CONFIG", "CONFIG_OK", "COUNTERADJUST", "LINKWAIT", "LINKWAITOK", "LINKSEL",
    "LINKDELIVERYSTART", "LINKDELIVERY", "LINKDELIVERYOK", "LINKSELOK", "COURSEVIEW",
    "COURSEVIEW_OK", "LINKREQ", "LINKSTANDBY", "LINKOK", "LINK", "PAUSE", "ERROR"};
static void (*fzgx_pool_fzgx_data_tbl[11])(void) = {
    fn_1_1420E0, fn_1_144E90, fn_1_144EE8, fn_1_149E2C, fn_1_149F04, fn_1_149DA4,
    fn_1_149DE8, fn_1_149F5C, fn_1_14A000, fn_1_14A004, fn_1_14A008};
static unsigned long fzgx_pool_fzgx_data_b[84] = {  /* fzgx-allow: A1 retail data bytes */
    0x5B000000, 0x5D000000, 0x4E414D45, 0x3A000000, 0x25640000, 0x4E414D45, 0x00000000, 0x50494C4F,
    0x54205241, 0x4E4B0000, 0x25316400, 0x252D3264, 0x00000000, 0x25303264, 0x3C253032, 0x643D2530,
    0x33640000, 0x25303264, 0x3B253032, 0x643C2530, 0x33640000, 0x25346400, 0x83418343, 0x838B8367,
    0x83938140, 0x835A8369, 0x00000000, 0x82608144, 0x83608346, 0x8355838A, 0x83588140, 0x00000000,
    0x836C838B, 0x835C8393, 0x81408373, 0x83508140, 0x00000000, 0x83418389, 0x83938140, 0x8376838D,  /* fzgx-allow: A1 retail data bytes (Shift-JIS text) */
    0x83588367, 0x00000000, 0x837D8358, 0x835E815B, 0x83898343, 0x835A8393, 0x83580000, 0x82528251,
    0x8B898389, 0x8343835A, 0x83938358, 0x00000000, 0x83708343, 0x838D8362, 0x83678CF3, 0x95E290B6,
    0x00000000, 0x82728272, 0x8B898389, 0x8343835A, 0x83938358, 0x00000000, 0x4E4F2044, 0x41544100,
    0x52455355, 0x4C545300, 0x544F5441, 0x4C205241, 0x4E4B494E, 0x47000000, 0x56532052, 0x4553554C,
    0x54530000, 0x56532054, 0x4F54414C, 0x2052414E, 0x4B494E47, 0x00000000, 0x54494D45, 0x20415454,
    0x41434B00, 0x50524143, 0x54494345, 0x00000000};
__declspec(section ".fzgxpool") static void fzgx_data_prime1(void) {
    void *volatile sink; const char *volatile str;  /* fzgx-allow: S2 data primer sinks */
    sink = fzgx_pool_fzgx_data_names;
    sink = fzgx_pool_fzgx_data_tbl;
    sink = fzgx_pool_fzgx_data_b;
    str = "GOMAR & SHIOH";
    str = "GOMAR , SHIOH";
}
static unsigned long fzgx_pool_fzgx_data_c[133] = {  /* fzgx-allow: A1 retail data bytes */
    0x43617069, 0x74616C20, 0x4C657474, 0x65727300, 0x47455220, 0x43617069, 0x74616C20, 0x4C657474,
    0x65727300, 0x46524520, 0x43617069, 0x74616C20, 0x4C657474, 0x65727300, 0x53504120, 0x43617069,
    0x74616C20, 0x4C657474, 0x65727300, 0x49544120, 0x43617069, 0x74616C20, 0x4C657474, 0x65727300,
    0x89709094, 0x00000000, 0x20536D61, 0x6C6C204C, 0x65747465, 0x72732000, 0x47455220, 0x536D616C,
    0x6C204C65, 0x74746572, 0x73000000, 0x46524520, 0x536D616C, 0x6C204C65, 0x74746572, 0x73000000,
    0x53504120, 0x536D616C, 0x6C204C65, 0x74746572, 0x73000000, 0x49544120, 0x536D616C, 0x6C204C65,
    0x74746572, 0x73000000, 0x8B4C8D86, 0x00000000, 0x20202020, 0x20536967, 0x6E732020, 0x20202000,
    0x47455220, 0x5369676E, 0x73000000, 0x46524520, 0x5369676E, 0x73000000, 0x53504120, 0x5369676E,
    0x73000000, 0x49544120, 0x5369676E, 0x73000000, 0x82A982C8, 0x00000000, 0x20202020, 0x4E756D62,
    0x65727320, 0x20200000, 0x47455220, 0x4E756D62, 0x65727300, 0x46524520, 0x4E756D62, 0x65727300,
    0x53504120, 0x4E756D62, 0x65727300, 0x49544120, 0x4E756D62, 0x65727300, 0x834A8369, 0x00000000,
    0x83A02044, 0x656C6574, 0x6520839F, 0x20456E74, 0x65722083, 0xB45B2573, 0x5D000000, 0x47455220,
    0x83A02044, 0x656C6574, 0x6520839F, 0x20456E74, 0x65722083, 0xB45B2573, 0x5D000000, 0x46524520,
    0x83A02044, 0x656C6574, 0x6520839F, 0x20456E74, 0x65722083, 0xB45B2573, 0x5D000000, 0x53504120,
    0x83A02044, 0x656C6574, 0x6520839F, 0x20456E74, 0x65722083, 0xB45B2573, 0x5D000000, 0x49544120,
    0x83A02044, 0x656C6574, 0x6520839F, 0x20456E74, 0x65722083, 0xB45B2573, 0x5D000000, 0x83A0208F,
    0xC182B720, 0x839F208C, 0x8892E820, 0x83B45B25, 0x735D0000};
__declspec(section ".fzgxpool") static void fzgx_data_prime2(void) {
    void *volatile sink; const char *volatile str;  /* fzgx-allow: S2 data primer sinks */
    sink = fzgx_pool_fzgx_data_c;
    str = "\201\347";
    str = "  ";
    str = "\201\350";
}
#pragma section code_type ".text"

typedef struct {
    f32 value0;
    u8 pad[8];
    f32 value_c;
} Sig_fn_1_149B24_Fn149B24Data;

struct fn_1_147A04_Copy96 { u32 a[24]; };
struct fn_1_147A04_Copy24 { const char *a[6]; };
typedef struct {
    u8 pad_0[0x20];
    s32 unk_20;
    s32 unk_24;
    char *unk_28;
    Obj_1_bss_4B9CC *unk_2C;
    u8 pad_30[0x1C];
    s32 unk_4C;
    u8 pad_50[0x14];
    s32 unk_64;
    s32 unk_68;
    u8 pad_6C[8];
    s32 unk_74;
    s32 unk_78;
} fn_1_147A04_Obj;
typedef struct { u8 r, g, b, a; } fn_1_147A04_Color;

extern char *strcpy(char *, const char *);
extern char *strncpy(char *, const char *, size_t);
extern size_t strlen(const char *);
extern s32 strncmp(const char *, const char *, size_t);
extern f32 fn_1_4B090(s32);
extern f32 lbl_8006D188(u32);
extern int sprintf(char *, const char *, ...);
extern s16 fn_1_12C930(s16);
extern s32 fn_8006FC1C(void *, const char *);
extern u32 lbl_801A66A4;
extern u32 fn_1_155F7C(void);
extern u32 fn_1_155F8C(void);
extern u32 fn_1_53B14(void *, f32, f32, f32, f32, f32);
extern u32 fn_1_53C9C(void *, u32, f32, f32, f32, f32, f32);
extern u32 lbl_1_bss_8E570[9];
extern s32 lbl_801A66B4;
extern u8 lbl_1_bss_8E594;
extern void fn_1_149B24(void *, Sig_fn_1_149B24_Fn149B24Data *);
extern void fn_1_149B64(void *, void *);
extern void fn_1_49410(void);
extern void fn_1_494DC(s16);
extern void fn_1_49514(u32 *);
extern void fn_1_49528(u32 *);
extern void fn_1_4954C(f32);
extern void fn_1_4955C(f32, f32);
extern void fn_1_49590(f32);
extern void fn_1_495B0(u32);
extern void fn_1_495C8(s32);
extern void fn_1_4962C(void);
extern void fn_1_4966C(f32, f32);
extern void fn_1_496FC(f32, f32);
extern void fn_1_49738(void *);
extern void fn_1_49748(f32);
extern void fn_1_4A0D8(const char *);
extern void fn_1_4CE48(Obj_1_bss_4B9CC *, f32);

static inline BOOL fn_1_147A04_range4(s32 mode) {
    BOOL r = TRUE;
    if (!((u32)(mode - 4) <= 1)) r = FALSE;
    return r;
}
static inline BOOL fn_1_147A04_range49(s32 mode) {
    BOOL r = TRUE;
    if (!fn_1_147A04_range4(mode) && mode != 9) r = FALSE;
    return r;
}
static inline BOOL fn_1_147A04_range49A(s32 mode) {
    BOOL r = TRUE;
    if (!fn_1_147A04_range49(mode) && mode != 10) r = FALSE;
    return r;
}
static inline BOOL fn_1_147A04_special(s32 mode) {
    BOOL r = TRUE;
    if (!fn_1_147A04_range49A(mode) && mode != 6) r = FALSE;
    return r;
}
static inline BOOL fn_1_147A04_range8(s32 mode) {
    BOOL r = TRUE;
    if (!((u32)(mode - 8) <= 1)) r = FALSE;
    return r;
}
static inline BOOL fn_1_147A04_range89A(s32 mode) {
    BOOL r = TRUE;
    if (!fn_1_147A04_range8(mode) && mode != 10) r = FALSE;
    return r;
}
static inline BOOL fn_1_147A04_range0(s32 mode) {
    BOOL r = TRUE;
    if (!((u32)mode <= 1)) r = FALSE;
    return r;
}

#pragma opt_propagation off
void fn_1_147A04(s32 arg0, const fn_1_147A04_Obj *arg1) {
    char *v12;
    u32 v10;
    char *v16;
    s32 v6;
    f32 v23;
    f32 v24;
    f32 v26;
    f32 v7;
    f32 v64;
    s32 x, y;
    char loc_A8[0x100];
    struct fn_1_147A04_Copy96 loc_48;
    char loc_34[17];
    const char *loc_1C[6];
    fn_1_147A04_Color loc_18;
    u32 loc_14;
    fn_1_147A04_Color loc_10;
    fn_1_147A04_Color loc_C;
    fn_1_147A04_Color loc_8;

    if (fn_1_147A04_special(arg0)) {
        fn_1_49410();
        fn_1_49738(fn_1_149B64);
        fn_1_49748(0.0f);
        fn_1_495C8(8);
        x = arg1->unk_68 + arg1->unk_74;
        fn_1_496FC((x + 180), (arg1->unk_64 + 21));
        fn_1_4955C(0.75f, 0.75f);
        fn_1_4954C(48.0f);
        loc_34[16] = 0;
        strncpy(loc_34, ((const fn_1_147A04_Obj *)arg1)->unk_28, 16);
        if (lbl_1_bss_8E51D == 6 && arg1->unk_20 == (s32)fn_1_155F8C()) {
            if (lbl_1_bss_8E594 != 0) {
                v10 = strlen(loc_34);
            } else {
                v10 = strlen(loc_34) - 2;
            }
        } else {
            v10 = strlen(loc_34);
        }
        v12 = loc_34;
        for (arg0 = 0; arg0 < v10; arg0 += 2) {
            if (strncmp(v12, "\201\347", 2) == 0) {
                strncpy(v12, "  ", 2);
                strcpy(v12 + 1, v12 + 2);
                v12 += 1;
            } else {
                v12 += 2;
            }
        }
        if (lbl_1_bss_8E51D == 6 && arg1->unk_20 == (s32)fn_1_155F8C()) {
            loc_14 = fzgx_pool_table33[0];
            fn_1_49514(&loc_14);
            loc_C = *(fn_1_147A04_Color *)&fzgx_pool_table34[0];
            loc_C.g = (255.0f * lbl_8006D188((s16)(lbl_801A66A4 << 8)));
            loc_C.b = (255.0f * lbl_8006D188((s16)(lbl_801A66A4 << 8)));
            loc_10 = loc_C;
            fn_1_49528((u32 *)&loc_10);
            if (lbl_1_bss_8E594 != 0) {
                if (lbl_801A66A4 % 60 > 10) {
                    strncpy(loc_34 + strlen(loc_34), "\201\350", 3);
                }
            } else {
                if (lbl_801A66A4 % 60 > 50 && strlen(loc_34) >= 2) {
                    loc_34[strlen(loc_34) - 2] = 0;
                }
            }
        }
        fn_1_4A0D8(loc_34);
        if (lbl_1_bss_8E51D == 6 && arg1->unk_20 == (s32)fn_1_155F8C()) {
            loc_48 = *(struct fn_1_147A04_Copy96 *)fzgx_pool_table35;
            *(struct fn_1_147A04_Copy24 *)loc_1C = *(struct fn_1_147A04_Copy24 *)&fzgx_pool_table36[0];
            if (arg1->unk_78 > 45.0f) {
                v6 = lbl_1_bss_8E570[0];
                sprintf(loc_A8, loc_1C[lbl_801A66B4], *(u32 *)((u8 *)&loc_48 + (v6 < 0 ? 0 : v6 > 3 ? 3 : v6) * 24 + lbl_801A66B4 * 4));
            }
            fn_1_49410();
            fn_1_495B0(0x80000000);
            fn_1_49590(0.5f);
            if (lbl_801A66B4 != 5) {
                v16 = loc_A8;
                v23 = (arg1->unk_68 + 158);
                v24 = (arg1->unk_64 + 46);
                if (arg1->unk_78 > 45.0f) {
                    fn_1_496FC(v23, v24);
                    v7 = 0.01f;
                    fn_1_4954C(v7 - 0.0005);
                    fn_1_4955C(0.6666667f, 0.6666667f);
                    fn_1_495C8(8);
                    fn_1_4A0D8(v16);
                    fn_1_53B14(0, 166.0f + v23, v24, 348.33334f, 13.333334f + fn_1_4B090((s32)v16), 0.01f);
                }
            } else {
                v26 = (arg1->unk_78 - 40.0f) / 5.0f;
                v26 = 1.0f < v26 ? 1.0f : v26;
                v7 = 9.0f + 7.0f * v26;
                fn_1_53C9C(0, (u32)loc_A8, (arg1->unk_68 + 290), (arg1->unk_64 + 46), 0.01f, 20.0f, (v7 / 24.0f));
            }
        }
    } else {
        fn_1_49410();
        fn_1_494DC(21);
        fn_1_495B0(0x80000000);
        fn_1_49738(fn_1_149B24);
        if (fn_1_147A04_range89A(arg0) || fn_1_147A04_special(arg0)) {
            x = arg1->unk_68 + arg1->unk_74;
            fn_1_496FC((x + 166), (arg1->unk_64 + 11));
        } else if (fn_1_147A04_range0(arg0)) {
            x = arg1->unk_68 + arg1->unk_74;
            fn_1_496FC((x + 150), (arg1->unk_64 + 13));
        } else {
            fn_1_496FC((arg1->unk_74 + 196), (arg1->unk_64 + 13));
        }
        fn_1_4954C(47.0f);
        fn_1_4962C();
        fn_1_49590(0.5f);
        fn_1_4966C(-1.0f, 0.0f);
        if (arg0 == 10 || arg0 == 6) {
            arg0 = arg1->unk_20 == 0;
        } else if (fn_1_147A04_special(arg0)) {
            arg0 = 0;
            if ((s32)fn_1_155F7C() != 0 && arg1->unk_20 == (s32)fn_1_155F8C()) arg0 = 1;
        } else {
            arg0 = arg1->unk_4C < lbl_1_bss_3C30.unk_8;
        }
        if (arg0) {
            loc_18.a = 255;
            loc_18.b = 255;
            loc_18.r = 255;
            v7 = lbl_8006D188((s32)(65536.0f * ((s32)lbl_801A66A4 % 60) / 60.0f));
            v64 = 0.5f;
            v7 = 1.0f - v7;
            v7 = v7 * v64;
            loc_18.g = (255.0f * v7);
            loc_8 = loc_18;
            fn_1_49514((u32 *)&loc_8);
        }
        if (lbl_1_bss_8E52C != 0) {
            if (fn_8006FC1C((void *)(&lbl_1_data_212A8.unk_0)[fn_1_12C930(arg1->unk_24)], "GOMAR & SHIOH") != 0) {
                fn_1_4CE48((Obj_1_bss_4B9CC *)"GOMAR , SHIOH", 170.0f);
            } else {
                fn_1_4CE48((Obj_1_bss_4B9CC *)(&lbl_1_data_212A8.unk_0)[fn_1_12C930(arg1->unk_24)], 170.0f);
            }
        } else {
            v7 = 170.0f;
            fn_1_4CE48(arg1->unk_2C, v7);
        }
    }
}
/* fzgx:end fn_1_147A04 */

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

/* fzgx:begin fn_1_148950 */
typedef struct {
    u32 v[8];
} Word8_fn_1_148950;

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
} Sp8_fn_1_148950;

typedef struct {
    u32 value[22];
} Fn139F18Data_fn_1_148950;

typedef struct StaticDispParams_fn_1_148950 {
    s32 id;
    f32 x;
    f32 y;
    f32 z;
    u32 unk1[8];
    s32 count;
    u32 unk2[9];
} StaticDispParams_fn_1_148950;

struct Struct_26F8_fn_1_148950 {
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
} PtrTab_fn_1_148950;

struct fn_1_13F8C4_lbl_801A6410_fn_1_148950 {
    u32 unk_0;
};

struct fn_1_149C64_lbl_1_bss_8E43C_fn_1_148950 {
    u32 unk_0;
};

struct fn_1_149C64_lbl_1_bss_8E440_fn_1_148950 {
    u32 unk_0;
};

typedef struct {
    s16 indices[2];
    u8 pad8[4];
    u32 flags;
} Source_fn_1_148950;

typedef struct {
    s16 index;
    u8 pad2[0x1e];
    char text[0x320];
    void *object;
    void *handle[4];
} Display_fn_1_148950;

struct Sig_fn_80071718_fn_80071718_Arg0_fn_1_148950 {
    u8 pad_0[0xC];
    u32 unk_C;
};

struct Sig_fn_800711A8_fn_800711A8_Entry_fn_1_148950 {
    u8 pad_00[0x24];
    void *field_24;
};

struct Sig_fn_800711A8_fn_800711A8_Arg0_fn_1_148950 {
    s32 count;
    u8 pad_04[4];
    struct Sig_fn_800711A8_fn_800711A8_Entry_fn_1_148950 **entries;
    u8 pad_0C[4];
    u32 field_10;
    void *field_14;
};

typedef struct {
    u8 data[4];
    f32 value;
    u8 tail[8];
} Fn1_14E9E4Entry_fn_1_148950;

typedef struct fn_1_150C8C_Entry_fn_1_148950 {
    u8 pad[0x68];
    u32 active;
    u8 tail[0x40];
} fn_1_150C8C_Entry_fn_1_148950;

typedef struct fn_1_150C8C_Object_fn_1_148950 {
    u8 pad_84[0x84];
    s32 count;
    fn_1_150C8C_Entry_fn_1_148950 entries[1];
} fn_1_150C8C_Object_fn_1_148950;

typedef struct fn_1_150F30_StaticDisp_fn_1_148950 {
    u8 pad_2728[0x2728];
    s32 unk_2728;
    s32 unk_272c;
} fn_1_150F30_StaticDisp_fn_1_148950;

typedef struct Fn14E09CValue_fn_1_148950 {
    void *value;
} Fn14E09CValue_fn_1_148950;

typedef struct Fn14E09CRef_fn_1_148950 {
    u8 pad8[8];
    Fn14E09CValue_fn_1_148950 *value;
} Fn14E09CRef_fn_1_148950;

typedef struct Fn14E09CObj_fn_1_148950 {
    u8 pad344[0x344];
    Fn14E09CRef_fn_1_148950 *ref;
} Fn14E09CObj_fn_1_148950;

typedef struct DispNode_fn_1_148950 {
    u8 pad[4];
    f32 value;
} DispNode_fn_1_148950;

typedef struct DispChildList_fn_1_148950 {
    DispNode_fn_1_148950 *child[3];
} DispChildList_fn_1_148950;

typedef struct DispObject_fn_1_148950 {
    u32 flags;
    u8 pad0[12];
    f32 value;
    u8 pad1[32];
    DispChildList_fn_1_148950 *children;
} DispObject_fn_1_148950;

typedef struct fn_1_151668_StaticDispEntry_fn_1_148950 {
    f32 first;
    u8 pad0[0x18];
    f32 values[3];
    DispObject_fn_1_148950 *object;
    u8 active;
    u8 scale_first;
    u8 scale_second;
    u8 clear_flag;
    u8 pad2[0x0c];
} fn_1_151668_StaticDispEntry_fn_1_148950;

typedef struct fn_1_151668_StaticDisp_fn_1_148950 {
    u8 pad0[0x1830];
    fn_1_151668_StaticDispEntry_fn_1_148950 entries[63];
    u8 pad1[0x30];
    s32 entry_count;
    s32 value_2728;
    s32 value_272c;
} fn_1_151668_StaticDisp_fn_1_148950;
extern void OSPanic(const char *file, int line, const char *msg, ...);
extern u32 __cvt_fp2unsigned(f32);
extern int sprintf(char *s, const char *format, ...);
extern size_t strlen(const char *str);
extern void qsort(void *arg0, u32 arg1, s32 arg2, void *callback);

typedef struct {
    u8 pad_0[0x30];
    u32 unk_30;
    u8 pad_34[0x8];
    u32 unk_3C;
    u16 unk_40;
    u8 pad_42[0x12];
    u16 unk_54;
    u8 pad_56[0x6];
    s32 unk_5C;
    u8 unk_60;
    u8 unk_61;
    u8 pad_62[0x2];
    s32 unk_64;
    s32 unk_68;
    u8 pad_6C[0x4];
    s32 unk_70;
    s32 unk_74;
} fn_1_148950_Row;

extern void fn_1_149B24(void);
extern void fn_1_149BF4(void);
extern int sprintf(char *, const char *, ...);

/* The TU's literal pool (lbl_1_rodata_92C0 .. +0x53C) in retail order: three default font
   packets (the row draws from the first two), then the tables between the literals this
   function reads, each literal placed by the primer after it. */
#pragma section code_type ".fzgxpool"
static const u32 fzgx_pool_table_000[22] = {
    0, 0, 0, 0x3DCCCCCD, 0x3F800000, 0x3F800000, 0, 0,
    0x3F800000, 0x3F800000, 0, 0x3F800000, 0x4000000, 0, 0xFFFFFFFF, 0,
    0, 0, 0, 0, 0, 0
};
static const u32 fzgx_pool_table_058[22] = {
    0, 0, 0, 0x3DCCCCCD, 0x3F800000, 0x3F800000, 0, 0,
    0x3F800000, 0x3F800000, 0, 0x3F800000, 0x4000000, 0, 0xFFFFFFFF, 0,
    0, 0, 0, 0, 0, 0
};
static const u32 fzgx_pool_table_0B0[22] = {
    0, 0, 0, 0x3DCCCCCD, 0x3F800000, 0x3F800000, 0, 0,
    0x3F800000, 0x3F800000, 0, 0x3F800000, 0x4000000, 0, 0xFFFFFFFF, 0,
    0, 0, 0, 0, 0, 0
};
void fzgx_pool_prime_108(const u32 **t, f32 *f) {
    t[0] = fzgx_pool_table_000;
    t[1] = fzgx_pool_table_058;
    t[2] = fzgx_pool_table_0B0;
    f[0] = 0.0f;
}
static const u32 fzgx_pool_table_10C[7] = {
    0x3F755555, 0x41B80000, 0x40000000, 0x3F2AAAAB, 0x3F000000, 0x3F155555, 0,
};
void fzgx_pool_prime_128(const u32 **t, f32 *f, s32 n) {
    t[0] = fzgx_pool_table_10C;
    f[0] = n;
}
static const u32 fzgx_pool_table_130[14] = {
    0x44150000, 0x44040000, 0x1A, 0x23, 0x9C, 0xA5, 0x18, 0x21,
    0x85, 0x8E, 0xF2, 0xFB, 0xC0C0C000, 0xC0800000,  /* fzgx-allow: A1 retail pool bytes */
};
void fzgx_pool_prime_168(const u32 **t, f32 *f) {
    t[0] = fzgx_pool_table_130;
    f[0] = 40.0f;
}
static const u32 fzgx_pool_table_16C[5] = {
    0x43F00000, 0x44200000, 0x47AFC800, 0x3E99999A, 0x3F333333,
};
void fzgx_pool_prime_180(const u32 **t, f32 *f) {
    t[0] = fzgx_pool_table_16C;
    f[0] = -1.0f;
}
static const u32 fzgx_pool_table_184[3] = {
    0x43500000, 0xC47A0000, 0xC2480000,
};
void fzgx_pool_prime_190(const u32 **t, f32 *f) {
    t[0] = fzgx_pool_table_184;
    f[0] = 1.0f;
}
static const u32 fzgx_pool_table_194[84] = {
    0x41200000, 0x430C0000, 0x43600000, 0x437E0000, 0x43800000, 0xC0C00000, 0x40A00000, 0x40800000,  /* fzgx-allow: A1 retail pool bytes */
    0x41400000, 0x41700000, 0, 0x43300000, 0, 0x4E4F204E, 0x414D4500, 0x4E4F2044,
    0x41544100, 0x42C80000, 0x43AF0000, 0x42300000, 0x41000000, 0xFFFFFFFF, 0xF0E6FF, 0x7873FF,
    0xA0FF00FF, 0x1A, 0x23, 0x13C, 0x145, 0x18, 0x21, 0x65,
    0x6E, 0xB2, 0xBB, 0x41F00000, 0x3F400000, 0x42580000, 0x43AB8000, 0x47800000,
    0x42F00000, 0x3EB33333, 0xFFFFFFFF, 0xF0E6FF, 0x7873FF, 0xFFFF00FF, 0xFFFF00FF, 0x8080FFFF,  /* fzgx-allow: A1 retail pool bytes */
    0x1A, 0x23, 0x13C, 0x145, 0x18, 0x21, 0x65, 0x6E,
    0xB2, 0xBB, 0x19FF1900, 0x19FF1900, 0, 0, 0, 0,
    0, 0, 0, 0x406FE000, 0, 0x41A00000, 0x1A, 0x23,
    0x13C, 0x145, 0xFFFFFF00, 0x19FF1900, 0x1A, 0x23, 0x13C, 0x145,
    0x19FF1900, 0xFFFFFF, 0xFFFFFF, 0xFFFFFF00,
};
void fzgx_pool_prime_2E4(const u32 **t, f32 *f) {
    t[0] = fzgx_pool_table_194;
    f[0] = 0.8f;
}
static const u32 fzgx_pool_table_2E8[89] = {
    0xC0000000, 0x1A, 0x23, 0x13C, 0x145, 0x18, 0x21, 0x1A,  /* fzgx-allow: A1 retail pool bytes */
    0x23, 0x13C, 0x145, 0x18, 0x21, 0xFFFF00FF, 0x19FF1900, 0,
    0x1A, 0x23, 0x13C, 0x145, 0x19FF1900, 0, 0, 0,
    0, 0, 0, 0, 0, 0x42880000, 0x42AC0000, 0x3EC00000,
    0x42A00000, 0x41600000, 0x41A80000, 0x3F8CCCCD, 0x43C78000, 0x440F8000, 0x3F59999A, 0x43FF0000,
    0x19FF1900, 0x19FF1900, 0xF4962800, 0xF4962800, 0xFFFF0000, 0, 0xFFFFFF00, 0xF4962800,
    0xF4962800, 0xFFFF0000, 0, 0xFFFFFF00, 0xF4962800, 0xFFFF00FF, 0, 0x19FF1900,
    0x19FF1900, 0xF4962800, 0xF4962800, 0x8080FF00, 0, 0xFFFFFF00, 0xF4962800, 0xF4962800,  /* fzgx-allow: A1 retail pool bytes */
    0x8080FF00, 0, 0xFFFFFF00, 0x43B10000, 0x42A80000, 0x41B00000, 0x3F266666, 0x43400000,  /* fzgx-allow: A1 retail pool bytes */
    0x42400000, 0x42380000, 0x425C0000, 0xFADC82FF, 0, 0x441FC000, 0x43EF8000, 0x43A00000,
    0x428C0000, 0x42E00000, 0x43F60000, 0x42040000, 0x41980000, 0x41C00000, 0x42480000, 0x41E80000,
    0x42900000,
};
void fzgx_pool_prime_44C(const u32 **t, f32 *f) {
    t[0] = fzgx_pool_table_2E8;
    f[0] = 47.0f;
}
static const u32 fzgx_pool_table_450[58] = {
    0x9736, 0x9737, 0x9738, 0x9739, 0x973A, 0x973B, 0x973C, 0x973D,
    0x42340000, 0x42280000, 0x42180000, 0, 0xC0C0C000, 0x42240000, 0x437F0000, 0x42700000,  /* fzgx-allow: A1 retail pool bytes */
    0xFFFF00FF, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0x3C23D70A, 0, 0x3F40624D, 0xD2F1A9FC, 0x41555556, 0x43260000, 0x43AE2AAB, 0x41100000,
    0x40E00000, 0x432A0000,
};
void fzgx_pool_prime_538(const u32 **t, f32 *f) {
    t[0] = fzgx_pool_table_450;
    f[0] = -10.0f;
}

/* The TU's .data (lbl_1_data_42198) up to the strings this function uses: the row's two words
   for a racer without a time and its three number formats. */
extern u8 fn_1_1420E0__fzgx_offset_0[];
extern u8 fn_1_144E90__fzgx_offset_0[];
extern u8 fn_1_144EE8__fzgx_offset_0[];
extern u8 fn_1_149DA4__fzgx_offset_0[];
extern u8 fn_1_149DE8__fzgx_offset_0[];
extern u8 fn_1_149E2C__fzgx_offset_0[];
extern u8 fn_1_149F04__fzgx_offset_0[];
extern u8 fn_1_149F5C__fzgx_offset_0[];
extern u8 fn_1_14A000__fzgx_offset_0[];
extern u8 fn_1_14A004__fzgx_offset_0[];
extern u8 fn_1_14A008__fzgx_offset_0[];
extern u8 lbl_1_data_42198__fzgx_offset_0[];
extern u8 lbl_1_data_4219C__fzgx_offset_0[];
extern u8 lbl_1_data_421A8__fzgx_offset_0[];
extern u8 lbl_1_data_421B4__fzgx_offset_0[];
extern u8 lbl_1_data_421C0__fzgx_offset_0[];
extern u8 lbl_1_data_421CC__fzgx_offset_0[];
extern u8 lbl_1_data_421D4__fzgx_offset_0[];
extern u8 lbl_1_data_421DC__fzgx_offset_0[];
extern u8 lbl_1_data_421E4__fzgx_offset_0[];
extern u8 lbl_1_data_421EC__fzgx_offset_0[];
extern u8 lbl_1_data_421F8__fzgx_offset_0[];
extern u8 lbl_1_data_42208__fzgx_offset_0[];
extern u8 lbl_1_data_42218__fzgx_offset_0[];
extern u8 lbl_1_data_42220__fzgx_offset_0[];
extern u8 lbl_1_data_42228__fzgx_offset_0[];
extern u8 lbl_1_data_42234__fzgx_offset_0[];
extern u8 lbl_1_data_42240__fzgx_offset_0[];
extern u8 lbl_1_data_42250__fzgx_offset_0[];
extern u8 lbl_1_data_42258__fzgx_offset_0[];
extern u8 lbl_1_data_42264__fzgx_offset_0[];
extern u8 lbl_1_data_42270__fzgx_offset_0[];
extern u8 lbl_1_data_42280__fzgx_offset_0[];
extern u8 lbl_1_data_42288__fzgx_offset_0[];
extern u8 lbl_1_data_42294__fzgx_offset_0[];
extern u8 lbl_1_data_422A0__fzgx_offset_0[];
extern u8 lbl_1_data_422B0__fzgx_offset_0[];
extern u8 lbl_1_data_422B8__fzgx_offset_0[];
extern u8 lbl_1_data_422C4__fzgx_offset_0[];
extern u8 lbl_1_data_422CC__fzgx_offset_0[];
extern u8 lbl_1_data_422D8__fzgx_offset_0[];
extern u8 lbl_1_data_422E8__fzgx_offset_0[];
extern u8 lbl_1_data_422F4__fzgx_offset_0[];
extern u8 lbl_1_data_42300__fzgx_offset_0[];
extern u8 lbl_1_data_42308__fzgx_offset_0[];
extern u8 lbl_1_data_4231C__fzgx_offset_0[];
extern u8 lbl_1_data_4232C__fzgx_offset_0[];
extern u8 lbl_1_data_4233C__fzgx_offset_0[];
extern u8 lbl_1_data_42348__fzgx_offset_0[];
extern u8 lbl_1_data_42354__fzgx_offset_0[];
extern u8 lbl_1_data_42364__fzgx_offset_0[];
extern u8 lbl_1_data_4236C__fzgx_offset_0[];
extern u8 lbl_1_data_42378__fzgx_offset_0[];
extern u8 lbl_1_data_42380__fzgx_offset_0[];
extern u8 lbl_1_data_42388__fzgx_offset_0[];
extern u8 lbl_1_data_42390__fzgx_offset_0[];
static u32 fzgx_pool_data_lbl_1_data_42198[416] = {  /* fzgx-allow: A1 retail data bytes and bindings */
    0x4E4F4E00, 0x4D415354, 0x45522052, 0x45435600, 0x4D415354, 0x45522053, 0x454E4400, 0x534C4156,
    0x45205345, 0x4E440000, 0x534C4156, 0x45205245, 0x43560000, 0x494E4954, 0x0, 0x54455354,
    0x0, 0x54455354, 0x454E4400, 0x53455455, 0x50000000, 0x53455455, 0x505F444F, 0x4E450000,
    0x53455455, 0x505F434F, 0x554E5445, 0x52000000, 0x53455455, 0x505F434E, 0x545F444F, 0x4E450000,
    0x554E4C49, 0x4E4B0000, 0x434F494E, 0x0, 0x454E5452, 0x595F5741, 0x49540000, 0x4348414C,
    0x4C454E47, 0x45520000, 0x4348414C, 0x4C454E47, 0x45525F4F, 0x4B000000, 0x454E5452, 0x59000000,
    0x454E5452, 0x595F4F4B, 0x0, 0x53494E47, 0x4C454348, 0x45434B00, 0x53494E47, 0x4C454348,
    0x45434B5F, 0x4F4B0000, 0x434F5552, 0x53450000, 0x434F5552, 0x53455F4F, 0x4B000000, 0x434F5552,
    0x53455F44, 0x41544100, 0x434F5552, 0x53455F44, 0x4154415F, 0x4F4B0000, 0x4D414348, 0x494E4500,
    0x4D414348, 0x494E455F, 0x4F4B0000, 0x434F4E46, 0x49470000, 0x434F4E46, 0x49475F4F, 0x4B000000,
    0x434F554E, 0x54455241, 0x444A5553, 0x54000000, 0x4C494E4B, 0x57414954, 0x0, 0x4C494E4B,
    0x57414954, 0x4F4B0000, 0x4C494E4B, 0x53454C00, 0x4C494E4B, 0x44454C49, 0x56455259, 0x53544152,
    0x54000000, 0x4C494E4B, 0x44454C49, 0x56455259, 0x0, 0x4C494E4B, 0x44454C49, 0x56455259,
    0x4F4B0000, 0x4C494E4B, 0x53454C4F, 0x4B000000, 0x434F5552, 0x53455649, 0x45570000, 0x434F5552,
    0x53455649, 0x45575F4F, 0x4B000000, 0x4C494E4B, 0x52455100, 0x4C494E4B, 0x5354414E, 0x44425900,
    0x4C494E4B, 0x4F4B0000, 0x4C494E4B, 0x0, 0x50415553, 0x45000000, 0x4552524F, 0x52000000,
    (u32)lbl_1_data_42198__fzgx_offset_0, (u32)lbl_1_data_4219C__fzgx_offset_0, (u32)lbl_1_data_421A8__fzgx_offset_0, (u32)lbl_1_data_421B4__fzgx_offset_0, (u32)lbl_1_data_421C0__fzgx_offset_0, (u32)lbl_1_data_421CC__fzgx_offset_0, (u32)lbl_1_data_421D4__fzgx_offset_0, (u32)lbl_1_data_421DC__fzgx_offset_0,
    (u32)lbl_1_data_421E4__fzgx_offset_0, (u32)lbl_1_data_421EC__fzgx_offset_0, (u32)lbl_1_data_421F8__fzgx_offset_0, (u32)lbl_1_data_42208__fzgx_offset_0, (u32)lbl_1_data_42218__fzgx_offset_0, (u32)lbl_1_data_42220__fzgx_offset_0, (u32)lbl_1_data_42228__fzgx_offset_0, (u32)lbl_1_data_42234__fzgx_offset_0,
    (u32)lbl_1_data_42240__fzgx_offset_0, (u32)lbl_1_data_42250__fzgx_offset_0, (u32)lbl_1_data_42258__fzgx_offset_0, (u32)lbl_1_data_42264__fzgx_offset_0, (u32)lbl_1_data_42270__fzgx_offset_0, (u32)lbl_1_data_42280__fzgx_offset_0, (u32)lbl_1_data_42288__fzgx_offset_0, (u32)lbl_1_data_42294__fzgx_offset_0,
    (u32)lbl_1_data_422A0__fzgx_offset_0, (u32)lbl_1_data_422B0__fzgx_offset_0, (u32)lbl_1_data_422B8__fzgx_offset_0, (u32)lbl_1_data_422C4__fzgx_offset_0, (u32)lbl_1_data_422CC__fzgx_offset_0, (u32)lbl_1_data_422D8__fzgx_offset_0, (u32)lbl_1_data_422E8__fzgx_offset_0, (u32)lbl_1_data_422F4__fzgx_offset_0,
    (u32)lbl_1_data_42300__fzgx_offset_0, (u32)lbl_1_data_42308__fzgx_offset_0, (u32)lbl_1_data_4231C__fzgx_offset_0, (u32)lbl_1_data_4232C__fzgx_offset_0, (u32)lbl_1_data_4233C__fzgx_offset_0, (u32)lbl_1_data_42348__fzgx_offset_0, (u32)lbl_1_data_42354__fzgx_offset_0, (u32)lbl_1_data_42364__fzgx_offset_0,
    (u32)lbl_1_data_4236C__fzgx_offset_0, (u32)lbl_1_data_42378__fzgx_offset_0, (u32)lbl_1_data_42380__fzgx_offset_0, (u32)lbl_1_data_42388__fzgx_offset_0, (u32)lbl_1_data_42390__fzgx_offset_0, (u32)fn_1_1420E0__fzgx_offset_0, (u32)fn_1_144E90__fzgx_offset_0, (u32)fn_1_144EE8__fzgx_offset_0,
    (u32)fn_1_149E2C__fzgx_offset_0, (u32)fn_1_149F04__fzgx_offset_0, (u32)fn_1_149DA4__fzgx_offset_0, (u32)fn_1_149DE8__fzgx_offset_0, (u32)fn_1_149F5C__fzgx_offset_0, (u32)fn_1_14A000__fzgx_offset_0, (u32)fn_1_14A004__fzgx_offset_0, (u32)fn_1_14A008__fzgx_offset_0,
    0x5B000000, 0x5D000000, 0x4E414D45, 0x3A000000, 0x25640000, 0x4E414D45, 0x0, 0x50494C4F,
    0x54205241, 0x4E4B0000, 0x25316400, 0x252D3264, 0x0, 0x25303264, 0x3C253032, 0x643D2530,
    0x33640000, 0x25303264, 0x3B253032, 0x643C2530, 0x33640000, 0x25346400, 0x83418343, 0x838B8367,
    0x83938140, 0x835A8369, 0x0, 0x82608144, 0x83608346, 0x8355838A, 0x83588140, 0x0,
    0x836C838B, 0x835C8393, 0x81408373, 0x83508140, 0x0, 0x83418389, 0x83938140, 0x8376838D,  /* fzgx-allow: A1 retail data bytes */
    0x83588367, 0x0, 0x837D8358, 0x835E815B, 0x83898343, 0x835A8393, 0x83580000, 0x82528251,
    0x8B898389, 0x8343835A, 0x83938358, 0x0, 0x83708343, 0x838D8362, 0x83678CF3, 0x95E290B6,
    0x0, 0x82728272, 0x8B898389, 0x8343835A, 0x83938358, 0x0, 0x4E4F2044, 0x41544100,
    0x52455355, 0x4C545300, 0x544F5441, 0x4C205241, 0x4E4B494E, 0x47000000, 0x56532052, 0x4553554C,
    0x54530000, 0x56532054, 0x4F54414C, 0x2052414E, 0x4B494E47, 0x0, 0x54494D45, 0x20415454,
    0x41434B00, 0x50524143, 0x54494345, 0x0, 0x474F4D41, 0x52202620, 0x5348494F, 0x48000000,
    0x474F4D41, 0x52202C20, 0x5348494F, 0x48000000, 0x43617069, 0x74616C20, 0x4C657474, 0x65727300,
    0x47455220, 0x43617069, 0x74616C20, 0x4C657474, 0x65727300, 0x46524520, 0x43617069, 0x74616C20,
    0x4C657474, 0x65727300, 0x53504120, 0x43617069, 0x74616C20, 0x4C657474, 0x65727300, 0x49544120,
    0x43617069, 0x74616C20, 0x4C657474, 0x65727300, 0x89709094, 0x0, 0x20536D61, 0x6C6C204C,
    0x65747465, 0x72732000, 0x47455220, 0x536D616C, 0x6C204C65, 0x74746572, 0x73000000, 0x46524520,
    0x536D616C, 0x6C204C65, 0x74746572, 0x73000000, 0x53504120, 0x536D616C, 0x6C204C65, 0x74746572,
    0x73000000, 0x49544120, 0x536D616C, 0x6C204C65, 0x74746572, 0x73000000, 0x8B4C8D86, 0x0,
    0x20202020, 0x20536967, 0x6E732020, 0x20202000, 0x47455220, 0x5369676E, 0x73000000, 0x46524520,
    0x5369676E, 0x73000000, 0x53504120, 0x5369676E, 0x73000000, 0x49544120, 0x5369676E, 0x73000000,
    0x82A982C8, 0x0, 0x20202020, 0x4E756D62, 0x65727320, 0x20200000, 0x47455220, 0x4E756D62,
    0x65727300, 0x46524520, 0x4E756D62, 0x65727300, 0x53504120, 0x4E756D62, 0x65727300, 0x49544120,
    0x4E756D62, 0x65727300, 0x834A8369, 0x0, 0x83A02044, 0x656C6574, 0x6520839F, 0x20456E74,
    0x65722083, 0xB45B2573, 0x5D000000, 0x47455220, 0x83A02044, 0x656C6574, 0x6520839F, 0x20456E74,
    0x65722083, 0xB45B2573, 0x5D000000, 0x46524520, 0x83A02044, 0x656C6574, 0x6520839F, 0x20456E74,
    0x65722083, 0xB45B2573, 0x5D000000, 0x53504120, 0x83A02044, 0x656C6574, 0x6520839F, 0x20456E74,
    0x65722083, 0xB45B2573, 0x5D000000, 0x49544120, 0x83A02044, 0x656C6574, 0x6520839F, 0x20456E74,
    0x65722083, 0xB45B2573, 0x5D000000, 0x83A0208F, 0xC182B720, 0x839F208C, 0x8892E820, 0x83B45B25,
    0x735D0000, 0x81E70000, 0x20200000, 0x81E80000, 0x25303264, 0x0, 0x25303364, 0x0
};
static char fzgx_pool_data_lbl_1_data_42198_680[8] = "RUNNING";
static char fzgx_pool_data_lbl_1_data_42198_688[16] = "DISQUALIFIED";
static char fzgx_pool_data_lbl_1_data_42198_698[16] = "%02d:%02d;%03d";
static char fzgx_pool_data_lbl_1_data_42198_6A8[8] = "%04d";
static char fzgx_pool_data_lbl_1_data_42198_6B0[4] = "%2d";
static void fzgx_data_layout_lbl_1_data_42198(void) {
    volatile u8 s;  /* fzgx-allow: S2 layout primer sink: keeps the retail .data objects in retail order */
    s = *(u8 *)fzgx_pool_data_lbl_1_data_42198;
    s = *(u8 *)fzgx_pool_data_lbl_1_data_42198_680;
    s = *(u8 *)fzgx_pool_data_lbl_1_data_42198_688;
    s = *(u8 *)fzgx_pool_data_lbl_1_data_42198_698;
    s = *(u8 *)fzgx_pool_data_lbl_1_data_42198_6A8;
    s = *(u8 *)fzgx_pool_data_lbl_1_data_42198_6B0;
}
#pragma section code_type ".text"

static inline BOOL fn_1_148950_mode_1_3(s32 mode) {
    BOOL r = FALSE;
    if (mode == 1 || mode == 3) {
        r = TRUE;
    }
    return r;
}
static inline BOOL fn_1_148950_mode_0_2_7_8(s32 mode) {
    BOOL r = FALSE;
    if (mode == 0 || mode == 2 || mode == 8 || mode == 7) {
        r = TRUE;
    }
    return r;
}
static inline BOOL fn_1_148950_mode_4_5(s32 mode) {
    BOOL r = TRUE;
    if (!((u32)(mode - 4) <= 1)) r = FALSE;
    return r;
}
static inline BOOL fn_1_148950_mode_4_5_9(s32 mode) {
    BOOL r = TRUE;
    if (!fn_1_148950_mode_4_5(mode) && mode != 9) r = FALSE;
    return r;
}
static inline BOOL fn_1_148950_mode_4_5_9_10(s32 mode) {
    BOOL r = TRUE;
    if (!fn_1_148950_mode_4_5_9(mode) && mode != 10) r = FALSE;
    return r;
}
static inline BOOL fn_1_148950_mode_4_5_6_9_10(s32 mode) {
    BOOL r = TRUE;
    if (!fn_1_148950_mode_4_5_9_10(mode) && mode != 6) r = FALSE;
    return r;
}

void fn_1_148950(s32 mode, const fn_1_148950_Row *row) {
    FontDrawPacket packet;
    char buf[0x100];
    s32 x;
    s32 y;
    u8 diff;

    packet = *(const FontDrawPacket *)fzgx_pool_table_058;
    packet.image = 0x9700;
    packet.x = (0x1AB + row->unk_68 + row->unk_74);
    packet.y = (row->unk_64 + 14);
    if (mode == 3) {
        packet.x += -10.0f;
    }
    packet.z = 47.0f;
    fn_1_4F734(&packet);
    x = mode == 3 ? 445 : 455;
    y = row->unk_64 + 12;
    if (!fn_1_148950_mode_1_3(mode) && row->unk_5C == 0xFF) {
        fn_1_49410();
        fn_1_494DC(0x15);
        fn_1_495B0(0x80000000);
        fn_1_49738(fn_1_149B24);
        fn_1_496FC((row->unk_74 + 0x1C0), y);
        fn_1_4954C(47.0f);
        fn_1_4955C(0.8f, 1.0f);
        fn_1_4966C(-1.0f, 0.0f);
        fn_1_4A0D8(fzgx_pool_data_lbl_1_data_42198_680);
    } else if (!fn_1_148950_mode_1_3(mode) && row->unk_5C == 0xFE) {
        fn_1_49410();
        fn_1_494DC(0x15);
        fn_1_495B0(0x80000000);
        fn_1_49738(fn_1_149B24);
        fn_1_496FC((row->unk_74 + 0x1C0), y);
        fn_1_4954C(47.0f);
        fn_1_4955C(0.8f, 1.0f);
        fn_1_4966C(-1.0f, 0.0f);
        fn_1_4A0D8(fzgx_pool_data_lbl_1_data_42198_688);
    } else if (fn_1_148950_mode_0_2_7_8(mode) || fn_1_148950_mode_4_5_6_9_10(mode)) {
        if (fn_1_148950_mode_4_5_6_9_10(mode)) {
            switch (lbl_1_bss_8E559) {
            case 0:
            default:
                sprintf(buf, fzgx_pool_data_lbl_1_data_42198_698, (row->unk_30 >> 20) & 0xFF,
                        (row->unk_30 >> 12) & 0xFF, row->unk_30 & 0xFFF);
                break;
            case 1:
                sprintf(buf, fzgx_pool_data_lbl_1_data_42198_6A8, row->unk_40);
                packet = *(const FontDrawPacket *)fzgx_pool_table_058;
                packet.image = 0x9704;
                packet.x = (row->unk_74 + (row->unk_68 + 0x205));
                packet.y = (row->unk_64 + 21);
                packet.z = 47.0f;
                fn_1_4F734(&packet);
                break;
            case 2:
                sprintf(buf, fzgx_pool_data_lbl_1_data_42198_698, (row->unk_3C >> 20) & 0xFF,
                        (row->unk_3C >> 12) & 0xFF, row->unk_3C & 0xFFF);
                break;
            }
        } else {
            sprintf(buf, fzgx_pool_data_lbl_1_data_42198_698, (row->unk_30 >> 20) & 0xFF,
                    (row->unk_30 >> 12) & 0xFF, row->unk_30 & 0xFFF);
        }
        fn_1_49410();
        fn_1_494DC(0x12);
        fn_1_495B0(0x80000000);
        fn_1_496FC((row->unk_74 + 0x1C0), y);
        fn_1_49738(fn_1_149C2C);
        fn_1_4954C(47.0f);
        fn_1_4A0D8(buf);
    } else {
        fn_1_49410();
        fn_1_494DC(0x12);
        fn_1_496FC((x + row->unk_74), y);
        fn_1_49738(fn_1_149C2C);
        fn_1_4954C(47.0f);
        fn_1_4AE0C(fzgx_pool_data_lbl_1_data_42198_6A8, row->unk_54);
        packet = *(const FontDrawPacket *)fzgx_pool_table_058;
        packet.image = 0x9721;
        packet.x = (0x42 + x + row->unk_74);
        packet.y = (row->unk_64 + 15);
        packet.z = 47.0f;
        fn_1_4F734(&packet);
        if (row->unk_60 != row->unk_61) {
            packet = *(const FontDrawPacket *)fzgx_pool_table_000;
            packet.x = (row->unk_70 + 24);
            packet.y = (row->unk_64 + 12);
            packet.z = 40.0f;
            packet.alpha = lbl_801A66A4 % 60 > 30 ? 1.0f : 0.0f;
            if (row->unk_60 < row->unk_61) {
                packet.image = 0x9702;
                fn_1_4F734(&packet);
                diff = row->unk_61 - row->unk_60;
            } else {
                packet.image = 0x9701;
                fn_1_4F734(&packet);
                diff = row->unk_60 - row->unk_61;
            }
            fn_1_49410();
            fn_1_494DC(0x1A);
            fn_1_496FC((row->unk_70 + 24), (row->unk_64 + 28));
            fn_1_49738(fn_1_149BF4);
            fn_1_4954C(47.0f);
            fn_1_4AE0C(fzgx_pool_data_lbl_1_data_42198_6B0, diff);
        }
    }
}
/* fzgx:end fn_1_148950 */

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

/* fzgx:begin fn_1_1492E0 */
#pragma section code_type ".fzgxpool"
static const u32 fzgx_pool_table1[3] = {0x00000000, 0x00000000, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep1(void) { const u32 *volatile cp; cp = fzgx_pool_table1; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime2(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 0.10000000149011612f;
}
static const u32 fzgx_pool_table3[62] = {0x3F800000, 0x3F800000, 0x00000000, 0x00000000, 0x3F800000, 0x3F800000, 0x00000000, 0x3F800000, 0x04000000, 0x00000000, 0xFFFFFFFF, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x3DCCCCCD, 0x3F800000, 0x3F800000, 0x00000000, 0x00000000, 0x3F800000, 0x3F800000, 0x00000000, 0x3F800000, 0x04000000, 0x00000000, 0xFFFFFFFF, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x3DCCCCCD, 0x3F800000, 0x3F800000, 0x00000000, 0x00000000, 0x3F800000, 0x3F800000, 0x00000000, 0x3F800000, 0x04000000, 0x00000000, 0xFFFFFFFF, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
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
    s = 1.0f;
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
static const u32 fzgx_pool_table9[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep9(void) { const u32 *volatile cp; cp = fzgx_pool_table9; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime10(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 4503599627370496.0;
}
static const u32 fzgx_pool_table11[1] = {0x4E4F204E};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep11(void) { const u32 *volatile cp; cp = fzgx_pool_table11; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime12(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 12.829345703125f;
}
static const u32 fzgx_pool_table13[1] = {0x4E4F2044};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep13(void) { const u32 *volatile cp; cp = fzgx_pool_table13; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime14(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 13.265869140625f;
    s = 100.0f;
    s = 350.0f;
    s = 44.0f;
    s = 8.0f;
}
static const u32 fzgx_pool_table15[14] = {0xFFFFFFFF, 0x00F0E6FF, 0x007873FF, 0xA0FF00FF, 0x0000001A, 0x00000023, 0x0000013C, 0x00000145, 0x00000018, 0x00000021, 0x00000065, 0x0000006E, 0x000000B2, 0x000000BB};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep15(void) { const u32 *volatile cp; cp = fzgx_pool_table15; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime16(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 30.0f;
    s = 0.75f;
    s = 54.0f;
    s = 343.0f;
    s = 65536.0f;
    s = 120.0f;
    s = 0.3499999940395355f;
}
static const u32 fzgx_pool_table17[25] = {0xFFFFFFFF, 0x00F0E6FF, 0x007873FF, 0xFFFF00FF, 0xFFFF00FF, 0x8080FFFF, 0x0000001A, 0x00000023, 0x0000013C, 0x00000145, 0x00000018, 0x00000021, 0x00000065, 0x0000006E, 0x000000B2, 0x000000BB, 0x19FF1900, 0x19FF1900, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep17(void) { const u32 *volatile cp; cp = fzgx_pool_table17; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime18(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 3.748046875f;
}
static const u32 fzgx_pool_table19[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep19(void) { const u32 *volatile cp; cp = fzgx_pool_table19; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime20(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 20.0f;
}
static const u32 fzgx_pool_table21[14] = {0x0000001A, 0x00000023, 0x0000013C, 0x00000145, 0xFFFFFF00, 0x19FF1900, 0x0000001A, 0x00000023, 0x0000013C, 0x00000145, 0x19FF1900, 0x00FFFFFF, 0x00FFFFFF, 0xFFFFFF00};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep21(void) { const u32 *volatile cp; cp = fzgx_pool_table21; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime22(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 0.800000011920929f;
    s = -2.0f;
}
static const u32 fzgx_pool_table23[28] = {0x0000001A, 0x00000023, 0x0000013C, 0x00000145, 0x00000018, 0x00000021, 0x0000001A, 0x00000023, 0x0000013C, 0x00000145, 0x00000018, 0x00000021, 0xFFFF00FF, 0x19FF1900, 0x00000000, 0x0000001A, 0x00000023, 0x0000013C, 0x00000145, 0x19FF1900, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep23(void) { const u32 *volatile cp; cp = fzgx_pool_table23; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime24(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 68.0f;
    s = 86.0f;
    s = 0.375f;
    s = 80.0f;
    s = 14.0f;
    s = 21.0f;
    s = 1.100000023841858f;
    s = 399.0f;
    s = 574.0f;
    s = 0.8500000238418579f;
    s = 510.0f;
}
static const u32 fzgx_pool_table25[27] = {0x19FF1900, 0x19FF1900, 0xF4962800, 0xF4962800, 0xFFFF0000, 0x00000000, 0xFFFFFF00, 0xF4962800, 0xF4962800, 0xFFFF0000, 0x00000000, 0xFFFFFF00, 0xF4962800, 0xFFFF00FF, 0x00000000, 0x19FF1900, 0x19FF1900, 0xF4962800, 0xF4962800, 0x8080FF00, 0x00000000, 0xFFFFFF00, 0xF4962800, 0xF4962800, 0x8080FF00, 0x00000000, 0xFFFFFF00};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep25(void) { const u32 *volatile cp; cp = fzgx_pool_table25; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime26(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 354.0f;
    s = 84.0f;
    s = 22.0f;
    s = 0.6499999761581421f;
    s = 192.0f;
    s = 48.0f;
    s = 46.0f;
    s = 55.0f;
}
static const u32 fzgx_pool_table27[2] = {0xFADC82FF, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep27(void) { const u32 *volatile cp; cp = fzgx_pool_table27; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime28(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 639.0f;
    s = 479.0f;
    s = 320.0f;
    s = 70.0f;
    s = 112.0f;
    s = 492.0f;
    s = 33.0f;
    s = 19.0f;
    s = 24.0f;
    s = 50.0f;
    s = 29.0f;
    s = 72.0f;
    s = 47.0f;
}
static const u32 fzgx_pool_table29[8] = {0x00009736, 0x00009737, 0x00009738, 0x00009739, 0x0000973A, 0x0000973B, 0x0000973C, 0x0000973D};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep29(void) { const u32 *volatile cp; cp = fzgx_pool_table29; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime30(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 45.0f;
    s = 42.0f;
    s = 38.0f;
}
static const u32 fzgx_pool_table31[2] = {0x00000000, 0xC0C0C000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep31(void) { const u32 *volatile cp; cp = fzgx_pool_table31; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime32(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 41.0f;
    s = 255.0f;
    s = 60.0f;
}
static const u32 fzgx_pool_table33[32] = {0xFFFF00FF, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep33(void) { const u32 *volatile cp; cp = fzgx_pool_table33; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime34(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 0.009999999776482582f;
}
static const u32 fzgx_pool_table35[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep35(void) { const u32 *volatile cp; cp = fzgx_pool_table35; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime36(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 0.0005;
    s = 13.333333969116211f;
    s = 166.0f;
    s = 348.3333435058594f;
    s = 9.0f;
    s = 7.0f;
    s = 170.0f;
    s = -10.0f;
    s = 74.0f;
    s = 92.0f;
    s = 105.0f;
    s = 110.0f;
    s = 302.0f;
}
#pragma section code_type ".text"

struct fn_1_1492E0_Copy88 { u32 a[22]; };
struct Results56 { u32 a[14]; };

extern f32 lbl_1_rodata_26F8[22];
extern void fn_1_51678(FontDrawPacket *, u32, s16, s16, s16, s16);
extern int fn_1_4F734(FontDrawPacket *);
extern s32 fn_1_156218(u32, void *, void *, void *);
extern void fn_1_49410(void);
extern void fn_1_494DC(s16);
extern void fn_1_495B0(u32);
extern void fn_1_49590(f32);
extern void fn_1_4955C(f32, f32);
extern void fn_1_496FC(f32, f32);
extern void fn_1_4AE0C(const char *, ...);
extern void fn_1_4A0D8(const char *);
extern int sprintf(char *, const char *, ...);

/* Shared literal pool layout of the TU (lbl_1_rodata_92C0 .. +0x54C): tables and
   the literals this function reads, in retail order. */

#define FONT_SETUP(n)            \
    fn_1_49410();                \
    fn_1_494DC(n);               \
    fn_1_495B0(0x80000000);      \
    fn_1_49590(0.5f);            \
    fn_1_4955C(0.8f, 0.8f)

extern u8 fn_1_1420E0__fzgx_offset_0[];
extern u8 fn_1_144E90__fzgx_offset_0[];
extern u8 fn_1_144EE8__fzgx_offset_0[];
extern u8 fn_1_149DA4__fzgx_offset_0[];
extern u8 fn_1_149DE8__fzgx_offset_0[];
extern u8 fn_1_149E2C__fzgx_offset_0[];
extern u8 fn_1_149F04__fzgx_offset_0[];
extern u8 fn_1_149F5C__fzgx_offset_0[];
extern u8 fn_1_14A000__fzgx_offset_0[];
extern u8 fn_1_14A004__fzgx_offset_0[];
extern u8 fn_1_14A008__fzgx_offset_0[];
extern u8 lbl_1_data_42198__fzgx_offset_0[];
extern u8 lbl_1_data_4219C__fzgx_offset_0[];
extern u8 lbl_1_data_421A8__fzgx_offset_0[];
extern u8 lbl_1_data_421B4__fzgx_offset_0[];
extern u8 lbl_1_data_421C0__fzgx_offset_0[];
extern u8 lbl_1_data_421CC__fzgx_offset_0[];
extern u8 lbl_1_data_421D4__fzgx_offset_0[];
extern u8 lbl_1_data_421DC__fzgx_offset_0[];
extern u8 lbl_1_data_421E4__fzgx_offset_0[];
extern u8 lbl_1_data_421EC__fzgx_offset_0[];
extern u8 lbl_1_data_421F8__fzgx_offset_0[];
extern u8 lbl_1_data_42208__fzgx_offset_0[];
extern u8 lbl_1_data_42218__fzgx_offset_0[];
extern u8 lbl_1_data_42220__fzgx_offset_0[];
extern u8 lbl_1_data_42228__fzgx_offset_0[];
extern u8 lbl_1_data_42234__fzgx_offset_0[];
extern u8 lbl_1_data_42240__fzgx_offset_0[];
extern u8 lbl_1_data_42250__fzgx_offset_0[];
extern u8 lbl_1_data_42258__fzgx_offset_0[];
extern u8 lbl_1_data_42264__fzgx_offset_0[];
extern u8 lbl_1_data_42270__fzgx_offset_0[];
extern u8 lbl_1_data_42280__fzgx_offset_0[];
extern u8 lbl_1_data_42288__fzgx_offset_0[];
extern u8 lbl_1_data_42294__fzgx_offset_0[];
extern u8 lbl_1_data_422A0__fzgx_offset_0[];
extern u8 lbl_1_data_422B0__fzgx_offset_0[];
extern u8 lbl_1_data_422B8__fzgx_offset_0[];
extern u8 lbl_1_data_422C4__fzgx_offset_0[];
extern u8 lbl_1_data_422CC__fzgx_offset_0[];
extern u8 lbl_1_data_422D8__fzgx_offset_0[];
extern u8 lbl_1_data_422E8__fzgx_offset_0[];
extern u8 lbl_1_data_422F4__fzgx_offset_0[];
extern u8 lbl_1_data_42300__fzgx_offset_0[];
extern u8 lbl_1_data_42308__fzgx_offset_0[];
extern u8 lbl_1_data_4231C__fzgx_offset_0[];
extern u8 lbl_1_data_4232C__fzgx_offset_0[];
extern u8 lbl_1_data_4233C__fzgx_offset_0[];
extern u8 lbl_1_data_42348__fzgx_offset_0[];
extern u8 lbl_1_data_42354__fzgx_offset_0[];
extern u8 lbl_1_data_42364__fzgx_offset_0[];
extern u8 lbl_1_data_4236C__fzgx_offset_0[];
extern u8 lbl_1_data_42378__fzgx_offset_0[];
extern u8 lbl_1_data_42380__fzgx_offset_0[];
extern u8 lbl_1_data_42388__fzgx_offset_0[];
extern u8 lbl_1_data_42390__fzgx_offset_0[];
static u32 fzgx_pool_data_lbl_1_data_42198[422] = {  /* fzgx-allow: A1 retail data bytes and bindings */
    0x4E4F4E00, 0x4D415354, 0x45522052, 0x45435600, 0x4D415354, 0x45522053, 0x454E4400, 0x534C4156,
    0x45205345, 0x4E440000, 0x534C4156, 0x45205245, 0x43560000, 0x494E4954, 0x0, 0x54455354,
    0x0, 0x54455354, 0x454E4400, 0x53455455, 0x50000000, 0x53455455, 0x505F444F, 0x4E450000,
    0x53455455, 0x505F434F, 0x554E5445, 0x52000000, 0x53455455, 0x505F434E, 0x545F444F, 0x4E450000,
    0x554E4C49, 0x4E4B0000, 0x434F494E, 0x0, 0x454E5452, 0x595F5741, 0x49540000, 0x4348414C,
    0x4C454E47, 0x45520000, 0x4348414C, 0x4C454E47, 0x45525F4F, 0x4B000000, 0x454E5452, 0x59000000,
    0x454E5452, 0x595F4F4B, 0x0, 0x53494E47, 0x4C454348, 0x45434B00, 0x53494E47, 0x4C454348,
    0x45434B5F, 0x4F4B0000, 0x434F5552, 0x53450000, 0x434F5552, 0x53455F4F, 0x4B000000, 0x434F5552,
    0x53455F44, 0x41544100, 0x434F5552, 0x53455F44, 0x4154415F, 0x4F4B0000, 0x4D414348, 0x494E4500,
    0x4D414348, 0x494E455F, 0x4F4B0000, 0x434F4E46, 0x49470000, 0x434F4E46, 0x49475F4F, 0x4B000000,
    0x434F554E, 0x54455241, 0x444A5553, 0x54000000, 0x4C494E4B, 0x57414954, 0x0, 0x4C494E4B,
    0x57414954, 0x4F4B0000, 0x4C494E4B, 0x53454C00, 0x4C494E4B, 0x44454C49, 0x56455259, 0x53544152,
    0x54000000, 0x4C494E4B, 0x44454C49, 0x56455259, 0x0, 0x4C494E4B, 0x44454C49, 0x56455259,
    0x4F4B0000, 0x4C494E4B, 0x53454C4F, 0x4B000000, 0x434F5552, 0x53455649, 0x45570000, 0x434F5552,
    0x53455649, 0x45575F4F, 0x4B000000, 0x4C494E4B, 0x52455100, 0x4C494E4B, 0x5354414E, 0x44425900,
    0x4C494E4B, 0x4F4B0000, 0x4C494E4B, 0x0, 0x50415553, 0x45000000, 0x4552524F, 0x52000000,
    (u32)lbl_1_data_42198__fzgx_offset_0, (u32)lbl_1_data_4219C__fzgx_offset_0, (u32)lbl_1_data_421A8__fzgx_offset_0, (u32)lbl_1_data_421B4__fzgx_offset_0, (u32)lbl_1_data_421C0__fzgx_offset_0, (u32)lbl_1_data_421CC__fzgx_offset_0, (u32)lbl_1_data_421D4__fzgx_offset_0, (u32)lbl_1_data_421DC__fzgx_offset_0,
    (u32)lbl_1_data_421E4__fzgx_offset_0, (u32)lbl_1_data_421EC__fzgx_offset_0, (u32)lbl_1_data_421F8__fzgx_offset_0, (u32)lbl_1_data_42208__fzgx_offset_0, (u32)lbl_1_data_42218__fzgx_offset_0, (u32)lbl_1_data_42220__fzgx_offset_0, (u32)lbl_1_data_42228__fzgx_offset_0, (u32)lbl_1_data_42234__fzgx_offset_0,
    (u32)lbl_1_data_42240__fzgx_offset_0, (u32)lbl_1_data_42250__fzgx_offset_0, (u32)lbl_1_data_42258__fzgx_offset_0, (u32)lbl_1_data_42264__fzgx_offset_0, (u32)lbl_1_data_42270__fzgx_offset_0, (u32)lbl_1_data_42280__fzgx_offset_0, (u32)lbl_1_data_42288__fzgx_offset_0, (u32)lbl_1_data_42294__fzgx_offset_0,
    (u32)lbl_1_data_422A0__fzgx_offset_0, (u32)lbl_1_data_422B0__fzgx_offset_0, (u32)lbl_1_data_422B8__fzgx_offset_0, (u32)lbl_1_data_422C4__fzgx_offset_0, (u32)lbl_1_data_422CC__fzgx_offset_0, (u32)lbl_1_data_422D8__fzgx_offset_0, (u32)lbl_1_data_422E8__fzgx_offset_0, (u32)lbl_1_data_422F4__fzgx_offset_0,
    (u32)lbl_1_data_42300__fzgx_offset_0, (u32)lbl_1_data_42308__fzgx_offset_0, (u32)lbl_1_data_4231C__fzgx_offset_0, (u32)lbl_1_data_4232C__fzgx_offset_0, (u32)lbl_1_data_4233C__fzgx_offset_0, (u32)lbl_1_data_42348__fzgx_offset_0, (u32)lbl_1_data_42354__fzgx_offset_0, (u32)lbl_1_data_42364__fzgx_offset_0,
    (u32)lbl_1_data_4236C__fzgx_offset_0, (u32)lbl_1_data_42378__fzgx_offset_0, (u32)lbl_1_data_42380__fzgx_offset_0, (u32)lbl_1_data_42388__fzgx_offset_0, (u32)lbl_1_data_42390__fzgx_offset_0, (u32)fn_1_1420E0__fzgx_offset_0, (u32)fn_1_144E90__fzgx_offset_0, (u32)fn_1_144EE8__fzgx_offset_0,
    (u32)fn_1_149E2C__fzgx_offset_0, (u32)fn_1_149F04__fzgx_offset_0, (u32)fn_1_149DA4__fzgx_offset_0, (u32)fn_1_149DE8__fzgx_offset_0, (u32)fn_1_149F5C__fzgx_offset_0, (u32)fn_1_14A000__fzgx_offset_0, (u32)fn_1_14A004__fzgx_offset_0, (u32)fn_1_14A008__fzgx_offset_0,
    0x5B000000, 0x5D000000, 0x4E414D45, 0x3A000000, 0x25640000, 0x4E414D45, 0x0, 0x50494C4F,
    0x54205241, 0x4E4B0000, 0x25316400, 0x252D3264, 0x0, 0x25303264, 0x3C253032, 0x643D2530,
    0x33640000, 0x25303264, 0x3B253032, 0x643C2530, 0x33640000, 0x25346400, 0x83418343, 0x838B8367,
    0x83938140, 0x835A8369, 0x0, 0x82608144, 0x83608346, 0x8355838A, 0x83588140, 0x0,
    0x836C838B, 0x835C8393, 0x81408373, 0x83508140, 0x0, 0x83418389, 0x83938140, 0x8376838D,  /* fzgx-allow: A1 retail data bytes */
    0x83588367, 0x0, 0x837D8358, 0x835E815B, 0x83898343, 0x835A8393, 0x83580000, 0x82528251,
    0x8B898389, 0x8343835A, 0x83938358, 0x0, 0x83708343, 0x838D8362, 0x83678CF3, 0x95E290B6,
    0x0, 0x82728272, 0x8B898389, 0x8343835A, 0x83938358, 0x0, 0x4E4F2044, 0x41544100,
    0x52455355, 0x4C545300, 0x544F5441, 0x4C205241, 0x4E4B494E, 0x47000000, 0x56532052, 0x4553554C,
    0x54530000, 0x56532054, 0x4F54414C, 0x2052414E, 0x4B494E47, 0x0, 0x54494D45, 0x20415454,
    0x41434B00, 0x50524143, 0x54494345, 0x0, 0x474F4D41, 0x52202620, 0x5348494F, 0x48000000,
    0x474F4D41, 0x52202C20, 0x5348494F, 0x48000000, 0x43617069, 0x74616C20, 0x4C657474, 0x65727300,
    0x47455220, 0x43617069, 0x74616C20, 0x4C657474, 0x65727300, 0x46524520, 0x43617069, 0x74616C20,
    0x4C657474, 0x65727300, 0x53504120, 0x43617069, 0x74616C20, 0x4C657474, 0x65727300, 0x49544120,
    0x43617069, 0x74616C20, 0x4C657474, 0x65727300, 0x89709094, 0x0, 0x20536D61, 0x6C6C204C,
    0x65747465, 0x72732000, 0x47455220, 0x536D616C, 0x6C204C65, 0x74746572, 0x73000000, 0x46524520,
    0x536D616C, 0x6C204C65, 0x74746572, 0x73000000, 0x53504120, 0x536D616C, 0x6C204C65, 0x74746572,
    0x73000000, 0x49544120, 0x536D616C, 0x6C204C65, 0x74746572, 0x73000000, 0x8B4C8D86, 0x0,
    0x20202020, 0x20536967, 0x6E732020, 0x20202000, 0x47455220, 0x5369676E, 0x73000000, 0x46524520,
    0x5369676E, 0x73000000, 0x53504120, 0x5369676E, 0x73000000, 0x49544120, 0x5369676E, 0x73000000,
    0x82A982C8, 0x0, 0x20202020, 0x4E756D62, 0x65727320, 0x20200000, 0x47455220, 0x4E756D62,
    0x65727300, 0x46524520, 0x4E756D62, 0x65727300, 0x53504120, 0x4E756D62, 0x65727300, 0x49544120,
    0x4E756D62, 0x65727300, 0x834A8369, 0x0, 0x83A02044, 0x656C6574, 0x6520839F, 0x20456E74,
    0x65722083, 0xB45B2573, 0x5D000000, 0x47455220, 0x83A02044, 0x656C6574, 0x6520839F, 0x20456E74,
    0x65722083, 0xB45B2573, 0x5D000000, 0x46524520, 0x83A02044, 0x656C6574, 0x6520839F, 0x20456E74,
    0x65722083, 0xB45B2573, 0x5D000000, 0x53504120, 0x83A02044, 0x656C6574, 0x6520839F, 0x20456E74,
    0x65722083, 0xB45B2573, 0x5D000000, 0x49544120, 0x83A02044, 0x656C6574, 0x6520839F, 0x20456E74,
    0x65722083, 0xB45B2573, 0x5D000000, 0x83A0208F, 0xC182B720, 0x839F208C, 0x8892E820, 0x83B45B25,
    0x735D0000, 0x81E70000, 0x20200000, 0x81E80000, 0x25303264, 0x0, 0x25303364, 0x0,
    0x52554E4E, 0x494E4700, 0x44495351, 0x55414C49, 0x46494544, 0x0
};
static u32 fzgx_pool_data_lbl_1_data_42198_698[7] = {  /* fzgx-allow: A1 retail data bytes and bindings */
    0x25303264, 0x3A253032, 0x643B2530, 0x33640000, 0x25303464, 0x0, 0x25326400
};
static u32 fzgx_pool_data_lbl_1_data_42198_6B4[3] = {  /* fzgx-allow: A1 retail data bytes and bindings */
    0x544F5441, 0x4C205449, 0x4D450000
};
static u32 fzgx_pool_data_lbl_1_data_42198_6C0[3] = {  /* fzgx-allow: A1 retail data bytes and bindings */
    0x4D415820, 0x53504545, 0x44000000
};
static u32 fzgx_pool_data_lbl_1_data_42198_6CC[3] = {  /* fzgx-allow: A1 retail data bytes and bindings */
    0x42455354, 0x204C4150, 0x0
};
static u32 fzgx_pool_data_lbl_1_data_42198_6D8[2] = {  /* fzgx-allow: A1 retail data bytes and bindings */
    0x20202530, 0x34640000
};

static inline s32 fn_1_1492E0_range(s32 mode) {
    s32 result = 1;
    if (!((u32)(mode - 4) <= 1)) result = 0;
    return result;
}
static inline s32 fn_1_1492E0_mode9(s32 mode) {
    s32 result = 1;
    if (!fn_1_1492E0_range(mode) && mode != 9) result = 0;
    return result;
}
static inline s32 fn_1_1492E0_mode10(s32 mode) {
    s32 result = 1;
    if (!fn_1_1492E0_mode9(mode) && mode != 10) result = 0;
    return result;
}
static inline s32 fn_1_1492E0_visible(s32 mode) {
    s32 result = 1;
    if (!fn_1_1492E0_mode10(mode) && mode != 6) result = 0;
    return result;
}
void fn_1_1492E0(s32 arg0, void *arg1) {
    
    char buf[256];
    struct fn_1_1492E0_Copy88 packet;
    struct Results56 a;
    struct Results56 b;
    struct Results56 c;
    s32 pos;
    s32 x;
    s32 y;
    s32 z;
    s32 i;

    if (fn_1_1492E0_visible(arg0)) {
        packet = *(struct fn_1_1492E0_Copy88 *)lbl_1_rodata_26F8;
        packet.a[0] = 0x9726;
        fn_1_51678((FontDrawPacket *)&packet, 0x9726, 0, 0, 87, 40);
        ((f32 *)packet.a)[1] = 74.0f;
        ((f32 *)packet.a)[2] = 92.0f;
        ((f32 *)packet.a)[3] = 60.0f;
        fn_1_4F734((FontDrawPacket *)&packet);
        for (i = 0, pos = 161; i < 9; i++, pos += 40) {
            packet = *(struct fn_1_1492E0_Copy88 *)lbl_1_rodata_26F8;
            packet.a[0] = 0x9726;
            fn_1_51678((FontDrawPacket *)&packet, packet.a[0], 47, 0, 40, 40);
            ((f32 *)packet.a)[1] = pos;
            ((f32 *)packet.a)[2] = 92.0f;
            ((f32 *)packet.a)[3] = 60.0f;
            fn_1_4F734((FontDrawPacket *)&packet);
        }
        packet = *(struct fn_1_1492E0_Copy88 *)lbl_1_rodata_26F8;
        packet.a[0] = 0x9726;
        fn_1_51678((FontDrawPacket *)&packet, 0x9726, 87, 0, 45, 40);
        ((f32 *)packet.a)[1] = pos;
        ((f32 *)packet.a)[2] = 92.0f;
        ((f32 *)packet.a)[3] = 60.0f;
        fn_1_4F734((FontDrawPacket *)&packet);
        fn_1_156218(*((u8 *)arg1 + 0x34), &a, &b, &c);
        if (lbl_1_bss_8E559 == 0) { x = -1; y = 115; z = 319; }
        if (lbl_1_bss_8E559 == 1) { x = 101; y = -1; z = 326; }
        if (lbl_1_bss_8E559 == 2) { x = 106; y = 341; z = -1; }
        if (x != -1) { FONT_SETUP(21); fn_1_496FC((f32)x, 105.0f); fn_1_4AE0C(((char *)fzgx_pool_data_lbl_1_data_42198_6B4)); }
        if (y != -1) { FONT_SETUP(21); fn_1_496FC((f32)y, 105.0f); fn_1_4AE0C(((char *)fzgx_pool_data_lbl_1_data_42198_6C0)); }
        if (z != -1) { FONT_SETUP(21); fn_1_496FC((f32)z, 105.0f); fn_1_4AE0C(((char *)fzgx_pool_data_lbl_1_data_42198_6CC)); }
        if (x != -1) {
            FONT_SETUP(18);
            sprintf(buf, ((char *)fzgx_pool_data_lbl_1_data_42198_698), (a.a[0] >> 20) & 255, (a.a[0] >> 12) & 255, a.a[0] & 4095);
            fn_1_496FC((x + 106), 105.0f);
            fn_1_4A0D8(buf);
        }
        if (y != -1) {
            FONT_SETUP(18);
            sprintf(buf, ((char *)fzgx_pool_data_lbl_1_data_42198_6D8), *(u16 *)((u8 *)&b + 0x18));
            fn_1_496FC((y + 89), 105.0f);
            fn_1_4A0D8(buf);
            packet = *(struct fn_1_1492E0_Copy88 *)lbl_1_rodata_26F8;
            packet.a[0] = 0x9704;
            ((f32 *)packet.a)[1] = (y + 156);
            ((f32 *)packet.a)[2] = 110.0f;
            fn_1_4F734((FontDrawPacket *)&packet);
        }
        if (z != -1) {
            FONT_SETUP(18);
            sprintf(buf, ((char *)fzgx_pool_data_lbl_1_data_42198_698), (c.a[1] >> 20) & 255, (c.a[1] >> 12) & 255, c.a[1] & 4095);
            fn_1_496FC((z + 101), 105.0f);
            fn_1_4A0D8(buf);
        }
    }
}
/* fzgx:end fn_1_1492E0 */

/* fzgx:begin fn_1_1498B8 */
struct fn_1_1498B8_Copy88 { u32 a[22]; };
struct fn_1_1498B8_lbl_801A66A4 { u32 unk_0; };
extern u32 lbl_1_bss_8E554;
extern u8 lbl_1_bss_8E550;

#pragma opt_propagation off
void fn_1_1498B8(u32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, f32 arg6) {
    struct fn_1_1498B8_Copy88 loc_8;
    if (((struct fn_1_1498B8_lbl_801A66A4 *)&lbl_801A66A4)->unk_0 - lbl_1_bss_8E528 >= lbl_1_bss_8E554 && (s32)arg0 != 5) {
        if (arg6 < (lbl_1_bss_8E550 - arg1)) {
            loc_8 = *(struct fn_1_1498B8_Copy88 *)&lbl_1_rodata_26F8;
            loc_8.a[0] = 0x971C;
            fn_1_51678((FontDrawPacket *)&loc_8, (*((0) + loc_8.a)), 20, 0, 20, 12);
            *(f32 *)((u8 *)&loc_8 + 4) = 302.0f;
            {
                s32 v7 = arg1 * arg2 - 6;
                v7 += arg5;
                *(f32 *)((u8 *)&loc_8 + 8) = (f32)(arg3 + v7);
            }
            *(f32 *)((u8 *)&loc_8 + 12) = 50.0f;
            *(f32 *)((u8 *)&loc_8 + 44) = ((struct fn_1_1498B8_lbl_801A66A4 *)&lbl_801A66A4)->unk_0 % 60 > 30 ? 1.0f : 0.0f;
            fn_1_4F734((FontDrawPacket *)&loc_8);
        }
        if (arg6 > 0.0f) {
            loc_8 = *(struct fn_1_1498B8_Copy88 *)&lbl_1_rodata_26F8;
            loc_8.a[0] = 0x971C;
            fn_1_51678((FontDrawPacket *)&loc_8, (*((0) + loc_8.a)), 0, 0, 20, 12);
            *(f32 *)((u8 *)&loc_8 + 4) = 302.0f;
            {
                s32 v12 = arg3 + arg4;
                v12 -= 16;
                *(f32 *)((u8 *)&loc_8 + 8) = (f32)v12;
            }
            *(f32 *)((u8 *)&loc_8 + 12) = 50.0f;
            *(f32 *)((u8 *)&loc_8 + 44) = ((struct fn_1_1498B8_lbl_801A66A4 *)&lbl_801A66A4)->unk_0 % 60 > 30 ? 1.0f : 0.0f;
            fn_1_4F734((FontDrawPacket *)&loc_8);
        }
    }
}
/* fzgx:end fn_1_1498B8 */

/* fzgx:begin fn_1_149B24 */
typedef struct {
    f32 value0;
    u8 pad[8];
    f32 value_c;
} Fn149B24Data;


void fn_1_149B24(void* context, Fn149B24Data* data) {
    f32 increment = lbl_1_rodata_946C;

    data->value0 += increment;
    data->value_c += increment;
    fn_1_149C2C(context, data);
}
/* fzgx:end fn_1_149B24 */

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

/* fzgx:begin fn_1_149F04 */
void fn_1_149F04(void) {
    lbl_1_bss_8E428.unk_0 = (u32)((u8 *)&lbl_1_bss_3C30 + 0x1394);
    if (lbl_1_bss_8E51D == lbl_1_bss_8E524) {
        fn_1_144F40(3, 0);
    }
}
/* fzgx:end fn_1_149F04 */

/* fzgx:begin fn_1_149F5C */
void fn_1_149F5C(void) {
    lbl_1_bss_8E428.unk_0 = (u32)&lbl_1_bss_3C30 + 0xe;
    if (lbl_1_bss_8E51D != lbl_1_bss_8E524) {
        return;
    }
    fn_1_144F40(7, 0);
}
/* fzgx:end fn_1_149F5C */

/* fzgx:begin fn_1_149FB4 */
u8 fn_1_149FB4(s32 index) {
    u8 *entry = (u8 *)&lbl_1_bss_26314 + index * 0x1fc;

    if (lbl_1_bss_3C30.unk_5 == 2) {
        return fn_1_155F8C();
    }

    return entry[0x115];
}
/* fzgx:end fn_1_149FB4 */

/* fzgx:begin fn_1_14A000 */
// fn_1_14A000: empty in retail (single blr).
void fn_1_14A000(void) {
}
/* fzgx:end fn_1_14A000 */

/* fzgx:begin fn_1_14A004 */
// fn_1_14A004: empty in retail (single blr).
void fn_1_14A004(void) {
}
/* fzgx:end fn_1_14A004 */

/* fzgx:begin fn_1_14A008 */
// fn_1_14A008: empty in retail (single blr).
void fn_1_14A008(void) {
}
/* fzgx:end fn_1_14A008 */

/* fzgx:begin fn_1_14A00C */
void fn_1_14A00C(void) {
    lbl_1_bss_8E520 = 1;
    lbl_1_bss_8E524 = 0xff;
}
/* fzgx:end fn_1_14A00C */
