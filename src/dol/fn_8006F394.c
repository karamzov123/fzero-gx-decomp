#include "types.h"
extern const f32 lbl_801A73F4;
extern s16 lbl_8006D24C(f32, f32);
typedef struct { f32 x, y, z; } Vec3;
#pragma opt_dead_assignments off
#pragma opt_dead_code off
u16 fn_8006F394(void) {
    /* Preserve the three stack stores observed in retail, including unused y. */
    volatile Vec3 v;
    f32 a, b, c;
    f32 scale = lbl_801A73F4;
    a = *(f32 *)(0xE0000000 + 8);
    c = *(f32 *)(0xE0000000 + 0x28);
    b = *(f32 *)(0xE0000000 + 0x18);
    a *= scale;
    c *= scale;
    b *= scale;
    v.x = a;
    v.y = b;
    v.z = c;
    return lbl_8006D24C(a, c);
}
#pragma opt_dead_assignments reset
