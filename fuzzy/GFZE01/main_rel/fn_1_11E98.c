/* Non-matching: best partial attempt (96.47% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"

typedef struct {
    f32 x;
    f32 y;
    f32 z;
} F3;
typedef struct {
    s32 x;
    u32 y;
    u32 z;
} U3;

extern s32 lbl_1_bss_17F8;
extern u32 lbl_1_data_4440[0x44];
extern u32 lbl_801A63C0;
extern u16 fn_1_86624(void);
extern u32 fn_1_FCB0(u8 *);
extern void fn_1_862D4(s32, void *);
extern void fn_1_8636C(s32, void *);
extern void lbl_8006DD14(void *, void *);
extern void lbl_8006DC6C(void *);
extern void lbl_8006E1B0(void *, void *);
extern f32 lbl_1_rodata_648[26];
extern u32 lbl_1_rodata_63C[3];

#define QX (((F3 *)&q)->x)
#define QY (((F3 *)&q)->y)
#define QZ (((F3 *)&q)->z)

#pragma opt_dead_assignments off
#pragma opt_lifetimes off
#pragma opt_propagation off
#pragma opt_strength_reduction off
static inline void fn_1_11E98_call_fn_1_862D4(s32 a0, void * a1) { fn_1_862D4(a0, a1); }
void fn_1_11E98(u8 *cam) {
    U3 q;
    F3 v;
    f32 dy_2;
    U3 vec;
    u32 obj[14];
    f32 dx;
    f32 dz_2;
    u32 i;
    f32 dy_2_2;
    f32 dx_2;
    f32 dz;
    f32 dy;
    f32 best;

    if ((s8)fn_1_86624() == 1) {
        fn_1_FCB0(cam);
    }

    if (*cam == 5 || *cam <= 1 || *cam == 2) {
        lbl_801A63C0 = lbl_801A63C0 * 0x676A4B6B + 0x33CB;
        *(s16 *)(cam + 0x14) = *(s16 *)(cam + 4) = (s16)((lbl_801A63C0 >> 1) & 0x7FFF);
    }

    fn_1_862D4(*(s16 *)(cam + 6), &q);

    if (*(s16 *)(cam + 6) == lbl_1_bss_17F8) {
        lbl_1_bss_17F8 = (lbl_1_bss_17F8 + 1) % (s8)fn_1_86624();
    }

    fn_1_11E98_call_fn_1_862D4(lbl_1_bss_17F8, &v);
    dx = v.x;
    dx -= QX;
    dy = v.y;
    dy -= QY;
    dz = v.z;
    dz -= QZ;
    dx = (f32)(dx * dx) + dy * dy + dz * dz;
    best = dx;

    for (i = 0; i < (u32)(s8)fn_1_86624(); i++) {
        if (i == (u32)*(s16 *)(cam + 6)) {
            continue;
        }

        fn_1_862D4(i, &v);
        dx = v.x;
        dx -= QX;
        dy_2 = v.y;
        dy_2 -= QY;
        dz = v.z;
        dz -= QZ;
        dx = (f32)(dx * dx) + dy_2 * dy_2 + dz * dz;

        if (best < dx) {
            continue;
        }

        best = dx;
        lbl_1_bss_17F8 = i;
    }

    if (best > lbl_1_rodata_648[0]) {
        *(s16 *)(cam + 0x12) = 0;
        *(u32 *)(cam + 0x18) = 1;
        ((void (**)(u8 *))lbl_1_data_4440)[*(s16 *)(cam + 0x12)](cam);
    } else {
        fn_1_8636C(lbl_1_bss_17F8, obj);
        lbl_8006DD14(obj, cam + 0x7c);
        fn_1_862D4(lbl_1_bss_17F8, &v);
        lbl_8006DC6C(obj);

        dx_2 = v.x;
        dy_2_2 = v.y;
        dz_2 = v.z;
        *(f32 *)(0xE0000000 + 0x0C) = dx_2;
        *(f32 *)(0xE0000000 + 0x1C) = dy_2_2;
        *(f32 *)(0xE0000000 + 0x2C) = dz_2;

        vec.x = lbl_1_rodata_63C[0];
        vec.y = lbl_1_rodata_63C[1];
        vec.z = lbl_1_rodata_63C[2];
        lbl_8006E1B0(&vec, (cam + 0x1c));

        *(U3 *)(cam + 0x4c) = q;
    }
}
#pragma opt_strength_reduction reset

#pragma opt_propagation reset

#pragma opt_lifetimes reset

#pragma opt_dead_assignments reset
