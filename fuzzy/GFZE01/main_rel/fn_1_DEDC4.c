/* Non-matching: best partial attempt (75.83% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"
#include "psvec.h"

typedef struct Vec3 {
    f32 x;
    f32 y;
    f32 z;
} Vec3;

typedef struct UVec3 {
    u32 x;
    u32 y;
    u32 z;
} UVec3;

struct fn_1_DEDC4_lbl_1_rodata_6780 {
    f32 unk_0;
    f32 unk_4;
    f32 unk_8;
    f32 unk_C;
    f32 unk_10;
    u8 pad_14[0xC];
    f32 unk_20;
    u8 pad_24[0x80];
    u32 unk_A4;
    u32 unk_A8;
    u32 unk_AC;
    f32 unk_B0;
    f32 unk_B4;
    f32 unk_B8;
    f32 unk_BC;
};

extern struct fn_1_DEDC4_lbl_1_rodata_6780 lbl_1_rodata_6780;
extern void fn_80008BEC(void *, int, int);
extern void lbl_8006DBAC(void *);
extern void fn_8006E2B0(void *, void *);
extern f32 lbl_8006D534(void *, void *);
extern void lbl_8006D5F0(void *, void *, f32);
extern void fn_8006E250(void *, void *);
extern f32 lbl_8006D0E8(f32);
extern void lbl_8006D668(void *);
extern void lbl_8006E1C0(void *, void *);

int fn_1_DEDC4(Vec3 *arg0, Vec3 *arg1, void *arg2, Vec3 *arg3, Vec3 *arg4, Vec3 *arg5, Vec3 *arg6, f32 arg7) {
    struct fn_1_DEDC4_lbl_1_rodata_6780 *pool = &lbl_1_rodata_6780;
    UVec3 loc50;
    Vec3 loc44;
    Vec3 loc38;
    Vec3 loc2c;
    Vec3 diff;
    f32 dot;
    f32 metric;
    f32 t;
    s32 side;
    s32 orientation;

    loc50.x = pool->unk_A4;
    loc50.y = pool->unk_A8;
    loc50.z = pool->unk_AC;
    fn_80008BEC(arg6, 0, 12);
    dot = arg4->x * arg3->x + arg4->y * arg3->y + arg4->z * arg3->z;
    metric = arg4->x * arg0->x + arg4->y * arg0->y + arg4->z * arg0->z;
    t = arg4->x * arg1->x + arg4->y * arg1->y + arg4->z * arg1->z;
    dot = (-dot + metric) * (-dot + t);
    if (dot < pool->unk_B0) {
        side = -1;
    } else if (dot > pool->unk_B4) {
        side = 1;
    } else {
        side = 0;
    }

    psvec_sub(arg1, arg3, &diff);
    t = diff.x * arg4->x + diff.y * arg4->y + diff.z * arg4->z;
    lbl_8006DBAC(arg6);
    fn_8006E2B0(arg4, &loc44);
    orientation = (s32)lbl_8006D534(&loc44, &loc50);
    if (pool->unk_4 <= orientation && pool->unk_8 >= orientation) {
        orientation = 1;
    } else if (pool->unk_C <= orientation && pool->unk_10 >= orientation) {
        orientation = -1;
    } else {
        orientation = 0;
    }

    if (orientation != 0) {
        if (side > 0) return 0;
        lbl_8006D5F0(arg4, arg5, pool->unk_B8 * t);
        return 1;
    }

    fn_8006E250(arg3, &loc38);
    if (side >= 0) {
        if (t > arg7) return 0;
        dot = loc44.y * loc38.y + loc44.x * loc38.x + loc44.z * loc38.z;
        metric = -dot;
        dot = __fabs(metric) * lbl_8006D0E8(metric);
        if (dot > arg7) return 0;
        loc44.z = 0.0f;
        lbl_8006D668(&loc44);
        psvec_scale(&loc44, arg7, arg6);
        metric = (loc44.x * arg6->x + loc44.z * arg6->z) - metric;
        metric = metric * metric;
        if (metric > 0.0f) psvec_scale(arg6, pool->unk_0, arg6);
        lbl_8006E1C0(arg6, &loc2c);
        psvec_sub(&loc2c, arg3, &diff);
        dot = diff.x * arg4->x + diff.y * arg4->y + diff.z * arg4->z;
        psvec_scale(arg4, pool->unk_BC * dot, arg5);
    } else {
        dot = loc44.y * loc38.y + loc44.x * loc38.x + loc44.z * loc38.z;
        metric = -dot;
        dot = __fabs(metric) * lbl_8006D0E8(metric);
        loc44.z = 0.0f;
        lbl_8006D668(&loc44);
        psvec_scale(&loc44, arg7, arg6);
        if (dot >= arg7) {
            metric = (loc44.x * arg6->x + loc44.z * arg6->z) - metric;
            if (metric <= 0.0f) psvec_scale(arg6, pool->unk_0, arg6);
        } else {
            psvec_scale(arg6, pool->unk_0, arg6);
        }
        lbl_8006E1C0(arg6, &loc2c);
        psvec_sub(&loc2c, arg3, &diff);
        dot = diff.x * arg4->x + diff.y * arg4->y + diff.z * arg4->z;
        psvec_scale(arg4, pool->unk_BC * dot, arg5);
    }
    return 3;
}
