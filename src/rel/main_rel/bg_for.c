#include "types.h"
#include "rel/main_rel/globals.h"
#include "rel/main_rel/bg_for.h"
extern void OSPanic(const char *, int, const char *, ...);
extern struct fn_1_DCE60_lbl_1_rodata_6750 lbl_1_rodata_6750;
extern void lbl_8006DAEC(void);
extern void lbl_8006DD14(void *, void *);
extern void fn_1_A7024(f32, f32, f32, f32);
extern void fn_8006F1F0(void *, void *, void *);
extern void lbl_8006DB74(void *);
extern void lbl_8006DCDC(void);
extern void lbl_8006DB30(void);
extern void fn_1_E1408(void *, void *);

/* fzgx:begin fn_1_DCBF4 */
#pragma opt_dead_assignments off
s32 fn_1_DCBF4(s32 value, s32 data) {
    Obj_1_data_2A7E0_At3C *obj;
    Obj_1_data_2A7E0_At3C *entry;
    u32 n;

    obj = lbl_1_data_2A7E0.unk_3C;
    switch (value) {
    case 0:
        obj->unk_1588 = data;
        break;
    case 1:
        entry = (Obj_1_data_2A7E0_At3C *)((u8 *)obj + obj->unk_0 * 0xAC);
        entry->unk_C |= 0x40000000;
        entry = (Obj_1_data_2A7E0_At3C *)((u8 *)obj + obj->unk_0 * 0xAC);
        entry->unk_C |= 0x10000000;
        n = obj->unk_0;
        entry = (Obj_1_data_2A7E0_At3C *)((u8 *)obj + n * 0xAC);
        entry->unk_4 = data;
        obj->unk_0 = obj->unk_0 + 1;
        if ((s32)obj->unk_0 >= 0x20) {
            OSPanic((const char *)lbl_1_data_3DC78, 0x21D, (const char *)&lbl_1_data_3DC84);
        }
        break;
    case 2:
        entry = (Obj_1_data_2A7E0_At3C *)((u8 *)obj + obj->unk_0 * 0xAC);
        entry->unk_C |= 0x40000000;
        entry = (Obj_1_data_2A7E0_At3C *)((u8 *)obj + obj->unk_0 * 0xAC);
        entry->unk_C |= 0x20000000;
        n = obj->unk_0;
        entry = (Obj_1_data_2A7E0_At3C *)((u8 *)obj + n * 0xAC);
        entry->unk_4 = data;
        obj->unk_0 = obj->unk_0 + 1;
        if ((s32)obj->unk_0 >= 0x20) {
            OSPanic((const char *)lbl_1_data_3DC78, 0x224, (const char *)&lbl_1_data_3DC84);
        }
        break;
    case 3:
        entry = (Obj_1_data_2A7E0_At3C *)((u8 *)obj + obj->unk_0 * 0xAC);
        entry->unk_C |= 0x40000000;
        entry = (Obj_1_data_2A7E0_At3C *)((u8 *)obj + obj->unk_0 * 0xAC);
        entry->unk_C |= 0x10000000;
        entry = (Obj_1_data_2A7E0_At3C *)((u8 *)obj + obj->unk_0 * 0xAC);
        entry->unk_C |= 0x08000000;
        n = obj->unk_0;
        entry = (Obj_1_data_2A7E0_At3C *)((u8 *)obj + n * 0xAC);
        entry->unk_4 = data;
        obj->unk_0 = obj->unk_0 + 1;
        if ((s32)obj->unk_0 >= 0x20) {
            OSPanic((const char *)lbl_1_data_3DC78, 0x22C, (const char *)&lbl_1_data_3DC84);
        }
        break;
    case 4:
        entry = (Obj_1_data_2A7E0_At3C *)((u8 *)obj + obj->unk_0 * 0xAC);
        entry->unk_C |= 0x40000000;
        entry = (Obj_1_data_2A7E0_At3C *)((u8 *)obj + obj->unk_0 * 0xAC);
        entry->unk_C |= 0x20000000;
        entry = (Obj_1_data_2A7E0_At3C *)((u8 *)obj + obj->unk_0 * 0xAC);
        entry->unk_C |= 0x08000000;
        n = obj->unk_0;
        entry = (Obj_1_data_2A7E0_At3C *)((u8 *)obj + n * 0xAC);
        entry->unk_4 = data;
        obj->unk_0 = obj->unk_0 + 1;
        if ((s32)obj->unk_0 >= 0x20) {
            OSPanic((const char *)lbl_1_data_3DC78, 0x234, (const char *)&lbl_1_data_3DC84);
        }
        break;
    }
    return 1;
}
#pragma opt_dead_assignments reset
/* fzgx:end fn_1_DCBF4 */

/* fzgx:begin fn_1_DCE60 */
struct fn_1_DCE60_Arg0 {
    u32 unk_0;
    u32 unk_4;
    u32 unk_8;
    u32 unk_C;
    u32 unk_10;
    u32 unk_14;
    u32 unk_18;
    u32 unk_1C;
    u32 unk_20;
    u32 unk_24;
    u32 unk_28;
    u32 unk_2C;
    f32 unk_30;
    f32 unk_34;
    f32 unk_38;
    f32 unk_3C;
};
struct fn_1_DCE60_Copy24 { u32 a[6]; };
struct fn_1_DCE60_Copy12 { u32 a[3]; };
struct fn_1_DCE60_lbl_1_rodata_6750 {
    u32 unk_0;
    u32 unk_4;
    u32 unk_8;
    u32 unk_C;
    u32 unk_10;
    u32 unk_14;
    u32 unk_18;
    u32 unk_1C;
    u32 unk_20;
    f32 unk_24;
    f32 unk_28;
    f32 unk_2C;
};

#pragma opt_propagation off
f32 fn_1_DCE60(struct fn_1_DCE60_Arg0 *arg0, f32 arg1) {
    u32 v0;
    u32 v4;
    f32 v3;
    f32 v2;
    f32 v1;

    v4 = lbl_1_rodata_6750.unk_0;
    v0 = lbl_1_rodata_6750.unk_4;
    v1 = lbl_1_rodata_6750.unk_24;
    arg0->unk_0 = v4;
    v2 = lbl_1_rodata_6750.unk_28;
    arg0->unk_4 = v0;
    v3 = lbl_1_rodata_6750.unk_2C;
    arg0->unk_8 = lbl_1_rodata_6750.unk_8;
    *(struct fn_1_DCE60_Copy12 *)((u8 *)(u32)arg0 + 24) = *(struct fn_1_DCE60_Copy12 *)((u8 *)&lbl_1_rodata_6750 + 12);
    *(struct fn_1_DCE60_Copy12 *)((u8 *)(u32)arg0 + 36) = *(struct fn_1_DCE60_Copy12 *)((u8 *)&lbl_1_rodata_6750 + 24);
    arg0->unk_30 = v1;
    arg0->unk_34 = arg1;
    arg0->unk_38 = v2;
    arg0->unk_3C = v3;
    return arg1;
}
#pragma opt_propagation reset
/* fzgx:end fn_1_DCE60 */

/* fzgx:begin fn_1_DCED0 */
typedef struct fn_1_DCED0_Vec3 {
    u32 x;
    u32 y;
    u32 z;
} fn_1_DCED0_Vec3;

typedef struct BgForObject {
    fn_1_DCED0_Vec3 value00;
    fn_1_DCED0_Vec3 value0c;
    u8 unk18[0xc];
    u32 value24;
    u8 unk28[0x8];
    f32 value30;
    f32 value34;
    f32 value38;
    f32 value3c;
    u8 unk40[0x30];
    u8 unk70[1];
} BgForObject;

void fn_1_DCED0(BgForObject *object) {
    lbl_8006DAEC();
    object->value0c = object->value00;
    lbl_8006DD14(&object->unk70, &object->unk40);
    fn_1_A7024(object->value30, object->value34, object->value38, object->value3c);
    fn_8006F1F0(object, &object->value24, &object->unk18);
    lbl_8006DB74(&object->unk70);
    lbl_8006DCDC();
    lbl_8006DB30();
}
/* fzgx:end fn_1_DCED0 */

/* fzgx:begin fn_1_DCF54 */
typedef struct fn_1_DCF54_Vec3 {
    u32 x;
    u32 y;
    u32 z;
} fn_1_DCF54_Vec3;

typedef struct State {
    fn_1_DCF54_Vec3 a;
    u8 pad[12];
    fn_1_DCF54_Vec3 b;
    fn_1_DCF54_Vec3 c;
} State;

extern State lbl_1_bss_7ADE8;

void fn_1_DCF54(fn_1_DCF54_Vec3 *a, fn_1_DCF54_Vec3 *b, fn_1_DCF54_Vec3 *c) {
    lbl_1_bss_7ADE8.a = *a;
    lbl_1_bss_7ADE8.b = *b;
    lbl_1_bss_7ADE8.c = *c;
}
/* fzgx:end fn_1_DCF54 */

/* fzgx:begin fn_1_DCFA4 noprologue */
#include "types.h"
#include "rel/main_rel/globals.h"
#include "rel/main_rel/bg_for.h"
#include "types.h"
#include "rel/main_rel/globals.h"
#include "rel/main_rel/bg_for.h"
#include "psvec.h"

/* begin game/main_rel/bg_for_types.h (deltawave784/fzgx, CC0) */
#ifndef GAME_MAIN_REL_BG_FOR_TYPES_H
#define GAME_MAIN_REL_BG_FOR_TYPES_H

// Types (and the externs that name them) of bg_for.c, hoisted out of its prologue so that
// a block can compile standalone and under the prologue. Hand-owned (librarian).


typedef struct fn_1_DCF54_Vec3 {
    u32 x;
    u32 y;
    u32 z;
} fn_1_DCF54_Vec3;

typedef struct State {
    fn_1_DCF54_Vec3 a;
    u8 pad[12];
    fn_1_DCF54_Vec3 b;
    fn_1_DCF54_Vec3 c;
} State;

struct fn_1_DCE60_lbl_1_rodata_6750 {
    u32 unk_0;
    u32 unk_4;
    u32 unk_8;
    u32 unk_C;
    u32 unk_10;
    u32 unk_14;
    u32 unk_18;
    u32 unk_1C;
    u32 unk_20;
    f32 unk_24;
    f32 unk_28;
    f32 unk_2C;
};

extern State lbl_1_bss_7ADE8;
extern struct fn_1_DCE60_lbl_1_rodata_6750 lbl_1_rodata_6750;

#endif  // GAME_MAIN_REL_BG_FOR_TYPES_H

/* end game/main_rel/bg_for_types.h */

#pragma fp_contract on

extern u8 lbl_1_rodata_6780[];
extern void fn_80008BA8(void *, const void *, u32);
extern void fn_1_57714(u8);
extern void lbl_8006D758(void);
extern void lbl_8006E1B0(void *, void *);
extern void lbl_8006DCA4(void);
extern void fn_80072558(void);
extern void fn_1_57810(u32, void *, void *);
extern void lbl_8006D784(void *);
extern void lbl_8006DBAC(void *);
extern void lbl_8006DFE8(void *);
extern void fn_1_DDF80(void *, void *, void *, void *, f32, f32);
extern void lbl_8006DAEC(void);
extern void lbl_8006DB30(void);
extern void fn_1_56298(f32, f32, f32, f32);
extern f32 lbl_8006D0B4(f32);
extern void fn_8006EE70(const void *, s16 *);
extern void mathutil_mtxA_rotate_z(s32);
extern void mathutil_mtxA_rotate_y(s32);
extern void mathutil_mtxA_rotate_x(s32);
extern void lbl_8006E15C(f32, f32, f32);
extern void fn_1_556B8(void *);
extern f64 fabs(f64);

typedef struct DCFA4Vec { f32 x,y,z; } DCFA4Vec;
typedef struct DCFA4Mtx { f32 m[3][4]; } DCFA4Mtx;
static inline void matrix_translation(DCFA4Mtx *m) {
    f32 x, y, z;
    u32 locked_cache_base = 0xE0000000;
    x = *(volatile f32 *)(locked_cache_base + 0xC); /* volatile: locked-cache current matrix */
    y = *(volatile f32 *)(locked_cache_base + 0x1C); /* volatile: locked-cache current matrix */
    z = *(volatile f32 *)(locked_cache_base + 0x2C); /* volatile: locked-cache current matrix */
    m->m[0][3] = x;
    m->m[1][3] = y;
    m->m[2][3] = z;
}
static inline void draw_color(u8 *p, u32 first) {
    f32 a, b;
    if (first) {
        a = *(f32 *)(p+0x28);
        b = *(f32 *)(p+0x20);
        fn_1_56298(a,b,b,a);
    } else {
        a = *(f32 *)(p+0x20);
        b = *(f32 *)(p+0x28);
        fn_1_56298(a,b,a,b);
    }
}

static inline void draw_vec(DCFA4Vec *v, s16 *angles, u8 *pool) {
    f32 x;
    f32 y;
    f32 len;
    f32 z;
    f32 scale;
    f32 max;
    f32 min;
    x = v->x;
    y = v->y;
    len = x*x;
    z = v->z;
    len = __fmadds(y, y, len);
    len = __fmadds(z, z, len);
    len = lbl_8006D0B4(len);
    if (!(__fabs(len) < *(f64 *)(pool + 0x18))) {
        fn_8006EE70(v, angles);
        mathutil_mtxA_rotate_z(angles[2]);
        mathutil_mtxA_rotate_y(angles[1]);
        mathutil_mtxA_rotate_x(angles[0]);
        max = *(f32 *)(pool+0x24);
        min = *(f32 *)(pool+0x20);
        scale = max * len;
        scale = scale < min ? min : scale > max ? max : scale;
        lbl_8006E15C(*(f32 *)(pool+0x28), *(f32 *)(pool+0x28), scale);
        fn_80072558();
        fn_1_556B8(*(void **)(lbl_1_bss_38454->unk_8 + 0x38));
    }
}

