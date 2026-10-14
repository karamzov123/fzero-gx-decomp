/* Non-matching: best partial attempt (36.70% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"
#include "rel/main_rel/globals.h"
#include "rel/main_rel/camera.h"

typedef struct { f32 x, y, z; } Vec3;
typedef struct {
    u8 pad0[4]; u8 unk4; u8 pad5[0x27]; f32 unk2C; u8 pad30[8]; u8 unk38; u8 unk39;
} Obj1010;
typedef struct {
    u8 pad0[0xC]; f32 f0C; u32 w10, w14, w18, w1C, w20, w24;
    f64 f28, f30, f38, f40, f48, f50, f58, f60, f68, f70, f78, f80;
} Pool;
extern Pool lbl_1_rodata_400;
extern void fn_1_C770(void);
extern void fn_8006EDBC(Vec3 *, Vec3 *, s16 *, s16 *);
extern void lbl_8006D7DC(void *);
extern void mathutil_mtxA_rotate_y(s16);
extern void mathutil_mtxA_rotate_x(s16);
extern void mathutil_mtxA_rotate_z(s16);
extern void lbl_8006E1B0(void *);
extern void fn_8006E250(void *);
extern f32 lbl_8006D0E8(f32);
extern f32 lbl_8006D0B4(f32);

void fn_1_B870(void) {
    Pool *pool = &lbl_1_rodata_400;
    Obj1010 *state = (Obj1010 *)&lbl_1_bss_1010;
    Vec3 *pos;
    Vec3 *look;
    Vec3 a, b;
    s16 rx, ry;
    f32 dist, scale, x, y, z;
    s32 step, dir;
    u16 flags;
    f64 d;

    if ((lbl_1_bss_D58.unk_8 & 0x20) != 0)
        state->unk38 ^= 1;
    if (state->unk4 != 0) {
        fn_1_C770();
        return;
    }
    pos = (Vec3 *)((u8 *)state + 12);
    look = (Vec3 *)((u8 *)state + 24);
    fn_8006EDBC(pos, look, &rx, &ry);
    d = (f64)(u32)lbl_1_bss_A48.unk_4;
    scale = (f32)((pool->f28 * state->unk2C) *
                  (pool->f30 + (pool->f38 * (d - pool->f78)) / pool->f40));
    if (scale > (f32)pool->f48)
        scale = (f32)pool->f48;
    if (state->unk39 != 0 && (lbl_1_bss_9F8.unk_0 & 0x40) == 0) {
        x = (f32)((f32)((s8)lbl_1_bss_A48.unk_0) * scale) / (f32)pool->f50;
        if ((lbl_1_bss_9F8.unk_2 & 0x200) != 0)
            y = (f32)((f32)((s8)lbl_1_bss_A48.unk_1) * scale) / (f32)pool->f50;
        else
            z = (f32)((f32)((s8)lbl_1_bss_A48.unk_1) * -scale) / (f32)pool->f50;
        x = (f32)((f32)((s8)lbl_1_bss_A48.unk_2) * scale) / (f32)pool->f50;
        if ((lbl_1_bss_9F8.unk_2 & 0x200) != 0)
            y = (f32)((f32)((s8)lbl_1_bss_A48.unk_3) * scale) / (f32)pool->f50;
        else
            z = (f32)((f32)((s8)lbl_1_bss_A48.unk_3) * -scale) / (f32)pool->f50;
        a.x = x; a.y = y; a.z = z;
    } else {
        a.x = pool->w10; a.y = pool->w14; a.z = pool->w18;
    }
    b.x = pool->w1C; b.y = pool->w20; b.z = pool->w24;
    lbl_8006D7DC(pos);
    mathutil_mtxA_rotate_y(ry);
    mathutil_mtxA_rotate_x(rx);
    mathutil_mtxA_rotate_z(*(s16 *)((u8 *)state + 40));
    lbl_8006E1B0(&a);
    fn_8006E250(look);
    look->x += b.x; look->y += b.y; look->z += b.z;
    lbl_8006E1B0(look);
    x = look->x - pos->x;
    y = *(f32 *)((u8 *)state + 28) - *(f32 *)((u8 *)state + 12);
    z = *(f32 *)((u8 *)state + 32) - *(f32 *)((u8 *)state + 16);
    d = (f64)((f32)(x*x) + y*y + z*z);
    if (d < pool->f58) {
        dist = lbl_8006D0E8((f32)d);
        scale = (f32)(pool->f60 * dist);
        pos->x += x * scale;
        *(f32 *)((u8 *)state + 28) += y * scale;
        *(f32 *)((u8 *)state + 32) += z * scale;
    }
    x = pos->x - look->x;
    y = pos->y - look->y;
    z = pos->z - look->z;
    state->unk2C = lbl_8006D0B4((f32)((x*x) + y*y + z*z));
    if ((lbl_1_bss_9F8.unk_2 & 0x200) != 0 && state->unk39 != 0) {
        flags = lbl_1_bss_9F8.unk_0;
        if ((flags & 1) != 0)
            step = 2048;
        else
            step = -2048 & -(s32)((flags >> 1) & 1);
        *(s16 *)((u8 *)state + 40) += step;
        if ((flags & 4) != 0)
            dir = 1;
        else
            dir = -((flags >> 3) & 1);
        *(f32 *)((u8 *)state + 36) += dir;
        if (*(f32 *)((u8 *)state + 36) < (f32)pool->f68)
            *(f32 *)((u8 *)state + 36) = (f32)pool->f68;
        else if (*(f32 *)((u8 *)state + 36) > (f32)pool->f70)
            *(f32 *)((u8 *)state + 36) = (f32)pool->f70;
        if ((lbl_1_bss_9F8.unk_8 & 0x200) != 0) {
            *(s16 *)((u8 *)state + 40) = 0;
            *(f32 *)((u8 *)state + 36) = pool->f0C;
        }
    }
}
