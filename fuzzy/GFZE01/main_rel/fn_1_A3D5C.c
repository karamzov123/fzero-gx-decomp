/* Non-matching: best partial attempt (50.43% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"

typedef struct {
    u32 x;
    u32 y;
    u32 z;
} Sig_fn_1_862D4_Triple;

typedef struct {
    s16 ang;
    u8 buf[14];
} fn_1_A3D5C_Out;

extern int camera_get_mode(void);
extern void fn_1_862D4(void *, Sig_fn_1_862D4_Triple *);
extern u8 fn_1_5910(void);
extern void fn_1_681C(u32, u32 *);
extern f32 fn_1_8652C(u32);
extern u32 lbl_8006DCA4(void);
extern u32 lbl_8006E1B0(void *, void *);
extern void fn_8006EF10(void *, s16 *, s16 *);
extern f32 lbl_8006D188(u32);
extern int fn_1_58C4(void);
extern u32 OSGetSoundMode(void);
extern f32 lbl_1_rodata_4470;
extern f32 lbl_1_rodata_4474;
extern f32 lbl_1_rodata_4550;
extern f32 lbl_1_rodata_4554;
extern f32 lbl_1_rodata_4558;
extern f32 lbl_1_rodata_455C;
extern f32 lbl_1_rodata_4560;
extern f32 lbl_1_rodata_4564;
extern f32 lbl_1_rodata_4568;
extern f32 lbl_1_rodata_456C;
extern f32 lbl_1_rodata_4570;
extern f32 lbl_1_rodata_4574;
extern f32 lbl_1_rodata_4578;
extern f64 lbl_1_rodata_42F0;
extern f64 lbl_1_rodata_4580;

#define PSQ(x) ((s16)((u16)(s32)((x) * 65536.0f) + 0x4000))
#define ABS(a) (((a) ^ ((a) >> 31)) - ((a) >> 31))

u8 fn_1_A3D5C(void *arg0, void *arg1, void *arg2, void *arg3) {
    s16 mode;
    f32 adj;
    f32 q29;
    f32 q30;
    f32 dist;
    f32 dx;
    f32 dy;
    f32 dz;
    f32 t;
    struct {
        u32 a[4];
    } v30;
    Sig_fn_1_862D4_Triple v24;
    f32 p18[3];
    fn_1_A3D5C_Out out;

    mode = (s16)camera_get_mode();
    fn_1_862D4(arg0, &v24);
    fn_1_681C((u32)(fn_1_5910() & 0xFF), (u32 *)p18);
    dx = p18[0] - *(f32 *)&v24.x;
    dy = p18[1] - *(f32 *)&v24.y;
    dz = p18[2] - *(f32 *)&v24.z;
    dist = (f32)(dx * dx) + dy * dy + dz * dz;

    if (dist > lbl_1_rodata_4550) {
        *(u8 *)arg1 = 0;
        *(u8 *)arg2 = 0;
        *(u8 *)arg3 = 0;
        return 0;
    }

    lbl_8006DCA4();
    lbl_8006E1B0(&v24, &v30);
    fn_8006EF10(&v30, (s16 *)&out.buf[0], &out.ang);

    adj = fn_1_8652C((u32)arg0);
    if (mode != -1) {
        dx = lbl_1_rodata_4558 * (f32)(adj - fn_1_8652C((u32)mode));
        if (dx < lbl_1_rodata_4554) {
            dx = lbl_1_rodata_4554;
        } else if (dx > lbl_1_rodata_4470) {
            dx = lbl_1_rodata_4470;
        }
        if (dx < lbl_1_rodata_4474) {
            adj = lbl_1_rodata_4470 - lbl_8006D188((u32)(s16)(lbl_1_rodata_455C * (f32)(lbl_1_rodata_4560 * (f32)(-dx))));
        } else {
            adj = lbl_1_rodata_4470 + lbl_8006D188((u32)(s16)(lbl_1_rodata_455C * (f32)(lbl_1_rodata_4560 * dx)));
        }
    } else {
        adj = lbl_1_rodata_4470;
    }

    t = lbl_1_rodata_455C * (f32)(lbl_1_rodata_4560 * (f32)(dist / lbl_1_rodata_4550));
    q29 = lbl_8006D188((u32)PSQ(t));

    dy = lbl_1_rodata_4564 * (f32)(adj * (q29 * q29));
    if (dy < lbl_1_rodata_4474) {
        dy = lbl_1_rodata_4474;
    } else if (dy > lbl_1_rodata_4564) {
        dy = lbl_1_rodata_4564;
    }
    q29 = dy;

    dx = lbl_1_rodata_4470 - (f32)(dist / lbl_1_rodata_4568);
    dz = dx;
    if (dz < lbl_1_rodata_4474) {
        dz = lbl_1_rodata_4474;
    } else if (dz > lbl_1_rodata_4470) {
        dz = lbl_1_rodata_4470;
    }
    q30 = lbl_1_rodata_4564 * dz;

    switch (fn_1_58C4()) {
    case 2:
        q29 = q29 * lbl_1_rodata_456C;
        q30 = q30 * lbl_1_rodata_456C;
        break;
    case 3:
        q29 = q29 * lbl_1_rodata_4570;
        q30 = q30 * lbl_1_rodata_4570;
        break;
    case 4:
        q29 = q29 * lbl_1_rodata_4574;
        q30 = q30 * lbl_1_rodata_4574;
        break;
    }

    mode = (s16)(u8)((u16)PSQ(q29) >> 8);
    *(u8 *)arg3 = (u8)((u16)PSQ(q30) >> 8);

    if (ABS(out.ang) < 0x4000) {
        *(u8 *)arg1 = (u8)(s32)((f32)(-out.ang) * lbl_1_rodata_4578);
    } else if (out.ang > 0) {
        *(u8 *)arg1 = (u8)(s32)((f32)(out.ang - 0x8000) * lbl_1_rodata_4578);
    } else {
        *(u8 *)arg1 = (u8)(s32)((f32)out.ang * lbl_1_rodata_4578);
    }

    *(u8 *)arg2 = (u8)(s32)((f64)(ABS(out.ang) - 0x4000) * lbl_1_rodata_4580);

    {
        s8 t8 = *(s8 *)arg1;
        if (t8 < -0x40) {
            t8 = -0x40;
        } else if (t8 > 0x3f) {
            t8 = 0x3f;
        }
        *(s8 *)arg1 = t8;
    }
    {
        s8 t8 = *(s8 *)arg2;
        if (t8 < -0x40) {
            t8 = -0x40;
        } else if (t8 > 0x3f) {
            t8 = 0x3f;
        }
        *(s8 *)arg2 = t8;
    }

    if (OSGetSoundMode() == 0) {
        *(u8 *)arg1 = 0;
    }

    return (u8)mode;
}