void fn_1_DCFA4(u32 arg0, f32 arg1) {
    u8 *p_lbl_1_rodata_6780;
    u32 v1;
    f32 v2;
    u32 v3;
    u32 v4;
    u64 flags;
    u32 v0;
    DCFA4Mtx m1;
    DCFA4Mtx m2;
    DCFA4Vec screen2;
    DCFA4Vec screen1;
    DCFA4Vec loc_74;
    DCFA4Vec delta1;
    DCFA4Vec delta2;
    DCFA4Vec out2;
    DCFA4Vec out1;
    DCFA4Vec out4;
    DCFA4Vec out3;
    s16 angles1[3];
    s16 angles2[3];
    s16 angles3[3];
    s16 angles4[3];
    u32 color;
    p_lbl_1_rodata_6780 = (u8 *)&lbl_1_rodata_6780;
    v2 = arg1;
    if (*(u32 *)(arg0+324) != 0) {
        flags = *(u64 *)((u8 *)arg0 + 312);
        if ((flags & 0x20000000ULL) != 0) {
            fn_80008BA8(&loc_74, (void *)(*(u32 *)(arg0+324) + 84), 12);
        } else if ((flags & 0x80000000ULL) != 0) {
            fn_80008BA8(&loc_74, (void *)(*(u32 *)(arg0+324) + 124), 12);
        } else {
            return;
        }
        fn_1_57714(20);
        lbl_8006D758();
        lbl_8006E1B0((void *)(arg0+0x54), &screen1);
        lbl_8006E1B0(&loc_74, &screen2);
        lbl_8006DCA4();
        fn_80072558();
        color = *(u32 *)(p_lbl_1_rodata_6780+0x2c);
        fn_1_57810(2, &screen1, &color);
        psvec_sub(&loc_74, (void *)(arg0+0x54), &delta1);
        lbl_8006D784(&m1);
        lbl_8006DBAC((void *)(arg0+0xc4));
        matrix_translation(&m1);
        lbl_8006DFE8(&m1);
        fn_1_DDF80((void *)(arg0+0x44), &delta1, &out1, &out2,
                   *(f32 *)(arg0+0x50), *(f32 *)(arg0+0x50));
        lbl_8006DAEC();
        draw_color(p_lbl_1_rodata_6780, 1);
        draw_vec(&out1, angles1, p_lbl_1_rodata_6780);
        lbl_8006DB30();
        draw_color(p_lbl_1_rodata_6780, 0);
        draw_vec(&out2, angles2, p_lbl_1_rodata_6780);
        fn_1_56298(*(f32 *)(p_lbl_1_rodata_6780+0x20), *(f32 *)(p_lbl_1_rodata_6780+0x20), *(f32 *)(p_lbl_1_rodata_6780+0x20), *(f32 *)(p_lbl_1_rodata_6780+0x20));
        if ((*(u64 *)((u8 *)arg0+312) & 0x80000000ULL) != 0) {
            v0 = *(u32 *)(arg0+0x144);
            psvec_sub(&loc_74, (void *)(arg0+0x54), &delta2);
            lbl_8006D784(&m2);
            lbl_8006DBAC((void *)(v0+0x14c));
            matrix_translation(&m2);
            lbl_8006DFE8(&m2);
            fn_1_DDF80((void *)(v0+0x94), &delta2, &out3, &out4, *(f32 *)(v0+0x17c), *(f32 *)(v0+0x17c));
            lbl_8006DAEC();
            draw_color(p_lbl_1_rodata_6780, 1);
            draw_vec(&out3, angles3, p_lbl_1_rodata_6780);
            lbl_8006DB30();
            draw_color(p_lbl_1_rodata_6780, 0);
            draw_vec(&out4, angles4, p_lbl_1_rodata_6780);
            fn_1_56298(*(f32 *)(p_lbl_1_rodata_6780+0x20), *(f32 *)(p_lbl_1_rodata_6780+0x20), *(f32 *)(p_lbl_1_rodata_6780+0x20), *(f32 *)(p_lbl_1_rodata_6780+0x20));
        }
    }
}
/* fzgx:end fn_1_DCFA4 */

/* fzgx:begin fn_1_DD4DC noprologue */
#include "types.h"
#include "rel/main_rel/globals.h"
#include "rel/main_rel/bg_for.h"
#include "types.h"
#include "rel/main_rel/bg_for.h"

extern void OSPanic(const char *, int, const char *, ...);
extern struct fn_1_DCE60_lbl_1_rodata_6750 lbl_1_rodata_6750;
extern void lbl_8006DAEC(void);
extern void lbl_8006DD14(void *, void *);
extern void fn_1_A7024(f32, f32, f32, f32);
extern void fn_8006F1F0(void *, void *, void *);
extern void lbl_8006DB74(void *);
extern void lbl_8006DCDC(void);
extern void lbl_8006DB30(void);
extern void fn_1_E1408(void *, void *);


#pragma fp_contract on

extern f32 lbl_1_rodata_6780[10];
extern void fn_1_E57F4(void *, f32);
extern void fn_1_556B8(void *);
extern f32 fn_1_56298(f32, f32, f32, f32);
extern void fn_1_DCFA4(void *);
extern void fn_1_55FF0(f32);
extern void lbl_8006D784(void *);
extern void lbl_8006DBAC(void *);
extern void lbl_8006DFE8(void *);
extern void fn_8006EE70(const void *, s16 *);
extern void mathutil_mtxA_rotate_z(u32);
extern void mathutil_mtxA_rotate_y(u32);
extern void mathutil_mtxA_rotate_x(u32);
extern void lbl_8006E15C(f32, f32, f32);
extern void fn_80072558(void);
extern f32 lbl_8006D0B4(f32);
extern void lbl_8006E0A4(void *);
extern void lbl_8006E14C(f32);
extern void lbl_8006D7DC(void *);
extern void lbl_8006DB74(void *);

typedef struct { f32 x, y, z; } DDVec;
typedef struct { f32 m[3][4]; } DDMtx;
typedef struct {
    u8 pad0[8];
    s16 unk8;
    u8 padA[0x22];
    DDVec v2C;
    u8 pad38[0xC];
    DDVec v44;
    f32 f50;
    u8 pad54[0x18];
    DDVec v6C;
    u8 pad78[0x10];
    DDVec v88;
    u8 pad94[0x30];
    DDMtx mC4;
    u8 padF4[0x1C];
    DDMtx m110;
} DDObj;
typedef struct {
    u8 pad0[0x20];
    void *p20;
    u8 pad24[4];
    void *p28;
    u8 pad2C[0xC];
    void *p38;
} DDModels;

#pragma fp_contract on
#pragma opt_propagation off
void fn_1_DD4DC(DDObj *obj) {
    f32 *pool = lbl_1_rodata_6780;
    DDMtx matrix;
    s16 angle1[3];
    s16 angle2[3];
    s16 angle3[3];
    f32 magnitude;
    f32 scaled;
    f32 limit;
    fn_1_E57F4(obj, pool[8]);
    if (obj->unk8 > 100) return;
    lbl_8006D784(&matrix);
    lbl_8006DBAC(&obj->mC4);
    {
        f32 z, y, x;
        x = *(f32 *)(0xE000000C);
        y = *(f32 *)(0xE000001C);
        z = *(f32 *)(0xE000002C);
        matrix.m[0][3] = x;
        matrix.m[1][3] = y;
        matrix.m[2][3] = z;
    }
    lbl_8006DFE8(&matrix);
    magnitude = obj->f50;
    if (!(__fabs(magnitude) < *(f64 *)((u8 *)pool + 0x18))) {
        fn_8006EE70(&obj->v44, angle1);
        mathutil_mtxA_rotate_z(angle1[2]);
        mathutil_mtxA_rotate_y(angle1[1]);
        mathutil_mtxA_rotate_x(angle1[0]);
        scaled = pool[9] * magnitude;
        limit = scaled < pool[8] ? pool[8] : scaled > pool[9] ? pool[9] : scaled;
        lbl_8006E15C(pool[10], pool[10], limit);
        fn_80072558();
        fn_1_556B8(((DDModels *)lbl_1_bss_38454->unk_8)->p38);
    }
    fn_1_56298(pool[10], pool[10], pool[8], pool[10]);
    lbl_8006DFE8(&matrix);
    {
        f32 sum;
        f32 y;
        f32 x;
        x = obj->v2C.x;
        y = obj->v2C.y;
        sum = x * x;
        sum = __fmadds(y, y, sum);
        sum = __fmadds(obj->v2C.z, obj->v2C.z, sum);
        magnitude = lbl_8006D0B4(sum);
    }
    if (!(__fabs(magnitude) < *(f64 *)((u8 *)pool + 0x18))) {
        fn_8006EE70(&obj->v2C, angle2);
        mathutil_mtxA_rotate_z(angle2[2]);
        mathutil_mtxA_rotate_y(angle2[1]);
        mathutil_mtxA_rotate_x(angle2[0]);
        scaled = pool[9] * magnitude;
        limit = scaled < pool[8] ? pool[8] : scaled > pool[9] ? pool[9] : scaled;
        lbl_8006E15C(pool[10], pool[10], limit);
        fn_80072558();
        fn_1_556B8(((DDModels *)lbl_1_bss_38454->unk_8)->p38);
    }
    fn_1_56298(pool[8], pool[8], pool[8], pool[8]);
    fn_1_DCFA4(obj);
    lbl_8006D784(&matrix);
    lbl_8006DBAC(&obj->mC4);
    {
        f32 z, y, x;
        x = *(f32 *)(0xE000000C);
        y = *(f32 *)(0xE000001C);
        z = *(f32 *)(0xE000002C);
        matrix.m[0][3] = x;
        matrix.m[1][3] = y;
        matrix.m[2][3] = z;
    }
    lbl_8006DFE8(&matrix);
    fn_1_56298(pool[8], pool[10], pool[8], pool[8]);
    {
        f32 sum;
        f32 y;
        f32 x;
        x = obj->v6C.x;
        y = obj->v6C.y;
        sum = x * x;
        sum = __fmadds(y, y, sum);
        sum = __fmadds(obj->v6C.z, obj->v6C.z, sum);
        magnitude = lbl_8006D0B4(sum);
    }
    if (!(__fabs(magnitude) < *(f64 *)((u8 *)pool + 0x18))) {
        fn_8006EE70(&obj->v6C, angle3);
        mathutil_mtxA_rotate_z(angle3[2]);
        mathutil_mtxA_rotate_y(angle3[1]);
        mathutil_mtxA_rotate_x(angle3[0]);
        scaled = pool[9] * magnitude;
        limit = scaled < pool[8] ? pool[8] : scaled > pool[9] ? pool[9] : scaled;
        lbl_8006E15C(pool[10], pool[10], limit);
        fn_80072558();
        fn_1_556B8(((DDModels *)lbl_1_bss_38454->unk_8)->p38);
    }
    fn_1_56298(pool[8], pool[8], pool[8], pool[8]);
    lbl_8006DFE8(&obj->mC4);
    lbl_8006E0A4(&obj->v88);
    lbl_8006E14C(pool[12]);
    fn_80072558();
    fn_1_55FF0(pool[13]);
    fn_1_56298(pool[10], pool[8], pool[8], pool[8]);
    fn_1_556B8(((DDModels *)lbl_1_bss_38454->unk_8)->p20);
    fn_1_56298(pool[8], pool[8], pool[8], pool[8]);
    lbl_8006D784(&matrix);
    lbl_8006D7DC(&obj->m110);
    lbl_8006DB74(&matrix);
    lbl_8006DFE8(&matrix);
    mathutil_mtxA_rotate_x(0xC000);
    lbl_8006E14C(pool[14]);
    fn_80072558();
    fn_1_556B8(((DDModels *)lbl_1_bss_38454->unk_8)->p28);
}
/* fzgx:end fn_1_DD4DC */

/* fzgx:begin fn_1_DD890 noprologue */
#include "types.h"
#include "types.h"
#include "rel/main_rel/globals.h"
#include "rel/main_rel/car_test.h"
#include "types.h"
#include "rel/main_rel/bg_for.h"

/* begin game/main_rel/car_test_types.h (deltawave784/fzgx, CC0) */
#ifndef GAME_MAIN_REL_CAR_TEST_TYPES_H
#define GAME_MAIN_REL_CAR_TEST_TYPES_H

// Types (and the externs that name them) of car_test.c, hoisted out of its prologue so that
// a block can compile standalone and under the prologue. Hand-owned (librarian).


typedef struct {
    f32 x;
    f32 y;
    f32 z;
} Fn183D28Vec3;

typedef struct {
    u8 pad_0[0x14c];
    Fn183D28Vec3 pos;
    u8 pad_158[0x200 - 0x158];
    f32 unk_200;
} Fn183D28Body;

typedef struct {
    u8 pad_0[0x8];
    Fn183D28Vec3 dir;
    f32 radius;
} Fn183D28Target;

typedef struct {
    s16 limit;
    s16 pad_2;
    Fn183D28Target **target;
    u8 pad_8[4];
} Fn183D28Entry;

typedef struct {
    u8 pad_0[0x8];
    Fn183D28Target **target;
} Fn183D28Slot;

typedef struct {
    u8 pad_0[0x344];
    Fn183D28Slot *slots[1];
} Fn183D28Alt;

typedef struct {
    u8 pad_0[0x320];
    s16 index;
    u8 pad_322[0xa];
    Fn183D28Body *body;
    Fn183D28Entry entries[6];
    u8 pad_378[0x18];
    u32 flags;
    u8 pad_394[0xc];
    Fn183D28Alt *alt;
} Fn183D28Car;

typedef struct {
    u32 flags;
    u8 pad_4[0x5];
    u8 count;
    u8 pad_A[0x14AE];
    f64 pad_14B8;
} CarTestInfo;

typedef struct {
    u8 pad_0[0x3ba];
    s16 state;
    u8 pad_3BC[0x84];
} CarTestCar;

extern s8 fn_1_84408(CarTestCar *);
extern void fn_1_8E084(CarTestCar *, u32 *, s32);
extern s8 fn_1_84124(Fn183D28Car *, s8, s8, u8 *);
extern void lbl_8006DFE8(Fn183D28Vec3 *);
extern void lbl_8006E1B0(Fn183D28Vec3 *, Fn183D28Vec3 *);
extern s8 fn_1_84644(Fn183D28Body *);

#endif  // GAME_MAIN_REL_CAR_TEST_TYPES_H

/* end game/main_rel/car_test_types.h */
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

