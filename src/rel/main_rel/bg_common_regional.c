/* Previously matched Japan/PAL units of bg_common.c, retained until that TU matches those releases as one unit. */
#include "types.h"
#include "rel/main_rel/globals.h"
#include "rel/main_rel/bg_common.h"

extern f32 lbl_1_rodata_78E8[19];
extern void fn_1_103B00();
extern f32 lbl_1_rodata_7934[11];
extern void fn_1_9E5B8(void *);
extern void *fn_1_54448(s32 arg0);
extern void fn_1_103FCC(void);
extern void fn_1_10688C(void);
extern void fn_1_106B68(void);
extern s32 fn_1_5910(void);
extern f32 lbl_1_rodata_7960[43];
extern f32 lbl_1_rodata_7A40[2];
extern s32 fn_1_58C4(void);
extern void lbl_8006DCA4(void);
extern void fn_1_57714(s32 arg0);
extern void fn_1_57720(s32 arg0, s32 arg1, s32 arg2, s32 arg3);
extern void fn_1_57CD0(s32 arg0, void *arg1);
extern u8 lbl_1_bss_86EC4;
extern void fn_80008BEC(void *arg0, int arg1, int arg2);
extern void fn_1_1088B8(void *arg);
extern void lbl_8006DBAC(void *arg);
extern void lbl_8006E1B0(void *arg0, void *arg1);
extern void fn_1_107F74(void *arg0, int arg1);
extern u32 lbl_801A6410;
extern u32 lbl_1_data_3F284[2];
extern s32 OSIsThreadTerminated(void *arg0);
extern void OSCancelThread(void *arg0);
extern void fn_1_46B4(s32 arg0, s32 arg1, u8 *arg2, s32 arg3);
extern void fn_1_469BC(void);
extern void fn_1_466B0(s32 arg0, s32 arg1);
extern u32 lbl_1_bss_85288[2];

/* fzgx:begin fn_1_106084 */
#include "psvec.h"

typedef struct {
    f32 x;
    f32 y;
    f32 z;
} Vec3;

typedef struct {
    Vec3 unk_0;
    u8 unk_C;
    u8 pad_D[3];
} Fn106084Entry;

typedef struct {
    Vec3 unk_0;
    u8 unk_C[4];
    Vec3 unk_10;
    u8 unk_1C[4];
} Fn106084Slot;

extern u32 lbl_801A63C0;
extern s32 fn_1_58C4(void);
extern void fn_1_681C(u8, void *);
extern void fn_1_6914(u8, void *);
extern void fn_1_6990(u8, void *);
extern void fn_1_6898(u8, void *);
extern s32 camera_get_state(void);
extern f32 lbl_8006D668(void *);
extern void lbl_8006DCA4(void);
extern void lbl_8006D5F0(void *, void *, f32);
extern s32 fn_1_6EC0(u8);
extern s32 fn_1_54E34(void *, f32);
extern void fn_1_A714C(f32 *, f32 *, f32 *, f32 *);
extern f32 fn_1_A71AC(void);

