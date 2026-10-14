/* Non-matching: best partial attempt (89.15% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"

typedef struct {
    f32 x;
    f32 y;
    f32 z;
} Vec3;

extern const f32 lbl_801A73F4;
extern s16 lbl_8006D24C(f32, f32);

u16 fn_8006F394(void) {
    Vec3 v;
    Vec3 *p = &v;

    p->x = *(f32 *)(0xE0000000 + 0x08) * lbl_801A73F4;
    p->z = *(f32 *)(0xE0000000 + 0x28) * lbl_801A73F4;
    p->y = *(f32 *)(0xE0000000 + 0x18) * lbl_801A73F4;

    return (u16)lbl_8006D24C(p->x, p->z);
}