typedef struct { f32 x, y, z; } Sig_fn_1_DD4DC_DDVec;
typedef struct { f32 m[3][4]; } Sig_fn_1_DD4DC_DDMtx;
typedef struct {
    u8 pad0[8];
    s16 unk8;
    u8 padA[0x22];
    Sig_fn_1_DD4DC_DDVec v2C;
    u8 pad38[0xC];
    Sig_fn_1_DD4DC_DDVec v44;
    f32 f50;
    u8 pad54[0x18];
    Sig_fn_1_DD4DC_DDVec v6C;
    u8 pad78[0x10];
    Sig_fn_1_DD4DC_DDVec v88;
    u8 pad94[0x30];
    Sig_fn_1_DD4DC_DDMtx mC4;
    u8 padF4[0x1C];
    Sig_fn_1_DD4DC_DDMtx m110;
} Sig_fn_1_DD4DC_DDObj;
typedef struct {
    u32 unk0;
    f32 value;
} Sig_fn_1_E5734_E5734Obj;

struct fn_1_DD890_lbl_1_rodata_6780 {
    u8 pad_0[0x18];
    f64 unk_18;
    f32 unk_20;
    f32 unk_24;
    f32 unk_28;
    u8 pad_2C[8];
    f32 unk_34;
    u8 pad_38[4];
    f32 unk_3C;
    f64 unk_40;
};
struct fn_1_DD890_lbl_801A66A0 {
    u32 unk_0;
};

extern f32 fn_1_56298(f32, f32, f32, f32);
extern f32 fn_1_E5734(Sig_fn_1_E5734_E5734Obj *);
extern struct fn_1_DD890_lbl_1_rodata_6780 lbl_1_rodata_6780;
extern struct fn_1_DD890_lbl_801A66A0 lbl_801A66A0[1];
#define lbl_801A66A0 (lbl_801A66A0[0])
extern void fn_1_DD4DC(Sig_fn_1_DD4DC_DDObj *);
extern void lbl_8006DFE8(Fn183D28Vec3 *);
extern void lbl_8006DBAC(Vec3 *);
extern void lbl_8006DB74(void *);
extern u32 fn_1_9BBE4(void *, u32, u32, Fn183D28Vec3 *);
extern u32 mathutil_mtxA_rotate_y(u32);
extern u32 mathutil_mtxA_rotate_x(u32);
extern u32 mathutil_mtxA_rotate_z(u32);
extern s32 fn_1_54F5C(void *, f32, f32);
extern void fn_80072558(void);
extern void fn_1_55FF0(f32);
extern void fn_1_553C4(void *, void *);
extern void fn_1_556B8(void *);
extern void lbl_8006E15C(f32, f32, f32);
extern void lbl_8006E14C(f32);
extern void lbl_8006D784(void *);
extern f32 lbl_8006D0B4(f32);
typedef struct Sig_fn_8006EE70_Vec3 {
    f32 x;
    f32 y;
    f32 z;
} Sig_fn_8006EE70_Vec3;
extern void fn_8006EE70(const Sig_fn_8006EE70_Vec3 *, s16 *);
extern void fn_1_A8DD4(const char *, ...);
extern void fn_1_E50F0(void *, void (*)(const char *, ...));
extern void fn_1_E5164(void *, void (*)(const char *, ...));
extern void fn_1_E52F8(void *, void (*)(const char *, ...));

#define FLAGS (*(u64 *)((u8 *)arg0 + 0x138))
#define F(off) (*(f32 *)((u8 *)arg0 + (off)))
#define S(off) (*(s16 *)((u8 *)arg0 + (off)))
#define MAX(a,b) ((a) > (b) ? (a) : (b))

#pragma section code_type ".fzgxpool"
/* Prime the translation unit's shared native literal pool in retail order. */
static void fzgx_DD890_pool_primer(volatile f32 *f, volatile f64 *d) {
    *f = -1.0f;
    *f = 0.99999988079071044921875f;
    *f = 1.00000011920928955078125f;
    *f = -1.00000011920928955078125f;
    *f = -0.99999988079071044921875f;
    *d = 1.1920928955078125e-07;
    *f = 0.0f;
    *f = 5.0f;
    *f = 1.0f;
    *f = 2.3418408851396162e-38f;
    *f = 0.1f;
    *f = 0.5f;
    *f = 10.0f;
    *f = 182.04444885253906f;
    *d = 4503599627370496.0;
}

#pragma section code_type ".text"

static inline f32 fn_1_DD890_clamp(f32 value, f32 lower, f32 upper) {
    if (value < lower) return lower;
    if (value > upper) return upper;
    return value;
}

#pragma fp_contract on
void fn_1_DD890(Sig_fn_1_DD4DC_DDObj *arg0, f32 arg1) {
    struct fn_1_DD890_lbl_1_rodata_6780 *p_lbl_1_rodata_6780;
    u32 v0;
    f32 v1;
    u32 v2;
    u32 v3;
    u32 v4;
    u32 v5;
    u32 v6;
    f32 v7;
    u32 v8;
    u32 v9;
    u32 v10;
    f32 v11;
    u32 v12;
    u32 v13;
    f32 v14;
    u32 v15;
    u32 v16;
    u32 v17;
    s16 i;
    u32 v18;
    s32 v19;
    f32 v20;
    f32 t1;
    f32 t2;
    f32 t3;
    f32 t4;
    f32 t6;
    union { f64 value; u32 words[2]; } conversion;
    Sig_fn_1_DD4DC_DDMtx mtx;
    Sig_fn_1_DD4DC_DDMtx tempMtx;
    s16 angles[3];
    f32 z;
    f32 sum;
    f32 y;
    f32 x;
    f32 length;
    v0 = (u32)arg0;
    v1 = arg1;
    if (arg0 != 0) {
    if ((FLAGS & 1ULL) == 0) {
    if ((FLAGS & 128ULL) != 0) {
        fn_1_DD4DC((Sig_fn_1_DD4DC_DDObj *)v0);
    }
    if ((FLAGS & 16384ULL) != 0) {
        if ((FLAGS & 0x40000000ULL) != 0) {
            v1 = 0.0f;
            v7 = 1.0f;
            fn_1_56298(v1, v1, v7, v7);
        }
        if ((FLAGS & 0x8000000ULL) != 0) {
            v1 = 1.0f;
            fn_1_56298(v1, v1, 0.0f, v1);
        }
        if ((FLAGS & 0x8000ULL) != 0) {
            v1 = 0.0f;
            v11 = 1.0f;
            fn_1_56298(v1, v11, v1, v11);
        }
        if ((FLAGS & 0x100000000ULL) != 0) {
            v14 = 1.0f;
            v1 = 0.0f;
            fn_1_56298(v1, v14, v14, v14);
        }
    }
    lbl_8006DFE8((Fn183D28Vec3 *)&arg0->mC4);
    if ((FLAGS & 0x2000000ULL) != 0) {
        v17 = lbl_1_bss_3BE0->unk_54;
        v18 = v17 + (S(14) << 6);
        *(u32 *)v18 &= 0x7FFFFFFF;
        t6 = fn_1_E5734((Sig_fn_1_E5734_E5734Obj *)arg0);
        *(f32 *)(v18 + 44) = 1.0f - t6;
        lbl_8006DBAC((Vec3 *)&arg0->mC4);
        if (S(10) == 5 || S(10) == 1) {
            struct fn_1_DD890_lbl_801A66A0 *clock = (struct fn_1_DD890_lbl_801A66A0 *)&lbl_801A66A0;
            v19 = (u32)(clock->unk_0 * 6) % 360;
            v20 = 182.04444885253906f;
            mathutil_mtxA_rotate_y((s32)(v20 * (f32)(u32)v19));
        }
        lbl_8006DB74(&mtx);
        fn_1_9BBE4((void *)lbl_1_bss_3BE0->unk_54, S(14), S(14), (Fn183D28Vec3 *)&mtx);
        *(u32 *)v18 |= 0x80000000;
        for (i = 0; i < 4; i++) {
            if (*(s16 *)((u8 *)arg0 + i * 2 + 0x10) != -1) {
                v18 = lbl_1_bss_3BE0->unk_54 + (*(s16 *)((u8 *)arg0 + i * 2 + 0x10) << 6);
                *(u32 *)v18 &= 0x7FFFFFFF;
                t6 = fn_1_E5734((Sig_fn_1_E5734_E5734Obj *)arg0);
                *(f32 *)(v18 + 44) = 1.0f - t6;
                lbl_8006DBAC((Vec3 *)&arg0->mC4);
                lbl_8006DB74(&mtx);
                fn_1_9BBE4((void *)lbl_1_bss_3BE0->unk_54, *(s16 *)((u8 *)arg0 + i * 2 + 0x10), *(s16 *)((u8 *)arg0 + i * 2 + 0x10), (Fn183D28Vec3 *)&mtx);
                *(u32 *)v18 |= 0x80000000;
            }
        }
    } else {
        FLAGS |= 0x400000000ULL;
        if (fn_1_54F5C((u8 *)*(u32 *)arg0 + 8, *(f32 *)(*(u32 *)arg0 + 0x14), MAX(MAX(F(0xF4), F(0xF8)), F(0xFC))) != 0) {
            if (fn_1_E5734((Sig_fn_1_E5734_E5734Obj *)arg0) != 0.0f) {
                FLAGS &= ~0x400000000ULL;
                fn_80072558();
                fn_1_55FF0(F(4));
                if (*(u32 *)arg0 == 0) {
                    return;
                }
                if ((FLAGS & 0x1000000ULL) != 0) {
                    fn_1_553C4(*(void **)arg0, (void *)1);
                } else {
                    fn_1_556B8(*(void **)arg0);
                }
            }
        }
    }
    if ((FLAGS & 0x100000ULL) != 0) {
        lbl_8006DFE8((Fn183D28Vec3 *)((u8 *)arg0 + 196));
        switch (S(12)) {
        case 1:
            v1 = F(0x1a0);
            lbl_8006E15C(v1, F(0x1a4), v1);
            fn_80072558();
            fn_1_55FF0(0.5f);
            fn_1_556B8(*(void **)(lbl_1_bss_38454->unk_8 + 0x18));
            break;
        case 0:
        default:
            lbl_8006E14C(F(0x84));
            fn_80072558();
            fn_1_55FF0(0.5f);
            fn_1_556B8(*(void **)(lbl_1_bss_38454->unk_8 + 0x20));
            break;
        }
    }
    if ((FLAGS & 0x400000ULL) != 0) {
        lbl_8006D784(&tempMtx);
        lbl_8006DBAC((Vec3 *)((u8 *)arg0 + 196));
        /* Locked cache current matrix: the volatile first load preserves translation-column load order. */
        x = *(volatile f32 *)(0xE0000000 + 0x0C); /* locked cache */
        y = *(f32 *)(0xE0000000 + 0x1C); /* locked cache */
        z = *(f32 *)(0xE0000000 + 0x2C); /* locked cache */
        tempMtx.m[0][3] = x;
        tempMtx.m[1][3] = y;
        tempMtx.m[2][3] = z;
        lbl_8006DFE8((Fn183D28Vec3 *)&tempMtx);
        v14 = 1.0f;
        fn_1_56298(0.0f, v14, v14, v14);
        x = arg0->m110.m[1][2];
        y = arg0->m110.m[1][3];
        z = arg0->m110.m[2][0];
        sum = x * x;
        sum += y * y;
        sum += z * z;
        length = lbl_8006D0B4(sum);
        if (!(__fabs(length) < 1.1920928955078125e-07)) {
            fn_8006EE70((Sig_fn_8006EE70_Vec3 *)&arg0->m110.m[1][2], angles);
            mathutil_mtxA_rotate_z(angles[2]);
            mathutil_mtxA_rotate_y(angles[1]);
            mathutil_mtxA_rotate_x(angles[0]);
            v1 = 5.0f * length;
            v14 = fn_1_DD890_clamp(v1, 0.0f, 5.0f);
            v1 = 1.0f;
            lbl_8006E15C(v1, v1, v14);
            fn_80072558();
            fn_1_556B8(*(void **)(lbl_1_bss_38454->unk_8 + 0x38));
        }
        v1 = 0.0f;
        fn_1_56298(v1, v1, v1, v1);
    }
    if ((FLAGS & 4ULL) != 0 || (FLAGS & 0x20000ULL) != 0) {
        fn_1_E50F0((void *)arg0, fn_1_A8DD4);
    }
    if ((FLAGS & 0x1000ULL) != 0) {
        fn_1_E5164((void *)arg0, fn_1_A8DD4);
    }
    if ((FLAGS & 0x200000ULL) != 0) {
        fn_1_E52F8((void *)arg0, fn_1_A8DD4);
    }
    v1 = 0.0f;
    fn_1_56298(v1, v1, v1, v1);
    }
    }
}
/* fzgx:end fn_1_DD890 */

/* fzgx:begin fn_1_DDF80 noprologue */
#include "types.h"
#include "psvec.h"

typedef struct {
    f32 x;
    f32 y;
    f32 z;
} Vec;

/* bg_for.c's literal pool: -1.0f at 0x0, 0.0f at 0x20, 1.0f at 0x28 */
typedef struct {
    f32 unk_0;
    u8 pad_4[0x1C];
    f32 unk_20;
    u8 pad_24[0x4];
    f32 unk_28;
} Pool;

extern const Pool lbl_1_rodata_6780;
extern f32 lbl_8006D534(Vec *, Vec *);
extern f32 lbl_8006D0B4(f32);
extern void fn_80008BA8(void *, void *, u32);
extern void lbl_8006D5F0(Vec *, Vec *, f32);
extern void lbl_8006D668(Vec *);

/* opt_common_subs off as in fn_1_DE180, which repeats this code; opt_propagation off keeps the pool pointer
 * in one register from the start, as retail does */
#pragma opt_common_subs off
#pragma opt_propagation off

static inline void cross(Vec *a, Vec *b, Vec *out) {
    f32 ax;
    f32 ay;
    f32 az;
    f32 bx;
    f32 by;
    f32 bz;
    f32 x;
    f32 y;
    f32 z;

    ay = a->y;
    bz = b->z;
    az = a->z;
    bx = b->x;
    by = b->y;
    ax = a->x;

    x = ay * bz;
    x -= az * by;
    y = az * bx;
    y -= ax * bz;
    z = ax * by;
    z -= ay * bx;
    out->x = x;
    out->y = y;
    out->z = z;
}

static inline f32 dot(Vec *a, Vec *b) {
    f32 result;
    f32 ay;
    f32 az;
    f32 ax;
    f32 bx;
    f32 by;
    f32 bz;
    ax = a->x;
    bx = b->x;
    ay = a->y;
    by = b->y;
    az = a->z;
    bz = b->z;
    result = ax * bx;
    result += ay * by;
    result += az * bz;
    return result;
}

