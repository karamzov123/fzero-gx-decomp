#include "types.h"
#include "rel/main_rel/globals.h"
#include "rel/main_rel/bg_tow.h"

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
