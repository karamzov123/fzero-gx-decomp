#include "types.h"
#include "rel/main_rel/globals.h"
#include "rel/main_rel/spline.h"
#include "dolphin/hw_regs.h"
#include "psvec.h"
#include "rel/main_rel/bg_cas.h"

extern s32 fn_1_58C4(void);
extern void fn_1_5948(s32);
extern void fn_1_627C(s32);
extern void fn_80008BA8(void *dst, const void *src, u32 size);
extern void fn_80008BEC(void *dst, int value, u32 size);
extern void fn_80072864(u32);
extern void fn_800734A8(u32, s32, s32, s32);
extern void fn_80073678(u32);
extern void fn_80073C6C(s32);
extern void fn_800745A4(u32, s32, s32, u32, u32, u32);
extern void fn_80074660(u32);
extern void fn_80074788(u32);
extern void fn_80074918(u8, s32, u8);

extern void fn_1_9A508(Obj_1_data_2A7E0 *arg0);
extern void fn_1_9AD88(void);
extern void fn_1_76BF8(void);
extern void fn_1_72648(void);
extern void fn_1_FB0B4(Obj_1_bss_84428 *data);
extern void fn_1_FB180(int *value);
extern void fn_1_9AD54(void);
extern void fn_1_FB18C(void);

extern u32 lbl_801A66A0;

extern void lbl_8006DB74(void *);
extern void OSPanic(const char *, int, const char *, ...);
extern void lbl_8006E13C(void *);
extern void lbl_8006E0A4(void *);

typedef struct SplineEntry {
    u8 pad0[0x104];
    u32 f104;
    u8 pad1[0xC];
    u32 f114;
    u8 pad2[0xC];
    u32 f124;
    u8 pad3[0xC];
    u32 f134;
    u8 pad4[0xC];
    u32 f144;
    u8 pad5[0xC];
    u32 f154;
    u8 pad6[0xC];
    f32 f164;
} SplineEntry;

typedef struct SplineMain {
    u8 pad0[4];
    u8 unk_4;
    u8 pad5[0x163];
    f32 unk_168;
} SplineMain;

void fn_1_FA89C(SplineMain *arg0);

Obj_1_bss_84428 lbl_1_bss_84428;

Obj_1_data_3EED0 lbl_1_data_3EED0 = {
    0x00U,
    0x01U,
    0x03U,
    0x02U,
    {0x3FU, 0x80U, 0x00U, 0x00U, 0x00U, 0x00U, 0x00U, 0x00U, 0x00U, 0x00U, 0x00U, 0x00U, 0x00U, 0x04U, 0x05U, 0x01U, 0x00U, 0x00U, 0x00U, 0x00U, 0x3FU, 0x80U, 0x00U, 0x00U, 0x00U, 0x00U, 0x00U, 0x00U, 0x00U, 0x02U, 0x06U, 0x04U, 0x00U, 0x00U, 0x00U, 0x00U, 0x00U, 0x00U, 0x00U, 0x00U, 0x3FU, 0x80U, 0x00U, 0x00U, 0x04U, 0x06U, 0x07U, 0x05U, 0xBFU, 0x80U, 0x00U, 0x00U, 0x00U, 0x00U, 0x00U, 0x00U, 0x00U, 0x00U, 0x00U, 0x00U, 0x02U, 0x03U, 0x07U, 0x06U, 0x00U, 0x00U, 0x00U, 0x00U, 0xBFU, 0x80U, 0x00U, 0x00U, 0x00U, 0x00U, 0x00U, 0x00U, 0x01U, 0x05U, 0x07U, 0x03U, 0x00U, 0x00U, 0x00U, 0x00U, 0x00U, 0x00U, 0x00U, 0x00U, 0xBFU, 0x80U, 0x00U, 0x00U}
};

