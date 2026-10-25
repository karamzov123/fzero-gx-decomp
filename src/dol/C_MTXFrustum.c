#include "types.h"

extern const f32 lbl_801A6F60;
extern const f32 lbl_801A6F64;
extern const f32 lbl_801A6F68;
extern const f32 lbl_801A6F6C;

struct fn_80015D7C_Matrix {
    f32 m[16];
};

static inline f32 fn_80015D7C_operand(f32 right, f32 left) { return left * right; }
void C_MTXFrustum(struct fn_80015D7C_Matrix *out, f32 a, f32 b, f32 c, f32 d, f32 e, f32 f) {
    f32 tmp;
    f32 t2;

    t2 = lbl_801A6F64 * e;
    tmp = lbl_801A6F60 / (d - c);
    out->m[0] = t2 * tmp;
    out->m[1] = lbl_801A6F68;
    out->m[2] = (d + c) * tmp;
    out->m[3] = lbl_801A6F68;
    out->m[4] = lbl_801A6F68;
    tmp = lbl_801A6F60 / (a - b);
    out->m[5] = fn_80015D7C_operand((tmp), (lbl_801A6F64 * e));
    out->m[6] = (a + b) * tmp;
    out->m[7] = lbl_801A6F68;
    out->m[8] = lbl_801A6F68;
    out->m[9] = lbl_801A6F68;
    tmp = lbl_801A6F60 / (f - e);
    out->m[10] = -e * tmp;
    out->m[11] = -(f * e) * tmp;
    out->m[12] = lbl_801A6F68;
    out->m[13] = lbl_801A6F68;
    out->m[14] = lbl_801A6F6C;
    (*((15) + (out->m))) = lbl_801A6F68;
}
