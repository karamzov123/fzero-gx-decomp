#include "types.h"

extern void lbl_8006DAEC(void);
extern const f32 lbl_801A73F0;
extern const f32 lbl_801A73F4;
extern const f32 lbl_801A73F8;
extern void lbl_8006E1C0(void *, void *);
extern s16 lbl_8006D24C(f32, f32);
extern f32 lbl_8006D0B4(f32);
extern void lbl_8006D8D8(s16);
extern void mathutil_mtxA_rotate_x(s16);
extern void fn_8006E2B0(void *, void *);
extern void lbl_8006DB30(void);

typedef struct { f32 x, y, z; } Vec3;
typedef struct { Vec3 dir; Vec3 up; } DirUp;

#pragma opt_common_subs off
#pragma opt_lifetimes off
#pragma opt_dead_assignments off
void fn_8006F4E0(s16 *arg0) {
    DirUp v;
    lbl_8006DAEC();
    v.up.x = lbl_801A73F0;
    v.up.y = lbl_801A73F4;
    v.up.z = lbl_801A73F0;
    {
        f32 a, b, c;
        f32 scale = lbl_801A73F8;
        a = *(f32 *)(0xE0000000 + 0x08) * scale;
        b = *(f32 *)(0xE0000000 + 0x18) * scale;
        c = *(f32 *)(0xE0000000 + 0x28) * scale;
        v.dir.x = a;
        v.dir.y = b;
        v.dir.z = c;
    }
    lbl_8006E1C0(&v.up, &v.up);
    {
        f32 z;
        f32 x;
        f32 magnitude;
        x = v.dir.x;
        z = v.dir.z;
        magnitude = x * x;
        magnitude += z * z;
        arg0[0] = lbl_8006D24C(v.dir.y, lbl_8006D0B4(magnitude));
    }
    arg0[1] = lbl_8006D24C(v.dir.x, v.dir.z) - 0x8000;
    lbl_8006D8D8(arg0[1]);
    mathutil_mtxA_rotate_x(arg0[0]);
    fn_8006E2B0(&v.up, &v.up);
    arg0[2] = -lbl_8006D24C(v.up.x, v.up.y);
    lbl_8006DB30();
}
#pragma opt_dead_assignments reset