Obj_1_data_3EF30 lbl_1_data_3EF30 = {
    0x3F800000U,
    0x3F800000U,
    0x3F800000U,
    {0x3FU, 0x80U, 0x00U, 0x00U, 0x3FU, 0x80U, 0x00U, 0x00U, 0xBFU, 0x80U, 0x00U, 0x00U, 0x3FU, 0x80U, 0x00U, 0x00U, 0xBFU, 0x80U, 0x00U, 0x00U, 0x3FU, 0x80U, 0x00U, 0x00U, 0x3FU, 0x80U, 0x00U, 0x00U, 0xBFU, 0x80U, 0x00U, 0x00U, 0xBFU, 0x80U, 0x00U, 0x00U, 0xBFU, 0x80U, 0x00U, 0x00U, 0x3FU, 0x80U, 0x00U, 0x00U, 0x3FU, 0x80U, 0x00U, 0x00U, 0xBFU, 0x80U, 0x00U, 0x00U, 0x3FU, 0x80U, 0x00U, 0x00U, 0xBFU, 0x80U, 0x00U, 0x00U, 0xBFU, 0x80U, 0x00U, 0x00U, 0xBFU, 0x80U, 0x00U, 0x00U, 0x3FU, 0x80U, 0x00U, 0x00U, 0xBFU, 0x80U, 0x00U, 0x00U, 0xBFU, 0x80U, 0x00U, 0x00U, 0xBFU, 0x80U, 0x00U, 0x00U}
};

/* fzgx:begin fn_1_FA6C0 */
extern u32 fn_1_76504(s32, void *, s32);
extern u32 lbl_801A63D0;
extern void fn_1_7269C(u32, u32, void *);
extern void fn_1_72768(u32, u32);
extern void fn_1_FAB40(void);

void fn_1_FA6C0(void) {
    u32 local[4] = {0, 0x028001E0, 0, 1};
    Obj_1_data_2A7E0_At3C *obj = lbl_1_data_2A7E0.unk_3C;

    obj->unk_16C = (u8)fn_1_76504(35, local, 0);
    fn_1_7269C((u8)obj->unk_16C, 0, (void *)lbl_801A63D0);
    fn_1_72768((u8)obj->unk_16C, (u32)fn_1_FAB40);
}
/* fzgx:end fn_1_FA6C0 */

/* fzgx:begin fn_1_FA75C */
extern void fn_1_76BF8(void);
extern void fn_1_72648(void);
extern void fn_1_9A508(Obj_1_data_2A7E0 *arg0);
extern void fn_1_FB0B4(Obj_1_bss_84428 *data);
extern void fn_1_FB180(int *value);

// Reset spline state while preserving the active spline entry.
void fn_1_FA75C(void) {
    s32 spline_index;
    Obj_1_data_2A7E0_At3C *obj;
    u8 *status;
    u32 saved_entry;

    spline_index = fn_1_58C4();
    obj = lbl_1_data_2A7E0.unk_3C;
    status = (u8 *)&obj->unk_4;
    saved_entry = obj->unk_170;
    fn_80008BEC(obj, 0, 0x174);
    obj->unk_170 = saved_entry;

    if (obj->unk_170 != 0 && spline_index <= 1) {
        fn_1_FA89C((SplineMain *)obj);
    } else {
        fn_1_76BF8();
        fn_1_72648();
        *status = 0;
    }

    obj->unk_0 = -1;
    {
        extern void fn_1_9A508(void);
        fn_1_9A508();
    }
    fn_1_FB0B4(&lbl_1_bss_84428);
    fn_1_FB180((int *)&lbl_1_bss_84428);

    if (*status == 0) {
        fn_1_76BF8();
        fn_1_72648();
        *status = 0;
    }
}
/* fzgx:end fn_1_FA75C */

/* fzgx:begin fn_1_FA82C */
// fn_1_FA82C: empty in retail (single blr).
void fn_1_FA82C(void) {
}
/* fzgx:end fn_1_FA82C */

/* fzgx:begin fn_1_FA830 */
void fn_1_FA830(void) {
    fn_1_9AD54();
    fn_1_FB18C();
}
/* fzgx:end fn_1_FA830 */

/* fzgx:begin fn_1_FA854 */
void fn_1_FA854(void) {
    fn_1_76BF8();
    fn_1_72648();
}
/* fzgx:end fn_1_FA854 */

/* fzgx:begin fn_1_FA878 */
void fn_1_FA878(void) {
    fn_1_9AD88();
}
/* fzgx:end fn_1_FA878 */

/* fzgx:begin fn_1_FA898 */
// fn_1_FA898: empty in retail (single blr).
void fn_1_FA898(void) {
}
/* fzgx:end fn_1_FA898 */