/* a helper of its own gives the -1.0 and the final scale retail's register order */
static inline void flip(const Pool *pool, Vec *v) {
    psvec_scale(v, pool->unk_0, v);
}

void fn_1_DDF80(Vec *a, Vec *b, Vec *along, Vec *side, f32 along_scale, f32 side_scale) {
    const Pool *pool = &lbl_1_rodata_6780;
    Vec pos;
    f32 c;
    f32 s;

    c = lbl_8006D534(a, b);
    s = lbl_8006D0B4(pool->unk_28 - (f32)(c * c));
    fn_80008BA8(along, b, sizeof(Vec));
    lbl_8006D5F0(along, along, along_scale * c);
    fn_80008BA8(&pos, a, sizeof(Vec));
    cross(&pos, b, side);
    cross(side, b, side);
    if (dot(side, side) > pool->unk_20) {
        lbl_8006D668(side);
    }
    if (!(dot(&pos, side) > pool->unk_20)) {
        flip(pool, side);
    }
    psvec_scale(side, side_scale * s, side);
}

#pragma opt_propagation reset
#pragma opt_common_subs reset
/* fzgx:end fn_1_DDF80 */

/* fzgx:begin fn_1_DE180 noprologue */
#include "types.h"
#include "psvec.h"
#include "types.h"

/* begin game/vec3.h (deltawave784/windows-and-types@cf9407c75) */
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

#endif  // GAME_VEC3_H

/* end game/vec3.h */

typedef struct fn_1_DE180_Obj {
    u8 pad_0[0x18];
    f32 unk_18;
    u8 pad_1C[0x4];
    f32 unk_20;
    u8 pad_24[0x20];
    Vec3 pos;
    f32 unk_50;
    u8 pad_54[0x18];
    Vec3 vel;
    u8 pad_78[0xC0];
    u64 flags;
} fn_1_DE180_Obj;

/* shared literal pool: -1.0f at 0x0, 0.0f at 0x20, 1.0f at 0x28 */
typedef struct fn_1_DE180_Pool {
    f32 neg_one;
    u8 pad_4[0x1C];
    f32 zero;
    u8 pad_24[0x4];
    f32 one;
} fn_1_DE180_Pool;

extern const fn_1_DE180_Pool lbl_1_rodata_6780;

extern f32 lbl_8006D534(Vec3 *, Vec3 *);
extern f32 lbl_8006D0B4(f32);
extern void fn_80008BA8(void *, void *, u32);
extern void lbl_8006D5F0(Vec3 *, Vec3 *, f32);
extern void lbl_8006D668(Vec3 *);
extern void fn_80008BEC(void *, int, u32);

#pragma opt_common_subs off
#pragma opt_propagation on

static inline void fn_1_DE180_cross(Vec3 *a, Vec3 *b, Vec3 *out) {
    f32 ay = a->y;
    f32 az = a->z;
    f32 bx = b->x;
    f32 by;
    f32 bz = b->z;
    f32 ax = a->x;
    f32 x;
    f32 z;
    f32 y;
    by = b->y;
    y = az * bx;
    y -= ax * bz;
    z = ax * by;
    z -= ay * bx;
    x = ay * bz;
    x -= az * by;
    out->x = x;
    out->y = y;
    out->z = z;
}

static inline f32 fn_1_DE180_dot(Vec3 *a, Vec3 *b) {
    f32 result;
    f32 ay;
    f32 az;
    f32 ax;
    f32 bx;
    f32 by;
    f32 bz;
    ax = a->x;
    bx = b->x;
    ay = a->y;
    by = b->y;
    az = a->z;
    bz = b->z;
    result = ax * bx;
    result += ay * by;
    result += az * bz;
    return result;
}

static inline void fn_1_DE180_perp(const fn_1_DE180_Pool *pool, Vec3 *a, Vec3 *b, Vec3 *out) {
    Vec3 *n = out;
    fn_1_DE180_cross(a, b, out);
    fn_1_DE180_cross(out, b, out);
    if (fn_1_DE180_dot(out, out) > pool->zero) {
        lbl_8006D668(n);
    }
}

static inline BOOL fn_1_DE180_clamp(const fn_1_DE180_Pool *pool, Vec3 *v, f32 r) {
    Vec3 *p;
    if (r < pool->zero) {
        return FALSE;
    }
    p = v;
    if (fn_1_DE180_dot(v, v) <= r * r) {
        fn_80008BEC(p, 0, sizeof(Vec3));
        return TRUE;
    }
    return FALSE;
}

void fn_1_DE180(fn_1_DE180_Obj *obj, Vec3 *dir, f32 radius) {
    f32 damping;
    f32 side_scale;
    f32 fzgx_live;
    f32 scale;
    const fn_1_DE180_Pool *pool;
    Vec3 push;
    Vec3 side;
    Vec3 pos;
    f32 s;
    f32 k;
    f32 dist;

    pool = &lbl_1_rodata_6780;
    if ((obj->flags & 0x8000) != 0) {
        return;
    }
    dist = lbl_8006D534(&obj->pos, dir);
    if (dist > pool->zero) {
        return;
    }
    s = lbl_8006D0B4(pool->one - (f32)(dist * dist));
    k = obj->unk_50;
    scale = k * -obj->unk_18;
    fn_80008BA8(&push, dir, sizeof(Vec3));
    lbl_8006D5F0(&push, &push, scale * dist);
    fn_80008BA8(&pos, &obj->pos, sizeof(Vec3));

    fn_1_DE180_perp(pool, &pos, dir, &side);
    if (!(fn_1_DE180_dot(&pos, &side) > pool->zero)) {
        fzgx_live = pool->neg_one;
        psvec_scale(&side, fzgx_live, &side);
    }
    side_scale = k * s;
    psvec_scale(&side, side_scale, &side);
    if (fn_1_DE180_clamp(pool, &push, radius) == TRUE) {
        obj->flags |= 0x8000;
        if ((obj->flags & 0x8000000) == 0) {
            obj->flags |= 0x100000000ULL;
        }
    }
    psvec_add(&push, &side, &obj->pos);
    damping = pool->one - obj->unk_20;
    psvec_scale(&obj->vel, damping, &obj->vel);
}

#pragma opt_common_subs reset
/* fzgx:end fn_1_DE180 */

/* fzgx:begin fn_1_DE4B0 */
#include "psvec.h"

extern void OSPanic(const char *, int, const char *, ...);
extern struct fn_1_DCE60_lbl_1_rodata_6750 lbl_1_rodata_6750;
extern void lbl_8006DAEC(void);
extern void lbl_8006DD14(void *, void *);
extern void fn_1_A7024(f32, f32, f32, f32);
extern void fn_8006F1F0(void *, void *, void *);
extern void lbl_8006DB74(void *);
extern void lbl_8006DCDC(void);
extern void lbl_8006DB30(void);
extern void fn_1_E1408(void *, void *);


typedef struct {
    f32 x;
    f32 y;
    f32 z;
} DE4B0Vec;

typedef struct {
    f32 x, y, z, w;
} DE4B0Quat;

typedef struct {
    s16 x;
    s16 y;
    s16 z;
} DE4B0Angles;

typedef struct {
    u8 pad_0[0xC];
    s16 mode;
    u8 pad_E[0x54 - 0xE];
    DE4B0Vec pos;
    u8 pad_60[0x6C - 0x60];
    DE4B0Vec rot;
    u8 pad_78[0x88 - 0x78];
    DE4B0Vec vel;
    u8 pad_94[0xC4 - 0x94];
    u8 mtx[0x30];
    u8 pad_F4[0x138 - 0xF4];
    u64 flags;
} DE4B0Obj;

extern u32 lbl_801A63C0;
extern void fn_1_E5840(void *, const void *);
extern void lbl_8006DBAC(void *);
extern void lbl_8006E1C0(void *, void *);
extern void lbl_8006E1B0(void *, void *);
extern f32 lbl_8006D668(void *);
extern void fn_80008BA8(void *, const void *, u32);
extern void fn_8006E978(DE4B0Quat *, DE4B0Vec *, DE4B0Vec *);
extern void mathutil_mtxA_from_quat(DE4B0Quat *);
extern void fn_8006F6A8(DE4B0Angles *);

/*
 * The literal pool lbl_1_rodata_6780 is shared by the whole retail TU; the
 * tables and primers below lay it out so this function's literals land on
 * retail's offsets.
 */
extern void fzgx_pool_sink(const void *, f32);

#pragma section RX ".fzgxpool"

__declspec(section ".fzgxpool") void fzgx_pool_primer0(void) {
    fzgx_pool_sink(0, -1.0f);
}
static const u32 pool_6784[7] = {
    0x3F7FFFFE, 0x3F800001, 0xBF800001, 0xBF7FFFFE,
    0x00000000, 0x3E800000, 0x00000000,
};
__declspec(section ".fzgxpool") void fzgx_pool_primer1(void) {
    fzgx_pool_sink(pool_6784, 0.0f);
    fzgx_pool_sink(pool_6784, 5.0f);
    fzgx_pool_sink(pool_6784, 1.0f);
}
static const u32 pool_67AC[1] = { 0x00FF00FF };
__declspec(section ".fzgxpool") void fzgx_pool_primer2(void) {
    fzgx_pool_sink(pool_67AC, 0.1f);
    fzgx_pool_sink(pool_67AC, 0.5f);
    fzgx_pool_sink(pool_67AC, 10.0f);
    fzgx_pool_sink(pool_67AC, 182.04445f);
    fzgx_pool_sink(pool_67AC, 176.0f);
}
static const f32 pool_67C4[2] = { 0.0f, -0.0027222224f };
__declspec(section ".fzgxpool") void fzgx_pool_primer3(void) {
    fzgx_pool_sink(pool_67C4, 0.0f);
}

#pragma section RX ".text"

/* the vector helpers of fn_1_DDF80 / fn_1_DE180 in this TU, under the same
 * propagation setting; cross writes its result through an f32 pointer so a
 * local result stays in memory */
#pragma opt_propagation off

static inline void cross(DE4B0Vec *a, DE4B0Vec *b, DE4B0Vec *out) {
    f32 ax;
    f32 ay;
    f32 az;
    f32 bx;
    f32 by;
    f32 bz;
    f32 x;
    f32 y;
    f32 z;
    f32 *dst = (f32 *)out;

    ay = a->y;
    bz = b->z;
    az = a->z;
    bx = b->x;
    by = b->y;
    ax = a->x;

    x = ay * bz;
    x -= az * by;
    y = az * bx;
    y -= ax * bz;
    z = ax * by;
    z -= ay * bx;
    dst[0] = x;
    dst[1] = y;
    dst[2] = z;
}

static inline f32 dot(DE4B0Vec *a, DE4B0Vec *b) {
    f32 result;
    f32 ay;
    f32 az;
    f32 ax;
    f32 bx;
    f32 by;
    f32 bz;
    ax = a->x;
    bx = b->x;
    ay = a->y;
    by = b->y;
    az = a->z;
    bz = b->z;
    result = ax * bx;
    result += ay * by;
    result += az * bz;
    return result;
}

/* a helper of its own gives the -1.0 and the final scale retail's register order (as in fn_1_DDF80) */
static inline void flip(DE4B0Vec *v) {
    psvec_scale(v, -1.0f, v);
}

static inline s16 DE4B0_sign(f32 v) {
    if (v < -1.1920929e-07f) {
        return -1;
    } else if (v > 1.1920929e-07f) {
        return 1;
    }
    return 0;
}

void fn_1_DE4B0(DE4B0Obj *obj, DE4B0Vec *dir) {
    DE4B0Vec out;
    DE4B0Vec up = { 0.0f, 1.0f, 0.0f };

    if ((obj->flags & 0x100000000ULL) == 0) {
        return;
    }
    switch (obj->mode) {
    case 1:
        if ((obj->flags & 0x400000000ULL) != 0) {
            DE4B0Vec axisA = { 0.0f, 1.0f, 0.0f };
            DE4B0Vec axisB = { 1.0f, 0.0f, 0.0f };
            DE4B0Vec rot;
            DE4B0Quat quat;
            DE4B0Angles angles;
            u32 seed;

            lbl_8006DBAC(obj->mtx);
            seed = lbl_801A63C0 * 0x676A4B6B + 0x33CB;
            lbl_801A63C0 = seed;
            if ((s32)((seed >> 16) & 0x7FFF) % 2 != 0) {
                lbl_8006E1C0(&axisA, &axisA);
                lbl_8006D668(&axisA);
                fn_80008BA8(&out, &axisA, sizeof(DE4B0Vec));
            } else {
                lbl_8006E1C0(&axisB, &axisB);
                lbl_8006D668(&axisB);
                fn_80008BA8(&out, &axisB, sizeof(DE4B0Vec));
            }
            fn_8006E978(&quat, &out, dir);
            mathutil_mtxA_from_quat(&quat);
            fn_8006F6A8(&angles);
            rot.x = 9.58738e-05f * angles.x;
            rot.y = 9.58738e-05f * angles.y;
            rot.z = 9.58738e-05f * angles.z;
            fn_1_E5840(obj, &rot);
        } else {
            DE4B0Vec side[1];
            DE4B0Vec top[1];
            DE4B0Vec base[1];
            DE4B0Vec velDir[1];
            DE4B0Vec normal[1];
            DE4B0Vec rot;
            DE4B0Quat quat;
            DE4B0Angles angles;
            s32 same;
            f32 d;

            same = 0;
            top[0].y = 1.5f * obj->vel.y;
            top[0].x = top[0].z = 0.0f;
            if (obj->vel.x == 0.0f && obj->vel.y == 0.0f && obj->vel.z == 0.0f) {
                return;
            }
            lbl_8006DBAC(obj->mtx);
            lbl_8006E1B0(top, top);
            lbl_8006E1B0(&obj->vel, base);
            lbl_8006E1C0(&obj->vel, velDir);
            lbl_8006E1C0(&up, &up);
            lbl_8006D668(&up);
            cross(velDir, dir, side);
            cross(side, dir, normal);
            d = -dot(normal, base);
            if (DE4B0_sign((d + dot(normal, top)) * (d + dot(normal, &obj->pos))) > 0) {
                same = 1;
            }
            if (same == 1) {
                fn_80008BA8(&out, &up, sizeof(DE4B0Vec));
            } else {
                cross(side, &up, &out);
                lbl_8006D668(&out);
            }
            if (dot(dir, &out) < 0.0f) {
                flip(&out);
            }
            fn_8006E978(&quat, &out, dir);
            mathutil_mtxA_from_quat(&quat);
            fn_8006F6A8(&angles);
            rot.x = 9.58738e-05f * angles.x;
            rot.y = 9.58738e-05f * angles.y;
            rot.z = 9.58738e-05f * angles.z;
            psvec_scale(&rot, 0.1f, &obj->rot);
        }
        break;
    }
}

