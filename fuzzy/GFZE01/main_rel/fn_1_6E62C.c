/* Non-matching: best partial attempt (20.69% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"
#include "rel/main_rel/effect_car.h"

typedef struct {
    u32 flags;
    u8 pad_4[0x14];
    s16 mode;
    u8 pad_1a[0x1e];
    u32 data;
    u8 pad_3c[0xc];
    f32 x, y, z;
    u8 pad_54[0x4];
    f32 px, py, pz;
    u8 pad_64[0x5c];
} EffectObj;
typedef struct {
    u8 pad_0[0x14];
    f32 x, y, z;
    u8 pad_20[0x24];
    f32 dx, dy, dz;
    u8 pad_4c[0x1c];
    f32 sx, sy, sz;
    u8 pad_64[0x84];
    u16 unk_e8[0];
} Particle;
typedef struct {
    u32 flags;
    u8 pad_4[0x10];
    f32 x, y, z;
    u8 pad_14[0x4];
    f32 ex, ey, ez;
    u8 pad_20[0x24];
    f32 ax, ay, az;
    u8 pad_44[0x200];
} EmitData;
extern f32 lbl_1_rodata_2D70[];
extern u8 fn_1_58C4(void);
extern s16 camera_get_mode(void);
extern u32 fn_1_584AC(void);
extern s16 fn_1_58F50(const void *);
extern f32 lbl_8006D0B4(f32);
extern void lbl_8006DD14(u32, void *);
extern u32 lbl_801A66A0;
extern u8 *memset(u8 *, int, u32);

s16 fn_1_6E62C(EffectObj *obj, f32 *velocity, f32 delta) {
    EmitData emit;
    f32 speed, dist, rate, duration;
    f32 tx, ty, tz, dx, dy, dz, len;
    f32 a, b, c, j, k, m;
    u32 mode, i, color;
    s16 camera;
    lbl_8006DD14((u32)((u8 *)obj + 0xb8), &emit);
    if (fn_1_58C4() >= 2)
        return 0;
    camera = camera_get_mode();
    if (obj->mode != camera && (lbl_801A66A0 & 1))
        return 0;
    for (i = 0; i < 4; i++) {
        EmitData *e = (EmitData *)((u8 *)&emit + 0x244 + i * 0x5c);
        if (e->flags & 2)
            continue;
        speed = (obj->x * obj->x + obj->y * obj->y + obj->z * obj->z) / lbl_1_rodata_2D70[23];
        if (speed == 0.0f)
            continue;
        if (speed > 0.9f) speed = 0.9f;
        memset((u8 *)&emit + 0x50, 0, 0xe8);
        ((u16 *)&emit)[0x34] = obj->mode;
        ((u16 *)&emit)[0x2e] = 24;
        ((u16 *)&emit)[0x35] = 1;
        tx = obj->x * 0.9f;
        ty = obj->y * 0.9f;
        tz = obj->z * 0.9f;
        rate = 0.3f;
        if (i == 3 || i == 1) rate *= -1.0f;
        tx += velocity[0] * rate;
        ty += velocity[1] * rate;
        tz += velocity[2] * rate;
        len = lbl_8006D0B4(tx * tx + ty * ty + tz * tz);
        duration = 0.03f * len;
        for (j = len; j > 0.4f; j -= 60.0f) {
            f32 step = j / len;
            f32 t = len - step;
            tx = obj->x * step + obj->px * t;
            ty = obj->y * step + obj->py * t;
            tz = obj->z * step + obj->pz * t;
            ((f32 *)&emit)[0x23] = tx;
            ((f32 *)&emit)[0x24] = ty;
            ((f32 *)&emit)[0x25] = tz;
            color = fn_1_584AC() & 0xffff;
            (void)color;
            fn_1_58F50(&emit);
        }
    }
    return 0;
}
