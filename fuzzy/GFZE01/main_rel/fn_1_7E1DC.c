/* Non-matching: best partial attempt (43.22% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"
#include "rel/main_rel/globals.h"
#include "rel/main_rel/car_test.h"

extern const f32 lbl_1_rodata_33A8;
extern u32 lbl_801A6CE0;
extern u32 lbl_1_bss_38454;
extern void fn_1_57714(s32);
extern void fn_1_57720(s32, s32, s32, s32);
typedef struct { f32 x, y, z; } Vec3;
extern void fn_1_5773C(Vec3 *, Vec3 *, u8 *);
extern void fn_1_57810(s32, Vec3 *, u8 *);
extern void fn_1_7BCCC(u32 *);
extern void fn_1_7BB80(void *, s32);
extern void fn_1_7BD6C(s32);
extern void lbl_8006D758(void);
extern void lbl_8006DCA4(void);
extern void mathutil_mtxA_rotate_y(s32);
extern void mathutil_mtxA_rotate_z(s32);
extern void lbl_8006E1B0(void *, void *);
extern void lbl_8006E0A4(void *);
extern void fn_80072558(void);
extern void fn_80077F8C(void *, f32, f32, f32);
extern void *memcpy(void *, const void *, u32);
extern void fn_80035680(void *, f32, f32, f32);
extern void fn_80035690(f32, f32, f32, void *);
extern void fn_80035420(void *, f32, s32);
extern void fn_800356AC(void *, void *);
extern void GXInitLightDistAttn(void *, f32, f32, s32);
extern void fn_80074CF4(f32, f32, f32);

void fn_1_7E1DC(f32 arg0, f32 arg1, f32 arg2) {
    Vec3 v, temp;
    f32 pos[3];
    f32 matrix[16];
    f32 points[20][3], points2[20][3];
    f32 light[16];
    u32 a[3];
    u8 b[4];
    u32 state;
    s32 i;

    state = *(u32 *)((u8 *)lbl_1_bss_6D7E8 + 0);
    if (*(u32 *)((u8 *)state + 0x20) & 0x40000000)
        return;

    if (((*(u16 *)((u8 *)&lbl_1_bss_9F8 + 0x16) >> 4) & 1)) {
        u32 obj = *(u32 *)((u8 *)state + 0x1c);
        s16 angle = *(s16 *)((u8 *)obj + 8);
        *(s16 *)((u8 *)obj + 8) = angle + 182;
    }
    if (((*(u16 *)((u8 *)&lbl_1_bss_9F8 + 0x16) >> 5) & 1))
        *(s16 *)(*(u32 *)((u8 *)*(u32 *)((u8 *)lbl_1_bss_6D7E8) + 0x1c) + 8) -= 183;
    if (((*(u16 *)((u8 *)&lbl_1_bss_9F8 + 0x16) >> 7) & 1))
        *(s16 *)(*(u32 *)((u8 *)*(u32 *)((u8 *)lbl_1_bss_6D7E8) + 0x1c) + 10) += 182;
    if (((*(u16 *)((u8 *)&lbl_1_bss_9F8 + 0x16) >> 6) & 1))
        *(s16 *)(*(u32 *)((u8 *)*(u32 *)((u8 *)lbl_1_bss_6D7E8) + 0x1c) + 10) -= 183;
    if (((*(u16 *)((u8 *)&lbl_1_bss_9F8 + 0x16) >> 8) & 1))
        *(f32 *)(*(u32 *)((u8 *)*(u32 *)((u8 *)lbl_1_bss_6D7E8) + 0x1c) + 4) += 0.1f;
    if (((*(u16 *)((u8 *)&lbl_1_bss_9F8 + 0x16) >> 9) & 1))
        *(f32 *)(*(u32 *)((u8 *)*(u32 *)((u8 *)lbl_1_bss_6D7E8) + 0x1c) + 4) -= 0.1f;

    state = *(u32 *)((u8 *)lbl_1_bss_6D7E8);
    {
        u32 obj = *(u32 *)((u8 *)state + 0x1c);
        s16 x = *(s16 *)((u8 *)obj + 8), y = *(s16 *)((u8 *)obj + 10);
        *(s16 *)((u8 *)obj + 8) = (x << 16) >> 16;
        *(s16 *)((u8 *)obj + 10) = (y << 16) >> 16;
        if (*(f32 *)((u8 *)obj + 4) < 0.01f)
            *(f32 *)((u8 *)obj + 4) = 0.01f;
        else if (*(f32 *)((u8 *)obj + 4) > 17.320507f)
            *(f32 *)((u8 *)obj + 4) = 17.320507f;
    }
    if (((*(u16 *)((u8 *)&lbl_1_bss_9F8 + 0x1c) >> 9) & 1)) {
        u32 obj = *(u32 *)((u8 *)*(u32 *)((u8 *)lbl_1_bss_6D7E8) + 0x1c);
        *(f32 *)((u8 *)obj + 4) = 17.320507f;
        *(s16 *)((u8 *)obj + 8) = -8192;
        *(s16 *)((u8 *)obj + 10) = 8192;
    }
    state = *(u32 *)((u8 *)lbl_1_bss_6D7E8);
    pos[0] = *(f32 *)((u8 *)*(u32 *)((u8 *)state + 0x1c) + 4);
    pos[1] = pos[2] = 0.0f;
    lbl_8006D758();
    mathutil_mtxA_rotate_y(*(s16 *)((u8 *)*(u32 *)((u8 *)*(u32 *)((u8 *)lbl_1_bss_6D7E8) + 0x1c) + 8));
    mathutil_mtxA_rotate_z(*(s16 *)((u8 *)*(u32 *)((u8 *)*(u32 *)((u8 *)lbl_1_bss_6D7E8) + 0x1c) + 10));
    lbl_8006E1B0(&v, &v);
    if (((*(u16 *)((u8 *)&lbl_1_bss_9F8 + 0x16) & 0x1e00) != 0) || ((*(u16 *)((u8 *)&lbl_1_bss_9F8 + 0x14) >> 8) & 1)) {
        a[0] = 0; a[1] = 0; a[2] = 0;
        b[0] = 0;
        lbl_8006DCA4();
        fn_1_57714(6);
        fn_1_57720(1,1,1,0);
        fn_1_5773C((Vec3 *)a, &v, b);
        lbl_8006E0A4(&v);
        fn_80072558();
        if (lbl_801A6CE0 & 1)
            fn_80077F8C((void *)(*(u32 *)((u8 *)*(u32 *)((u8 *)lbl_1_bss_38454 + 8) + 0x20)), arg0,arg1,arg2);
        for (i=0; i<20; i++) {
            lbl_8006D758();
            mathutil_mtxA_rotate_y((s32)(182.04445f * (f32)i));
            mathutil_mtxA_rotate_z(*(s16 *)((u8 *)*(u32 *)((u8 *)*(u32 *)((u8 *)lbl_1_bss_6D7E8) + 0x1c) + 10));
            lbl_8006E1B0(pos, points[i]);
        }
        memcpy(matrix, points, 12);
        lbl_8006DCA4();
        fn_1_57810(21, (Vec3 *)points, b);
        for (i=0; i<20; i++) {
            lbl_8006D758();
            mathutil_mtxA_rotate_y(*(s16 *)((u8 *)*(u32 *)((u8 *)*(u32 *)((u8 *)lbl_1_bss_6D7E8) + 0x1c) + 8));
            mathutil_mtxA_rotate_z((s32)(182.04445f * (f32)i));
            lbl_8006E1B0(pos, points2[i]);
        }
        memcpy(matrix, points2, 12);
        lbl_8006DCA4();
        fn_1_57810(21, (Vec3 *)points, b);
    }
    lbl_8006DCA4();
    lbl_8006E1B0(&v, &v);
    fn_1_7BCCC((u32 *)&v);
    fn_80035680(light, v.x, v.y, v.z);
    fn_80035690(v.x, v.y, v.z, light);
    fn_80035420(light, 0.0f, 0);
    b[0] = *(u8 *)*(u32 *)((u8 *)*(u32 *)((u8 *)*(u32 *)((u8 *)lbl_1_bss_6D7E8 + 0) + 0x1c) + 0);
    fn_800356AC(light, b);
    GXInitLightDistAttn(light, 0.0f, 0.0f, 0);
    fn_1_7BB80(light, 1);
    fn_1_7BD6C(1);
    fn_80074CF4(0.6f, 0.6f, 0.6f);
}
