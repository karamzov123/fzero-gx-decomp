/* RESEARCH ONLY: fn_1_F75D8
 * Raw objdiff 95.3%; adjusted instruction score 77.8%; 37 of 167 remaining aligned rows. Not an exact match.
 * Excluded from the canonical build. Do not mark matching or submit without a fresh object check and linked checksum gate.
 */
#include "types.h"
#include "psvec.h"
#pragma section code_type ".fzgxpool"
__declspec(section ".fzgxpool") static void fzgx_pool_prime1(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = -100000.0f;
    s = -1.0f;
    s = 255.0f;
    s = 0.0f;
    d = 4503599627370496.0;
}
#pragma section code_type ".text"
typedef struct { f32 x,y,z; } ClosureLightVec;
typedef struct { u32 words[16]; } ClosureLightObj;
typedef union { u32 rgba; struct { u8 r,g,b,a; } c; } ClosureLightColor;
typedef struct { ClosureLightVec direction; ClosureLightVec position; u32 ambient; u32 color; s8 distance_type; u8 pad21[3]; f32 distance,brightness; s8 spot_type; u8 pad2d[3]; f32 cutoff; } ClosureLightEntry;
extern f32 lbl_1_rodata_6E20[6];
typedef struct { s32 ambient_enabled[4]; u32 ambient[4]; s32 light_enabled[4]; u32 color[4]; u32 reserved[4]; } ClosureLightOverrides;
extern ClosureLightOverrides lbl_1_bss_7F050;
extern s32 fn_1_5910(void);
extern void fn_1_7BB80(void *,s32);
extern void fn_1_7BCCC(void *);
extern u32 fn_1_7BD6C(s32);
extern void lbl_8006DAEC(void);
extern void lbl_8006D758(void);
extern void lbl_8006DCA4(void);
extern f32 lbl_8006D668(void *);
extern void lbl_8006D5F0(f32,void *,void *);
extern void lbl_8006E1B0(void *,void *);
extern void lbl_8006E1C0(void *,void *);
extern void fn_800356AC(void *,void *);
extern void fn_80035680(void *,f32,f32,f32);
extern void fn_80035690(void *,f32,f32,f32);
extern void fn_80035420(void *,s32,f32);
extern void GXInitLightDistAttn(void *,s32,f32,f32);
extern void fn_80074CF4(f32,f32,f32);
extern void lbl_8006DB30(void);
#pragma fp_contract off
#pragma opt_propagation off
void fn_1_F75D8(ClosureLightEntry **entries,s32 override,s32 mode) {
    ClosureLightObj light;
    ClosureLightVec direction;
    ClosureLightVec position;
    ClosureLightColor ambient;
    u32 override_color;
    u32 entry_color;
    s32 index;
    s32 i;
    s32 lightnum = 1;
    f32 *rodata = lbl_1_rodata_6E20;
    ClosureLightOverrides *bss = &lbl_1_bss_7F050;
    ClosureLightEntry **cursor;
    lbl_8006DAEC();
    if (override) index = fn_1_5910(); else index = 0;
    if (mode) lbl_8006D758(); else lbl_8006DCA4();
    cursor = entries;
    for(i=0;i<32;i++,cursor++) {
        ClosureLightEntry *entry = *cursor;
        if (!entry) break;
        if (i==0) {
            if (override && bss->ambient_enabled[index]) ambient.rgba = bss->ambient[index];
            else ambient.rgba = entry->ambient;
        }
        position = entry->position;
        lbl_8006D668(&position);
        if (!entry->distance_type && !entry->spot_type) {
            lbl_8006D5F0((-100000.0f),&position,&direction);
            lbl_8006E1B0(&direction,&direction);
        } else lbl_8006E1B0(entry,&direction);
        lbl_8006E1C0(&position,&position);
        if (override && bss->light_enabled[index]) {
            override_color = bss->color[index];
            fn_800356AC(&light,&override_color);
        } else {
            entry_color=entry->color;
            fn_800356AC(&light,&entry_color);
        }
        fn_80035680(&light,direction.x,direction.y,direction.z);
        fn_80035690(&light,position.x,position.y,position.z);
        fn_80035420(&light,entry->spot_type,entry->cutoff);
        GXInitLightDistAttn(&light,entry->distance_type,entry->distance,entry->brightness);
        fn_1_7BB80(&light,lightnum++);
        if (i==0) {
            psvec_scale(&position,(-1.0f),&position);
            fn_1_7BCCC(&position);
        }
    }
    fn_1_7BD6C(1);
    fn_80074CF4((f32)(u32)ambient.c.r / (255.0f),(f32)(u32)ambient.c.g / (255.0f),(f32)(u32)ambient.c.b / (255.0f));
    lbl_8006DB30();
}
#pragma opt_propagation reset
#pragma fp_contract reset