/* fzgx:begin fn_1_FA89C */
extern u32 __cvt_fp2unsigned(f64);
extern void fn_1_A714C(f32 *, f32 *, f32 *, f32 *);
extern void C_MTXLightPerspective(f32 *, f32, f32, f32, f32, f32, f32);
extern void GXGetScissor(u32 *, u32 *, u32 *, u32 *);


void fn_1_FA89C(SplineMain *arg0) {
    SplineEntry *v4;
    u8 *v3;
    f32 v1;
    u32 v7;
    u32 v5;
    u32 v8;
    u32 v6;
    s32 v2;
    SplineEntry *v0;
    s16 v9;
    s16 v10;
    f32 v11;
    f32 v12;
    f32 v13;
    f32 v14;
    f32 v15;
    f32 v16;
    f32 sp14;
    f32 sp10;
    f32 spC;
    f32 sp8;
    int t0;
    u32 t3;
    u32 t4;

    t0 = fn_1_58C4();
    v0 = (SplineEntry *)((u8 *)arg0 + 4);
    v1 = 1.0f;
    arg0->unk_4 = 0;
    arg0->unk_168 = v1;
    v2 = 0;
    v4 = v0;
    v3 = (u8 *)v0;
    while (v2 < t0) {
        fn_1_5948(v2);
        GXGetScissor(&v4->f104, &v4->f114, &v4->f124, &v4->f134);
        t3 = (v4->f124 / v0->f164);
        v4->f144 = t3;
        t4 = (v4->f134 / v0->f164);
        v4->f154 = t4;
        v5 = v4->f124;
        v6 = v4->f134;
        v7 = v4->f104;
        v8 = v4->f114;
        v9 = (v7 + (v5 >> 1));
        v10 = (v8 + (v6 >> 1));
        v11 = ((f32)(s16)v7 / v9);
        v12 = (s16)v8;
        v13 = (v11 - v1);
        v14 = ((v12 / v10) - v1);
        fn_1_A714C(&sp14, &sp10, &spC, &sp8);
        v15 = ((((f32)(s16)(v8 + v6) / v10) - v1) - v14);
        v16 = ((((f32)(s16)(v7 + v5) / v9) - v1) - v13);
        C_MTXLightPerspective((f32 *)(((0x44) + v3)), sp14, sp10, (v1 / v16), (-1.0f / v15), ((-v13) / v16), ((-v14) / v15));
        fn_1_627C(v2);
        v4 = (SplineEntry *)((u8 *)v4 + 4);
        v3 += 0x30;
        v2++;
    }
}
/* fzgx:end fn_1_FA89C */

/* fzgx:begin fn_1_FAB40 */
#include "game/vec3.h"

typedef struct {
    f32 value0, value4, value8;
} Sig_fn_8006F900_Fn8006F900Data;

extern Obj_1_data_3EED0 lbl_1_data_3EED0;
extern Obj_1_data_3EF30 lbl_1_data_3EF30;
extern u32 lbl_801A6D00;
extern s32 fn_1_5910(void);
extern s16 fn_1_3F0C8(void);
extern void fn_1_681C(u32, Vec3 *);
extern s32 fn_1_54E34(void *, f32);
extern void fn_1_76BD0(u8, u8);
extern void *fn_1_72714(u8, u32);
extern f32 fn_1_A71AC(void);
extern void fn_1_55FF0(f32);
extern void fn_1_556B8(void *);
extern void lbl_8006DCA4(void);
extern void lbl_8006E0A4(void *);
extern void mathutil_mtxA_rotate_z(s32);
extern void mathutil_mtxA_rotate_y(s32);
extern void mathutil_mtxA_rotate_x(s32);
extern void lbl_8006E14C(f32);
extern void lbl_8006E13C(void *);
extern void fn_80072558(void);
extern void fn_800724C8(void);
extern void fn_80073778(void *, s32);
extern void fn_80072EDC(s32, s32);
extern void fn_80073898(u32);
extern void fn_8007245C(u32);
extern void fn_800728A8(s32, s32, s32, s32);
extern void lbl_8006DAEC(void);
extern void lbl_8006DBE4(void);
extern void fn_8006F900(Vec3 *, Sig_fn_8006F900_Fn8006F900Data *, f32);
extern void lbl_8006D7F4(f32, f32, f32);
extern void lbl_8006DB74(void *);
extern void lbl_8006DB30(void);
extern void lbl_8006DFD8(void *);
extern u32 GXLoadTexMtxImm(u32, u32, u32);
extern void fn_8003462C(u32, u32, u32);
extern void lbl_8006DC20(void);


