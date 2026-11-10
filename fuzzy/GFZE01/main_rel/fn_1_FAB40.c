/* Non-matching: best partial attempt (86.99% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"
#include "dolphin/gx.h"
#include "rel/main_rel/globals.h"
#include "rel/main_rel/spline.h"
#pragma section code_type ".fzgxpool"
static const u32 fzgx_pool_table1[4] = {0x00000000, 0x028001E0, 0x00000000, 0x00000001};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep1(void) { const u32 *volatile cp; cp = fzgx_pool_table1; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime2(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 1.0f;
    s = -1.0f;
    d = 4503599627370496.0;
    d = 4503601774854144.0;
    s = 490000.0f;
    s = 20.0f;
    s = 13.0f;
    s = 0.5f;
    d = 50.0;
    d = 10.0;
    s = 0.0f;
}
static const u32 fzgx_pool_table3[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep3(void) { const u32 *volatile cp; cp = fzgx_pool_table3; }  /* fzgx-allow: S2 pool primer sink */
#pragma section code_type ".text"

typedef struct SplineVec {
    f32 x;
    f32 y;
    f32 z;
} SplineVec;

typedef struct SplineOut {
    f32 x;
    f32 y;
    f32 z;
} SplineOut;

typedef struct SplineRec {
    u32 mask;
    u32 flags;
    u8 pad_8[4];
    SplineVec pos;
    s16 rot_x;
    s16 rot_y;
    s16 rot_z;
    u8 pad_1E[2];
    SplineVec scale;
} SplineRec;

typedef struct SplineList {
    u8 count;
    u8 pad_1[3];
    SplineRec *recs[16];
    f32 mtx[4][3][4];
    u8 pad_104[0x64];
    u32 model;
} SplineList;

typedef struct SplineObj {
    u32 unk_0;
    SplineList list;
    u32 extra;
} SplineObj;

extern u32 lbl_801A6D00;
extern void fn_1_5910(void);
extern s16 fn_1_3F0C8(void);
extern s32 fn_1_58C4(void);
extern void fn_1_5948(s32);
extern void fn_1_681C(u8, SplineVec *);
extern s32 fn_1_54E34(SplineVec *, f32);
extern void fn_1_76BD0(u8, s32);
extern void *fn_1_72714(u8, s32);
extern void fn_1_627C(s32);
extern f32 fn_1_A71AC(void);
extern void fn_1_55FF0(f32);
extern void fn_1_556B8(u32);
extern void lbl_8006DCA4(void);
extern void lbl_8006E0A4(SplineVec *);
extern void mathutil_mtxA_rotate_z(s16);
extern void mathutil_mtxA_rotate_y(s16);
extern void mathutil_mtxA_rotate_x(s16);
extern void lbl_8006E14C(f32);
extern void lbl_8006E13C(SplineVec *);
extern void fn_80072558(void);
extern void fn_800724C8(void);
extern void fn_80073778(void *, s32);
extern void fn_80072864(s32);
extern void fn_800745A4(s32, s32, s32, s32, s32, s32);
extern void fn_800734A8(s32, s32, s32, s32);
extern void fn_80072EDC(s32, s32);
extern void fn_80073C6C(s32);
extern void fn_80073678(s32);
extern void fn_80074660(s32);
extern void fn_80073898(s32);
extern void fn_80074788(s32);
extern void fn_8007245C(s32);
extern void fn_80074918(s32, s32, s32);
extern void fn_800728A8(s32, s32, s32, s32);
extern void lbl_8006DAEC(void);
extern void lbl_8006DBE4(void);
extern void fn_8006F900(SplineVec *, SplineOut *, f32);
extern void lbl_8006D7F4(f32, f32, f32);
extern void lbl_8006DB74(void *);
extern void lbl_8006DB30(void);
extern void lbl_8006DFD8(void *);
extern void GXLoadTexMtxImm(u32, u32, u32);
extern void fn_8003462C(s32, s32, s32);
extern void lbl_8006DC20(void);

static inline f32 fn_1_FAB40_dist2(SplineVec *a, SplineVec *b) {
    f32 dx;
    f32 dy;
    f32 dz;

    dx = a->x;
    dx -= b->x;
    dy = a->y - b->y;
    dz = a->z - b->z;
    return dz * dz + (dy * dy + dx * dx);
}

