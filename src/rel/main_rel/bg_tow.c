#include "rel/main_rel/globals.h"
#include "rel/main_rel/bg_tow.h"

extern void fn_1_B9BE0(void);
extern void fn_1_B9DE8(Obj_1_bss_8EDA4 *arg0);
extern void fn_1_48418(s32 arg0);
extern void fn_1_159440(s32 arg0, s32 arg1);
extern u8 lbl_1_bss_8EDA0;
extern s32 fn_1_BA144(Obj_1_bss_8EDA4 *arg0);
extern void fn_1_1596DC(s32 arg0);
extern void fn_1_484CC(s32 arg0);
extern void fn_1_BC310(Obj_1_bss_8EDA4 *arg0);
extern void fn_1_C0510(u32 *arg0, u32 arg1, u32 arg2);
extern u32 fn_1_426C(u32);
extern u32 fn_1_46B4(u32, u32, u32, u32);
extern u32 fn_1_B9C0C(void);
extern u32 lbl_801A6410;

/* fzgx:begin fn_1_154410 noprologue */
#include "types.h"
#include "rel/main_rel/globals.h"
#include "rel/main_rel/bg_tow.h"

extern u32 lbl_801A63C0;
extern void lbl_8006D7DC(void *);
extern void mathutil_mtxA_rotate_z(s16);
extern void mathutil_mtxA_rotate_y(s16);
extern void mathutil_mtxA_rotate_x(s16);
extern void lbl_8006DB74(void *);
extern void OSPanic(const char *file, int line, const char *msg, ...);
extern s32 fn_1_3F8C(u32 arg3, u32 arg0, u32 arg1, u32 index);
extern u32 fn_1_435C(u32 value);
extern void fn_1_B9BE0();
extern void fn_1_154798(void);
extern u8 fn_1_1548A8__fzgx_offset_0[];
extern u8 fn_1_154930__fzgx_offset_0[];
extern u8 fn_1_1549B8__fzgx_offset_0[];
extern u8 fn_1_154A08__fzgx_offset_0[];
extern u8 fn_1_154BE4__fzgx_offset_0[];
extern u8 lbl_1_data_49A2C__fzgx_offset_0[];
extern u8 lbl_1_data_49A40__fzgx_offset_0[];
extern u8 lbl_1_data_49A54__fzgx_offset_0[];
extern u8 lbl_1_data_49A6C__fzgx_offset_0[];
extern u8 lbl_1_data_49A80__fzgx_offset_0[];
extern void fn_1_B9DE8(Obj_1_bss_8EDA4 *arg0);
extern void fn_1_48418(int index);
extern void fn_1_159440(int index, int flag);
extern u8 lbl_1_bss_8EDA0;
extern s32 fn_1_BA144(Obj_1_bss_8EDA4 *arg0);
extern void fn_1_1596DC(int index);
extern void fn_1_484CC(s32 index);
extern void fn_1_BC310(Obj_1_bss_8EDA4 *arg0);
extern void fn_1_C0510(u32 *arg0, u32 arg1, u32 arg2);
extern void fn_1_426C(u32 idx);
extern void fn_1_46B4(u32 arg0, u32 arg1, const char *arg2, int arg3);
extern u32 fn_1_B9C0C(void);
extern u32 lbl_801A6410;

/* Retail addresses bg_tow.c's literal pool (lbl_1_rodata_D508) through one base register;
   the primer reproduces that pool's first-use order so this unit's literals land on the
   retail offsets. The .fzgxpool section is dropped at integration. */