typedef struct {
    u32 flags;
    u32 mask;
    u32 unk8;
    Vec3 origin;
    s16 rx, ry, rz;
    s16 pad1e;
    Vec3 scale;
} DrawRecord;

typedef struct {
    u8 count;
    u8 pad1[3];
    DrawRecord *records[16];
    f32 matrix[4][12];
    u8 pad104[0x64];
    u32 image;
} DrawList;

/* WARNING: compiler-diff device, not original code */
/* Preserve the retail multiply operand order after inlining. */
static inline f32 fn_1_FAB40_operand(f32 right, f32 left) { return left * right; }
/* The early return exits both visibility loops without an extra branch. */
static inline void visibility(u8 *selected, DrawList *list, Vec3 *pos) {
    s32 count;
    /* WARNING: compiler-diff device, not original code */
    /* Scalarized index and explicit cursor preserve distinct register homes. */
    struct { s32 value; } j;
    s32 i;
    u8 *scan;
    DrawRecord *record;
    Vec3 *origin;
    f32 dx, dy, dz;
    count = fn_1_58C4();
    for (i = 0; i < count; i++) {
        fn_1_5948(i);
        lbl_8006DCA4();
        fn_1_681C((u8)i, pos);
        for (scan = (u8 *)list, j.value = 0; j.value < list->count; scan += 4, j.value++) {
            record = *(DrawRecord **)(scan + 4);
            if ((record->mask == -1U || (record->mask & lbl_1_data_2A7E0.unk_50)) &&
                (record->flags & lbl_1_data_2A7E0.unk_4C)) {
                origin = &record->origin;
                dx = pos->x;
                dx = dx - origin->x;
                dy = pos->y - origin->y;
                dz = pos->z - origin->z;
                if ((f32)(dx * dx) + dy * dy + dz * dz < (490000.0f) &&
                    fn_1_54E34(origin, (20.0f))) {
                    *selected = 0;
                    return;
                }
            }
        }
    }
}

