/* Non-matching: best partial attempt (95.04% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"
#pragma section code_type ".fzgxpool"
__declspec(section ".fzgxpool") static void fzgx_pool_prime1(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 60.0f;
    s = 0.10000000149011612f;
    s = 32767.0f;
    s = 0.05000000074505806f;
    d = 0.07;
    s = 20000.0f;
}
static const u32 fzgx_pool_table2[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep2(void) { const u32 *volatile cp; cp = fzgx_pool_table2; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime3(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 4503599627370496.0;
    s = 1.0f;
    s = -0.029999999329447746f;
    d = 15.0;
    d = 4503601774854144.0;
    d = 1.5;
    d = 0.5;
    s = 0.0f;
    s = 0.5f;
    s = 8.0f;
    s = 255.0f;
}
#pragma section code_type ".text"

typedef struct Vec3f {
    f32 x;
    f32 y;
    f32 z;
} Vec3f;

struct fn_1_59770_lbl_1_rodata_2950 {
    u8 pad_0[0x4];
    f32 unk_4;
    u8 pad_8[0x20];
    f32 unk_28;
    u8 pad_2C[0x14];
    f64 unk_40;
    f64 unk_48;
    f32 unk_50;
    f32 unk_54;
    f32 unk_58;
    f32 unk_5C;
};
struct fn_1_59770_lbl_801A66CC {
    void *unk_0;
};

typedef struct EffDraw {
    f32 unk_0;
    f32 unk_4;
    u8 unk_8[0x34];
    u8 r;
    u8 g;
    u8 b;
    u8 a;
} EffDraw;

typedef struct EffectWork {
    u8 pad_00[0x8];
    u32 unk_8;
    u8 pad_0c[0xc];
    s16 unk_18;
    f32 unk_1c;
    f32 unk_20;
    f32 unk_24;
    f32 unk_28;
    u8 pad_2c[0x8];
    void *unk_34;
    u8 pad_38[0x4];
    Vec3f unk_3c;
    u8 pad_48[0x18];
    Vec3f unk_60;
} EffectWork;

extern f32 lbl_8006D0B4(f32);
extern f32 lbl_8006D668(void *);
extern int fn_1_9F914(const void *, const void *);
const u8 lbl_1_rodata_2950[4] = {0x42,0x70,0x00,0x00};
const f32 lbl_1_rodata_2954 = 0.100000001f;
const u8 lbl_1_rodata_2954__fzgx_offset_4[4] = {0x46,0xFF,0xFE,0x00};
const u8 lbl_1_rodata_295C[28] = {0x3D,0x4C,0xCC,0xCD,0x3F,0xB1,0xEB,0x85,0x1E,0xB8,0x51,0xEC,0x46,0x9C,0x40,0x00,0x00,0x00,0x00,0x00,0x43,0x30,0x00,0x00,0x00,0x00,0x00,0x00};
const f32 lbl_1_rodata_2978 = 1.0f;
const u8 lbl_1_rodata_2978__fzgx_offset_4[12] = {0xBC,0xF5,0xC2,0x8F,0x40,0x2E,0x00,0x00,0x00,0x00,0x00,0x00};
const u8 lbl_1_rodata_2988[8] = {0x43,0x30,0x00,0x00,0x80,0x00,0x00,0x00};
const f64 lbl_1_rodata_2988__fzgx_offset_8 = 1.5;
const f64 lbl_1_rodata_2988__fzgx_offset_10 = 0.5;
const f32 lbl_1_rodata_2988__fzgx_offset_18 = 0.0f;
const f32 lbl_1_rodata_29A4 = 0.5f;
const f32 lbl_1_rodata_29A4__fzgx_offset_4 = 8.0f;
const f32 lbl_1_rodata_29AC = 255.0f;
const u8 lbl_1_rodata_29AC__fzgx_offset_4[16] = {0x41,0x70,0x00,0x00,0x3E,0x4C,0xCC,0xCD,0x3D,0xA3,0xD7,0x0A,0x3E,0x80,0x00,0x00};
extern struct fn_1_59770_lbl_801A66CC lbl_801A66CC;
extern s16 lbl_8006D24C(f32, f32);
extern void lbl_8006DBAC(void *);
extern void lbl_8006DCA4(void);
extern void mathutil_mtxA_rotate_x(s16);
extern void lbl_8006DC6C(void *);
extern void *memset(void *, int, u32);
extern void fn_1_8636C(s16, void *);
extern void fn_8006E294(void *);
extern void fn_8006EDBC(Vec3f *, Vec3f *, s16 *, s16 *);
extern void lbl_8006D7DC(void *);
extern void lbl_8006DB74(void *);
extern void lbl_8006E0A4(void *);
extern void lbl_8006E15C(f32, f32, f32);
extern void lbl_8006E1B0(void *, void *);
extern void mathutil_mtxA_rotate_y(s16);

static inline f32 fn_1_59770_read_pointer(Vec3f * owner) { return owner->z; }
#pragma opt_propagation off
#pragma opt_lifetimes off
void fn_1_59770(EffectWork *self) {
    f32 fzgx_live;
    struct fn_1_59770_lbl_1_rodata_2950 *pool;
    f32 mtx[12];
    EffDraw draw;
    Vec3f p1;
    Vec3f p0;
    Vec3f mid;
    Vec3f dir;
    s16 rx;
    s16 ry;
    void *model;
    f32 size;
    f32 width;
    f32 dy;
    f32 dz;
    f32 ox;
    f32 len;
    f32 t;

    model = self->unk_34;
    fn_1_8636C(self->unk_18, mtx);
    width = self->unk_28;
    lbl_8006DBAC(lbl_801A66CC.unk_0);
    lbl_8006E1B0(&self->unk_60, &p0);
    lbl_8006DCA4();
    lbl_8006E1B0(&self->unk_3c, &p1);
    p0.x = (f64)(lbl_1_rodata_2988__fzgx_offset_8 * p0.x) - (f64)(lbl_1_rodata_2988__fzgx_offset_10 * p1.x);
    p0.y = (f64)(lbl_1_rodata_2988__fzgx_offset_8 * p0.y) - (f64)(lbl_1_rodata_2988__fzgx_offset_10 * p1.y);
    p0.z = (f64)(lbl_1_rodata_2988__fzgx_offset_8 * p0.z) - (f64)(lbl_1_rodata_2988__fzgx_offset_10 * fn_1_59770_read_pointer(&p1));
    if (fn_1_59770_read_pointer(&p1) < lbl_1_rodata_2988__fzgx_offset_18 && p0.z < lbl_1_rodata_2988__fzgx_offset_18) {
        size = self->unk_28;
        dir.x = p1.x - p0.x;
        dir.y = p1.y - p0.y;
        if (lbl_1_rodata_2988__fzgx_offset_18 == dir.x && lbl_1_rodata_2988__fzgx_offset_18 == dir.y) {
            lbl_8006E0A4(&self->unk_3c);
            lbl_8006DC6C(mtx);
            mathutil_mtxA_rotate_x(0x4000);
        } else {
            dir.z = lbl_1_rodata_2988__fzgx_offset_18;
            lbl_8006D668(&dir);
            t = width;
            t *= lbl_1_rodata_2954;
            fzgx_live = dir.x;
            ox = fzgx_live * t;
{
    f32 oy;
            oy = dir.y * t;
            p0.x -= ox;
            p1.x += ox;
            p0.y -= oy;
            p1.y += oy;
}
            mid.x = lbl_1_rodata_29A4 * (p1.x + p0.x);
            mid.y = lbl_1_rodata_29A4 * (p1.y + p0.y);
            mid.z = lbl_1_rodata_29A4 * (fn_1_59770_read_pointer(&p1) + p0.z);
{
    f32 dx;
            dx = p1.x - p0.x;
            dy = p1.y - p0.y;
            dz = fn_1_59770_read_pointer(&p1) - p0.z;
            len = lbl_8006D0B4(dx * dx + dy * dy + dz * dz);
}
            fn_8006EDBC(&p1, &p0, &rx, &ry);
            lbl_8006D7DC(&mid);
            mathutil_mtxA_rotate_y(ry);
            mathutil_mtxA_rotate_x(rx);
            lbl_8006E15C(lbl_1_rodata_2978, lbl_1_rodata_2978, len / width);
            mathutil_mtxA_rotate_x(0x4000);
            fn_8006E294(&dir);
            fzgx_live = dir.x;
            mathutil_mtxA_rotate_y(lbl_8006D24C(fzgx_live, dir.z));
        }
        memset(&draw, 0, 0x40);
        lbl_8006DB74(draw.unk_8);
        draw.unk_0 = lbl_1_rodata_29A4__fzgx_offset_4 * size;
        if ((self->unk_8 >> 14) & 1) {
            draw.unk_0 *= lbl_1_rodata_29A4;
        }
        draw.r = lbl_1_rodata_29AC * self->unk_1c;
        draw.g = lbl_1_rodata_29AC * self->unk_20;
        draw.b = lbl_1_rodata_29AC * self->unk_24;
        draw.a = 0xff;
        fn_1_9F914(&draw, model);
    }
}
#pragma opt_lifetimes reset

#pragma opt_propagation reset