#pragma section code_type ".fzgxpool"
static const u32 fzgx_pool_table1[2] = {0x42700000, 0x43360B61};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep1(void) { const u32 *volatile cp; cp = fzgx_pool_table1; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime1(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 4503601774854144.0;
    s = 1.0f;
    s = 0.5f;
    s = 0.0f;
    s = 5.0f;
}
static const u32 fzgx_pool_table2[6] = {0x3E4CCCCD, 0xBF800000, 0x47000000, 0x46800000, 0x40000000, 0x47C00000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep2(void) { const u32 *volatile cp; cp = fzgx_pool_table2; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime2(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 0.25f;
    s = 3.0f;
}
static const u32 fzgx_pool_table3[3] = {0x3ECCCCCD, 0xBDCCCCCD, 0x3F19999A};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep3(void) { const u32 *volatile cp; cp = fzgx_pool_table3; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime3(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 2.5f;
}
static const u32 fzgx_pool_table4[4] = {0x41A00000, 0x3F59999A, 0x40D55555, 0x3FC00000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep4(void) { const u32 *volatile cp; cp = fzgx_pool_table4; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime4(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 30.0f;
}
static const u32 fzgx_pool_table5[5] = {0x3C23D70A, 0x00000000, 0x00000000, 0x40080000, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep5(void) { const u32 *volatile cp; cp = fzgx_pool_table5; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime5(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 32767.0f;
}
static const u32 fzgx_pool_table6[3] = {0x00000000, 0x3FE00000, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep6(void) { const u32 *volatile cp; cp = fzgx_pool_table6; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime6(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 4503599627370496.0;
}
static const u32 fzgx_pool_table7[2] = {0x40800000, 0x47800000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep7(void) { const u32 *volatile cp; cp = fzgx_pool_table7; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime7(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 0.3f;
}
static const u32 fzgx_pool_table8[42] = {0x3F4CCCCD, 0x3F333333, 0x46C00000, 0x46000000, 0x41000000, 0x45800000, 0xC1A00000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x3F800000, 0x00000000, 0x3F800000, 0x00000000, 0x44820000, 0x41180000, 0x42200000, 0x41EC0000, 0x430C0000, 0x42DB0000, 0x000001A4, 0x00000168, 0x0000012C, 0x00000028, 0x00000000, 0x41700000, 0x40133333, 0x00000011, 0x0000000F, 0x0000000E, 0x0000000D, 0x00000013, 0x00000014, 0x0000001B, 0x0000001C, 0x0000001D, 0x0000001E, 0x3E570A3D, 0x606060A0, 0x808080C0};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep8(void) { const u32 *volatile cp; cp = fzgx_pool_table8; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime8(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 1.25f;
    s = -0.5f;
    s = 45.0f;
}
#pragma section code_type ".text"

static inline s32 rand15(void) {
    lbl_801A63C0 = lbl_801A63C0 * 0x676A4B6B + 0x33CB;
    return (lbl_801A63C0 >> 16) & 0x7FFF;
}

static inline f32 dist_sq(Vec3 *a, Vec3 *b) {
    f32 dx;
    f32 dy;
    f32 dz;

    dx = a->x;
    dx -= b->x;
    dy = a->y;
    dy -= b->y;
    dz = a->z;
    dz -= b->z;
    dx *= dx;
    dx += dy * dy;
    dx += dz * dz;
    return dx;
}

/* the cross product of bg_common.c fn_1_108128, copied verbatim */
static inline void cross(Vec3 *a, Vec3 *b, Vec3 *axb) {
    f32 ax = a->x, ay = a->y, az = a->z;
    f32 bx = *(volatile f32 *)&b->x, by = b->y, bz = b->z;  /* fzgx-allow: S2 volatile view keeps the verified load order */
    f32 nx = ay * bz;
    f32 ny = az * bx;
    f32 nz = ax * by;
    nx -= az * by;
    ny -= ax * bz;
    nz -= ay * bx;
    axb->x = nx;
    axb->y = ny;
    axb->z = nz;
}

/* the body of fn_1_105BD8, which retail inlines here */
static inline void fn_1_105BD8_body(u32 id, Vec3 *pos, Vec3 *up, Vec3 *dir, Vec3 *side) {
    fn_1_681C(id, pos);
    fn_1_6914(id, dir);
    fn_1_6990(id, up);
    if ((s8)camera_get_state() == 9) {
        up->x = 0.0f;
        up->y = 1.0f;
        up->z = 0.0f;
    }
    psvec_sub(dir, pos, dir);
    lbl_8006D668(dir);
    cross(dir, up, side);
}

/* the body of fn_1_105CC8, which retail inlines here */
static inline void fn_1_105CC8_body(Fn106084Entry *entry, Fn106084Slot *p, u8 *col, u8 *col2, Vec3 *pos,
                                    Vec3 *up, Vec3 *dir, Vec3 *side) {
    f32 b;
    f32 c;
    f32 a;
    f32 d;
    Vec3 acc;
    s32 k;
    f32 dist;
    f32 scale_up;
    f32 m;
    f32 scale_side;
    f32 r;
    f32 s;

    if (fn_1_58C4() <= 2) {
        fn_1_A714C(&a, &b, &c, &d);
        acc = *pos;
        c -= 3.0f;
        r = rand15() / 32767.0f;
        k = rand15();
        dist = c + (f32)(r * (30.0f - c));
        psvec_scale_add(&acc, dir, dist, &acc);
        s = (3.0f + dist) * fn_1_A71AC();
        scale_up = s * ((f32)(2.5f * (k / 32767.0f)) - 1.25f);
        k = rand15();
        psvec_scale_add(&acc, up, scale_up, &acc);
        s = (3.0f + dist) * fn_1_A71AC();
        m = b * s;
        scale_side = m * ((f32)(2.5f * (k / 32767.0f)) - 1.25f);
        psvec_scale_add(&acc, side, scale_side, &acc);
        entry->unk_0.x = 0.0f;
        entry->unk_0.y = -0.5f;
        entry->unk_0.z = 0.0f;
        entry->unk_C = 45.0f - dist;
        p->unk_0 = acc;
        s = 1.0f - (f32)(0.3f * r);
        p->unk_C[0] = col[0] * s;
        p->unk_C[1] = col[1] * s;
        p->unk_C[2] = col[2] * s;
        p->unk_C[3] = col[3];
        p->unk_1C[0] = col2[0] * s;
        p->unk_1C[1] = col2[1] * s;
        p->unk_1C[2] = col2[2] * s;
        /* retail stores byte 0xF a second time here (stb at 0xF(r24)); byte 0x1F is never written */
        p->unk_C[3] = col[3];
    }
}

/* fn_1_58C4 returns the number of viewports: the entry count per viewport */
static inline u32 entries_per_view(void) {
    u32 limit;

    fn_1_58C4();
    limit = 0x400U / fn_1_58C4();
    if (0x200U / fn_1_58C4() > limit) {
        limit = 0x400U / fn_1_58C4();
    } else {
        limit = 0x200U / fn_1_58C4();
    }
    return limit;
}

void fn_1_106084(u8 *base, s32 index, f32 t, f32 num, f32 den) {
    s32 dist_test;
    u8 *other;
    Vec3 pos;
    Vec3 up;
    Vec3 dir;
    Vec3 side;
    Vec3 delta;
    Vec3 target;
    Vec3 half;
    Vec3 move;
    f32 s;
    s32 start;
    s32 i;
    s32 end;
    Fn106084Entry *entry;
    Fn106084Slot *p;
    u32 col;
    u32 col2;

    if (fn_1_58C4() <= 2) {
        *(u32 *)(base + 0xC000) = entries_per_view();
        base[0xC004] = base[0xC005] = base[0xC006] = (f32)(32.0f * t) + (f32)(96.0f * (1.0f - t));
        base[0xC007] = (48.0f * t) + (f32)(160.0f * (1.0f - t));
        base[0xC008] = base[0xC009] = base[0xC00A] = (f32)(64.0f * t) + (f32)(128.0f * (1.0f - t));
        base[0xC00B] = (48.0f * t) + (f32)(192.0f * (1.0f - t));
        fn_1_105BD8_body(index, &pos, &up, &dir, &side);
        fn_1_6898(index, &target);
        psvec_sub(&pos, &target, &delta);
        s = 0.5f + 0.25f * num / den;
        lbl_8006DCA4();
        start = index * *(s32 *)(base + 0xC000);
        end = start + *(s32 *)(base + 0xC000);
        dist_test = !fn_1_6EC0(index);
        entry = (Fn106084Entry *)(base + start * 16);
        other = base + start * 32;
        for (i = start; i < end; i++, entry++) {
            p = (Fn106084Slot *)(other + 0x4000);
            psvec_add(p, entry, p);
            if (entry->unk_C == 0 || fn_1_54E34(p, 5.0f) == 0 ||
                (dist_test != 0 && dist_sq(&p->unk_0, &pos) > 100.0f)) {
                col2 = *(u32 *)(base + 0xC008);
                col = *(u32 *)(base + 0xC004);
                fn_1_105CC8_body(entry, p, (u8 *)&col, (u8 *)&col2, &pos, &up, &dir, &side);
            } else {
                entry->unk_C--;
            }
            psvec_scale_add(entry, &delta, -0.5f, &half);
            lbl_8006D5F0(&half, &move, s);
            psvec_add(p, &move, &p->unk_10);
            other += 0x20;
        }
    }
}
/* fzgx:end fn_1_106084 */

/* fzgx:begin fn_1_1067A8 */
void fn_1_1067A8(void *arg0, f32 arg1, f32 arg2) {
    s32 result;
    s32 value;
    s32 count;
    s32 stride;
    u8 *base;
    f32 scale;
    f32 offset;

    scale = arg1;
    offset = arg2;
    result = fn_1_5910();

    value = (lbl_1_rodata_7960[0] * scale / offset + lbl_1_rodata_7A40[0]);
    count = fn_1_58C4();
    if (count <= 2) {
        lbl_8006DCA4();
        fn_1_57714(value);
        fn_1_57720(1, 4, 5, 0);
        base = arg0;
        stride = *(s32 *)(base + 0xC000);
        fn_1_57CD0((stride & 0x7FFF) << 1, base + (result * stride << 5) + 0x4000);
        fn_1_57714(6);
    }
}
/* fzgx:end fn_1_1067A8 */