#pragma opt_propagation reset
/* fzgx:end fn_1_DE4B0 */

/* fzgx:begin fn_1_DE9C4 noprologue */
#include "types.h"
#include "rel/main_rel/bg_for.h"
#include "psvec.h"

#pragma section code_type ".fzgxpool"
__declspec(section ".fzgxpool") static void fzgx_pool_prime1(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = -1.0f;
    s = 0.9999998807907104f;
    s = 1.0000001192092896f;
    s = -1.0000001192092896f;
    s = -0.9999998807907104f;
}
static const u32 fzgx_pool_table2[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep2(void) { const u32 *volatile cp; cp = fzgx_pool_table2; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime3(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 1.1920928955078125e-07;
    s = 0.0f;
    s = 5.0f;
    s = 1.0f;
}
static const u32 fzgx_pool_table4[1] = {0x00FF00FF};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep4(void) { const u32 *volatile cp; cp = fzgx_pool_table4; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime5(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 0.10000000149011612f;
    s = 0.5f;
    s = 10.0f;
    s = 182.04444885253906f;
    d = 4503599627370496.0;
    s = -0.0027222223579883575f;
}
static const u32 fzgx_pool_table6[9] = {0x00000000, 0x3F800000, 0x00000000, 0x00000000, 0x3F800000, 0x00000000, 0x3F800000, 0x00000000, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep6(void) { const u32 *volatile cp; cp = fzgx_pool_table6; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime7(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 9.58738019107841e-05f;
    s = 1.5f;
    s = -1.1920928955078125e-07f;
    s = 1.1920928955078125e-07f;
    d = 4503601774854144.0;
    s = 60.0f;
    s = 1000000.0f;
    s = 250000.0f;
    s = 20.0f;
}
#pragma section code_type ".text"
typedef struct Sig_fn_8006F6A8_Fn8006F6A8 {
    s16 angle_y;
    s16 angle_x;
    s16 angle_z;
} Sig_fn_8006F6A8_Fn8006F6A8;
struct fn_1_DE9C4_Arg0 {
    u8 pad_0[10];
    s16 unk_A;
    u8 pad_C[0x48];
    f32 unk_54;
    f32 unk_58;
    f32 unk_5C;
    u8 pad_60[0x18];
    f32 unk_78;
    f32 unk_7C;
    f32 unk_80;
    u8 pad_84[0x70];
    f32 unk_F4;
    u8 pad_F8[0x40];
    u64 unk_138;
    u8 pad_140[0x1C];
    s32 unk_15C;
    u32 *unk_160;
    u32 unk_164;
    f32 *unk_168;
    u32 unk_16C;
};
extern f32 fn_1_9E14C(u32, void *, f32);
extern f32 fn_1_9E194(u32, void *, f32);
extern u32 fn_1_A5594(u32, void *);
extern u32 lbl_8006D7DC(u32);
extern u32 mathutil_mtxA_rotate_x(u32);
extern u32 mathutil_mtxA_rotate_y(u32);
extern u32 mathutil_mtxA_rotate_z(u32);
extern void *fn_1_86254(int);
extern void fn_8006F6A8(Sig_fn_8006F6A8_Fn8006F6A8 *);
extern void lbl_8006DAEC(void);
extern void lbl_8006DB30(void);
extern void lbl_8006E0B4(f32, f32, f32);

#pragma opt_strength_reduction off
void fn_1_DE9C4(struct fn_1_DE9C4_Arg0 *arg0) {
    f32 fzgx_live;
    u32 *v2 = arg0->unk_160;
    f32 v12;
    f32 t5;
    f32 t6;
    f32 t7;
    f32 t9;
    f32 t11;
    f32 t13;
    f32 v16;
    f32 v17;
    f32 v19;
    f32 v4 = (f32)arg0->unk_15C / 60.0f;
    f32 dx;
    f32 dz;
    f32 next;
    void *t19;
    Sig_fn_8006F6A8_Fn8006F6A8 loc_8;
    if (arg0->unk_15C < 0) v4 = 0.0f;
    lbl_8006DAEC();
    lbl_8006D7DC(arg0->unk_16C);
    mathutil_mtxA_rotate_z((s32)(182.04444885253906f * arg0->unk_168[2]));
    mathutil_mtxA_rotate_y((s32)(182.04444885253906f * arg0->unk_168[1]));
    mathutil_mtxA_rotate_x((s32)(182.04444885253906f * arg0->unk_168[0]));
    lbl_8006E0B4(fn_1_9E14C(v2[6], (void *)v2[7], v4), fn_1_9E14C(v2[8], (void *)v2[9], v4), fn_1_9E14C(v2[10], (void *)v2[11], v4));
    mathutil_mtxA_rotate_z((s32)(182.04444885253906f * fn_1_9E14C(v2[4], (void *)v2[5], v4)));
    mathutil_mtxA_rotate_y((s32)(182.04444885253906f * fn_1_9E14C(v2[2], (void *)v2[3], v4)));
    mathutil_mtxA_rotate_x((s32)(182.04444885253906f * fn_1_9E14C(v2[0], (void *)v2[1], v4)));
    psvec_set(&arg0->unk_54, *(f32 *)(0xE0000000 + 0x2C), *(f32 *)(0xE0000000 + 0x1C), *(f32 *)(0xE0000000 + 0x0C));
    fn_8006F6A8(&loc_8);
    arg0->unk_78 = 9.58738019107841e-05f * (f32)loc_8.angle_y;
    arg0->unk_7C = 9.58738019107841e-05f * (f32)loc_8.angle_x;
    arg0->unk_80 = 9.58738019107841e-05f * (f32)loc_8.angle_z;
    lbl_8006DB30();
    if ((arg0->unk_138 & 8192) == 0) arg0->unk_15C++;
    if (*(s16 *)&lbl_1_bss_960 == 9 && arg0->unk_A == 2) {
        next = (f32)arg0->unk_15C / 60.0f;
        v16 = fn_1_9E194(v2[8], (void *)v2[9], v4);
        v17 = fn_1_9E194(v2[8], (void *)v2[9], next);
        if (v16 < v17) {
            t19 = fn_1_86254(0);
            dx = *(f32 *)((u8 *)t19 + 124);
            dx -= arg0->unk_54;
{
    f32 v18;
            v18 = *(f32 *)((u8 *)t19 + 128) - arg0->unk_58;
            dz = *(f32 *)((u8 *)t19 + 132) - arg0->unk_5C;
            dx = dx * dx;
            dx = dx + v18 * v18;
            dx = dx + dz * dz;
            v19 = dx;
}
            if (v19 < 1000000.0f) {
                v12 = v17-v16;
                if (v12 > 5.0f && v19 < 250000.0f) {
                    if (arg0->unk_F4 > 20.0f) fn_1_A5594(0xA90A0300, &arg0->unk_54);
                    else fn_1_A5594(0xA90A0100, &arg0->unk_54);
                } else {
                    if (v12 > 5.0f && arg0->unk_F4 > 20.0f) fn_1_A5594(0xA90A0200, &arg0->unk_54);
                    else fn_1_A5594(0xA90A0000, &arg0->unk_54);
                }
            }
        }
    }
}
#pragma opt_strength_reduction reset
/* fzgx:end fn_1_DE9C4 */

/* fzgx:begin fn_1_DF2A4 */
#include "psvec.h"

#pragma fp_contract on
#pragma opt_propagation off

typedef struct DF2A4Vec { f32 x, y, z; } DF2A4Vec;
typedef struct DF2A4Mtx { f32 m[3][4]; } DF2A4Mtx;

extern u8 lbl_1_rodata_6780[];
extern void lbl_8006DBAC(void *);
extern void fn_80008BEC(void *, int, u32);
extern void fn_8006E2B0(void *, void *);
extern f32 lbl_8006D534(void *, void *);
extern void lbl_8006D5F0(void *, void *, f32);
extern void fn_8006E250(void *, void *);
extern void mathutil_mtxA_rotate_x(s32);
extern void lbl_8006E0A4(void *);
extern void lbl_8006DB74(void *);
extern void lbl_8006DC34(void *);
extern void lbl_8006D7DC(void *);
extern void lbl_8006DFC4(void *);
extern void lbl_8006D758(void);
extern s32 fn_1_DEDC4(void *, void *, void *, DF2A4Vec *, DF2A4Vec *, DF2A4Vec *, DF2A4Vec *, f32);

static inline f32 vec_dot_read_pointer(DF2A4Vec * owner) { return owner->y; }
static inline void vec_dot(DF2A4Vec *a, DF2A4Vec *b, f32 *dot) {
    f32 result;
    f32 ax;
    f32 bx;
    f32 by;
    f32 ay;
    ax = a->x;
    bx = b->x;
    by = b->y;
    ay = a->y;
    bx = ax * bx;
    bx += ay * by;
    bx += a->z * b->z;
    *dot = bx;
}

#pragma opt_common_subs off
static inline void vec_dot_plane(DF2A4Vec *a, DF2A4Vec *b, f32 *dot) {
    f32 result;
    f32 ay;
    f32 az;
    f32 ax;
    f32 bx;
    f32 by;
    f32 bz;
    bx = b->x;
    ax = a->x;
    by = b->y;
    ay = a->y;
    bz = b->z;
    az = a->z;
    result = ax * bx;
    result += ay * by;
    result += az * bz;
    *dot = result;
}
static inline s32 distance_outside(f32 bound, f32 distance) {
    return distance * distance > bound;
}

static inline void plane_distance(DF2A4Vec *a, DF2A4Vec *b, DF2A4Vec *normal, f32 *dot) {
    DF2A4Vec d;
    psvec_sub(a, b, &d);
    vec_dot(&d, normal, dot);
}

static inline void plane_distance_second(DF2A4Vec *a, DF2A4Vec *b, DF2A4Vec *normal, DF2A4Vec *hit, const f32 *scale) {
    f32 dist;
    DF2A4Vec d;
    psvec_sub(a, b, &d);
    vec_dot_plane(&d, normal, &dist);
    lbl_8006D5F0(normal, hit, *scale * dist);
}

static inline s32 plane_outside(DF2A4Vec *a, DF2A4Vec *b, DF2A4Vec *normal, f32 bound) {
    f32 dist;
    plane_distance(a, b, normal, &dist);
    return dist * dist > bound;
}

static inline void fn_1_DF2A4_bound(f32 radius, f32 height, f32 *bound) {
    f32 result = radius * radius;
    result += height * height;
    *bound = result;
}
static inline f32 fn_1_DF2A4_operand_pointer(const f32 *left, f32 right) {
    f32 result = *left * right;
    return result;
}
#define fn_1_DF2A4_operand(left, right) fn_1_DF2A4_operand_pointer(&(left), right)
static inline void fn_1_DF2A4_translation(DF2A4Vec *out) {
    f32 x = *(f32 *)(0xE0000000 + 0x0C);
    f32 y = *(f32 *)(0xE0000000 + 0x1C);
    f32 z = *(f32 *)(0xE0000000 + 0x2C);
    psvec_set(out, z, y, x);
}
#pragma opt_lifetimes off
s16 fn_1_DF2A4(DF2A4Vec *pos, DF2A4Vec * __restrict prev, void *mtx, DF2A4Vec *point, DF2A4Vec *normal,
               DF2A4Vec *hit, DF2A4Vec *out, f32 radius, f32 height) {
    u8 *pool = lbl_1_rodata_6780;
    DF2A4Mtx mtxB;
    DF2A4Mtx mtxA;
    DF2A4Vec up;
    DF2A4Vec nrm;
    DF2A4Vec p68;
    DF2A4Vec p5c;
    DF2A4Vec off;
    DF2A4Vec lpos;
    DF2A4Vec lprev;
    DF2A4Vec rot;
    DF2A4Vec pt;
    f32 finalY, finalX;
    f32 dist;
    f32 boundSquared;
    register f32 cosv;
    f32 firstY, firstX;
    f32 secondY, secondX;
    f32 dd;
    f32 side;
    s16 sign;
    s16 result;

    up = *(DF2A4Vec *)(pool + 0xC0);
    lbl_8006DBAC(mtx);
    {
    f32 dist;
    fn_1_DF2A4_bound(radius, height, &dist);
    plane_distance(prev, point, normal, &boundSquared);
    boundSquared *= boundSquared;
    if (boundSquared > dist) {
        fn_80008BEC(out, 0, 12);
        return 0;
    }
    }
    fn_8006E2B0(normal, &nrm);
    cosv = lbl_8006D534(&up, &nrm);
    if (__fabs(cosv) < *(f64 *)(pool + 0x18)) {
        fn_80008BEC(out, 0, 12);
        lbl_8006D5F0(normal, &off, -radius);
        psvec_add(pos, &off, &p5c);
        psvec_add(prev, &off, &p68);
        {
        f32 px, py, pz;
        f32 nx, ny, nz;
        f32 sx, sy;
        f32 tx, ty;
        f32 dotPoint, dotPos, dotPrev;
        nx = normal->x;
        sx = p5c.x;
        tx = p68.x;
        ny = normal->y;
        sy = p5c.y;
        ty = p68.y;
        nz = normal->z;
        dotPoint = nx * point->x;
        dotPoint += ny * point->y;
        dotPoint += nz * point->z;
        dotPos = nx * sx;
        dotPos += ny * sy;
        dotPos += nz * p5c.z;
        dotPrev = nx * tx;
        dotPrev += ny * ty;
        dotPrev += nz * p68.z;
        dd = -dotPoint;
        side = (dd + dotPos) * (dd + dotPrev);
        }
        if (side < *(f32 *)(pool + 0x78)) {
            sign = -1;
        } else if (side > *(f32 *)(pool + 0x7C)) {
            sign = 1;
        } else {
            sign = 0;
        }
        if (sign > 0) {
            return 0;
        }
        plane_distance_second(&p68, point, normal, hit, (f32 *)(pool + 0xB8));
        fn_8006E250(&p68, out);
        return 2;
    }
    height = *(f32 *)(pool + 0x34) * height;
    fn_8006E250(point, &pt);
    fn_80008BEC(&rot, 0, 12);
    rot.y = height;
    if (cosv > *(f32 *)(pool + 0x20)) {
        mathutil_mtxA_rotate_x(-0x8000);
    }
    lbl_8006E0A4(&rot);
    lbl_8006DB74(&mtxB);
    psvec_set(&lpos, *(f32 *)(0xE0000000 + 0x2C), *(f32 *)(0xE0000000 + 0x1C), *(f32 *)(0xE0000000 + 0x0C));
    lbl_8006DC34(&mtxA);
    lbl_8006D7DC(pos);
    lbl_8006DFC4(&mtxA);
    lbl_8006E0A4(&rot);
    psvec_set(&lprev, *(f32 *)(0xE0000000 + 0x2C), *(f32 *)(0xE0000000 + 0x1C), *(f32 *)(0xE0000000 + 0x0C));
    result = fn_1_DEDC4(&lprev, &lpos, &mtxB, point, normal, hit, out, radius);
    if (result != 0) {
        lbl_8006D758();
        if (cosv > *(f32 *)(pool + 0x20)) {
            mathutil_mtxA_rotate_x(-0x8000);
        }
        out->y = height;
        lbl_8006E0A4(out);
        fn_1_DF2A4_translation(out);
    }
    return result;
}
#pragma opt_lifetimes reset
/* fzgx:end fn_1_DF2A4 */

/* fzgx:begin fn_1_DF6AC */
#include "psvec.h"

typedef struct {
    f32 x;
    f32 y;
    f32 z;
} Vec;

extern f32 lbl_8006D534(Vec *, Vec *);
extern f32 lbl_8006D0B4(f32);
extern void fn_80008BA8(void *, void *, u32);
extern void fn_80008BEC(void *, int, u32);
extern void lbl_8006D5F0(Vec *, Vec *, f32);
extern void lbl_8006D668(Vec *);

/* bg_for.c's literal pool up to 1.0f at 0x28, so -1.0f, 0.0f and 1.0f land at retail's offsets */
#pragma section code_type ".fzgxpool"
__declspec(section ".fzgxpool") static void fzgx_pool_prime1(void) {
    volatile f32 s;  /* fzgx-allow: S2 pool primer sink */
    s = -1.0f;
    s = 0.9999998807907104f;
    s = 1.0000001192092896f;
    s = -1.0000001192092896f;
    s = -0.9999998807907104f;
}
static const u32 fzgx_pool_table2[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep2(void) { const u32 *volatile cp; cp = fzgx_pool_table2; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime3(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 1.1920928955078125e-07;
    s = 0.0f;
    s = 5.0f;
    s = 1.0f;
}
#pragma section code_type ".text"

/* as in fn_1_DDF80 and fn_1_DE180, whose code this repeats: retail reloads each field at every use */
#pragma opt_common_subs off
/* keeps the sqrt results as named values, which retail holds in f20/f21 below the parameters */
#pragma opt_dead_assignments off

static inline void cross(Vec *a, Vec *b, Vec *out) {
    f32 ax;
    f32 ay;
    f32 az;
    f32 bx;
    f32 by;
    f32 bz;
    f32 x;
    f32 y;
    f32 z;

    ay = a->y;
    bz = b->z;
    az = a->z;
    bx = b->x;
    by = b->y;
    ax = a->x;

    y = az * bx;
    y -= ax * bz;
    z = ax * by;
    z -= ay * bx;
    x = ay * bz;
    x -= az * by;
    out->x = x;
    out->y = y;
    out->z = z;
}

static inline f32 dot(Vec *a, Vec *b) {
    f32 result;
    f32 ay;
    f32 az;
    f32 ax;
    f32 bx;
    f32 by;
    f32 bz;
    ax = a->x;
    bx = b->x;
    ay = a->y;
    by = b->y;
    az = a->z;
    bz = b->z;
    result = ax * bx;
    result += ay * by;
    result += az * bz;
    return result;
}

/* as fn_1_DE180's perp: retail sets up the normalise argument before the test */
static inline void perp(Vec *a, Vec *b, Vec *out) {
    Vec *n = out;

    cross(a, b, out);
    cross(out, b, out);
    if (dot(out, out) > 0.0f) {
        lbl_8006D668(n);
    }
}

/* a helper of its own gives the -1.0 retail's register order (fn_1_DDF80) */
static inline void flip(Vec *v) {
    psvec_scale(v, -1.0f, v);
}

/* fn_1_DDF80's body; retail inlines it twice, which needs a larger inline size limit */
#pragma inline_max_size(4096)
static inline void split(Vec *a, Vec *b, Vec *along, Vec *side, f32 along_scale, f32 side_scale) {
    Vec pos;
    f32 c;
    f32 s;

    c = lbl_8006D534(a, b);
    s = lbl_8006D0B4(1.0f - (f32)(c * c));
    fn_80008BA8(along, b, sizeof(Vec));
    lbl_8006D5F0(along, along, along_scale * c);
    fn_80008BA8(&pos, a, sizeof(Vec));
    perp(&pos, b, side);
    if (!(dot(&pos, side) > 0.0f)) {
        flip(side);
    }
    psvec_scale(side, side_scale * s, side);
}

void fn_1_DF6AC(Vec *a, Vec *b, Vec *c, Vec *out_b, Vec *out_c, f32 scale_b, f32 scale_c, f32 k0, f32 k1, f32 k2,
                f32 unused) {
    Vec along_b;
    Vec along_c;
    Vec side_b;
    Vec side_c;
    Vec dir;
    f32 len_b;
    f32 len_c;
    f32 u; /* declared before t: retail keeps u in f27 above t in f26 */
    f32 t;
    Vec *src;

    split(b, a, &along_b, &side_b, scale_b, scale_b);
    split(c, a, &along_c, &side_c, scale_c, scale_c);
    len_b = lbl_8006D0B4(dot(&along_b, &along_b));
    len_c = lbl_8006D0B4(dot(&along_c, &along_c));
    /* the (f32) casts keep each product a separate fmuls, as retail has no fmadds here */
    t = ((f32)(len_b * ((1.0f + k2) * k0)) + (f32)(len_c * (f32)(k1 - (f32)(k0 * k2)))) / (k0 + k1);
    u = t + (f32)(-k2 * (len_b - len_c));
    src = &along_b;
    if (dot(src, src) != 0.0f) {
        fn_80008BA8(&dir, src, sizeof(Vec));
    } else {
        src = &along_c;
        if (dot(src, src) != 0.0f) {
            fn_80008BA8(&dir, src, sizeof(Vec));
        } else {
            fn_80008BEC(out_b, 0, sizeof(Vec));
            fn_80008BEC(out_c, 0, sizeof(Vec));
            return;
        }
    }
    lbl_8006D668(&dir);
    psvec_scale(&dir, u, &along_b);
    psvec_scale(&dir, t, &along_c);
    psvec_add(&along_b, &side_b, out_b);
    psvec_add(&along_c, &side_c, out_c);
}

#pragma inline_max_size reset
#pragma opt_dead_assignments reset
#pragma opt_common_subs reset
/* fzgx:end fn_1_DF6AC */

/* fzgx:begin fn_1_E07B8 */
#include "psvec.h"

/* bg_for.c's literal pool up to 1.0f at 0x28, so -1.0f, 0.0f and 1.0f land at retail's offsets */
#pragma section code_type ".fzgxpool"
__declspec(section ".fzgxpool") static void fzgx_pool_prime1(void) {
    volatile f32 s;  /* fzgx-allow: S2 pool primer sink */
    s = -1.0f;
    s = 0.9999998807907104f;
    s = 1.0000001192092896f;
    s = -1.0000001192092896f;
    s = -0.9999998807907104f;
}
static const u32 fzgx_pool_table2[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep2(void) { const u32 *volatile cp; cp = fzgx_pool_table2; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime3(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 1.1920928955078125e-07;
    s = 0.0f;
    s = 5.0f;
    s = 1.0f;
}
static const u32 fzgx_pool_table4[1] = {0x00FF00FF};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep4(void) { const u32 *volatile cp; cp = fzgx_pool_table4; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime5(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 0.10000000149011612f;
    s = 0.5f;
    s = 10.0f;
    s = 182.04444885253906f;
    d = 4503599627370496.0;
    s = -0.0027222223579883575f;
}
static const u32 fzgx_pool_table6[9] = {0x00000000, 0x3F800000, 0x00000000, 0x00000000, 0x3F800000, 0x00000000, 0x3F800000, 0x00000000, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep6(void) { const u32 *volatile cp; cp = fzgx_pool_table6; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime7(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 9.58738019107841e-05f;
    s = 1.5f;
    s = -1.1920928955078125e-07f;
    s = 1.1920928955078125e-07f;
    d = 4503601774854144.0;
    s = 60.0f;
    s = 1000000.0f;
    s = 250000.0f;
    s = 20.0f;
}
static const u32 fzgx_pool_table8[6] = {0x00000000, 0x3F800000, 0x00000000, 0x00000000, 0x3F800000, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep8(void) { const u32 *volatile cp; cp = fzgx_pool_table8; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime9(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = -0.009999999776482582f;
    s = 0.009999999776482582f;
    s = -1.0099999904632568f;
    s = 9.999999747378752e-05f;
}
static const u32 fzgx_pool_table10[3] = {0x00000000, 0x3F800000, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep10(void) { const u32 *volatile cp; cp = fzgx_pool_table10; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime11(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 0.9900000095367432f;
    s = 2.0f;
    s = -0.0f;
    d = 216.0;
    d = 3.1415927410125732;
    d = 4.0;
    d = 60.0;
    s = 1.0099999904632568f;
    s = 0.05000000074505806f;
    s = 1.0010000467300415f;
    s = 0.8999999761581421f;
    s = 3.0f;
}
static const u32 fzgx_pool_table12[1] = {0x3FE00000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep12(void) { const u32 *volatile cp; cp = fzgx_pool_table12; }  /* fzgx-allow: S2 pool primer sink */
#pragma section code_type ".text"

typedef struct {
    f32 x;
    f32 y;
    f32 z;
} Vec;

typedef struct {
    u8 pad_0[0xC];
    s16 mode;
    u8 pad_E[0xA];
    f32 unk_18;
    u8 pad_1C[0x4];
    f32 unk_20;
    u8 pad_24[0x20];
    Vec pos;
    f32 unk_50;
    Vec unk_54;
    Vec unk_60;
    Vec vel;
    u8 pad_78[0xC];
    f32 unk_84;
    Vec unk_88;
    u8 pad_94[0x28];
    u32 unk_BC;
    u32 unk_C0;
    Vec unk_C4;
    u8 pad_D0[0x24];
    f32 unk_F4;
    f32 unk_F8;
    u8 pad_FC[0x4];
    s32 unk_100;
    s32 unk_104;
    s32 unk_108;
    s32 unk_10C;
    Vec unk_110;
    Vec unk_11C;
    Vec unk_128;
    u8 pad_134[0x4];
    u64 flags;
    u8 pad_140[0x60];
    f32 unk_1A0;
    f32 unk_1A4;
} Obj;

typedef struct {
    f32 x;
    f32 y;
    f32 z;
} HitPoint;

typedef struct {
    u32 unk_0;
    u8 pad_4[0x8];
} Entry;

extern u32 lbl_801A66A0;
extern void *fn_1_14F04(void);
extern s32 fn_1_20A5C(Vec *, f32 *);
extern s32 fn_1_15578(Vec *, Vec *, f32 *, HitPoint *, s32, s32 *, u32, s32, s32, s32);
extern s16 fn_1_DF2A4(Vec *, Vec *, Vec *, Vec *, Vec *, Vec *, Vec *, f32, f32);
extern void lbl_8006D5A4(Vec *, Vec *, Vec *, f32);
extern f32 lbl_8006D534(Vec *, Vec *);
extern f32 lbl_8006D0B4(f32);
extern void fn_80008BA8(void *, void *, u32);
extern void lbl_8006D5F0(Vec *, Vec *, f32);
extern void lbl_8006D668(Vec *);
extern void fn_80008BEC(void *, int, u32);

#pragma opt_common_subs off
#pragma opt_propagation off

static inline void cross(Vec *a, Vec *b, Vec *out) {
    f32 ax;
    f32 ay;
    f32 az;
    f32 bx;
    f32 by;
    f32 bz;
    f32 x;
    f32 y;
    f32 z;

    ay = a->y;
    bz = b->z;
    az = a->z;
    bx = b->x;
    by = b->y;
    ax = a->x;

    y = az * bx;
    y -= ax * bz;
    z = ax * by;
    z -= ay * bx;
    x = ay * bz;
    x -= az * by;
    out->x = x;
    out->y = y;
    out->z = z;
}

static inline f32 dot(Vec *a, Vec *b) {
    f32 result;
    f32 ay;
    f32 az;
    f32 ax;
    f32 bx;
    f32 by;
    f32 bz;
    ax = a->x;
    bx = b->x;
    ay = a->y;
    by = b->y;
    az = a->z;
    bz = b->z;
    result = ax * bx;
    result += ay * by;
    result += az * bz;
    return result;
}

static inline void perp(Vec *a, Vec *b, Vec *out) {
    Vec *n = out;
    cross(a, b, out);
    cross(out, b, out);
    if (dot(out, out) > 0.0f) {
        lbl_8006D668(n);
    }
}

static inline BOOL clamp(Vec *v, f32 r) {
    Vec *p;
    if (r < 0.0f) {
        return FALSE;
    }
    p = v;
    if (dot(v, v) <= r * r) {
        fn_80008BEC(p, 0, sizeof(Vec));
        return TRUE;
    }
    return FALSE;
}

/* a helper of its own for the -1.0 flip, as in fn_1_DDF80 / fn_1_DF6AC */
static inline void flip(Vec *v) {
    psvec_scale(v, -1.0f, v);
}

static inline void split(Vec *a, Vec *b, Vec *along, Vec *side, f32 along_scale, f32 side_scale, f32 c, f32 s) {
    Vec pos;

    fn_80008BA8(along, b, sizeof(Vec));
    lbl_8006D5F0(along, along, along_scale * c);
    fn_80008BA8(&pos, a, sizeof(Vec));
    perp(&pos, b, side);
    if (!(dot(&pos, side) > 0.0f)) {
        flip(side);
    }
    psvec_scale(side, side_scale * s, side);
}

/* fn_1_DE180's body, which retail inlines here three times; split is fn_1_DDF80's body (as in fn_1_DF6AC)
 * taking the precomputed dot and sqrt */
#pragma inline_max_size(4096)
static inline void slide(Obj *obj, Vec *dir, f32 radius) {
    Vec push;
    Vec side;
    f32 s;
    f32 k;
    f32 dist;

    if ((obj->flags & 0x8000) != 0) {
        return;
    }
    dist = lbl_8006D534(&obj->pos, dir);
    if (dist > 0.0f) {
        return;
    }
    s = lbl_8006D0B4(1.0f - (f32)(dist * dist));
    k = obj->unk_50;
    split(&obj->pos, dir, &push, &side, k * -obj->unk_18, k, dist, s);
    if (clamp(&push, radius) == TRUE) {
        obj->flags |= 0x8000;
        if ((obj->flags & 0x8000000) == 0) {
            obj->flags |= 0x100000000ULL;
        }
    }
    psvec_add(&push, &side, &obj->pos);
    psvec_scale(&obj->vel, 1.0f - obj->unk_20, &obj->vel);
}

s32 fn_1_E07B8(Obj *obj) {
    Vec cur;
    Vec prev;
    Vec ofs;
    HitPoint hit;
    Vec push;
    f32 info;
    f32 t;
    f32 sc;
    void *p;
    s32 ret;
    s16 r;
    u32 now;
    u32 dt;

    ret = 0;
    if ((obj->flags & 0x20) != 0) {
        return 0;
    }
    sc = 1.01f * obj->unk_84 * obj->unk_F8;
    fn_80008BA8(&cur, &obj->unk_54, sizeof(Vec));
    fn_80008BA8(&prev, &obj->unk_60, sizeof(Vec));
    fn_80008BA8(&ofs, &obj->unk_128, sizeof(Vec));
    psvec_scale(&ofs, -sc, &ofs);
    psvec_add(&cur, &ofs, &cur);
    psvec_add(&prev, &ofs, &prev);
    p = fn_1_14F04();
    obj->unk_100 = fn_1_20A5C(&cur, &info);
    obj->unk_104 = obj->unk_108 = obj->unk_10C = obj->unk_100;
    switch (obj->mode) {
    case 1:
        if (obj->unk_100 >= 0 &&
            fn_1_15578(&cur, &prev, &t, &hit, 1, &obj->unk_100,
                       ((Entry *)lbl_1_bss_3BE0->unk_C)[obj->unk_100].unk_0, 0, 0, 0) != 0) {
            fn_80008BA8(&obj->unk_11C, &hit, sizeof(Vec));
            lbl_8006D668(&obj->unk_11C);
            if ((obj->flags & 0x10000) != 0) {
                fn_80008BA8(&obj->unk_128, &obj->unk_11C, sizeof(Vec));
            }
            lbl_8006D5A4(&prev, &cur, &obj->unk_110, t);
        }
        r = fn_1_DF2A4(&obj->unk_60, &obj->unk_54, &obj->unk_C4, &obj->unk_110, &obj->unk_11C, &push, &obj->unk_88,
                       obj->unk_1A0 * obj->unk_F4, obj->unk_1A4 * obj->unk_F8);
        if (r != 0) {
            ret = 1;
            obj->flags |= 0x40000000;
            if (r != 3) {
                obj->flags |= 0x8000000;
            }
            psvec_add(&obj->unk_54, &push, &obj->unk_54);
            slide(obj, &obj->unk_11C, 0.05f * obj->unk_18);
        }
        break;
    case 0:
    default:
        if (obj->unk_100 >= 0 &&
            fn_1_15578(&cur, &prev, &t, &hit, 5, &obj->unk_100,
                       ((Entry *)lbl_1_bss_3BE0->unk_C)[obj->unk_100].unk_0, 0, 0, 0) != 0) {
            if ((*(u32 *)((u8 *)p + 0x118) & 4) != 0) {
                slide(obj, (Vec *)&hit, 0.05f * obj->unk_18);
            }
            ret = 1;
            obj->flags |= 0x40000000;
            fn_80008BA8(&obj->unk_11C, &hit, sizeof(Vec));
            if ((obj->flags & 0x10000) != 0) {
                fn_80008BA8(&obj->unk_128, &obj->unk_11C, sizeof(Vec));
            }
            psvec_scale(&ofs, 1.001f, &ofs);
            psvec_sub(&cur, &ofs, &cur);
            fn_80008BA8(&obj->unk_54, &cur, sizeof(Vec));
            slide(obj, &obj->unk_11C, 0.05f * obj->unk_18);
        }
        break;
    }
    if ((obj->flags |= 0x10000000000ULL) != 0 && obj->unk_C0 != -1 && ret != 0) {
        now = lbl_801A66A0;
        dt = now - obj->unk_C0;
        if (dt < 360) {
            if (dt < 120) {
                obj->unk_C0 = now - (obj->unk_BC - 30);
            } else {
                obj->unk_C0 = now - (obj->unk_BC - 120);
            }
        }
    }
    /* Retail tests ret here (an unused cmpwi r30,0 before the return): the
     * original source had a final test of ret whose two paths compile to the
     * same code. */
    if (ret) {
        return ret;
    }
    return ret;
}

#pragma inline_max_size reset
#pragma opt_propagation reset
#pragma opt_common_subs reset
/* fzgx:end fn_1_E07B8 */

/* fzgx:begin fn_1_E1408 noprologue */
#include "types.h"
#include "psvec.h"

typedef struct {
    f32 x;
    f32 y;
    f32 z;
} E1408Vec;

typedef struct {
    u8 pad0[0x18];
    f32 field18;
    f32 field1C;
    u8 pad20[0x24];
    E1408Vec field44;
    f32 field50;
    E1408Vec pos;
    E1408Vec vel;
    u8 pad6C[0x18];
    f32 field84;
    u8 pad88[0x6c];
    f32 fieldF4;
    u8 padF8[0x40];
    union {
        u64 flags;
        struct {
            u32 hi;
            u32 lo;
        } w;
    } f138;
    u32 mask140;
    void *other;
} E1408Object;

typedef struct {
    f32 unk_0;
    u8 pad4[0x1c];
    f32 unk_20;
    u8 pad24[0x10];
    f32 unk_34;
    u8 pad38[0x3c];
    f32 unk_74;
    u8 pad78[0x4];
    f32 unk_7C;
    u8 pad80[0x34];
    f32 unk_B4;
    u8 padB8[0x14];
    f32 unk_CC;
} E1408Pool;

extern E1408Pool lbl_1_rodata_6780;
extern void fn_1_DF6AC(void *, void *, void *, void *, void *, f32, f32, f32, f32, f32, f32);
extern f32 lbl_8006D0B4(f32);
extern void lbl_8006D5A4(void *, void *, void *, f32);
extern void lbl_8006D5F0(void *, f32, void *);

/* Earliest time t at which two moving spheres of combined radius r touch. */
#pragma opt_propagation off
#pragma opt_lifetimes off
static inline f32 E1408_length(f32 u, f32 v, f32 w) {
    f32 length = u * u;
    length += v * v;
    length += w * w;
    return length;
}
#pragma opt_lifetimes off
static inline s32 E1408_sweep(E1408Pool *pool, E1408Vec *dp, E1408Vec *dv, f32 r, f32 *t) {
    f32 B;
    f32 A;
    f32 C;
    f32 length;
    f32 u;
    f32 zero;
    f32 disc;
    f32 y = dp->y;
    f32 x = dp->x;
    f32 z = dp->z;

    A = x * x;
    A += y * y;
    A += z * z;
    if (A < pool->unk_7C) {
        return 0;
    }

    {
        f32 v = dv->y;
        f32 w = dv->z;
        u = *(volatile f32 *)&dv->x;  /* fzgx-allow: S2 volatile view keeps the verified load order */
        length = u * u;
        length += v * v;
        length += w * w;
        B = u * x;
        B += v * y;
        B += w * z;
        C = length - (f32)(r * r);
    }
    zero = pool->unk_20;
    disc = (f32)(B * B) - (f32)(A * C);
    if (disc < zero) {
        return 0;
    }
    if (C <= zero) {
        *t = zero;
        return 1;
    }
    if (C + (B + (A + B)) > zero) {
        if (B >= zero) {
            return 0;
        }
        if (-B >= A) {
            return 0;
        }
    }
    *t = -(B + lbl_8006D0B4(disc)) / A;
    return 1;
}

/* Whether `me` may push `other` out of the way. */
#pragma opt_propagation off
static inline u32 E1408_pushes(u64 me, u64 other, u32 result) {

    if (((me & 0x80000) != 0 && (other & 0x80000) == 0) || ((me & 0x40000) == 0 && (other & 0x40000) != 0)) {
        result = 1;
    }
    return result;
}

#pragma opt_propagation off
static inline u64 E1408_flags_core(u64 fa, u64 fb, u32 pa, u32 pb) {
    if (((fa & 0x80000) != 0 && (fb & 0x80000) == 0) || ((fa & 0x40000) == 0 && (fb & 0x40000) != 0)) {
        pa = 1;
    }
    if (((fb & 0x80000) != 0 && (fa & 0x80000) == 0) || ((fb & 0x40000) == 0 && (fa & 0x40000) != 0)) {
        pb = 1;
    }
    return ((u64)pb << 32) | pa;
}
static inline u64 E1408_flags(u32 pb, u32 pa, u32 fb, u64 fa) {
    fa = (u32)fa;
    if (((fa & 0x80000) != 0 && ((u64)fb & 0x80000) == 0) || ((fa & 0x40000) == 0 && ((u64)fb & 0x40000) != 0)) {
        pa = 1;
    }
    if ((((u64)fb & 0x80000) != 0 && (fa & 0x80000) == 0) || (((u64)fb & 0x40000) == 0 && (fa & 0x40000) != 0)) {
        pb = 1;
    }
    return pb | ((u64)pa << 32);
}

#pragma opt_propagation reset
static inline f32 fn_1_E1408_read_pointer(E1408Object * owner) { return owner->fieldF4; }
#pragma opt_propagation off
static inline void E1408_add_reverse(E1408Vec *pos, E1408Vec *delta, f32 scale) {
    psvec_add(pos, delta, pos);
    psvec_scale(delta, scale, delta);
}
static inline void E1408_separate(E1408Vec *a, E1408Vec *b, E1408Vec *delta, f32 scale) {
    psvec_add(a, delta, a);
    psvec_scale(delta, scale, delta);
    psvec_add(b, delta, b);
}
#pragma opt_propagation on
s32 fn_1_E1408(E1408Object *a, E1408Object *b) {
    E1408Vec n;
    E1408Vec dp;
    E1408Vec dv;
    E1408Vec t20;
    E1408Vec t14;
    E1408Vec t8;
    E1408Pool *pool;
    u32 pushA;
    u32 pushB;
    f32 r;
    f32 t;
    u64 fa;
    u64 fb;

    pool = &lbl_1_rodata_6780;
    if ((a->f138.flags & 0x40) != 0 || (b->f138.flags & 0x40) != 0) {
        return 0;
    }
    if ((a->mask140 & b->mask140) == 0) {
        return 0;
    }

    psvec_sub(&a->vel, &b->vel, &dv);
    psvec_sub(&a->pos, &b->pos, &dp);
    psvec_sub(&dp, &dv, &dp);
    r = (f32)(pool->unk_CC * a->field84 * fn_1_E1408_read_pointer(a)) + (f32)(pool->unk_CC * b->field84 * fn_1_E1408_read_pointer(b));
    if (E1408_sweep(pool, &dp, &dv, r, &t) == 0) {
        return 0;
    }

    lbl_8006D5A4(&a->vel, &a->pos, &a->pos, t);
    lbl_8006D5A4(&b->vel, &b->pos, &b->pos, t);
    psvec_sub(&b->pos, &a->pos, &n);

    fa = E1408_flags(0, 0, (u32)b->f138.flags, (u64)(u32)a->f138.flags);
    pushA = (u32)(fa >> 32);
    pushB = (u32)fa;

    if (pushB == 1) {
        lbl_8006D5F0(&n, pool->unk_74 * r, &t20);
        psvec_add(&a->pos, &t20, &b->pos);
    } else if (pushA == 1) {
        lbl_8006D5F0(&n, -(pool->unk_74 * r), &t14);
        psvec_add(&b->pos, &t14, &a->pos);
    } else {
        lbl_8006D5F0(&n, -(pool->unk_B4 * r), &t8);
        E1408_separate(&a->pos, &b->pos, &t8, pool->unk_0);
    }

    if ((a->f138.flags & 0x800000) != 0 || (b->f138.flags & 0x800000) != 0) {
        return 0;
    }
    fn_1_DF6AC(&n, &a->field44, &b->field44, &a->field44, &b->field44, a->field50, b->field50, a->field1C,
               b->field1C, pool->unk_34 * (a->field18 + b->field18), pool->unk_20);
    a->f138.flags |= 0x20000000;
    b->f138.flags |= 0x20000000;
    a->other = b;
    b->other = a;
    return 1;
}
#pragma opt_propagation reset
/* fzgx:end fn_1_E1408 */

/* fzgx:begin fn_1_E1934 */
typedef struct {
    u8 pad0[0x8];
    s16 field8;
    s16 fieldA;
    u8 padC[0x12c];
    u64 field138;
    u8 pad140[0x68];
} Fn1E1934Object;

void fn_1_E1934(Fn1E1934Object *obj, Fn1E1934Object *base, s16 limit) {
    s16 index;

    if ((obj->field138 & 0x40) != 0) {
        return;
    }

    if (obj->fieldA != base->fieldA) {
        index = 0;
    } else {
        index = obj->field8 + 1;
    }

    while ((s16)index < limit) {
        fn_1_E1408(obj, &base[index]);
        index++;
    }
}
/* fzgx:end fn_1_E1934 */

/* fzgx:begin fn_1_E1A00 */
#pragma section code_type ".fzgxpool"
__declspec(section ".fzgxpool") static void fzgx_pool_prime1(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = -1.0f;
    s = 0.9999998807907104f;
    s = 1.0000001192092896f;
    s = -1.0000001192092896f;
    s = -0.9999998807907104f;
    s = 0.0f;
    d = 1.1920928955078125e-07;
}
static const u32 fzgx_pool_table2[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep2(void) { const u32 *volatile cp; cp = fzgx_pool_table2; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime3(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 5.0f;
    s = 1.0f;
}
static const u32 fzgx_pool_table4[1] = {0x00FF00FF};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep4(void) { const u32 *volatile cp; cp = fzgx_pool_table4; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime5(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 0.10000000149011612f;
    s = 0.5f;
    s = 10.0f;
    s = 182.04444885253906f;
    d = 4503599627370496.0;
    s = -0.0027222223579883575f;
}
static const u32 fzgx_pool_table6[9] = {0x00000000, 0x3F800000, 0x00000000, 0x00000000, 0x3F800000, 0x00000000, 0x3F800000, 0x00000000, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep6(void) { const u32 *volatile cp; cp = fzgx_pool_table6; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime7(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 9.58738019107841e-05f;
    s = 1.5f;
    s = -1.1920928955078125e-07f;
    s = 1.1920928955078125e-07f;
    d = 4503601774854144.0;
    s = 60.0f;
    s = 1000000.0f;
    s = 250000.0f;
    s = 20.0f;
}
static const u32 fzgx_pool_table8[6] = {0x00000000, 0x3F800000, 0x00000000, 0x00000000, 0x3F800000, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep8(void) { const u32 *volatile cp; cp = fzgx_pool_table8; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime9(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = -0.009999999776482582f;
    s = 0.009999999776482582f;
    s = -1.0099999904632568f;
    s = 9.999999747378752e-05f;
}
static const u32 fzgx_pool_table10[3] = {0x00000000, 0x3F800000, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep10(void) { const u32 *volatile cp; cp = fzgx_pool_table10; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime11(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 0.9900000095367432f;
    s = 2.0f;
    s = -0.0f;
    d = 216.0;
    d = 3.1415927410125732;
    d = 4.0;
    d = 60.0;
    s = 1.0099999904632568f;
    s = 0.05000000074505806f;
    s = 1.0010000467300415f;
    s = 0.8999999761581421f;
    s = 3.0f;
}
static const u32 fzgx_pool_table12[1] = {0x3FE00000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep12(void) { const u32 *volatile cp; cp = fzgx_pool_table12; }  /* fzgx-allow: S2 pool primer sink */
#pragma section code_type ".text"

extern void fn_1_E57F4(void *, f32);
extern void fn_1_E57FC(void *, void *);
extern void fn_1_E5840(void *, const void *);
extern void fn_1_E5884(void *, void *);
extern void fn_1_E58CC(void *, const void *);
extern void fn_1_E5970(void *, f32);
extern void fn_1_E5978(void *, f32);
extern void fn_1_E5980(void *, f32);
extern void fn_1_E5988(void *, void *);
extern void fn_1_E5A0C(void *, void *);
extern void fn_1_E5A50(void *, void *);
extern void fn_1_E5A94(void *, void *);
extern void fn_1_E5AD8(void *, f32);
extern void fn_80008BA8(void *, void *, u32);
extern f32 lbl_1_rodata_6780[];

typedef struct {
    u8 pad0[0x8];
    s16 field8;
    s16 fieldA;
    u8 padC[0x48];
    f32 field54;
    f32 field58;
    f32 field5C;
    u8 pad60[0xD8];
    u64 field138;
    u8 pad140[0x14];
    u32 field154;
    u32 field158;
    u32 field15C;
} Fn1E1A00Object;

#pragma opt_common_subs on
#pragma opt_strength_reduction off
void fn_1_E1A00(Fn1E1A00Object *obj, u8 *str) {
    struct { const f32 *value; } pool;
    pool.value = lbl_1_rodata_6780;

    while (*str != 0) {
        switch (*str) {
        case 0x65:
            fn_1_E5970(obj, (0.899999976f));
            break;
        case 0x6D:
            fn_1_E5978(obj, (1.0f));
            break;
        case 0x75:
            fn_1_E5980(obj, (0.5f));
            break;
        case 0x6B:
            fn_1_E5AD8(obj, (1.0f));
            break;
        case 0x46:
            fn_1_E5A0C(obj, 0);
            break;
        case 0x61:
            fn_1_E5A50(obj, 0);
            break;
        case 0x76:
            fn_1_E57FC(obj, 0);
            break;
        case 0x70:
            fn_1_E5988(obj, 0);
            if ((obj->field138 & 0x800) == 0 && (obj->field138 & 3) == 0) {
                f32 ten = (10.0f);

                obj->field58 = ten;
                obj->field5C = ten * (f32)obj->field8;
                obj->field54 = (3.0f) * (f32)obj->fieldA;
                fn_80008BA8(&obj->pad60[0], &obj->field54, 12);
            }
            break;
        case 0x77:
            fn_1_E5A94(obj, 0);
            break;
        case 0x72:
            fn_1_E5840(obj, 0);
            break;
        case 0x6E:
            fn_1_E58CC(obj, 0);
            break;
        case 0x66:
            obj->field138 = 0;
            break;
        case 0x73:
            fn_1_E5884(obj, 0);
            break;
        case 0x74:
            fn_1_E57F4(obj, (1.0f));
            break;
        case 0x54:
            obj->field154 = 0;
            obj->field158 = 0;
            obj->field15C = 0;
            break;
        }
        str++;
    }
}
#pragma opt_strength_reduction reset

#pragma opt_common_subs reset
/* fzgx:end fn_1_E1A00 */

/* fzgx:begin fn_1_E3324 */
#include "rel/main_rel/spline.h"

extern s16 fn_1_E5430(s16);
extern void *fn_1_E54A8(s16, s16);
extern void fn_1_E1A00(void *, void *);
extern void fn_1_E2DCC(void);
extern void fn_1_E252C(s16, s16, void *);
extern void fn_1_E2AE8(void);
extern s32 fn_1_7B054(void);
extern void fn_1_E5930(void *, s64);
extern Obj_1_bss_84428 *fn_1_FB0A8(void);
extern void fn_1_E1C10(void);
extern void fn_1_E87A4(f64, f64);
extern const f32 lbl_1_rodata_6994;
extern f32 lbl_1_rodata_6998[13];
extern u8 lbl_1_bss_9C;

/* the retail TU's .bss objects this function uses, at their retail offsets, so MWCC addresses them off one section base */
u8 fzgx_obj_lbl_1_bss_7AE88[0xC];
s16 lbl_1_bss_7AE88__fzgx_offset_C;
u16 fzgx_pool_gap_7AE96;
u32 fzgx_pool_gap_7AE98;
s16 lbl_1_bss_7AE88__fzgx_offset_14;
u16 fzgx_pool_gap_7AE9E;
u32 fzgx_pool_gap_7AEA0[3];
s16 lbl_1_bss_7AE88__fzgx_offset_24;
u16 fzgx_pool_gap_7AEAE;
u32 fzgx_pool_gap_7AEB0;
s16 lbl_1_bss_7AE88__fzgx_offset_2C;
u16 fzgx_pool_gap_7AEB6;
u32 fzgx_obj_lbl_1_bss_7AEB8;

#pragma section code_type ".fzgxpool"
static void fzgx_bss_layout(void) {
    volatile u8 s;  /* fzgx-allow: S2 layout primer sink: MWCC emits .bss objects in first-access order */
    s = *(u8 *)&fzgx_obj_lbl_1_bss_7AE88;
    s = *(u8 *)&lbl_1_bss_7AE88__fzgx_offset_C;
    s = *(u8 *)&fzgx_pool_gap_7AE96;
    s = *(u8 *)&fzgx_pool_gap_7AE98;
    s = *(u8 *)&lbl_1_bss_7AE88__fzgx_offset_14;
    s = *(u8 *)&fzgx_pool_gap_7AE9E;
    s = *(u8 *)&fzgx_pool_gap_7AEA0;
    s = *(u8 *)&lbl_1_bss_7AE88__fzgx_offset_24;
    s = *(u8 *)&fzgx_pool_gap_7AEAE;
    s = *(u8 *)&fzgx_pool_gap_7AEB0;
    s = *(u8 *)&lbl_1_bss_7AE88__fzgx_offset_2C;
    s = *(u8 *)&fzgx_pool_gap_7AEB6;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_7AEB8;
}
#pragma section code_type ".text"

static inline void fn_1_E3324_loop2(void) {
    s16 j;
    s16 n;
    void *p;
    s16 i;
    for (i = 0; i < 6; i++) {
        n = fn_1_E5430(i);
        p = fn_1_E54A8(i, 0);
        for (j = 0; j < n; j++, p = (void *)((u8 *)p + 0x1a8)) {
            fn_1_E252C(i, j, p);
        }
    }
}

/* course header +0xA4/+0xA8: the miscellaneous trigger list (0x24 each); counts the entries whose +0x20 top bit is set */
static inline void fn_1_E3324_count_flagged_misc_triggers(void) {
    s16 i;
    u8 *trigger;
    s16 n;

    n = lbl_1_bss_3BE0->unk_A4;
    lbl_1_bss_7AE88__fzgx_offset_2C = i = 0;
    trigger = (u8 *)lbl_1_bss_3BE0->unk_A8;
    for (; i < n; i++, trigger += 0x24) {
        if (*(u32 *)(trigger + 0x20) & 0x80000000) {
            lbl_1_bss_7AE88__fzgx_offset_2C++;
        }
    }
}

/* course header +0xB4/+0xB8: the story object triggers (0x38 each); counts those whose byte +3 low nibble is the
   story selector (.bss 0x9C+1 in story mode, else 0) */
static inline s32 fn_1_E3324_count_story_triggers(void) {
    u8 *trigger;
    struct { s32 value; } total;
    u8 sel;
    s32 count;
    struct { s16 value; } i;

    trigger = (u8 *)lbl_1_bss_3BE0->unk_B8;
    sel = *(s16 *)&lbl_1_bss_960 == 9 ? (&lbl_1_bss_9C)[1] : 0;
    count = 0;
    total.value = lbl_1_bss_3BE0->unk_B4;
    for (i.value = 0; i.value < total.value; i.value++, trigger += 0x38) {
        if ((u32)(trigger[3] & 0xF) == sel) {
            count++;
        }
    }
    return count;
}

void fn_1_E3324(void) {
    s16 n;
    struct { u8 *value; } name;
    void *p;
    s16 i;
    s16 j;

    switch (lbl_1_data_2B0D4.pad_0[(s16)fn_1_7B054()]) {
    case 13:
        lbl_1_bss_7AE88__fzgx_offset_24 = fn_1_FB0A8()->unk_A;
        break;
    }
    fn_1_E3324_count_flagged_misc_triggers();
    if ((s16)fn_1_7B054() == 37) {
        lbl_1_bss_7AE88__fzgx_offset_C = fn_1_E3324_count_story_triggers();
        lbl_1_bss_7AE88__fzgx_offset_14 = 0;
    } else {
        lbl_1_bss_7AE88__fzgx_offset_C = 0;
        lbl_1_bss_7AE88__fzgx_offset_14 = lbl_1_bss_3BE0->unk_B4;
    }
    fn_1_E1C10();
    name.value = lbl_1_data_3DDA8;
    for (i = 0; i < 6; i++) {
        n = fn_1_E5430(i);
        p = fn_1_E54A8(i, 0);
        for (j = 0; j < n; j++, p = (void *)((u8 *)p + 0x1a8)) {
            fn_1_E1A00(p, name.value);
        }
    }
    fn_1_E2DCC();
    fn_1_E3324_loop2();
    fn_1_E2AE8();
    switch (lbl_1_data_2B0D4.pad_0[(s16)fn_1_7B054()]) {
    case 13:
        for (j = 0; j < (s16)fn_1_E5430(4); j++) {
            fn_1_E5930(fn_1_E54A8(4, j), 3);
        }
        break;
    }
    if (fn_1_E5430(2) != 0) {
        fn_1_E87A4(lbl_1_rodata_6994, lbl_1_rodata_6998[0]);
        fzgx_obj_lbl_1_bss_7AEB8 |= 0x80000000;
    } else {
        fzgx_obj_lbl_1_bss_7AEB8 &= ~0x80000000;
    }
}
/* fzgx:end fn_1_E3324 */

/* fzgx:begin fn_1_E3778 */
extern s16 fn_1_E5430(s16);
extern void *fn_1_E54A8(s16, s16);
extern void fn_1_E1A00(void *, void *);
extern void fn_1_E2DCC(void);
extern void fn_1_E252C(s16, s16, void *);
extern void fn_1_E2AE8(void);
extern s32 fn_1_7B054(void);
extern void fn_1_E5930(void *, s64);


static inline void fn_1_E3778_loop2(void) {
    s16 j;
    s16 n;
    void *p;
    s16 i;
    for (i = 0; i < 6; i++) {
        n = fn_1_E5430(i);
        p = fn_1_E54A8(i, 0);
        for (j = 0; j < n; j++, p = (void *)((u8 *)p + 0x1a8)) {
            fn_1_E252C(i, j, p);
        }
    }
}

static inline void fn_1_E3778_call_fn_1_E1A00(void * a0, void * a1) { fn_1_E1A00(a0, a1); }
void fn_1_E3778(void) {
    s16 n;
    struct { u8 *value; } name;
    void *p;
    s16 i;
    s16 j;

    name.value = lbl_1_data_3DDA8;
    for (i = 0; i < 6; i++) {
        n = fn_1_E5430(i);
        p = fn_1_E54A8(i, 0);
        for (j = 0; j < n; j++, p = (void *)((u8 *)p + 0x1a8)) {
            fn_1_E3778_call_fn_1_E1A00(p, name.value);
        }
    }
    fn_1_E2DCC();
    fn_1_E3778_loop2();
    fn_1_E2AE8();
    switch (lbl_1_data_2B0D4.pad_0[(s16)fn_1_7B054()]) {
    case 13:
        for (j = 0; j < (s16)fn_1_E5430(4); j++) {
            fn_1_E5930(fn_1_E54A8(4, j), 3);
        }
        break;
    }
}
/* fzgx:end fn_1_E3778 */