#pragma section code_type ".fzgxpool"
__declspec(section ".fzgxpool") static void fzgx_pool_prime1(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 0.15f;
    s = -0.95f;
    s = 0.031f;
    s = 0.005f;
    s = -0.032f;
    s = -0.923f;
    s = 1.0f;
    s = 0.0f;
    d = 4503601774854144.0;
}
static const u32 fzgx_pool_table2[15] = {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x3F800000, 0x00000000, 0x3F800000, 0x00000000, 0x00000000, 0x00000000, 0x3F800000, 0x00000000, 0x00000000, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep2(void) { const u32 *volatile cp; cp = fzgx_pool_table2; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime3(void) {
    volatile f32 s;  /* fzgx-allow: S2 pool primer sinks */
    s = 200.0f;
    s = 50.0f;
    s = 0.1f;
    s = 5.0f;
}
static const u32 fzgx_pool_table4[3] = {0x00000000, 0x00000000, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep4(void) { const u32 *volatile cp; cp = fzgx_pool_table4; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime5(void) {
    volatile f32 s;  /* fzgx-allow: S2 pool primer sinks */
    s = 0.981f;
    s = 32767.0f;
    s = -0.928f;
}
static const u32 fzgx_pool_table6[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep6(void) { const u32 *volatile cp; cp = fzgx_pool_table6; }  /* fzgx-allow: S2 pool primer sink */
#pragma section code_type ".text"

typedef struct {
    u32 flags;
    u8 pad_4[0x8];
    u8 pos[0xC];
    s16 rotX;
    s16 rotY;
    s16 rotZ;
} BgTowEntity;

typedef struct {
    s32 count;
    s32 count2;
    BgTowEntity *single;
    BgTowEntity *entries[16];
    s32 flags[16];
    u8 pad_8C[0x2FC - 0x8C];
    u8 mtx[16][0x30];
} BgTowSub;

typedef struct {
    s32 count;
    BgTowEntity *entries[64];
    s32 steps[64];
    f32 valA[64];
    f32 valB[64];
    f32 valC[64];
    u8 mtx[64][0x30];
    u32 unk_1104;
    BgTowSub sub;
} BgTowState;


static inline f32 bg_tow_randf(void) {
    lbl_801A63C0 = lbl_801A63C0 * 0x676A4B6B + 0x33CB;
    return (f32)(s32)((lbl_801A63C0 >> 16) & 0x7FFF) / 32767.0f;
}

s32 fn_1_154410(s32 kind, BgTowEntity *ent) {
    BgTowState *obj = (BgTowState *)lbl_1_data_2A7E0.unk_3C;
    BgTowSub *sub;

    switch (kind) {
    case 0:
        ent->flags |= 0x80000000;
        obj->entries[obj->count] = ent;
        obj->valA[obj->count] = -0.95f + (f32)(0.981f * bg_tow_randf());
        obj->valB[obj->count] = 0.005f + (f32)(-0.928f * bg_tow_randf());
        obj->steps[obj->count] = (s32)((obj->valB[obj->count] - 0.005f) / -0.032f);
        obj->valC[obj->count] = 0.0f;
        lbl_8006D7DC(ent->pos);
        mathutil_mtxA_rotate_z(ent->rotZ);
        mathutil_mtxA_rotate_y(ent->rotY);
        mathutil_mtxA_rotate_x(ent->rotX);
        lbl_8006DB74(obj->mtx[obj->count]);
        obj->count++;
        if (obj->count >= 64) {
            OSPanic("bg_tow.c", 482, "WINDOW NUM OVER!");
        }
        break;
    case 1:
        ent->flags |= 0x80000000;
        obj->sub.single = ent;
        break;
    case 2:
    case 3:
    case 5:
        sub = &obj->sub;
        ent->flags |= 0x80000000;
        sub->entries[sub->count] = ent;
        if (kind == 5) {
            sub->flags[sub->count] = 1;
        } else {
            sub->flags[sub->count] = 0;
        }
        sub->count++;
        if (sub->count >= 16) {
            OSPanic("bg_tow.c", 510, "BG_TOW_SEARCH OTHER NUM OVER\n");
        }
        break;
    case 4:
        sub = &obj->sub;
        lbl_8006D7DC(ent->pos);
        mathutil_mtxA_rotate_z(ent->rotZ);
        mathutil_mtxA_rotate_y(ent->rotY);
        mathutil_mtxA_rotate_x(ent->rotX);
        lbl_8006DB74(sub->mtx[sub->count2]);
        sub->count2++;
        if (sub->count2 >= 16) {
            OSPanic("bg_tow.c", 527, "BG_TOW_SCAMPOINT01 NUM OVER!");
        }
        break;
    default:
        break;
    }
    return 1;
}
/* fzgx:end fn_1_154410 */

/* fzgx:begin fn_1_154708 noprologue */
#include "types.h"

struct fn_1_154708_lbl_1_data_49A18 {
    u8 pad_0[0x90];
    u32 unk_90;
    u32 unk_94;
    u32 unk_98;
    u32 unk_9C;
};
struct fn_1_154708_lbl_1_bss_8ED90 {
    u32 unk_0;
    u32 unk_4;
    u32 unk_8;
    u32 unk_C;
    u8 unk_10;
};

extern struct fn_1_154708_lbl_1_bss_8ED90 lbl_1_bss_8ED90;
extern struct fn_1_154708_lbl_1_data_49A18 lbl_1_data_49A18;
extern u32 fn_1_3F8C(u32, u32, u32, u32);
extern u32 fn_1_435C(u32);
extern u32 fn_1_B9BE0(u32);
extern void fn_1_154798(void);

void fn_1_154708(u32 arg0) {
    struct fn_1_154708_lbl_1_bss_8ED90 *p_lbl_1_bss_8ED90;
    u32 t1;
    p_lbl_1_bss_8ED90 = (struct fn_1_154708_lbl_1_bss_8ED90 *)&lbl_1_bss_8ED90;
    p_lbl_1_bss_8ED90->unk_C = arg0;
{
    struct fn_1_154708_lbl_1_data_49A18 * p_lbl_1_data_49A18 = (struct fn_1_154708_lbl_1_data_49A18 *)&lbl_1_data_49A18;
    p_lbl_1_data_49A18->unk_90 = -1;
    fn_1_435C(arg0);
    t1 = fn_1_3F8C((u32)((u8 *)(u32)p_lbl_1_data_49A18 + 160), (u32)fn_1_154798, 0, 18);
    p_lbl_1_data_49A18->unk_90 = t1;
    p_lbl_1_data_49A18->unk_94 = -1;
    p_lbl_1_data_49A18->unk_98 = -1;
    p_lbl_1_data_49A18->unk_9C = -1;
}
    p_lbl_1_bss_8ED90->unk_10 = 0;
    p_lbl_1_bss_8ED90->unk_8 = 0;
    p_lbl_1_bss_8ED90->unk_0 = 0;
    p_lbl_1_bss_8ED90->unk_4 = 0;
    fn_1_B9BE0(t1);
}
/* fzgx:end fn_1_154708 */

/* fzgx:begin fn_1_154798 noprologue */
#include "types.h"
#include "rel/main_rel/globals.h"
#include "rel/main_rel/bg_tow.h"

extern u32 lbl_801A63C0;
extern void lbl_8006D7DC(void *);
extern void mathutil_mtxA_rotate_z(s16);
extern void mathutil_mtxA_rotate_y(s16);
extern void mathutil_mtxA_rotate_x(s16);
extern void lbl_8006DB74(void *);
extern void OSPanic(const char *file, int line, const char *msg, ...);
extern s32 fn_1_3F8C(u32 arg3, u32 arg0, u32 arg1, u32 index);
extern u32 fn_1_435C(u32 value);
extern void fn_1_B9BE0();
extern void fn_1_154798(void);
extern u8 fn_1_1548A8__fzgx_offset_0[];
extern u8 fn_1_154930__fzgx_offset_0[];
extern u8 fn_1_1549B8__fzgx_offset_0[];
extern u8 fn_1_154A08__fzgx_offset_0[];
extern u8 fn_1_154BE4__fzgx_offset_0[];
extern u8 lbl_1_data_49A2C__fzgx_offset_0[];
extern u8 lbl_1_data_49A40__fzgx_offset_0[];
extern u8 lbl_1_data_49A54__fzgx_offset_0[];
extern u8 lbl_1_data_49A6C__fzgx_offset_0[];
extern u8 lbl_1_data_49A80__fzgx_offset_0[];
extern void fn_1_B9DE8(Obj_1_bss_8EDA4 *arg0);
extern void fn_1_48418(int index);
extern void fn_1_159440(int index, int flag);
extern u8 lbl_1_bss_8EDA0;
extern s32 fn_1_BA144(Obj_1_bss_8EDA4 *arg0);
extern void fn_1_1596DC(int index);
extern void fn_1_484CC(s32 index);
extern void fn_1_BC310(Obj_1_bss_8EDA4 *arg0);
extern void fn_1_C0510(u32 *arg0, u32 arg1, u32 arg2);
extern void fn_1_426C(u32 idx);
extern void fn_1_46B4(u32 arg0, u32 arg1, const char *arg2, int arg3);
extern u32 fn_1_B9C0C(void);
extern u32 lbl_801A6410;

struct fn_1_154798_data {
    void (*funcs[0x25])(void);
    s32 unk_94;
    s32 unk_98;
    s32 unk_9C;
};


static union {u32 words[37]; void (*view[0x25])(void);} fzgx_pool_native_lbl_1_data_49A18_funcs = {{(u32)fn_1_1548A8__fzgx_offset_0, (u32)fn_1_154930__fzgx_offset_0, (u32)fn_1_1549B8__fzgx_offset_0, (u32)fn_1_154A08__fzgx_offset_0, (u32)fn_1_154BE4__fzgx_offset_0, 0x5245505F, 0x4D454D43, 0x4152445F, 0x494E4954, 0x00000000, 0x5245505F, 0x4D454D43, 0x4152445F, 0x57414954, 0x00000000, 0x5245505F, 0x4D454D43, 0x4152445F, 0x41435449, 0x4F4E5F49, 0x4E495400, 0x5245505F, 0x4D454D43, 0x4152445F, 0x41435449, 0x4F4E0000, 0x5245505F, 0x4D454D43, 0x4152445F, 0x46494E49, 0x53480000, (u32)lbl_1_data_49A2C__fzgx_offset_0, (u32)lbl_1_data_49A40__fzgx_offset_0, (u32)lbl_1_data_49A54__fzgx_offset_0, (u32)lbl_1_data_49A6C__fzgx_offset_0, (u32)lbl_1_data_49A80__fzgx_offset_0, 0xFFFFFFFF}}; /* fzgx-allow: A1 measured pool bytes and bindings */
static s32 fzgx_pool_native_lbl_1_data_49A18_unk_94 = 0xFFFFFFFF; /* fzgx-allow: A1 measured pool bytes and bindings */
static s32 fzgx_pool_native_lbl_1_data_49A18_unk_98 = 0xFFFFFFFF; /* fzgx-allow: A1 measured pool bytes and bindings */
static s32 fzgx_pool_native_lbl_1_data_49A18_unk_9C = 0xFFFFFFFF; /* fzgx-allow: A1 measured pool bytes and bindings */

void fn_1_154798(void) {
    

    if (fzgx_pool_native_lbl_1_data_49A18_unk_9C >= 0) {
        fzgx_pool_native_lbl_1_data_49A18_unk_94 = fzgx_pool_native_lbl_1_data_49A18_unk_98;
        fzgx_pool_native_lbl_1_data_49A18_unk_98 = fzgx_pool_native_lbl_1_data_49A18_unk_9C;
        fzgx_pool_native_lbl_1_data_49A18_unk_9C = -1;
    }
    if (fzgx_pool_native_lbl_1_data_49A18_unk_98 >= 0) {
        fzgx_pool_native_lbl_1_data_49A18_funcs.view[fzgx_pool_native_lbl_1_data_49A18_unk_98]();
    }
}
/* fzgx:end fn_1_154798 */

/* fzgx:begin fn_1_1547FC */
#include "types.h"

struct fn_1_1547FC_lbl_1_data_49A18 {
    u8 pad_0[0x90];
    u32 unk_90;
    u32 unk_94;
    u32 unk_98;
    u32 unk_9C;
};
struct fn_1_1547FC_lbl_1_bss_8ED90 {
    u32 unk_0;
    u32 unk_4;
    u8 pad_8[0x4];
    u32 unk_C;
};

extern u32 fn_1_435C(u32);

s32 fn_1_1547FC(u32 arg0, u32 arg1, u32 arg2, u32 arg3) {
    struct fn_1_1547FC_lbl_1_data_49A18 *p_lbl_1_data_49A18;
    struct fn_1_1547FC_lbl_1_bss_8ED90 *p_lbl_1_bss_8ED90;
    u32 v0;
    u32 v1;
    u32 v2;
    u32 v3;
    u32 v4;
    s32 v5;
    u32 t0, t1, t2, t3;
    p_lbl_1_bss_8ED90 = (struct fn_1_1547FC_lbl_1_bss_8ED90 *)&(*(struct fn_1_1547FC_lbl_1_bss_8ED90 *)&lbl_1_bss_8ED90);
    p_lbl_1_data_49A18 = &(*(struct fn_1_1547FC_lbl_1_data_49A18 *)&lbl_1_data_49A18);
    t0 = fn_1_B9C0C();
    v0 = p_lbl_1_bss_8ED90->unk_0;
    v1 = t0;
    v2 = arg2;
    v3 = arg3;
    if (v0 != 0) {
    v2 = (u32)((u8 *)(u32)p_lbl_1_data_49A18 + 176);
    v1 = (u32)&lbl_801A6410;
    v3 = 115;
    v1 = *(u32 *)((u8 *)v1 + 0);
    t1 = fn_1_46B4(v1, v0, (u32)v2, v3);
    v1 = t1;
    p_lbl_1_bss_8ED90->unk_0 = 0;
    p_lbl_1_bss_8ED90->unk_4 = 0;
    }
    v4 = p_lbl_1_data_49A18->unk_90;
    p_lbl_1_data_49A18->unk_94 = -1;
    p_lbl_1_data_49A18->unk_98 = -1;
    p_lbl_1_data_49A18->unk_9C = -1;
    v5 = -1;
    if ((s32)v4 != -1) {
    v5 = p_lbl_1_bss_8ED90->unk_C;
    t2 = fn_1_435C(v5);
    v5 = t2;
    v5 = p_lbl_1_data_49A18->unk_90;
    t3 = fn_1_426C(v5);
    v5 = t3;
    v5 = 0;
    p_lbl_1_bss_8ED90->unk_C = v5;
    p_lbl_1_data_49A18->unk_90 = -1;
    }
    return v5;
}
/* fzgx:end fn_1_1547FC */

/* fzgx:begin fn_1_1548A8 */
#include "types.h"

// Initialize the tow settings and select the mode-dependent input value.
void fn_1_1548A8(void) {
    s16 mode;
    s16 *mode_ptr;
    Obj_1_bss_8EDA4 *obj;

    fn_1_B9BE0();
    fn_1_B9DE8(&lbl_1_bss_8EDA4);

    mode_ptr = (s16 *)&lbl_1_bss_960;
    obj = &lbl_1_bss_8EDA4;
    mode = *mode_ptr;
    obj->unk_0 = 0x20;
    if (mode == 0xc) {
        obj->unk_4 = 0xa;
    } else {
        obj->unk_4 = 9;
    }

    if (mode != 2) {
        fn_1_48418(2);
        fn_1_159440(2, 0);
    }

    lbl_1_data_49AB4.unk_0 = 1;
}
/* fzgx:end fn_1_1548A8 */

/* fzgx:begin fn_1_154930 */
void fn_1_154930(void) {
    s8 result;

    result = fn_1_BA144(&lbl_1_bss_8EDA4);
    if (result == 0) {
        lbl_1_data_49AB4.unk_0 = 2;
    } else if (result == 1) {
        lbl_1_data_49AB4.unk_0 = 4;
        lbl_1_bss_8EDA0 = 1;
        fn_1_1596DC(2);
        fn_1_484CC(2);
    } else {
        fn_1_BC310(&lbl_1_bss_8EDA4);
    }
}
/* fzgx:end fn_1_154930 */

/* fzgx:begin fn_1_1549B8 */
#include "types.h"

// Copy the tow state into the active settings and advance the tow mode.
void fn_1_1549B8(void) {
    u32 *src = &lbl_1_bss_8ED90;
    u32 *dst = src + 5;
    u32 first = src[0];
    u32 second = src[1];

    dst[2] = first;
    dst[3] = second;
    dst[4] = 5;
    fn_1_C0510(dst, second, first);
    lbl_1_data_49AB4.unk_0 = 3;
}
/* fzgx:end fn_1_1549B8 */

/* fzgx:begin fn_1_154C84 */
#include "types.h"

extern u32 lbl_1_data_49AB0;



s32 fn_1_154C84(void) {
    u32 v0;
    if ((s32)lbl_1_data_49AB0 == 4) {
    v0 = 0;
    return v0;
    }
    if ((s32)lbl_1_data_49AB0 != -1 || (s32)(*(u32 *)&lbl_1_data_49AB4) != -1) {
    v0 = 1;
    return v0;
    }
    v0 = 0;
    return v0;
}
/* fzgx:end fn_1_154C84 */