void fn_1_FAB40(void) {
    Vec3 vertices[4];
    f32 matrix[12];
    Vec3 pos;
    Sig_fn_8006F900_Fn8006F900Data transformed;
    Vec3 center;
    Obj_1_data_2A7E0_At3C *obj;
    /* WARNING: compiler-diff device, not original code */
    struct { u8 value; } selected;
    s32 count;
    DrawList *list;
    s32 j;
    DrawRecord *record_2;
    u8 *indices;
    Vec3 *points;
    /* Unsigned address induction, with the retail signed loop comparison. */
    u32 i;
    s32 k;

    obj = lbl_1_data_2A7E0.unk_3C;
    list = (DrawList *)((u8 *)obj + 4);
    fn_1_5910();
    if (list->count == 0)
        return;
    if (fn_1_3F0C8() == 45)
        return;
    selected.value = 1;
    visibility(&selected.value, list, &pos);
    fn_1_76BD0(obj->unk_16C, selected.value);
    count = fn_1_58C4();
    for (i = 0; (s32)i < count; i++) {
        fn_1_5948(i);
        for (j = 0; j < list->count; j++) {
            record_2 = list->records[j];
            if ((record_2->mask == -1U || (record_2->mask & lbl_1_data_2A7E0.unk_50)) &&
                (record_2->flags & lbl_1_data_2A7E0.unk_4C)) {
                lbl_8006DCA4();
                lbl_8006E0A4(&record_2->origin);
                mathutil_mtxA_rotate_z(record_2->rz);
                mathutil_mtxA_rotate_y(record_2->ry);
                mathutil_mtxA_rotate_x(record_2->rx);
                mathutil_mtxA_rotate_z(0x1c71);
                mathutil_mtxA_rotate_y(0);
                mathutil_mtxA_rotate_x(0x2000);
                lbl_8006E14C((13.0f));
                lbl_8006E13C(&record_2->scale);
                fn_80072558();
                fn_800724C8();
                fn_80073778(fn_1_72714(list->image, 0), 0);
                fn_80072864(2);
                fn_800745A4(0, 0, 0, 30, 0, 125);
                fn_800734A8(0, 0, 0, 255);
                fn_80072EDC(0, 3);
                fn_80073C6C(0);
                fn_80073678(1);
                fn_80074660(1);
                fn_80073898(0);
                fn_80074788(0);
                fn_8007245C(512);
                fn_80074918(1, 3, 0);
                fn_800728A8(1, 4, 0, 0);
                lbl_8006DAEC();
                indices = (u8 *)&lbl_1_data_3EED0;
                points = (Vec3 *)&lbl_1_data_3EF30;
                for (k = 0; k < 6; k++) {
                    lbl_8006DBE4();
                    vertices[0] = points[indices[k * 16]];
                    vertices[1] = points[indices[k * 16 + 1]];
                    vertices[2] = points[indices[k * 16 + 2]];
                    vertices[3] = points[indices[k * 16 + 3]];
                    center.x = fn_1_FAB40_operand(0.5f, vertices[0].x + vertices[2].x);
                    center.y = fn_1_FAB40_operand(0.5f, vertices[0].y + vertices[2].y);
                    center.z = fn_1_FAB40_operand(0.5f, vertices[0].z + vertices[2].z);
                    fn_8006F900(&center, &transformed, fn_1_A71AC());
                    lbl_8006DAEC();
                    lbl_8006D7F4(50.0 * -transformed.value0,
                                10.0 * -transformed.value4,
                                (0.0f));
                    lbl_8006DB74(matrix);
                    lbl_8006DB30();
                    lbl_8006DFD8(matrix);
                    lbl_8006DFD8((list->matrix[i]));
                    GXLoadTexMtxImm(lbl_801A6D00, 30, 0);
                    fn_8003462C(128, 0, 4);
                    /* fzgx-allow: S2 GX FIFO stores must remain ordered hardware writes. */
                    #define FIFO (*(volatile f32 *)GX_FIFO_BASE)
                    FIFO = vertices[0].x;
                    FIFO = vertices[0].y;
                    FIFO = vertices[0].z;
                    FIFO = vertices[1].x;
                    FIFO = vertices[1].y;
                    FIFO = vertices[1].z;
                    FIFO = vertices[2].x;
                    FIFO = vertices[2].y;
                    FIFO = vertices[2].z;
                    FIFO = vertices[3].x;
                    FIFO = vertices[3].y;
                    FIFO = vertices[3].z;
                    #undef FIFO
                }
                lbl_8006DC20();
                if (obj->unk_170) {
                    fn_80074918(1, 3, 1);
                    lbl_8006DCA4();
                    lbl_8006E0A4(&record_2->origin);
                    mathutil_mtxA_rotate_z(record_2->rz);
                    mathutil_mtxA_rotate_y(record_2->ry);
                    mathutil_mtxA_rotate_x(record_2->rx);
                    lbl_8006E13C(&record_2->scale);
                    fn_80072558();
                    fn_1_55FF0((0.5f));
                    fn_1_556B8((void *)obj->unk_170);
                    fn_1_55FF0((1.0f));
                }
            }
        }
        fn_1_627C(i);
    }
}
/* fzgx:end fn_1_FAB40 */

/* fzgx:begin fn_1_FB0A8 */
Obj_1_bss_84428 *fn_1_FB0A8(void) {
    return &lbl_1_bss_84428;
}

typedef struct {
    f32 x, y, z;
} SplineVec;
/* fzgx:end fn_1_FB0A8 */

/* fzgx:begin fn_1_FB0B4 */
void fn_1_FB0B4(Obj_1_bss_84428 *data) {
    SplineVec first = {0.0f, 20.0f, 0.0f};
    SplineVec second = {20.0f, 0.0f, 0.0f};

    data->unk_0 = 0;
    data->unk_4 = -1;
    lbl_1_bss_84428.unk_6 = 3;
    lbl_1_bss_84428.unk_8 = 20;
    lbl_1_bss_84428.unk_A = 0;
    lbl_1_bss_84428.unk_C = 30;

    fn_80008BA8((u8 *)&lbl_1_bss_84428 + 0x10, &first, 0xc);
    fn_80008BA8((u8 *)&lbl_1_bss_84428 + 0x1c, &second, 0xc);
}
/* fzgx:end fn_1_FB0B4 */

