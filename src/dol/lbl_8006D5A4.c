#include "types.h"
#include "game/vec3.h"

#pragma fp_contract off

void lbl_8006D5A4(Vec3 *a, Vec3 *b, Vec3 *out, f32 t) {
    out->x = a->x + t * (b->x - a->x);
    out->y = a->y + t * (b->y - a->y);
    out->z = a->z + t * (b->z - a->z);
}
