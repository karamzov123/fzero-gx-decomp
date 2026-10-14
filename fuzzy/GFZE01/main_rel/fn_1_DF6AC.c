/* Non-matching: best partial attempt (76.77% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"
#include "psvec.h"

typedef struct FzVec3 {
    f32 x;
    f32 y;
    f32 z;
} Vec3f;

extern f32 lbl_8006D534(void *, void *);
extern f32 lbl_8006D0B4(f32);
extern void fn_80008BA8(void *, void *, u32);
extern void lbl_8006D5F0(void *, f32);
extern void lbl_8006D668(void *);
extern void fn_80008BEC(void *, int, u32);

static void VecCross(Vec3f *a, Vec3f *b, Vec3f *out) {
    out->x = (f32)(a->y * b->z) - a->z * b->y;
    out->y = (f32)(a->z * b->x) - a->x * b->z;
    out->z = (f32)(a->x * b->y) - a->y * b->x;
}

void fn_1_DF6AC(Vec3f *n, Vec3f *v1, Vec3f *v2, Vec3f *o1, Vec3f *o2, f32 s1, f32 s2, f32 s3, f32 s4, f32 s5) {
    Vec3f G, F, E, D, C, B, A;
    f32 d, s, d2, s2b, lg, lf, c1, c2;

    d = lbl_8006D534(v1, n);
    s = lbl_8006D0B4(1.0f - (f32)(d * d));
    fn_80008BA8(&G, n, 0xC);
    lbl_8006D5F0(&G, s1 * d);
    fn_80008BA8(&B, v1, 0xC);

    VecCross(&B, n, &E);
    VecCross(&E, n, &E);
    if ((f32)(E.x * E.x) + E.y * E.y + E.z * E.z > 0.0f) {
        lbl_8006D668(&E);
    }
    c1 = (f32)(B.x * E.x) + B.y * E.y + B.z * E.z;
    if (!(c1 > 0.0f)) {
        psvec_scale(&E, -1.0f, &E);
    }
    psvec_scale(&E, s1 * s, &E);

    d2 = lbl_8006D534(v2, n);
    s2b = lbl_8006D0B4(1.0f - (f32)(d2 * d2));
    fn_80008BA8(&F, n, 0xC);
    lbl_8006D5F0(&F, s2 * d2);
    fn_80008BA8(&A, v2, 0xC);

    VecCross(&A, n, &D);
    VecCross(&D, n, &D);
    if ((f32)(D.x * D.x) + D.y * D.y + D.z * D.z > 0.0f) {
        lbl_8006D668(&D);
    }
    c1 = (f32)(A.x * D.x) + A.y * D.y + A.z * D.z;
    if (!(c1 > 0.0f)) {
        psvec_scale(&D, -1.0f, &D);
    }
    psvec_scale(&D, s2 * s2b, &D);

    lg = lbl_8006D0B4((f32)(G.x * G.x) + G.y * G.y + G.z * G.z);
    lf = lbl_8006D0B4((f32)(F.x * F.x) + F.y * F.y + F.z * F.z);

    c1 = (lg * ((1.0f + s5) * s3) + lf * (s4 - s3 * s5)) / (s3 + s4);
    c2 = c1 - s5 * (lg - lf);

    if (0.0f != (f32)(G.x * G.x) + G.y * G.y + G.z * G.z) {
        fn_80008BA8(&C, &G, 0xC);
    } else if (0.0f != (f32)(F.x * F.x) + F.y * F.y + F.z * F.z) {
        fn_80008BA8(&C, &F, 0xC);
    } else {
        fn_80008BEC(o1, 0, 0xC);
        fn_80008BEC(o2, 0, 0xC);
        return;
    }

    lbl_8006D668(&C);
    psvec_scale(&C, c2, &G);
    psvec_scale(&C, c1, &F);
    psvec_add(&G, &E, o1);
    psvec_add(&F, &D, o2);
}