/* fzgx:begin fn_1_FB180 */
// Set the destination value to one.
void fn_1_FB180(int *value) {
    *value = 1;
}
/* fzgx:end fn_1_FB180 */

/* fzgx:begin fn_1_FB18C */
typedef struct {
    u8 pad_0[0x8];
    s16 unk_8;
    u8 pad_A[0xE];
    f32 unk_18;
    u8 pad_1C[0x3C];
    f32 unk_58;
    u8 pad_5C[0x28];
    f32 unk_84;
    u8 pad_88[0x6C];
    f32 unk_F4;
    u8 pad_F8[0x5C];
    u32 unk_154;
} SplineObj;

extern u32 lbl_801A63C0;
extern u32 lbl_801A66A0;

extern s16 fn_1_E5430(s16);
extern SplineObj *fn_1_E54A8(s16, s16);
extern s32 fn_1_E5770(SplineObj *, u64);
extern void fn_1_E5930(SplineObj *, u64);
extern void fn_1_E594C(SplineObj *, u64);
extern s16 fn_1_E5568(s16);
extern u32 fn_1_DE180(SplineObj *, SplineVec *, f32);
/* retail evaluates the float argument before the object at both call sites */
extern void fn_1_E57F4(f32, SplineObj *);
extern void fn_1_E5988(SplineObj *, SplineVec *);
extern void fn_1_E5A94(SplineObj *, SplineVec *);
extern void fn_1_E57FC(SplineObj *, SplineVec *);


static inline s32 spline_rand(void) {
    lbl_801A63C0 = lbl_801A63C0 * 0x676A4B6B + 0x33CB;
    return (lbl_801A63C0 >> 16) & 0x7FFF;
}

static inline f32 spline_clamp01(f32 x) {
    return (x < 0.0f) ? 0.0f : ((x > 1.0f) ? 1.0f : x);
}

/* Fade pass: age every object and fade it out over its last 30 frames. */
static inline void spline_fade_pass(void) {
    s16 i2;
    SplineObj *obj2;
    s16 n;
    f32 limit;
    f32 rem;
    f32 t;

    n = fn_1_E5430(4);
    for (i2 = 0; i2 < n; i2++) {
        obj2 = fn_1_E54A8(4, i2);
        if (!fn_1_E5770(obj2, 3)) {
            obj2->unk_154++;
        }
        limit = (obj2->unk_8 % 4 == 0) ? 240.0f : 120.0f;
        if (obj2->unk_154 > limit) {
            obj2->unk_154 = 0;
            fn_1_E5930(obj2, 3);
        } else {
            rem = limit - obj2->unk_154;
            if (rem < 30.0f) {
                t = rem / 30.0f;
                fn_1_E57F4(spline_clamp01(t), obj2);
            }
        }
    }
}

/* Spawn scan over the n objects, starting at the running spawn count. */
static inline void spline_spawn_loop(s16 n) {
    /* Unused preset table: retail keeps its initializer in the literal pool. */
    Obj_1_bss_84428 presets[3] = {{1}, {1, 300, 5, 5, 200}, {1, 600, 3, 20, 500}};
    s16 i3;
    s16 count;
    SplineObj *obj3;

    count = 0;
    for (i3 = count; i3 < n; i3++) {
        obj3 = fn_1_E54A8(4, i3);
        if (fn_1_E5770(obj3, 3) && count < lbl_1_bss_84428.unk_8 && fn_1_E5568(4) < lbl_1_bss_84428.unk_A) {
            SplineVec out;
            SplineVec tmp;
            SplineVec scale;
            SplineVec rot;
            f32 dx;
            f32 dy;
            f32 dz;

            fn_1_E594C(obj3, 3);
            fn_1_E594C(obj3, 0x8000);
            fn_1_E57F4(1.0f, obj3);
            obj3->unk_154 = 0;

            /* position: box center offset by a random point of the box */
            psvec_scale(&lbl_1_bss_84428.unk_1C, -0.5f, &tmp);
            dx = lbl_1_bss_84428.unk_1C * (spline_rand() / 32767.0f);
            dy = lbl_1_bss_84428.unk_20 * (spline_rand() / 32767.0f);
            dz = lbl_1_bss_84428.unk_24 * (spline_rand() / 32767.0f);
            tmp.x += dx;
            tmp.y += dy;
            tmp.z += dz;
            psvec_add((u8 *)&lbl_1_bss_84428 + 0x10, &tmp, &out);
            fn_1_E5988(obj3, &out);

            rot.x = 0.05235988f * (spline_rand() % 2 + 2);
            rot.y = 0.05235988f * (spline_rand() % 2 + 2);
            rot.z = 0.05235988f * (spline_rand() % 2 + 2);
            fn_1_E5A94(obj3, &rot);

            fn_80008BEC(&scale, 0, sizeof(scale));
            scale.z = (spline_rand() % 180 + 30) / 216.0;
            fn_1_E57FC(obj3, &scale);
            count++;
        }
    }
}