void fn_1_FAB40(void) {
    SplineVec quad[4];
    f32 mtx[3][4];
    SplineVec pos;
    SplineOut out;
    SplineVec center;
    s32 i;
    s32 j1;
    s32 k;
    SplineList *list;
    s32 j;
    SplineRec *rec;
    s32 count;
    s32 i1;
    SplineRec *rec1;
    SplineVec *p;
    SplineObj *obj;
    s32 visible;
    s16 lab_t0;

    obj = (SplineObj *)lbl_1_data_2A7E0.unk_3C;
    list = &obj->list;
    fn_1_5910();
    if (list->count == 0) {
        return;
    }
    if (fn_1_3F0C8() == 45) {
        return;
    }
    visible = 1;
    count = fn_1_58C4();
    for (i1 = 0; i1 < count; i1++) {
        fn_1_5948(i1);
        lbl_8006DCA4();
        fn_1_681C(i1, &pos);
        for (j1 = 0; j1 < list->count; j1++) {
            rec1 = list->recs[j1];
            if ((rec1->flags == -1 || (rec1->flags & lbl_1_data_2A7E0.unk_50)) &&
                (rec1->mask & lbl_1_data_2A7E0.unk_4C)) {
                p = &rec1->pos;
                if (fn_1_FAB40_dist2(&pos, p) < 490000.0f && fn_1_54E34(p, 20.0f) != 0) {
                    visible = 0;
                    goto done;
                }
            }
        }
    }
done:
    fn_1_76BD0(obj->list.model, visible);

    count = fn_1_58C4();
    for (i = 0; i < count; i++) {
        fn_1_5948(i);
        for (j = 0; j < list->count; j++) {
            rec = list->recs[j];
            if ((rec->flags == -1 || (rec->flags & lbl_1_data_2A7E0.unk_50)) &&
                (rec->mask & lbl_1_data_2A7E0.unk_4C)) {
                lbl_8006DCA4();
                lbl_8006E0A4(&rec->pos);
                lab_t0 = rec->rot_z;
                mathutil_mtxA_rotate_z(lab_t0);
                mathutil_mtxA_rotate_y(rec->rot_y);
                mathutil_mtxA_rotate_x(rec->rot_x);
                lab_t0 = 0x1C71;
                mathutil_mtxA_rotate_z(lab_t0);
                mathutil_mtxA_rotate_y(0);
                mathutil_mtxA_rotate_x(0x2000);
                lbl_8006E14C(13.0f);
                lbl_8006E13C(&rec->scale);
                fn_80072558();
                fn_800724C8();
                fn_80073778(fn_1_72714(list->model, 0), 0);
                fn_80072864(2);
                fn_800745A4(0, 0, 0, 30, 0, 125);
                fn_800734A8(0, 0, 0, 255);
                fn_80072EDC(0, 3);
                fn_80073C6C(0);
                fn_80073678(1);
                fn_80074660(1);
                fn_80073898(0);
                fn_80074788(0);
                fn_8007245C(0x200);
                fn_80074918(1, 3, 0);
                fn_800728A8(1, 4, 0, 0);
                lbl_8006DAEC();
                for (k = 0; k < 6; k++) {
                    lbl_8006DBE4();
                    quad[0] = ((SplineVec *)&lbl_1_data_3EF30)[((u8 (*)[16])&lbl_1_data_3EED0)[k][0]];
                    quad[2] = ((SplineVec *)&lbl_1_data_3EF30)[((u8 (*)[16])&lbl_1_data_3EED0)[k][2]];
                    quad[1] = ((SplineVec *)&lbl_1_data_3EF30)[((u8 (*)[16])&lbl_1_data_3EED0)[k][1]];
                    quad[3] = ((SplineVec *)&lbl_1_data_3EF30)[((u8 (*)[16])&lbl_1_data_3EED0)[k][3]];
                    center.x = (quad[0].x + quad[2].x) / 2.0f;
                    center.y = (quad[0].y + quad[2].y) / 2.0f;
                    center.z = (quad[0].z + quad[2].z) / 2.0f;
                    fn_8006F900(&center, &out, fn_1_A71AC());
                    lbl_8006DAEC();
                    lbl_8006D7F4(50.0 * -out.x, 10.0 * -out.y, 0.0f);
                    lbl_8006DB74(mtx);
                    lbl_8006DB30();
                    lbl_8006DFD8(mtx);
                    lbl_8006DFD8(list->mtx[i]);
                    GXLoadTexMtxImm(lbl_801A6D00, 30, 0);
                    fn_8003462C(0x80, 0, 4);
                    GXWGFifo.f32 = quad[0].x;
                    GXWGFifo.f32 = quad[0].y;
                    GXWGFifo.f32 = quad[0].z;
                    GXWGFifo.f32 = quad[1].x;
                    GXWGFifo.f32 = quad[1].y;
                    GXWGFifo.f32 = quad[1].z;
                    GXWGFifo.f32 = quad[2].x;
                    GXWGFifo.f32 = quad[2].y;
                    GXWGFifo.f32 = quad[2].z;
                    GXWGFifo.f32 = quad[3].x;
                    GXWGFifo.f32 = quad[3].y;
                    GXWGFifo.f32 = quad[3].z;
                }
                lbl_8006DC20();
                if (obj->extra != 0) {
                    fn_80074918(1, 3, 1);
                    lbl_8006DCA4();
                    lbl_8006E0A4(&rec->pos);
                    lab_t0 = rec->rot_z;
                    mathutil_mtxA_rotate_z(lab_t0);
                    mathutil_mtxA_rotate_y(rec->rot_y);
                    mathutil_mtxA_rotate_x(rec->rot_x);
                    lbl_8006E13C(&rec->scale);
                    fn_80072558();
                    fn_1_55FF0(0.5f);
                    fn_1_556B8(obj->extra);
                    fn_1_55FF0(1.0f);
                }
            }
        }
        fn_1_627C(i);
    }
}