/* WARNING: compiler-diff device, not original code */
/* Retail pools the spawn literals before fn_1_FB18C's own initializer. */
#pragma section code_type ".fzgxpool"
void fzgx_pool_primer3(f32 *f, f64 *d) {
    f[0] = -0.5f;
    f[1] = 32767.0f;
    f[2] = 0.05235988f;
    d[0] = 216.0;
}
#pragma section code_type ".text"

void fn_1_FB18C(void) {
    SplineObj *obj1;
    s16 i1;
    s16 n;
    f32 v;
    f32 base;

    n = fn_1_E5430(4);
    {
        SplineVec up = {0.0f, 1.0f, 0.0f};

        base = 0.0f;
        for (i1 = 0; i1 < n; i1++) {
            obj1 = fn_1_E54A8(4, i1);
            if (fn_1_E5770(obj1, 0x20)) {
                v = 0.99f * obj1->unk_84 * obj1->unk_F4;
                if (obj1->unk_58 < base + v) {
                    obj1->unk_58 = base + v;
                    fn_1_DE180(obj1, &up, 0.05f * obj1->unk_18);
                    fn_1_E5930(obj1, 0x40000000);
                }
            }
        }
    }

    spline_fade_pass();

    if ((s32)lbl_1_bss_84428.unk_0 == 1) {
        if (lbl_1_bss_84428.unk_4 != -1) {
            lbl_1_bss_84428.unk_4 = (lbl_1_bss_84428.unk_4-- > 0) ? lbl_1_bss_84428.unk_4-- : 0;
        }
        if (lbl_1_bss_84428.unk_4 == 0) {
            lbl_1_bss_84428.unk_0 = 0;
        }

        n = fn_1_E5430(4);
        if (lbl_801A66A0 % lbl_1_bss_84428.unk_6 == 0) {
            spline_spawn_loop(n);
        }
    }
}
/* fzgx:end fn_1_FB18C */

/* fzgx:begin fn_1_FB770 */
int fn_1_FB770(int flag, u32 *value) {
    Obj_1_data_2A7E0_At3C *object = lbl_1_data_2A7E0.unk_3C;

    switch (flag) {
    case 0:
        object->unk_170 = *value;
        break;
    default:
        break;
    }

    return 1;
    return 1;
}
/* fzgx:end fn_1_FB770 */

/* fzgx:begin fn_1_FB798 */
int fn_1_FB798(int mode, u32 *value) {
    Obj_1_data_2A7E0_At3C *entry = lbl_1_data_2A7E0.unk_3C;

    switch (mode) {
    case 0: {
        u8 *cursor = (u8 *)lbl_1_bss_3BE0->unk_54;
        entry->unk_0 = 0;
        while (cursor != (u8 *)value) {
            u32 count = entry->unk_0;
            cursor += 0x40;
            entry->unk_0 = count + 1;
        }
        *value |= 0x80000000;
        break;
    }

    case 1: {
        u8 *p = (u8 *)entry + 4;
        ((u32 *)(p + 4))[*p] = (u32)value;
        *(u8 *)p = *(u8 *)p + 1;
        *value |= 0x80000000;
        if (*p >= 0x10) {
            OSPanic("bg_cas.c", 0x2f2, "DICE OVER!");
        }
        break;
    }
    }

    return 1;
}
/* fzgx:end fn_1_FB798 */
