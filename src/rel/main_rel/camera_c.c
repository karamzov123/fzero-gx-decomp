#include "types.h"
#include "rel/main_rel/globals.h"
#include "rel/main_rel/camera.h"

extern void fn_1_BD54(void);
extern void fn_1_B870(void);
extern void camera_get_extended_state_storage(__typeof__(lbl_1_bss_F68));
extern void lbl_8006DBAC(void);
extern void fn_8006F038(void *, void *, s16);
extern void lbl_8006DCDC(void);
extern s16 fn_1_6B48(s16 value);
extern void fn_1_6D2C(u32);
extern s32 lbl_1_bss_F78;
extern void fn_1_A2DF4(u32, u32, u32);
extern s8 fn_1_86624(void);
extern s8 fn_1_86634(s32 index);
extern void OSPanic(u8 *file, int line, u8 *message, ...);
extern u8 lbl_1_bss_F74;
extern u8 lbl_1_bss_F75;
extern f32 lbl_1_rodata_188;
extern s32 fn_1_8708(u8 mode, f32 *value0, f32 *value1);
extern void fn_1_8A0C(s16 index);
extern void fn_1_A6FE8(void);
extern void fn_1_8D08(GameCameraEntry *value);
extern f32 lbl_1_bss_1040;
extern f32 lbl_1_bss_1044;
extern void OSReport(const unsigned char *, ...);
extern u8 lbl_1_bss_103C[4];
extern u8 lbl_1_bss_108C[52];
extern u8 lbl_1_bss_1014;

extern s8 fn_1_86624(void);
extern s8 fn_1_86634(s32 index);
extern void OSPanic(u8 *file, int line, u8 *message, ...);
extern void fn_1_8A0C(s16 index);
extern void OSReport(const unsigned char *, ...);

extern f32 lbl_1_rodata_2E0[32];
extern f32 lbl_8006D6FC(f32 *value, void *target);
u32 fn_1_6514(u32);
extern struct fn_1_6400_lbl_801A6410 lbl_801A6410;
extern u32 fn_1_46B4(u32, u32, void *, u32);
extern f64 lbl_1_rodata_478;
extern f32 lbl_1_rodata_49C;
extern f32 lbl_1_bss_10C0[6];

/* fzgx:begin fn_1_B724 noprologue */
#include "types.h"

typedef struct {
    f32 x, y, z;
} CamVec;

typedef struct {
    u32 unk_0;
    CamVec unk_4;
    CamVec unk_10;
    f32 unk_1C;
    s16 unk_20;
} CamKey;

typedef struct {
    s32 unk_0;
    s32 unk_4;
    s32 unk_8;
    f32 unk_C;
} CamCtl;

extern f32 lbl_8006D0B4(f32);

/* the retail TU's .bss objects this function uses, in retail order, so MWCC addresses them off one section base */
u32 fzgx_obj_lbl_1_bss_1010;
u8 lbl_1_bss_1014;
u8 fzgx_pool_gap_1015;  /* retail writes this byte (stb at 0x1015); symbols.txt names no object there */
u16 fzgx_pool_gap_1016;
CamKey fzgx_obj_camera_state;
f32 lbl_1_bss_103C;
f32 lbl_1_bss_1040;
f32 lbl_1_bss_1044;
u8 fzgx_obj_camera_flag_0;
u8 fzgx_obj_camera_flag_1;
u16 fzgx_pool_gap_104A;
CamCtl lbl_1_bss_104C;

#pragma section code_type ".fzgxpool"
static void fzgx_bss_layout(void) {
    volatile u8 s;  /* fzgx-allow: S2 layout primer sink: MWCC emits .bss objects in first-access order */
    s = *(u8 *)&fzgx_obj_lbl_1_bss_1010;
    s = lbl_1_bss_1014;
    s = *(u8 *)&fzgx_pool_gap_1015;
    s = *(u8 *)&fzgx_pool_gap_1016;
    s = *(u8 *)&fzgx_obj_camera_state;
    s = *(u8 *)&lbl_1_bss_103C;
    s = *(u8 *)&lbl_1_bss_1040;
    s = *(u8 *)&lbl_1_bss_1044;
    s = fzgx_obj_camera_flag_0;
    s = fzgx_obj_camera_flag_1;
    s = *(u8 *)&fzgx_pool_gap_104A;
    s = *(u8 *)&lbl_1_bss_104C;
}
#pragma section code_type ".text"

void fn_1_B724(CamVec *pos, CamVec *at, s16 roll, f32 fov) {
    f32 dz, dy, dx;

    fzgx_obj_camera_state.unk_4 = *pos;
    fzgx_obj_camera_state.unk_10 = *at;
    dx = fzgx_obj_camera_state.unk_4.x;
    dy = fzgx_obj_camera_state.unk_4.y;
    dz = fzgx_obj_camera_state.unk_4.z;
    dx -= fzgx_obj_camera_state.unk_10.x;
    dy -= fzgx_obj_camera_state.unk_10.y;
    dz -= fzgx_obj_camera_state.unk_10.z;
    dx *= dx;
    dx += dy * dy;
    dx += dz * dz;
    fzgx_obj_camera_state.unk_1C = fov;
    fzgx_obj_camera_state.unk_20 = roll;
    lbl_1_bss_103C = lbl_8006D0B4(dx);
    lbl_1_bss_1040 = 1.0f;
    lbl_1_bss_1044 = 0.1f;
    fzgx_obj_camera_flag_0 = 1;
    fzgx_obj_camera_flag_1 = 1;
    lbl_1_bss_1014 = 0;
    fzgx_pool_gap_1015 = 0;
    lbl_1_bss_104C.unk_0 = 0;
    lbl_1_bss_104C.unk_4 = 0;
    lbl_1_bss_104C.unk_8 = 200;
    lbl_1_bss_104C.unk_C = 0.01f;
}
/* fzgx:end fn_1_B724 */

/* fzgx:begin fn_1_B81C */
struct fn_1_B81C_Copy12 { u32 a[3]; };

void fn_1_B81C(struct fn_1_B81C_Copy12 *first, struct fn_1_B81C_Copy12 *second, u32 value) {
    *(struct fn_1_B81C_Copy12 *)((u8 *)&camera_state + 4) = *first;
    *(struct fn_1_B81C_Copy12 *)((u8 *)&camera_state + 16) = *second;
    camera_state.unk_20 = value;
}
/* fzgx:end fn_1_B81C */

/* fzgx:begin camera_save_parameters */
// Saves the two current camera parameters for later processing.
void camera_save_parameters(f32 first_parameter, f32 second_parameter) {
    lbl_1_bss_1040 = first_parameter;
    lbl_1_bss_1044 = second_parameter;
}
/* fzgx:end camera_save_parameters */

/* fzgx:begin fn_1_B870 */
#ifndef GAME_VEC3_H
#define GAME_VEC3_H

typedef struct Vec3f {
    f32 x, y, z;
} Vec3f;

#endif  // GAME_VEC3_H

/* end game/vec3.h */

typedef struct B870Camera {
    u8 pad_0[0x4];
    Vec3f pos;    /* 0x04 */
    Vec3f lookAt; /* 0x10 */
    f32 fov;      /* 0x1C */
    s16 rotZ;     /* 0x20 */
} B870Camera;

typedef struct {
    u8 pad_0[0x8];
    u16 unk_8;
} B870Bss_D58;

typedef struct {
    s8 stick[4];
    u8 unk_4;
} B870Bss_A48;

typedef struct {
    u16 unk_0;
    u16 unk_2;
    u8 pad_4[0x4];
    u16 unk_8;
} B870Bss_9F8;


/* camera.c's .bss cluster at lbl_1_bss_1010, addressed off one section base. */
u32 fzgx_obj_lbl_1_bss_1010;
u8 lbl_1_bss_1014;
B870Camera camera_state__fzgx_offset_0;
f32 fzgx_obj_lbl_1_bss_103C;
f32 lbl_1_bss_1040;
f32 lbl_1_bss_1044;
u8 camera_flag_0__fzgx_offset_0;
u8 camera_flag_1__fzgx_offset_0;

extern void fn_1_C770(void);
extern void fn_8006EDBC(Vec3f *, Vec3f *, s16 *, s16 *);
extern void lbl_8006D7DC(Vec3f *);
extern void mathutil_mtxA_rotate_x(s16);
extern void mathutil_mtxA_rotate_y(s16);
extern void mathutil_mtxA_rotate_z(s16);
extern void lbl_8006E1B0(Vec3f *, Vec3f *);
extern void fn_8006E250(Vec3f *, Vec3f *);
extern f32 lbl_8006D0E8(f32);
extern f32 lbl_8006D0B4(f32);

/* Primer: the .bss order and the literals of earlier camera.c functions, as in retail. */
extern void fzgx_touch_f(f32);
extern void fzgx_touch(void *);
#pragma section RX ".fzgxpool"
__declspec(section ".fzgxpool") void fzgx_pool_primer(void) {
    fzgx_touch(&fzgx_obj_lbl_1_bss_1010);
    fzgx_touch(&lbl_1_bss_1014);
    fzgx_touch(&camera_state__fzgx_offset_0);
    fzgx_touch(&fzgx_obj_lbl_1_bss_103C);
    fzgx_touch(&lbl_1_bss_1040);
    fzgx_touch(&lbl_1_bss_1044);
    fzgx_touch(&camera_flag_0__fzgx_offset_0);
    fzgx_touch(&camera_flag_1__fzgx_offset_0);
    fzgx_touch_f(1.0f);
    fzgx_touch_f(0.1f);
    fzgx_touch_f(0.01f);
    fzgx_touch_f(55.0f);
}

#pragma opt_lifetimes off
void fn_1_B870(void) {
    f32 speed;
    f32 clamped;
    f32 scale;
    s32 rot;
    s32 zoom;
    u32 buttons;
    s16 rotX;
    s16 rotY;

    if ((((B870Bss_D58 *)&lbl_1_bss_D58)->unk_8 >> 10) & 1) {
        camera_flag_0__fzgx_offset_0 ^= 1;
    }
    if (lbl_1_bss_1014 != 0) {
        fn_1_C770();
        return;
    }
    fn_8006EDBC(&camera_state__fzgx_offset_0.pos, &camera_state__fzgx_offset_0.lookAt, &rotX, &rotY);
    speed = fzgx_obj_lbl_1_bss_103C;
    speed = 0.040000000000000008 * speed;
    speed = speed * (1.0 + 4.0 * ((B870Bss_A48 *)&lbl_1_bss_A48)->unk_4 / 140.0);
    clamped = (speed > 50.0) ? 50.0 : speed;
    {
        Vec3f offsetA = {0.0f, 0.0f, 0.0f};
        Vec3f offsetB = {0.0f, 0.0f, 0.0f};
        Vec3f tmp;

        if (camera_flag_1__fzgx_offset_0 != 0 && !((((B870Bss_9F8 *)&lbl_1_bss_9F8)->unk_0 >> 6) & 1)) {
            offsetA.x = speed * (*((0) + (((B870Bss_A48 *)&lbl_1_bss_A48)->stick))) / 60.0;
            if ((((B870Bss_9F8 *)&lbl_1_bss_9F8)->unk_2 >> 9) & 1) {
                offsetA.y = clamped * (*((1) + (((B870Bss_A48 *)&lbl_1_bss_A48)->stick))) / 60.0;
            } else {
                offsetA.z = -clamped * (*((1) + (((B870Bss_A48 *)&lbl_1_bss_A48)->stick))) / 60.0;
            }
            offsetB.x = speed * (*((2) + (((B870Bss_A48 *)&lbl_1_bss_A48)->stick))) / 60.0;
            if (((*&((B870Bss_9F8 *)&lbl_1_bss_9F8)->unk_2) >> 9) & 1) {
                offsetB.y = clamped * (*((3) + (((B870Bss_A48 *)&lbl_1_bss_A48)->stick))) / 60.0;
            } else {
                offsetB.z = -clamped * (*((3) + (((B870Bss_A48 *)&lbl_1_bss_A48)->stick))) / 60.0;
            }
        }
        lbl_8006D7DC(&camera_state__fzgx_offset_0.pos);
        mathutil_mtxA_rotate_y(rotY);
        mathutil_mtxA_rotate_x(rotX);
        mathutil_mtxA_rotate_z(camera_state__fzgx_offset_0.rotZ);
        lbl_8006E1B0(&offsetA, &camera_state__fzgx_offset_0.pos);
        fn_8006E250(&camera_state__fzgx_offset_0.lookAt, &tmp);
        tmp.x += offsetB.x;
        tmp.y += offsetB.y;
        tmp.z += offsetB.z;
        lbl_8006E1B0(&tmp, &camera_state__fzgx_offset_0.lookAt);
        tmp.x = camera_state__fzgx_offset_0.lookAt.x - camera_state__fzgx_offset_0.pos.x;
        tmp.y = camera_state__fzgx_offset_0.lookAt.y - camera_state__fzgx_offset_0.pos.y;
        tmp.z = camera_state__fzgx_offset_0.lookAt.z - camera_state__fzgx_offset_0.pos.z;
        if (__fmadds(tmp.z, tmp.z, __fmadds(tmp.y, tmp.y, tmp.x * tmp.x)) < 0.09) {
            scale = 0.3 * lbl_8006D0E8(__fmadds(tmp.z, tmp.z, __fmadds(tmp.y, tmp.y, tmp.x * tmp.x)));
            camera_state__fzgx_offset_0.lookAt.x = camera_state__fzgx_offset_0.pos.x + (f32)(tmp.x * scale);
            camera_state__fzgx_offset_0.lookAt.y = camera_state__fzgx_offset_0.pos.y + (f32)(tmp.y * scale);
            camera_state__fzgx_offset_0.lookAt.z = camera_state__fzgx_offset_0.pos.z + (f32)(tmp.z * scale);
        }
    }
    {
        Vec3f *pos = &camera_state__fzgx_offset_0.pos;
        Vec3f *lookAt = &camera_state__fzgx_offset_0.lookAt;
        f32 dx = pos->x;
        f32 dz = pos->z;
        f32 dy = pos->y;
        dx -= lookAt->x;
        dy -= lookAt->y;
        dz -= lookAt->z;
        dx = dx * dx;
        dx = dy * dy + dx;
        dx = dz * dz + dx;
        fzgx_obj_lbl_1_bss_103C = lbl_8006D0B4(dx);
    }
    if (((((B870Bss_9F8 *)&lbl_1_bss_9F8)->unk_2 >> 9) & 1) && camera_flag_1__fzgx_offset_0 != 0) {
        buttons = (*&(((B870Bss_9F8 *)&lbl_1_bss_9F8)->unk_0));
        if (buttons & 1) {
            rot = 0x800;
        } else {
            rot = ((buttons >> 1) & 1) ? -0x800 : 0;
        }
{
    B870Camera *cam = &camera_state__fzgx_offset_0;
        cam->rotZ += rot;
}
        buttons = ((B870Bss_9F8 *)&lbl_1_bss_9F8)->unk_0;
        if ((buttons >> 2) & 1) {
            zoom = 1;
        } else {
            zoom = ((buttons >> 3) & 1) ? -1 : 0;
        }
        camera_state__fzgx_offset_0.fov += zoom;
        camera_state__fzgx_offset_0.fov = (camera_state__fzgx_offset_0.fov < 0.1) ? 0.1
                           : (camera_state__fzgx_offset_0.fov > 90000.0) ? 90000.0 : camera_state__fzgx_offset_0.fov;
        if ((((B870Bss_9F8 *)&lbl_1_bss_9F8)->unk_8 >> 9) & 1) {
            camera_state__fzgx_offset_0.rotZ = 0;
            camera_state__fzgx_offset_0.fov = 55.0f;
        }
    }
}
#pragma opt_lifetimes reset
/* fzgx:end fn_1_B870 */

/* fzgx:begin fn_1_BD54 */
#include "dolphin/hw_regs.h"
#include "psvec.h"

/* the camera TU's .rodata pool in retail order, ahead of this function's constants */
#pragma section code_type ".fzgxpool"
__declspec(section ".fzgxpool") static void fzgx_pool_prime1(void) {
    volatile f32 s;  /* fzgx-allow: S2 pool primer sink */
    s = 1.0f;
    s = 0.10000000149011612f;
    s = 0.009999999776482582f;
    s = 55.0f;
}
static const u32 fzgx_pool_table2[6] = {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep2(void) { const u32 *volatile cp; cp = fzgx_pool_table2; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime3(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 0.04000000000000001;
    d = 1.0;
    d = 4.0;
    d = 140.0;
    d = 50.0;
    d = 60.0;
    d = 0.09;
    d = 0.3;
    d = 0.1;
    d = 90000.0;
    d = 4503599627370496.0;
    d = 4503601774854144.0;
    d = 0.02;
    s = 60.0f;
    s = 15.0f;
    s = 0.8999999761581421f;
    s = 0.0f;
}
#pragma section code_type ".text"

#define MTXA ((f32(*)[4])LC_BASE)

typedef struct {
    f32 x;
    f32 y;
    f32 z;
} BD54Vec;

typedef struct {
    u32 unk_0;
    BD54Vec unk_4;
    BD54Vec unk_10;
    f32 unk_1C;
    s16 unk_20;
} BD54Camera;

extern u32 fn_1_10780C(BD54Vec *, BD54Vec *, BD54Vec *, f32 *);
extern u32 fn_80008C20(void *, void *, void *);
extern void lbl_8006E0B4(f32, f32, f32);
extern void mathutil_mtxA_rotate_x(s16);
extern void fn_8006FB20(void *, f32);
extern void lbl_8006DB74(void *);
extern void fn_8006F3E4(s16 *, s16 *, s16 *);
extern void lbl_8006DF44(void);

/* the retail TU's .bss objects this function uses, at their retail offsets, so MWCC addresses them off one
 * section base; the fzgx_pool_gap_ objects span the retail objects in between, which this function does not touch */
f32 fzgx_obj_lbl_1_bss_1010;
u8 fzgx_pool_gap_1014[4];
BD54Camera fzgx_obj_camera_state;
u8 fzgx_pool_gap_103C[0x10];
u8 fzgx_obj_lbl_1_bss_104C[0x10];
u8 lbl_1_bss_104C__fzgx_offset_10[0x30];
u8 lbl_1_bss_108C[52];

#pragma section code_type ".fzgxpool"
static void fzgx_bss_layout(void) {
    volatile u8 s;  /* fzgx-allow: S2 layout primer sink: MWCC emits .bss objects in first-access order */
    s = *(u8 *)&fzgx_obj_lbl_1_bss_1010;
    s = *(u8 *)&fzgx_pool_gap_1014;
    s = *(u8 *)&fzgx_obj_camera_state;
    s = *(u8 *)&fzgx_pool_gap_103C;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_104C;
    s = *(u8 *)&lbl_1_bss_104C__fzgx_offset_10;
    s = *(u8 *)&lbl_1_bss_108C;
}

#pragma section code_type ".text"

static inline void track_follow(BD54Vec *t, BD54Vec *a) {
    f32 (*src)[4];
    f32 (*dst)[4];
    f32 x;
    f32 z;
    f32 y;

    /* one name for the reads, one for the writes: as a chained pair the locked-cache matrix address stays a
     * real local, which gives retail's saved-register order (.bss base r29, flags r30) */
    dst = src = MTXA;
    psvec_set(t, src[2][3], src[1][3], src[0][3]);
    x = fzgx_obj_camera_state.unk_4.x += 0.1 * (t->x - fzgx_obj_camera_state.unk_4.x);
    y = fzgx_obj_camera_state.unk_4.y += 0.1 * (t->y - fzgx_obj_camera_state.unk_4.y);
    z = fzgx_obj_camera_state.unk_4.z += 0.1 * (t->z - fzgx_obj_camera_state.unk_4.z);
    fzgx_obj_camera_state.unk_10.x += 0.1 * (a->x - fzgx_obj_camera_state.unk_10.x);
    fzgx_obj_camera_state.unk_10.y += 0.1 * (a->y - fzgx_obj_camera_state.unk_10.y);
    fzgx_obj_camera_state.unk_10.z += 0.1 * (a->z - fzgx_obj_camera_state.unk_10.z);
    dst[0][3] = x;
    dst[1][3] = y;
    dst[2][3] = z;
}

/* retail multiplies and adds in separate fmul/fadd steps; with contraction MWCC fuses them into fmadd */
#pragma fp_contract off
void fn_1_BD54(void) {
    s16 rotY;
    s16 rotX;
    BD54Vec t;
    BD54Vec a;
    BD54Vec b;
    BD54Vec c;
    f32 value;
    u32 flags;

    lbl_1_data_4068 += (s8)lbl_1_bss_A48.unk_3 * 2;
    fzgx_obj_lbl_1_bss_1010 += 0.02 * (s8)lbl_1_bss_A48.unk_2;
    flags = fn_1_10780C(&a, &b, &c, &value);
    fn_80008C20(&a, &b, &c);
    if ((flags & 0x1400000) && !(flags & 1)) {
        lbl_8006E0B4(fzgx_obj_lbl_1_bss_1010, value, 60.0f);
    } else {
        lbl_8006E0B4(fzgx_obj_lbl_1_bss_1010, 15.0f, 60.0f);
    }
    mathutil_mtxA_rotate_x(lbl_1_data_4068);
    track_follow(&t, &a);
    fn_8006FB20(lbl_1_bss_104C__fzgx_offset_10, 0.9f);
    lbl_8006DB74(lbl_1_bss_104C__fzgx_offset_10);
    fn_8006F3E4(&rotX, &rotY, &fzgx_obj_camera_state.unk_20);
    lbl_8006DF44();
    lbl_8006DB74(lbl_1_bss_108C);
}
#pragma fp_contract reset
/* fzgx:end fn_1_BD54 */

/* fzgx:begin fn_1_BFA0 */
extern u32 fn_1_CC5C(void);
extern void lbl_8006D9D8(void *);
extern void lbl_8006E14C(f32);
extern void fn_1_55FC4(f32);
extern void fn_80072558(void);
extern void fn_1_55FF0(f32);
extern u32 lbl_801A6CE0;
extern u32 lbl_1_bss_38454;
extern u32 fn_1_55210(u32);

typedef struct CameraUpdateState {
    u8 unk_00[4];
    u8 unk_04;
    u8 unk_05[3];
    u8 unk_08[40];
    f32 unk_30;
    f32 unk_34;
    u8 unk_38;
} CameraUpdateState;

static inline void update_camera_transform(u8 *value) {
    lbl_8006D9D8(value + 0x10);
}

/* file-scope objects of the retail TU, in retail order: MWCC addresses them off one section base */
u32 fzgx_obj_lbl_1_bss_1010;
u8 lbl_1_bss_1014;
u8 fzgx_pool_lbl_1_bss_1010_gap_1015;
u16 fzgx_pool_lbl_1_bss_1010_gap_1015_fill_1016;
u8 fzgx_obj_camera_state;
u8 camera_state__fzgx_offset_1;
u16 camera_state__fzgx_offset_2;
u32 camera_state__fzgx_offset_4[8];
u8 lbl_1_bss_103C[4];
f32 lbl_1_bss_1040;
f32 lbl_1_bss_1044;
u8 fzgx_obj_camera_flag_0;

#pragma section code_type ".fzgxpool"
static void fzgx_bss_layout(void) {
    volatile u8 s;  /* fzgx-allow: S2 layout primer sink: MWCC emits .bss objects in first-access order */
    s = *(u8 *)&fzgx_obj_lbl_1_bss_1010;
    s = lbl_1_bss_1014;
    s = *(u8 *)&fzgx_pool_lbl_1_bss_1010_gap_1015;
    s = *(u8 *)&fzgx_pool_lbl_1_bss_1010_gap_1015_fill_1016;
    s = fzgx_obj_camera_state;
    s = camera_state__fzgx_offset_1;
    s = *(u8 *)&camera_state__fzgx_offset_2;
    s = *(u8 *)&camera_state__fzgx_offset_4;
    s = *(u8 *)&lbl_1_bss_103C;
    s = *(u8 *)&lbl_1_bss_1040;
    s = *(u8 *)&lbl_1_bss_1044;
    s = fzgx_obj_camera_flag_0;
}
#pragma section code_type ".text"

void fn_1_BFA0(void) {
    
    if (lbl_1_bss_1014 != 0) {
        fn_1_CC5C();
    }
    if (fzgx_obj_camera_flag_0 != 0) {
        update_camera_transform((*(u8 (*)[40])&fzgx_obj_camera_state));
        lbl_8006E14C(lbl_1_bss_1044);
        fn_1_55FC4(lbl_1_bss_1044);
        fn_80072558();
        fn_1_55FF0(lbl_1_bss_1040);
        if (lbl_801A6CE0 & 1) {
            fn_1_55210(*(u32 *)(*(u32 *)(lbl_1_bss_38454 + 8) + 0x20));
        }
    }
}
/* fzgx:end fn_1_BFA0 */

/* fzgx:begin fn_1_C038 */
void fn_1_C038(s32 value, f32 start, f32 end) {
    f32 difference;
    f32 ratio;
    f32 converted;

    difference = end - start;
    ratio = difference / (((u32)(value * value)) >> 2);

    lbl_1_bss_10C0[0] = start;
    lbl_1_bss_10C0[1] = end;
    lbl_1_bss_10C0[4] = lbl_1_rodata_49C;

    lbl_1_bss_10C0[5] = ratio;
    converted = (u32)value;
    lbl_1_bss_10C0[3] = converted;
    lbl_1_bss_10C0[2] = converted;
}
/* fzgx:end fn_1_C038 */

/* fzgx:begin camera_save_slot */
typedef struct {
    u32 unk_0;
    u32 unk_4;
    u32 unk_8;
    u32 unk_C;
    u32 unk_10;
    u32 unk_14;
    u32 unk_18;
    u32 unk_1C;
    u32 unk_20;
} CameraSlot;

// Copies the current camera parameters into the selected camera slot.
void camera_save_slot(u8 index) {
    CameraSlot *dst = (CameraSlot *)&lbl_1_bss_10D8 + index;

    dst->unk_0 = camera_state.unk_0;
    dst->unk_4 = camera_state.unk_4;
    dst->unk_8 = camera_state.unk_8;
    dst->unk_C = camera_state.unk_C;
    dst->unk_10 = camera_state.unk_10;
    dst->unk_14 = camera_state.unk_14;
    dst->unk_18 = camera_state.unk_18;
    dst->unk_1C = camera_state.unk_1C;
    dst->unk_20 = *(u32 *)&camera_state.unk_20;
}
/* fzgx:end camera_save_slot */

/* fzgx:begin fn_1_C10C */
typedef struct {
    u32 unk_0;
    u32 unk_4;
    u32 unk_8;
    u32 unk_C;
    u32 unk_10;
    u32 unk_14;
    u32 unk_18;
    u32 unk_1C;
    u32 unk_20;
} CameraPreset;

typedef struct {
    u8 pad_0[0x5];
    u8 unk_5;
    u8 pad_6[0x2];
    CameraPreset current;
    u8 pad_2C[0x9C];
    CameraPreset presets[1];
} CameraState_np_fn_1_C10C;


/* file-scope objects of the retail TU, in retail order: MWCC addresses them off one section base */
u32 fzgx_obj_lbl_1_bss_1010;
u8 lbl_1_bss_1014;
u8 fzgx_pool_lbl_1_bss_1010_gap_1015;
u16 fzgx_pool_lbl_1_bss_1010_gap_1015_fill_1016;
CameraPreset fzgx_obj_camera_state;
u8 lbl_1_bss_103C[4];
f32 lbl_1_bss_1040;
f32 lbl_1_bss_1044;
u8 fzgx_obj_camera_flag_0;
u8 fzgx_obj_camera_flag_1;
u16 fzgx_pool_lbl_1_bss_1010_gap_104A;
u32 lbl_1_bss_104C[16];
u8 lbl_1_bss_108C[52];
f32 lbl_1_bss_10C0[6];
CameraPreset fzgx_obj_lbl_1_bss_10D8[1];
u32 lbl_1_bss_10D8__fzgx_offset_24[19];

#pragma section code_type ".fzgxpool"
static void fzgx_bss_layout(void) {
    volatile u8 s;  /* fzgx-allow: S2 layout primer sink: MWCC emits .bss objects in first-access order */
    s = *(u8 *)&fzgx_obj_lbl_1_bss_1010;
    s = lbl_1_bss_1014;
    s = *(u8 *)&fzgx_pool_lbl_1_bss_1010_gap_1015;
    s = *(u8 *)&fzgx_pool_lbl_1_bss_1010_gap_1015_fill_1016;
    s = *(u8 *)&fzgx_obj_camera_state;
    s = *(u8 *)&lbl_1_bss_103C;
    s = *(u8 *)&lbl_1_bss_1040;
    s = *(u8 *)&lbl_1_bss_1044;
    s = fzgx_obj_camera_flag_0;
    s = fzgx_obj_camera_flag_1;
    s = *(u8 *)&fzgx_pool_lbl_1_bss_1010_gap_104A;
    s = *(u8 *)&lbl_1_bss_104C;
    s = *(u8 *)&lbl_1_bss_108C;
    s = *(u8 *)&lbl_1_bss_10C0;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_10D8;
    s = *(u8 *)&lbl_1_bss_10D8__fzgx_offset_24;
}
#pragma section code_type ".text"

void fn_1_C10C(u8 idx) {
    fzgx_pool_lbl_1_bss_1010_gap_1015 = 0;
    fzgx_obj_camera_state = fzgx_obj_lbl_1_bss_10D8[idx];
}
/* fzgx:end fn_1_C10C */

/* fzgx:begin fn_1_C178 */
typedef struct { u8 pad_0[0x4]; f32 unk_4; u32 unk_8; f32 unk_C; } Bss_104C;
typedef struct {
    u8 pad_0[0x4]; f32 unk_4; f32 unk_8; f32 unk_C; f32 unk_10; f32 unk_14; f32 unk_18; f32 unk_1C;
    s16 unk_20; u8 pad_22[0x6]; f32 unk_28; f32 unk_2C; f32 unk_30; f32 unk_34; f32 unk_38; f32 unk_3C; f32 unk_40;
    s16 unk_44; u8 pad_46[0x2A];
} Obj_1_bss_10D8;
extern Bss_104C lbl_1_bss_104C;

void fn_1_C178(void *self) {
    OSReport(lbl_1_data_406C, lbl_1_bss_104C.unk_8, lbl_1_bss_104C.unk_C,
        lbl_1_bss_10D8.unk_4, lbl_1_bss_10D8.unk_8, lbl_1_bss_10D8.unk_C,
        lbl_1_bss_10D8.unk_10, lbl_1_bss_10D8.unk_14, lbl_1_bss_10D8.unk_18,
        lbl_1_bss_10D8.unk_1C, lbl_1_bss_10D8.unk_20);
    OSReport(lbl_1_data_40C8, lbl_1_bss_10D8.unk_28, lbl_1_bss_10D8.unk_2C,
        lbl_1_bss_10D8.unk_30, lbl_1_bss_10D8.unk_34, lbl_1_bss_10D8.unk_38,
        lbl_1_bss_10D8.unk_3C, lbl_1_bss_10D8.unk_40, lbl_1_bss_10D8.unk_44,
        self);
}
/* fzgx:end fn_1_C178 */

/* fzgx:begin camera_report_position */
// Reports the camera's current position values for debugging.
void camera_report_position(void) {
    OSReport(lbl_1_data_4128, lbl_1_bss_10D8.unk_10,
             lbl_1_bss_10D8.unk_14, lbl_1_bss_10D8.unk_18);
}
/* fzgx:end camera_report_position */

/* fzgx:begin fn_1_C268 noprologue */
#include "types.h"
#include "rel/main_rel/camera.h"

extern f64 lbl_1_rodata_4A8[7];
extern void OSReport(const char *format, ...);

void fn_1_C268(s32 arg) {
    if ((55.0) == lbl_1_bss_10D8.unk_1C) {
        OSReport((char *)lbl_1_data_4144, lbl_1_bss_10D8.unk_4,
                 lbl_1_bss_10D8.unk_8, lbl_1_bss_10D8.unk_C,
                 lbl_1_bss_10D8.unk_28, lbl_1_bss_10D8.unk_2C,
                 lbl_1_bss_10D8.unk_30, lbl_1_bss_10D8.unk_20, arg,
                 lbl_1_bss_10D8.unk_1C);
    } else {
        OSReport((char *)lbl_1_data_4198, lbl_1_bss_10D8.unk_4,
                 lbl_1_bss_10D8.unk_8, lbl_1_bss_10D8.unk_C,
                 lbl_1_bss_10D8.unk_28, lbl_1_bss_10D8.unk_2C,
                 lbl_1_bss_10D8.unk_30, lbl_1_bss_10D8.unk_20, arg,
                 lbl_1_bss_10D8.unk_1C);
    }
}
/* fzgx:end fn_1_C268 */

/* fzgx:begin fn_1_C304 */
// Reports the camera parameters and caller-supplied value for debugging.
void fn_1_C304(s32 arg) {
    OSReport(lbl_1_data_4198,
             lbl_1_bss_10D8.unk_4, lbl_1_bss_10D8.unk_8,
             lbl_1_bss_10D8.unk_C, lbl_1_bss_10D8.unk_10,
             lbl_1_bss_10D8.unk_14, lbl_1_bss_10D8.unk_18,
             lbl_1_bss_10D8.unk_20, arg,
             lbl_1_bss_10D8.unk_1C);
}
/* fzgx:end fn_1_C304 */

/* fzgx:begin camera_snapshot noprologue */
#include "types.h"

typedef struct CameraGlobals {
    u8 pad_00[0x08];
    u32 unk_08;
    u32 unk_0C;
    u32 unk_10;
    u32 unk_14;
    u32 unk_18;
    u32 unk_1C;
    u32 unk_20;
    u32 unk_24;
    u32 unk_28;
    u8 pad_2C[0x10];
    u32 unk_3C;
    u8 pad_40[0x88];
    u32 unk_C8;
    u32 unk_CC;
    u32 unk_D0;
    u32 unk_D4;
    u32 unk_D8;
    u32 unk_DC;
    u32 unk_E0;
    u32 unk_E4;
    u32 unk_E8;
} CameraGlobals;

extern CameraGlobals lbl_1_bss_1010;

// Copies the live camera state into its snapshot and resets the snapshot flag.
void camera_snapshot(void) {
    lbl_1_bss_1010.unk_08 = lbl_1_bss_1010.unk_C8;
    lbl_1_bss_1010.unk_0C = lbl_1_bss_1010.unk_CC;
    lbl_1_bss_1010.unk_10 = lbl_1_bss_1010.unk_D0;
    lbl_1_bss_1010.unk_14 = lbl_1_bss_1010.unk_D4;
    lbl_1_bss_1010.unk_18 = lbl_1_bss_1010.unk_D8;
    lbl_1_bss_1010.unk_1C = lbl_1_bss_1010.unk_DC;
    lbl_1_bss_1010.unk_20 = lbl_1_bss_1010.unk_E0;
    lbl_1_bss_1010.unk_24 = lbl_1_bss_1010.unk_E4;
    lbl_1_bss_1010.unk_28 = lbl_1_bss_1010.unk_E8;
    lbl_1_bss_1010.unk_3C = 0;
}
/* fzgx:end camera_snapshot */

/* fzgx:begin fn_1_C3B8 noprologue */
#include "types.h"

typedef struct {
    f32 x, y, z;
} CamVec;

typedef struct {
    u32 unk_0;
    CamVec pos;
    CamVec at;
    f32 unk_1C;
    s16 unk_20;
} CamKey;

typedef struct {
    s32 counter;
    s32 state;
    s32 total;
    f32 rate;
    u8 pad_10[0x30];
} CamCtl;

typedef struct {
    f32 unk_0;
    f32 unk_4;
    f32 unk_8;
    f32 unk_C;
    f32 unk_10;
    f32 unk_14;
} CamSway;

extern void lbl_8006D5A4(CamVec *a, CamVec *b, CamVec *out, f32 t);

/* file-scope objects of the retail TU, in retail order: MWCC addresses them off one section base */
u32 fzgx_obj_lbl_1_bss_1010;
u8 lbl_1_bss_1014;
u8 fzgx_pool_lbl_1_bss_1010_gap_1015;
u16 fzgx_pool_lbl_1_bss_1010_gap_1015_fill_1016;
CamKey fzgx_obj_camera_state;
u32 lbl_1_bss_103C;
u32 lbl_1_bss_1040;
u32 lbl_1_bss_1044;
u8 fzgx_obj_camera_flag_0;
u8 fzgx_obj_camera_flag_1;
u16 fzgx_pool_lbl_1_bss_1010_gap_104A;
CamCtl lbl_1_bss_104C;
u32 lbl_1_bss_108C[13];
CamSway lbl_1_bss_10C0;
CamKey fzgx_obj_lbl_1_bss_10D8[2];
u32 lbl_1_bss_10D8__fzgx_offset_48[10];

#pragma section code_type ".fzgxpool"
static void fzgx_bss_layout(void) {
    volatile u8 s;  /* fzgx-allow: S2 layout primer sink: MWCC emits .bss objects in first-access order */
    s = *(u8 *)&fzgx_obj_lbl_1_bss_1010;
    s = lbl_1_bss_1014;
    s = *(u8 *)&fzgx_pool_lbl_1_bss_1010_gap_1015;
    s = *(u8 *)&fzgx_pool_lbl_1_bss_1010_gap_1015_fill_1016;
    s = *(u8 *)&fzgx_obj_camera_state;
    s = *(u8 *)&lbl_1_bss_103C;
    s = *(u8 *)&lbl_1_bss_1040;
    s = *(u8 *)&lbl_1_bss_1044;
    s = fzgx_obj_camera_flag_0;
    s = fzgx_obj_camera_flag_1;
    s = *(u8 *)&fzgx_pool_lbl_1_bss_1010_gap_104A;
    s = *(u8 *)&lbl_1_bss_104C;
    s = *(u8 *)&lbl_1_bss_108C;
    s = *(u8 *)&lbl_1_bss_10C0;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_10D8;
    s = *(u8 *)&lbl_1_bss_10D8__fzgx_offset_48;
}
#pragma section code_type ".text"

void fn_1_C3B8(void) {
    CamKey from = fzgx_obj_lbl_1_bss_10D8[0];
    CamKey to = fzgx_obj_lbl_1_bss_10D8[1];
    f32 t;

    switch (lbl_1_bss_104C.state) {
    case 0:
        t = (f32)lbl_1_bss_104C.counter / lbl_1_bss_104C.total;
        lbl_8006D5A4(&from.pos, &to.pos, &fzgx_obj_camera_state.pos, t);
        lbl_8006D5A4(&from.at, &to.at, &fzgx_obj_camera_state.at, t);
        fzgx_obj_camera_state.unk_1C = from.unk_1C + (f32)(t * (to.unk_1C - from.unk_1C));
        fzgx_obj_camera_state.unk_20 = from.unk_20 + (s16)(t * (to.unk_20 - from.unk_20));
        if (lbl_1_bss_104C.counter >= lbl_1_bss_104C.total) {
            fzgx_pool_lbl_1_bss_1010_gap_1015 = 0;
        }
        break;
    case 3:
        lbl_1_bss_10C0.unk_8 -= 1.0f;
        if (lbl_1_bss_10C0.unk_8 < lbl_1_bss_10C0.unk_C / 2.0f) {
            lbl_1_bss_10C0.unk_10 -= lbl_1_bss_10C0.unk_14;
        } else {
            lbl_1_bss_10C0.unk_10 += lbl_1_bss_10C0.unk_14;
        }
        t = lbl_1_bss_10C0.unk_0 + lbl_1_bss_10C0.unk_10;
        lbl_1_bss_10C0.unk_0 = t;
        lbl_8006D5A4(&from.pos, &to.pos, &fzgx_obj_camera_state.pos, t);
        lbl_8006D5A4(&from.at, &to.at, &fzgx_obj_camera_state.at, t);
        fzgx_obj_camera_state.unk_1C = from.unk_1C + (f32)(t * (to.unk_1C - from.unk_1C));
        fzgx_obj_camera_state.unk_20 = from.unk_20 + (s16)(t * (to.unk_20 - from.unk_20));
        if (lbl_1_bss_104C.counter >= lbl_1_bss_104C.total) {
            fzgx_pool_lbl_1_bss_1010_gap_1015 = 0;
        }
        break;
    case 2:
        lbl_8006D5A4(&fzgx_obj_camera_state.pos, &to.pos, &fzgx_obj_camera_state.pos, lbl_1_bss_104C.rate);
        lbl_8006D5A4(&fzgx_obj_camera_state.at, &to.at, &fzgx_obj_camera_state.at, lbl_1_bss_104C.rate);
        fzgx_obj_camera_state.unk_1C += (f32)(lbl_1_bss_104C.rate * (to.unk_1C - fzgx_obj_camera_state.unk_1C));
        fzgx_obj_camera_state.unk_20 += (s32)(lbl_1_bss_104C.rate * (to.unk_20 - fzgx_obj_camera_state.unk_20));
        break;
    }
    lbl_1_bss_104C.counter++;
}
/* fzgx:end fn_1_C3B8 */

/* fzgx:begin fn_1_C770 */
extern void fn_1_BD54(void);
extern void fn_1_B870(void);
extern void camera_get_extended_state_storage(__typeof__(lbl_1_bss_F68));
extern void lbl_8006DBAC(void);
extern void fn_8006F038(void *, void *, s16);
extern void lbl_8006DCDC(void);
extern s16 fn_1_6B48(s16 value);
extern void fn_1_6D2C(u32);
extern s32 lbl_1_bss_F78;
extern void fn_1_A2DF4(u32, u32, u32);
extern s8 fn_1_86624(void);
extern s8 fn_1_86634(s32 index);
extern void OSPanic(u8 *file, int line, u8 *message, ...);
extern u8 lbl_1_bss_F74;
extern u8 lbl_1_bss_F75;
extern f32 lbl_1_rodata_188;
extern s32 fn_1_8708(u8 mode, f32 *value0, f32 *value1);
extern void fn_1_8A0C(s16 index);
extern void fn_1_A6FE8(void);
extern void fn_1_8D08(GameCameraEntry *value);
extern f32 lbl_1_bss_1040;
extern f32 lbl_1_bss_1044;
extern void OSReport(const unsigned char *, ...);
extern u8 lbl_1_bss_103C[4];
extern u8 lbl_1_bss_108C[52];
extern u8 lbl_1_bss_1014;

extern s8 fn_1_86624(void);
extern s8 fn_1_86634(s32 index);
extern void OSPanic(u8 *file, int line, u8 *message, ...);
extern void fn_1_8A0C(s16 index);
extern void OSReport(const unsigned char *, ...);

extern f32 lbl_1_rodata_2E0[32];
extern f32 lbl_8006D6FC(f32 *value, void *target);
u32 fn_1_6514(u32);
extern struct fn_1_6400_lbl_801A6410 lbl_801A6410;
extern u32 fn_1_46B4(u32, u32, void *, u32);
extern f64 lbl_1_rodata_478;
extern f32 lbl_1_rodata_49C;
extern f32 lbl_1_bss_10C0[6];

typedef struct {
    u32 w[9];
} CamKey;

/* playback of the camera keys (fn_1_C3B8) */
typedef struct {
    s32 unk_0;
    s32 unk_4;
    s32 unk_8;
    f32 unk_C;
    u8 pad_10[0x30];
} CamCtl;

extern f32 lbl_1_bss_BF0[32];

/* the retail TU's .bss objects this function uses, at their retail offsets, so MWCC addresses them off one section base */
u32 fzgx_obj_lbl_1_bss_1010;
u8 lbl_1_bss_1014;
u8 fzgx_pool_lbl_1_bss_1010_gap_1015;
u16 fzgx_pool_lbl_1_bss_1010_gap_1015_fill_1016;
CamKey fzgx_obj_camera_state;
u8 lbl_1_bss_103C[4];
f32 lbl_1_bss_1040;
f32 lbl_1_bss_1044;
u8 fzgx_obj_camera_flag_0;
u8 fzgx_obj_camera_flag_1;
u16 fzgx_pool_lbl_1_bss_1010_gap_104A;
CamCtl lbl_1_bss_104C;
u8 lbl_1_bss_108C[52];
f32 lbl_1_bss_10C0[6];
CamKey fzgx_obj_lbl_1_bss_10D8[2];
CamKey lbl_1_bss_10D8__fzgx_offset_48;

#pragma section code_type ".fzgxpool"
static void fzgx_bss_layout(void) {
    volatile u8 s;  /* fzgx-allow: S2 layout primer sink: MWCC emits .bss objects in first-access order */
    s = *(u8 *)&fzgx_obj_lbl_1_bss_1010;
    s = lbl_1_bss_1014;
    s = *(u8 *)&fzgx_pool_lbl_1_bss_1010_gap_1015;
    s = *(u8 *)&fzgx_pool_lbl_1_bss_1010_gap_1015_fill_1016;
    s = *(u8 *)&fzgx_obj_camera_state;
    s = *(u8 *)&lbl_1_bss_103C;
    s = *(u8 *)&lbl_1_bss_1040;
    s = *(u8 *)&lbl_1_bss_1044;
    s = fzgx_obj_camera_flag_0;
    s = fzgx_obj_camera_flag_1;
    s = *(u8 *)&fzgx_pool_lbl_1_bss_1010_gap_104A;
    s = *(u8 *)&lbl_1_bss_104C;
    s = *(u8 *)&lbl_1_bss_108C;
    s = *(u8 *)&lbl_1_bss_10C0;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_10D8;
    s = *(u8 *)&lbl_1_bss_10D8__fzgx_offset_48;
}

/* the camera TU's literal pool in retail order, ahead of this function's constants */
static void fzgx_pool_head(f32 *f) {
    f[0] = 1.0f;
    f[1] = 0.1f;
    f[2] = 0.01f;
    f[3] = 55.0f;
}

static const u32 fzgx_pool_table_10[6] = { 0, 0, 0, 0, 0, 0 };

static void fzgx_pool_tail(f64 *d, f32 *f) {
    d[0] = fzgx_pool_table_10[0];
    d[1] = 0.040000000000000008;
    d[2] = 1.0;
    d[3] = 4.0;
    d[4] = 140.0;
    d[5] = 50.0;
    d[6] = 60.0;
    d[7] = 0.09;
    d[8] = 0.3;
    d[9] = 0.1;
    d[10] = 90000.0;
    d[11] = 4503599627370496.0;
    d[12] = 4503601774854144.0;
    d[13] = 0.02;
    f[0] = 60.0f;
    f[1] = 15.0f;
    f[2] = 0.9f;
    f[3] = 0.0f;
    f[4] = 0.5f;
    d[14] = 55.0;
    f[5] = 10.0f;
    d[15] = 0.0;
    d[16] = 0.5;
    d[17] = 0.0001;
}
#pragma section code_type ".text"

/* the TU's .data from lbl_1_data_4068: the editor's bytes (item 1's value, the selected item),
 * then the report formats ahead of this function's strings */
u16 fzgx_pool_lbl_1_data_4068 = 0xF000;
u8 fzgx_pool_data_406A = 9;
u8 fzgx_pool_data_406B = 3;

extern void fzgx_touch(const char *);
#pragma section code_type ".fzgxpool"
static void fzgx_data_layout(void) {
    volatile u8 s;  /* fzgx-allow: S2 layout primer sink */
    s = fzgx_pool_lbl_1_data_4068;
    s = fzgx_pool_data_406A;
    s = fzgx_pool_data_406B;
    fzgx_touch("\t{ %3d, %1.3f, {  0,{  %8.3f, %8.3f, %8.3f }, {  %8.3f, %8.3f, %8.3f },  %5.1f, %5d, 0,},\n");
    fzgx_touch("\t              {  0,{  %8.3f, %8.3f, %8.3f }, {  %8.3f, %8.3f, %8.3f },  %5.1f, %5d, 0,}, %s},\n");
    fzgx_touch("\t{  %8.3f, %8.3f, %8.3f },\n");
    fzgx_touch("\t{ 00,{  %8.3f, %8.3f, %8.3f }, {  %8.3f, %8.3f, %8.3f }, %5d,  PERS_DEGREE, %s},\n");
    fzgx_touch("\t{ 00,{  %8.3f, %8.3f, %8.3f }, {  %8.3f, %8.3f, %8.3f }, %5d,  %11.3f, %s},\n");
}
#pragma section code_type ".text"

extern void camera_save_slot(u8);
extern void camera_snapshot(void);
extern void fn_1_C038(f32 start, f32 end, s32 frames);  /* retail evaluates the floats first */
extern void fn_1_C10C(u8);
extern void fn_1_C178(void *);
extern void camera_report_position(void);
extern void fn_1_C268(s32);
extern void fn_1_C304(s32);
extern void fn_1_C3B8(void);

/* a value stepped past one end of [lo, hi] restarts from the other */
#define WRAP(v, lo, hi) ((v) > (hi) ? (lo) : ((v) < (lo) ? (hi) : (v)))

static inline s32 menu_prev(s32 item) {
    if (item - 1 > 38) return 0;
    return --item < 0 ? 38 : item;
}
static inline s32 menu_next(s32 item) {
    if (item + 1 > 38) return 0;
    return ++item < 0 ? 38 : item;
}

/* The camera editor's input: up/down picks an item, left/right edits or runs it. */
void fn_1_C770(void) {
    Obj_1_bss_D58 *pad = &lbl_1_bss_D58;
    s32 item;
    s32 dir;
    s32 step;
    s32 n;
    s32 v;
    f64 d;

    dir = 0;
    step = 1;
    if ((pad->unk_10 >> 8) & 1) {
        dir = 1;
    } else if ((pad->unk_10 >> 9) & 1) {
        dir = -1;
    }
    if (lbl_1_bss_BF0[5]) {
        step = 10.0f * lbl_1_bss_BF0[5];
    }

    item = fzgx_pool_data_406B;
    if (item == 1) {
        n = fzgx_pool_data_406A;
        n += dir * step;
        if (n > 15) {
            v = 0;
        } else {
            v = n < 0 ? 15 : n;
        }
        fzgx_pool_data_406A = v;
    }
    if (item == 2 && dir != 0) {
        lbl_1_bss_1014 = 0;
    }
    if (item == 3 && dir != 0) {
        camera_save_slot(0);
    }
    if ((s32)fzgx_pool_data_406B == 4 && dir != 0) {
        camera_save_slot(1);
    }
    if ((s32)fzgx_pool_data_406B == 5) {
        d = 0.0001 * dir * step;
        lbl_1_bss_104C.unk_C = WRAP(lbl_1_bss_104C.unk_C + d, 0.0, 0.5);
    }
    if ((s32)fzgx_pool_data_406B == 6) {
        v = lbl_1_bss_104C.unk_8 + dir * step;
        lbl_1_bss_104C.unk_8 = WRAP(v, 0, 1000);
    }
    if ((s32)fzgx_pool_data_406B == 7 && dir != 0) {
        fzgx_pool_lbl_1_bss_1010_gap_1015 = 1;
        lbl_1_bss_10D8__fzgx_offset_48 = fzgx_obj_camera_state;
        lbl_1_bss_104C.unk_4 = 0;  /* NORMAL */
        camera_snapshot();
    }
    if ((s32)fzgx_pool_data_406B == 8 && dir != 0) {
        fzgx_pool_lbl_1_bss_1010_gap_1015 = 1;
        lbl_1_bss_10D8__fzgx_offset_48 = fzgx_obj_camera_state;
        lbl_1_bss_104C.unk_4 = 3;  /* EASE_IN_OUT */
        fn_1_C038(0.0f, 1.0f, lbl_1_bss_104C.unk_8);
        camera_snapshot();
    }
    if ((s32)fzgx_pool_data_406B == 9 && dir != 0) {
        fzgx_pool_lbl_1_bss_1010_gap_1015 = 1;
        lbl_1_bss_10D8__fzgx_offset_48 = fzgx_obj_camera_state;
        lbl_1_bss_104C.unk_4 = 2;  /* EASE_OUT */
        camera_snapshot();
    }
    if ((s32)fzgx_pool_data_406B == 10 && dir != 0) {
        fn_1_C10C(0);
    }
    if ((s32)fzgx_pool_data_406B == 11 && dir != 0) {
        fn_1_C10C(1);
    }
    if ((s32)fzgx_pool_data_406B == 12 && dir != 0) {
        lbl_1_bss_1014 = 0;
    }
    if ((s32)fzgx_pool_data_406B == 13 && dir != 0) {
        fn_1_C178("NORMAL");
    }
    if ((s32)fzgx_pool_data_406B == 14 && dir != 0) {
        fn_1_C178("EASE_OUT");
    }
    if ((s32)fzgx_pool_data_406B == 15 && dir != 0) {
        fn_1_C178("EASE_IN_OUT");
    }
    if ((s32)fzgx_pool_data_406B == 16 && dir != 0) {
        camera_report_position();
    }
    if ((s32)fzgx_pool_data_406B == 17 && dir != 0) {
        fn_1_C268((s32)"STATIC_MOVE_PERS");
    }
    if ((s32)fzgx_pool_data_406B == 18 && dir != 0) {
        fn_1_C304((s32)"STATIC_FIX");
    }

    if ((pad->unk_10 >> 3) & 1) {
        fzgx_pool_data_406B = menu_prev(fzgx_pool_data_406B);
    } else if ((pad->unk_10 >> 2) & 1) {
        fzgx_pool_data_406B = menu_next(fzgx_pool_data_406B);
    }

    if (fzgx_pool_lbl_1_bss_1010_gap_1015 != 0) {
        fn_1_C3B8();
    }
    if (((lbl_1_bss_D58.unk_0 >> 10) & 1) && ((lbl_1_bss_D58.unk_8 >> 11) & 1)) {
        fzgx_pool_lbl_1_bss_1010_gap_1015 = 0;
        lbl_1_bss_1014 = 0;
    }
}
/* fzgx:end fn_1_C770 */

/* fzgx:begin fn_1_CC5C */
#ifndef REL_MAIN_REL_CAMERA_H
#define REL_MAIN_REL_CAMERA_H
#ifndef REL_MAIN_REL_GLOBALS_H
#define REL_MAIN_REL_GLOBALS_H

#endif  // REL_MAIN_REL_GLOBALS_H

// fzgx_pool_lbl_1_data_4068: .data size 0x1, 3 refs from camera.c (own data block)
extern u16 fzgx_pool_lbl_1_data_4068;

// lbl_1_bss_D58: .bss size 0x18, 3 refs from camera.c
#ifndef FZGX_TYPES_LBL_1_BSS_D58
#define FZGX_TYPES_LBL_1_BSS_D58
// one layout for every TU header that declares this symbol (librarian, typedefs.json)
typedef struct {
    u16 unk_0;  // 5 loads, 0 stores
    u16 unk_2;  // 1 loads, 0 stores
    u8 pad_4[0x4];
    u16 unk_8;  // 24 loads, 0 stores
    u16 unk_A;  // 3 loads, 0 stores
    u8 pad_C[0x4];
    u16 unk_10;  // 18 loads, 0 stores
    u16 unk_12;  // 4 loads, 0 stores
    u8 pad_14[0x4];
} Obj_1_bss_D58_np_fn_1_CC5C;
#endif
extern Obj_1_bss_D58_np_fn_1_CC5C lbl_1_bss_D58;

#endif  // REL_MAIN_REL_CAMERA_H

/* end rel/main_rel/camera.h */

/* RGBA colour, passed by value (MWCC copies it to the stack per call) */
typedef struct { u8 r, g, b, a; } fn_1_CC5C_Color;

u16 fzgx_pool_lbl_1_data_4068 = 0xF000;
u8 fzgx_pool_fn_1_CC5C_menu_cursor = 9;
u8 fzgx_pool_fn_1_CC5C_menu_selected = 3;
u8 fzgx_pool_fn_1_CC5C_menu_data_pad[0x1BC] = {
    0x09, 0x7B, 0x20, 0x25, 0x33, 0x64, 0x2C, 0x20, 0x25, 0x31, 0x2E, 0x33, 0x66, 0x2C, 0x20, 0x7B,
    0x20, 0x20, 0x30, 0x2C, 0x7B, 0x20, 0x20, 0x25, 0x38, 0x2E, 0x33, 0x66, 0x2C, 0x20, 0x25, 0x38,
    0x2E, 0x33, 0x66, 0x2C, 0x20, 0x25, 0x38, 0x2E, 0x33, 0x66, 0x20, 0x7D, 0x2C, 0x20, 0x7B, 0x20,
    0x20, 0x25, 0x38, 0x2E, 0x33, 0x66, 0x2C, 0x20, 0x25, 0x38, 0x2E, 0x33, 0x66, 0x2C, 0x20, 0x25,
    0x38, 0x2E, 0x33, 0x66, 0x20, 0x7D, 0x2C, 0x20, 0x20, 0x25, 0x35, 0x2E, 0x31, 0x66, 0x2C, 0x20,
    0x25, 0x35, 0x64, 0x2C, 0x20, 0x30, 0x2C, 0x7D, 0x2C, 0x0A, 0x00, 0x00, 0x09, 0x20, 0x20, 0x20,
    0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x7B, 0x20, 0x20, 0x30, 0x2C,
    0x7B, 0x20, 0x20, 0x25, 0x38, 0x2E, 0x33, 0x66, 0x2C, 0x20, 0x25, 0x38, 0x2E, 0x33, 0x66, 0x2C,
    0x20, 0x25, 0x38, 0x2E, 0x33, 0x66, 0x20, 0x7D, 0x2C, 0x20, 0x7B, 0x20, 0x20, 0x25, 0x38, 0x2E,
    0x33, 0x66, 0x2C, 0x20, 0x25, 0x38, 0x2E, 0x33, 0x66, 0x2C, 0x20, 0x25, 0x38, 0x2E, 0x33, 0x66,
    0x20, 0x7D, 0x2C, 0x20, 0x20, 0x25, 0x35, 0x2E, 0x31, 0x66, 0x2C, 0x20, 0x25, 0x35, 0x64, 0x2C,
    0x20, 0x30, 0x2C, 0x7D, 0x2C, 0x20, 0x25, 0x73, 0x7D, 0x2C, 0x0A, 0x00, 0x09, 0x7B, 0x20, 0x20,
    0x25, 0x38, 0x2E, 0x33, 0x66, 0x2C, 0x20, 0x25, 0x38, 0x2E, 0x33, 0x66, 0x2C, 0x20, 0x25, 0x38,
    0x2E, 0x33, 0x66, 0x20, 0x7D, 0x2C, 0x0A, 0x00, 0x09, 0x7B, 0x20, 0x30, 0x30, 0x2C, 0x7B, 0x20,
    0x20, 0x25, 0x38, 0x2E, 0x33, 0x66, 0x2C, 0x20, 0x25, 0x38, 0x2E, 0x33, 0x66, 0x2C, 0x20, 0x25,
    0x38, 0x2E, 0x33, 0x66, 0x20, 0x7D, 0x2C, 0x20, 0x7B, 0x20, 0x20, 0x25, 0x38, 0x2E, 0x33, 0x66,
    0x2C, 0x20, 0x25, 0x38, 0x2E, 0x33, 0x66, 0x2C, 0x20, 0x25, 0x38, 0x2E, 0x33, 0x66, 0x20, 0x7D,
    0x2C, 0x20, 0x25, 0x35, 0x64, 0x2C, 0x20, 0x20, 0x50, 0x45, 0x52, 0x53, 0x5F, 0x44, 0x45, 0x47,
    0x52, 0x45, 0x45, 0x2C, 0x20, 0x25, 0x73, 0x7D, 0x2C, 0x0A, 0x00, 0x00, 0x09, 0x7B, 0x20, 0x30,
    0x30, 0x2C, 0x7B, 0x20, 0x20, 0x25, 0x38, 0x2E, 0x33, 0x66, 0x2C, 0x20, 0x25, 0x38, 0x2E, 0x33,
    0x66, 0x2C, 0x20, 0x25, 0x38, 0x2E, 0x33, 0x66, 0x20, 0x7D, 0x2C, 0x20, 0x7B, 0x20, 0x20, 0x25,
    0x38, 0x2E, 0x33, 0x66, 0x2C, 0x20, 0x25, 0x38, 0x2E, 0x33, 0x66, 0x2C, 0x20, 0x25, 0x38, 0x2E,
    0x33, 0x66, 0x20, 0x7D, 0x2C, 0x20, 0x25, 0x35, 0x64, 0x2C, 0x20, 0x20, 0x25, 0x31, 0x31, 0x2E,
    0x33, 0x66, 0x2C, 0x20, 0x25, 0x73, 0x7D, 0x2C, 0x0A, 0x00, 0x00, 0x00, 0x4E, 0x4F, 0x52, 0x4D,
    0x41, 0x4C, 0x00, 0x00, 0x45, 0x41, 0x53, 0x45, 0x5F, 0x4F, 0x55, 0x54, 0x00, 0x00, 0x00, 0x00,
    0x45, 0x41, 0x53, 0x45, 0x5F, 0x49, 0x4E, 0x5F, 0x4F, 0x55, 0x54, 0x00, 0x53, 0x54, 0x41, 0x54,
    0x49, 0x43, 0x5F, 0x4D, 0x4F, 0x56, 0x45, 0x5F, 0x50, 0x45, 0x52, 0x53, 0x00, 0x00, 0x00, 0x00,
    0x53, 0x54, 0x41, 0x54, 0x49, 0x43, 0x5F, 0x46, 0x49, 0x58, 0x00, 0x00,
};
char fzgx_pool_fn_1_CC5C_fmt_1C0[0x10] = { 0x43, 0x41, 0x4D, 0x83, 0x47, 0x83, 0x66, 0x83, 0x42, 0x83, 0x5E, 0x0A, 0x00, 0x00, 0x00, 0x00 };
char fzgx_pool_fn_1_CC5C_fmt_1D0[0x8] = { 0x82, 0xA2, 0x82, 0xC7, 0x82, 0xA4, 0x20, 0x00 };
char fzgx_pool_fn_1_CC5C_fmt_1D8[0x8] = { 0x82, 0xC6, 0x82, 0xB6, 0x82, 0xE9, 0x0A, 0x00 };
char fzgx_pool_fn_1_CC5C_fmt_1E0[0x10] = { 0x83, 0x5A, 0x83, 0x62, 0x83, 0x67, 0x20, 0x83, 0x4A, 0x83, 0x81, 0x83, 0x89, 0x41, 0x0A, 0x00 };
char fzgx_pool_fn_1_CC5C_fmt_1F0[0x10] = { 0x83, 0x5A, 0x83, 0x62, 0x83, 0x67, 0x20, 0x83, 0x4A, 0x83, 0x81, 0x83, 0x89, 0x42, 0x0A, 0x00 };
char fzgx_pool_fn_1_CC5C_fmt_200[0xC] = { 0x91, 0xAC, 0x93, 0x78, 0x20, 0x25, 0x31, 0x2E, 0x33, 0x66, 0x0A, 0x00 };
char fzgx_pool_fn_1_CC5C_fmt_20C[0xC] = { 0x83, 0x52, 0x83, 0x7D, 0x20, 0x25, 0x33, 0x64, 0x0A, 0x00, 0x00, 0x00 };
char fzgx_pool_fn_1_CC5C_fmt_218[0x14] = { 0x4E, 0x4F, 0x52, 0x4D, 0x41, 0x4C, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x3A, 0x20, 0x50, 0x4C, 0x41, 0x59, 0x0A, 0x00 };
char fzgx_pool_fn_1_CC5C_fmt_22C[0x14] = { 0x45, 0x41, 0x53, 0x45, 0x5F, 0x49, 0x4E, 0x5F, 0x4F, 0x55, 0x54, 0x20, 0x3A, 0x20, 0x50, 0x4C, 0x41, 0x59, 0x0A, 0x00 };
char fzgx_pool_fn_1_CC5C_fmt_240[0x14] = { 0x45, 0x41, 0x53, 0x45, 0x5F, 0x4F, 0x55, 0x54, 0x20, 0x20, 0x20, 0x20, 0x3A, 0x20, 0x50, 0x4C, 0x41, 0x59, 0x0A, 0x00 };
char fzgx_pool_fn_1_CC5C_fmt_254[0x10] = { 0x83, 0x4A, 0x83, 0x81, 0x83, 0x89, 0x41, 0x82, 0xC9, 0x88, 0xDA, 0x93, 0xAE, 0x0A, 0x00, 0x00 };
char fzgx_pool_fn_1_CC5C_fmt_264[0x10] = { 0x83, 0x4A, 0x83, 0x81, 0x83, 0x89, 0x42, 0x82, 0xC9, 0x88, 0xDA, 0x93, 0xAE, 0x0A, 0x00, 0x00 };
char fzgx_pool_fn_1_CC5C_fmt_274[0xC] = { 0x82, 0xC6, 0x82, 0xB6, 0x82, 0xE9, 0x0A, 0x0A, 0x00, 0x00, 0x00, 0x00 };
char fzgx_pool_fn_1_CC5C_fmt_280[0x8] = { 0x20, 0x4E, 0x4F, 0x52, 0x4D, 0x41, 0x4C, 0x00 };
char fzgx_pool_fn_1_CC5C_fmt_288[0x8] = { 0x20, 0x4F, 0x55, 0x54, 0x00, 0x00, 0x00, 0x00 };
char fzgx_pool_fn_1_CC5C_fmt_290[0xC] = { 0x20, 0x49, 0x4E, 0x5F, 0x4F, 0x55, 0x54, 0x0A, 0x00, 0x00, 0x00, 0x00 };
char fzgx_pool_fn_1_CC5C_fmt_29C[0x8] = { 0x20, 0x43, 0x41, 0x4D, 0x5F, 0x42, 0x00, 0x00 };
char fzgx_pool_fn_1_CC5C_fmt_2A4[0x8] = { 0x20, 0x53, 0x54, 0x41, 0x54, 0x49, 0x43, 0x00 };
char fzgx_pool_fn_1_CC5C_fmt_2AC[0x10] = { 0x20, 0x53, 0x54, 0x41, 0x54, 0x49, 0x43, 0x5F, 0x46, 0x49, 0x58, 0x0A, 0x00, 0x00, 0x00, 0x00 };
char fzgx_pool_fn_1_CC5C_fmt_2BC[0x4] = { 0x0A, 0x00, 0x00, 0x00 };
char fzgx_pool_fn_1_CC5C_fmt_2C0[0xC] = { 0x54, 0x49, 0x4D, 0x45, 0x52, 0x3A, 0x25, 0x64, 0x0A, 0x00, 0x00, 0x00 };
char fzgx_pool_fn_1_CC5C_fmt_2CC[0xC] = { 0x20, 0x70, 0x65, 0x72, 0x73, 0x3A, 0x25, 0x35, 0x2E, 0x33, 0x66, 0x00 };
char fzgx_pool_fn_1_CC5C_fmt_2D8[0x10] = { 0x20, 0x7A, 0x61, 0x6E, 0x67, 0x3A, 0x25, 0x30, 0x34, 0x68, 0x78, 0x0A, 0x00, 0x00, 0x00, 0x00 };
char fzgx_pool_fn_1_CC5C_fmt_2E8[0x10] = { 0x83, 0x4A, 0x83, 0x81, 0x83, 0x89, 0x41, 0x20, 0x78, 0x3A, 0x25, 0x35, 0x2E, 0x33, 0x66, 0x00 };
char fzgx_pool_fn_1_CC5C_fmt_2F8[0xC] = { 0x20, 0x79, 0x3A, 0x25, 0x35, 0x2E, 0x33, 0x66, 0x00, 0x00, 0x00, 0x00 };
char fzgx_pool_fn_1_CC5C_fmt_304[0xC] = { 0x20, 0x7A, 0x3A, 0x25, 0x35, 0x2E, 0x33, 0x66, 0x0A, 0x00, 0x00, 0x00 };
char fzgx_pool_fn_1_CC5C_fmt_310[0x10] = { 0x81, 0x40, 0x81, 0x40, 0x81, 0x40, 0x20, 0x20, 0x78, 0x3A, 0x25, 0x35, 0x2E, 0x33, 0x66, 0x00 };
char fzgx_pool_fn_1_CC5C_fmt_320[0x10] = { 0x20, 0x20, 0x70, 0x65, 0x72, 0x73, 0x3A, 0x25, 0x35, 0x2E, 0x33, 0x66, 0x0A, 0x00, 0x00, 0x00 };
char fzgx_pool_fn_1_CC5C_fmt_330[0x10] = { 0x20, 0x20, 0x7A, 0x61, 0x6E, 0x67, 0x3A, 0x25, 0x30, 0x34, 0x68, 0x78, 0x0A, 0x00, 0x00, 0x00 };
char fzgx_pool_fn_1_CC5C_fmt_340[0x10] = { 0x83, 0x4A, 0x83, 0x81, 0x83, 0x89, 0x42, 0x20, 0x78, 0x3A, 0x25, 0x35, 0x2E, 0x33, 0x66, 0x00 };
extern void fn_1_49410(void);
extern void fn_1_49514(fn_1_CC5C_Color);
extern void fn_1_4954C(f32);
extern void fn_1_4955C(f32, f32);
extern void fn_1_495FC(void);
extern void fn_1_496FC(f32, f32);
extern void fn_1_4A0D8(const char *);
extern void fn_1_4AE0C(const char *, ...);

#pragma opt_common_subs off
/* file-scope objects of the retail TU, in retail order: MWCC addresses them off one section base */
u32 fzgx_obj_lbl_1_bss_1010;
u8 lbl_1_bss_1014;
u8 fzgx_pool_lbl_1_bss_1010_gap_1015;
u16 fzgx_pool_lbl_1_bss_1010_gap_1015_fill_1016;
u8 fzgx_obj_camera_state;
u8 camera_state__fzgx_offset_1;
u16 camera_state__fzgx_offset_2;
u32 camera_state__fzgx_offset_4[8];
u8 lbl_1_bss_103C[4];
f32 lbl_1_bss_1040;
f32 lbl_1_bss_1044;
u8 fzgx_obj_camera_flag_0;
u8 fzgx_obj_camera_flag_1;
u16 fzgx_pool_lbl_1_bss_1010_gap_104A;
u32 fzgx_obj_lbl_1_bss_104C;
u32 lbl_1_bss_104C__fzgx_offset_4[15];
u8 lbl_1_bss_108C[52];
f32 lbl_1_bss_10C0[6];
u8 fzgx_obj_lbl_1_bss_10D8;
u8 lbl_1_bss_10D8__fzgx_offset_1;
u16 lbl_1_bss_10D8__fzgx_offset_2;
u32 lbl_1_bss_10D8__fzgx_offset_4[26];
u8 lbl_1_bss_10D8__fzgx_offset_6C;
u8 lbl_1_bss_10D8__fzgx_offset_6D;
u16 lbl_1_bss_10D8__fzgx_offset_6E;

#pragma section code_type ".fzgxpool"
static void fzgx_bss_layout(void) {
    volatile u8 s;  /* fzgx-allow: S2 layout primer sink: MWCC emits .bss objects in first-access order */
    s = *(u8 *)&fzgx_obj_lbl_1_bss_1010;
    s = lbl_1_bss_1014;
    s = *(u8 *)&fzgx_pool_lbl_1_bss_1010_gap_1015;
    s = *(u8 *)&fzgx_pool_lbl_1_bss_1010_gap_1015_fill_1016;
    s = fzgx_obj_camera_state;
    s = camera_state__fzgx_offset_1;
    s = *(u8 *)&camera_state__fzgx_offset_2;
    s = *(u8 *)&camera_state__fzgx_offset_4;
    s = *(u8 *)&lbl_1_bss_103C;
    s = *(u8 *)&lbl_1_bss_1040;
    s = *(u8 *)&lbl_1_bss_1044;
    s = fzgx_obj_camera_flag_0;
    s = fzgx_obj_camera_flag_1;
    s = *(u8 *)&fzgx_pool_lbl_1_bss_1010_gap_104A;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_104C;
    s = *(u8 *)&lbl_1_bss_104C__fzgx_offset_4;
    s = *(u8 *)&lbl_1_bss_108C;
    s = *(u8 *)&lbl_1_bss_10C0;
    s = fzgx_obj_lbl_1_bss_10D8;
    s = lbl_1_bss_10D8__fzgx_offset_1;
    s = *(u8 *)&lbl_1_bss_10D8__fzgx_offset_2;
    s = *(u8 *)&lbl_1_bss_10D8__fzgx_offset_4;
    s = lbl_1_bss_10D8__fzgx_offset_6C;
    s = lbl_1_bss_10D8__fzgx_offset_6D;
    s = *(u8 *)&lbl_1_bss_10D8__fzgx_offset_6E;
}

/* literal pool of the retail TU in retail order; this function's own
 * colour table and 2.0f follow the 0.0001 double. */
__declspec(section ".fzgxpool") static void fzgx_pool_prime1(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    s = 1.0f;
    s = 0.10000000149011612f;
    s = 0.009999999776482582f;
    s = 55.0f;
}
static const unsigned long fzgx_pool_table2[6] = {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep2(void) { const unsigned long *volatile cp; cp = fzgx_pool_table2; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime3(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    d = 0.04000000000000001;
    d = 1.0;
    d = 4.0;
    d = 140.0;
    d = 50.0;
    d = 60.0;
    d = 0.09;
    d = 0.3;
    d = 0.1;
    d = 90000.0;
    d = 4503599627370496.0;
    d = 4503601774854144.0;
    d = 0.02;
    s = 60.0f;
    s = 15.0f;
    s = 0.8999999761581421f;
    s = 0.0f;
    s = 0.5f;
}
static const unsigned long fzgx_pool_table4[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep4(void) { const unsigned long *volatile cp; cp = fzgx_pool_table4; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime5(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    d = 55.0;
    s = 10.0f;
}
static const unsigned long fzgx_pool_table6[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep6(void) { const unsigned long *volatile cp; cp = fzgx_pool_table6; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime7(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    d = 0.0;
    d = 0.5;
    d = 0.0001;
}
#pragma section code_type ".text"

/* one past the camera state block: a field address equal to it has no value to show */
#define END_ADDR ((u32)&lbl_1_bss_10D8__fzgx_offset_6C)

/* the field address is advanced through a pointer cast so the offset stays on the
 * address variable (retail: addi r3, r3, 0xc; lfs f1, 0x0(r3)) */
#define ADVANCE(off) p = (u32)((u8 *)p + (off))
#define FIELD(type) (*(type *)p)

#define SELECT_COLOR(n) \
    if ((s32)fzgx_pool_fn_1_CC5C_menu_selected == (n)) fn_1_49514(colors[0]); else fn_1_49514(colors[2])

#define PRINT_VALUE(fmt, val) \
    if (p != END_ADDR) fn_1_4AE0C(fmt, val); else fn_1_4A0D8(fmt)

#define PRINT_VALUE2(fmt, val) \
    if (p != END_ADDR) { \
        if (p == END_ADDR) fn_1_4AE0C(fmt, val); else fn_1_4AE0C(fmt, val); \
    } else fn_1_4A0D8(fmt)

void fn_1_CC5C(void) {
    fn_1_CC5C_Color colors[3] = { { 0x00, 0xFF, 0x00, 0xFF }, { 0x80, 0x80, 0x80, 0xFF }, { 0xFF, 0xFF, 0xFF, 0xFF } };
    u8 idx;
    u16 x;
    u16 y;
    u32 p;

    idx = fzgx_pool_fn_1_CC5C_menu_cursor;
    x = (idx % 4) * 150;
    y = ((idx >> 2) & 0x3F) * 60;
    if (((lbl_1_bss_D58.unk_2 >> 8) & 1) == 0) {
        fn_1_49410();
        fn_1_4954C(2.0f);
        fn_1_4955C(0.5f, 0.5f);
        fn_1_495FC();
        fn_1_496FC(x, y);

        SELECT_COLOR(0);
        fn_1_4A0D8(fzgx_pool_fn_1_CC5C_fmt_1C0);
        SELECT_COLOR(1);
        p = (u32)&fzgx_pool_fn_1_CC5C_menu_cursor;
        PRINT_VALUE(fzgx_pool_fn_1_CC5C_fmt_1D0, fzgx_pool_fn_1_CC5C_menu_cursor);
        SELECT_COLOR(2);
        fn_1_4A0D8(fzgx_pool_fn_1_CC5C_fmt_1D8);
        SELECT_COLOR(3);
        fn_1_4A0D8(fzgx_pool_fn_1_CC5C_fmt_1E0);
        SELECT_COLOR(4);
        fn_1_4A0D8(fzgx_pool_fn_1_CC5C_fmt_1F0);
        SELECT_COLOR(5);
        p = (u32)&fzgx_obj_lbl_1_bss_104C;
        ADVANCE(12);
        PRINT_VALUE2(fzgx_pool_fn_1_CC5C_fmt_200, FIELD(f32));
        SELECT_COLOR(6);
        p = (u32)&fzgx_obj_lbl_1_bss_104C;
        ADVANCE(8);
        PRINT_VALUE2(fzgx_pool_fn_1_CC5C_fmt_20C, FIELD(u32));
        SELECT_COLOR(7);
        fn_1_4A0D8(fzgx_pool_fn_1_CC5C_fmt_218);
        SELECT_COLOR(8);
        fn_1_4A0D8(fzgx_pool_fn_1_CC5C_fmt_22C);
        SELECT_COLOR(9);
        fn_1_4A0D8(fzgx_pool_fn_1_CC5C_fmt_240);
        SELECT_COLOR(10);
        fn_1_4A0D8(fzgx_pool_fn_1_CC5C_fmt_254);
        SELECT_COLOR(11);
        fn_1_4A0D8(fzgx_pool_fn_1_CC5C_fmt_264);
        SELECT_COLOR(12);
        fn_1_4A0D8(fzgx_pool_fn_1_CC5C_fmt_274);
        SELECT_COLOR(13);
        fn_1_4A0D8(fzgx_pool_fn_1_CC5C_fmt_280);
        SELECT_COLOR(14);
        fn_1_4A0D8(fzgx_pool_fn_1_CC5C_fmt_288);
        SELECT_COLOR(15);
        fn_1_4A0D8(fzgx_pool_fn_1_CC5C_fmt_290);
        SELECT_COLOR(16);
        fn_1_4A0D8(fzgx_pool_fn_1_CC5C_fmt_29C);
        SELECT_COLOR(17);
        fn_1_4A0D8(fzgx_pool_fn_1_CC5C_fmt_2A4);
        SELECT_COLOR(18);
        fn_1_4A0D8(fzgx_pool_fn_1_CC5C_fmt_2AC);
        SELECT_COLOR(19);
        fn_1_4A0D8(fzgx_pool_fn_1_CC5C_fmt_2BC);
        SELECT_COLOR(20);
        p = (u32)&fzgx_obj_lbl_1_bss_104C;
        PRINT_VALUE(fzgx_pool_fn_1_CC5C_fmt_2C0, fzgx_obj_lbl_1_bss_104C);
        SELECT_COLOR(21);
        p = (u32)&fzgx_obj_camera_state;
        ADVANCE(28);
        PRINT_VALUE(fzgx_pool_fn_1_CC5C_fmt_2CC, FIELD(f32));
        SELECT_COLOR(22);
        p = (u32)&fzgx_obj_camera_state;
        ADVANCE(32);
        PRINT_VALUE(fzgx_pool_fn_1_CC5C_fmt_2D8, FIELD(s16));
        SELECT_COLOR(23);
        p = (u32)&fzgx_obj_lbl_1_bss_10D8;
        ADVANCE(4);
        PRINT_VALUE(fzgx_pool_fn_1_CC5C_fmt_2E8, FIELD(f32));
        SELECT_COLOR(24);
        p = (u32)&fzgx_obj_lbl_1_bss_10D8;
        ADVANCE(8);
        PRINT_VALUE(fzgx_pool_fn_1_CC5C_fmt_2F8, FIELD(f32));
        SELECT_COLOR(25);
        p = (u32)&fzgx_obj_lbl_1_bss_10D8;
        ADVANCE(12);
        PRINT_VALUE(fzgx_pool_fn_1_CC5C_fmt_304, FIELD(f32));
        SELECT_COLOR(26);
        p = (u32)&fzgx_obj_lbl_1_bss_10D8;
        ADVANCE(16);
        PRINT_VALUE(fzgx_pool_fn_1_CC5C_fmt_310, FIELD(f32));
        SELECT_COLOR(27);
        p = (u32)&fzgx_obj_lbl_1_bss_10D8;
        ADVANCE(20);
        PRINT_VALUE(fzgx_pool_fn_1_CC5C_fmt_2F8, FIELD(f32));
        SELECT_COLOR(28);
        p = (u32)&fzgx_obj_lbl_1_bss_10D8;
        ADVANCE(24);
        PRINT_VALUE(fzgx_pool_fn_1_CC5C_fmt_304, FIELD(f32));
        SELECT_COLOR(29);
        p = (u32)&fzgx_obj_lbl_1_bss_10D8;
        ADVANCE(28);
        PRINT_VALUE(fzgx_pool_fn_1_CC5C_fmt_320, FIELD(f32));
        SELECT_COLOR(30);
        p = (u32)&fzgx_obj_lbl_1_bss_10D8;
        ADVANCE(32);
        PRINT_VALUE(fzgx_pool_fn_1_CC5C_fmt_330, FIELD(s16));
        SELECT_COLOR(31);
        p = (u32)&fzgx_obj_lbl_1_bss_10D8;
        ADVANCE(40);
        PRINT_VALUE(fzgx_pool_fn_1_CC5C_fmt_340, FIELD(f32));
        SELECT_COLOR(32);
        p = (u32)&fzgx_obj_lbl_1_bss_10D8;
        ADVANCE(44);
        PRINT_VALUE(fzgx_pool_fn_1_CC5C_fmt_2F8, FIELD(f32));
        SELECT_COLOR(33);
        p = (u32)&fzgx_obj_lbl_1_bss_10D8;
        ADVANCE(48);
        PRINT_VALUE(fzgx_pool_fn_1_CC5C_fmt_304, FIELD(f32));
        SELECT_COLOR(34);
        p = (u32)&fzgx_obj_lbl_1_bss_10D8;
        ADVANCE(52);
        PRINT_VALUE(fzgx_pool_fn_1_CC5C_fmt_310, FIELD(f32));
        SELECT_COLOR(35);
        p = (u32)&fzgx_obj_lbl_1_bss_10D8;
        ADVANCE(56);
        PRINT_VALUE(fzgx_pool_fn_1_CC5C_fmt_2F8, FIELD(f32));
        SELECT_COLOR(36);
        p = (u32)&fzgx_obj_lbl_1_bss_10D8;
        ADVANCE(60);
        PRINT_VALUE(fzgx_pool_fn_1_CC5C_fmt_304, FIELD(f32));
        SELECT_COLOR(37);
        p = (u32)&fzgx_obj_lbl_1_bss_10D8;
        ADVANCE(64);
        PRINT_VALUE(fzgx_pool_fn_1_CC5C_fmt_320, FIELD(f32));
        SELECT_COLOR(38);
        p = (u32)&fzgx_obj_lbl_1_bss_10D8;
        ADVANCE(68);
        PRINT_VALUE(fzgx_pool_fn_1_CC5C_fmt_330, FIELD(s16));
    }
}
#pragma opt_common_subs reset
/* fzgx:end fn_1_CC5C */

/* fzgx:begin camera_get_state_object */
// Returns the camera state object's base address.
CameraState* camera_get_state_object(void) {
    return &camera_state;
}
/* fzgx:end camera_get_state_object */

/* fzgx:begin camera_get_state_field_0x4 */
// Returns the address of the camera state field at offset 4.
u32* camera_get_state_field_0x4(void) {
    return &camera_state.unk_4;
}
/* fzgx:end camera_get_state_field_0x4 */

/* fzgx:begin camera_get_state_field_0x8 */
// Returns the address of the camera state field at offset 0x8.
u32* camera_get_state_field_0x8(void) {
    return &camera_state.unk_8;
}
/* fzgx:end camera_get_state_field_0x8 */

/* fzgx:begin camera_get_state_field_0xc */
// Returns a pointer to the camera object's field at offset 0xC.
u32* camera_get_state_field_0xc(void) {
    return &camera_state.unk_C;
}
/* fzgx:end camera_get_state_field_0xc */

/* fzgx:begin camera_get_state_field_0x10 */
// Returns a pointer to the camera object's state field.
u32* camera_get_state_field_0x10(void) {
    return &camera_state.unk_10;
}
/* fzgx:end camera_get_state_field_0x10 */

/* fzgx:begin camera_get_state_field_0x14 */
// Returns a pointer to the camera object's field at offset 0x14.
u32* camera_get_state_field_0x14(void) {
    return &camera_state.unk_14;
}
/* fzgx:end camera_get_state_field_0x14 */

/* fzgx:begin camera_get_state_field_0x18 */
// Returns a pointer to the camera object's state field at offset 0x18.
u32* camera_get_state_field_0x18(void) {
    return &camera_state.unk_18;
}
/* fzgx:end camera_get_state_field_0x18 */

/* fzgx:begin camera_get_state_storage */
// Returns the camera state storage used by the surrounding camera code.
u8* camera_get_state_storage(void) {
    return lbl_1_bss_103C;
}
/* fzgx:end camera_get_state_storage */

/* fzgx:begin camera_get_extended_state_storage noprologue */
#include "types.h"

extern u8 lbl_1_bss_108C[52];

// Returns the storage reserved for the camera's extended state.
u8* camera_get_extended_state_storage(void) {
    return lbl_1_bss_108C;
}
/* fzgx:end camera_get_extended_state_storage */

/* fzgx:begin camera_get_state_flag */
// Returns the current camera state flag.
u8 camera_get_state_flag(void) {
    return lbl_1_bss_1014;
}
/* fzgx:end camera_get_state_flag */

/* fzgx:begin camera_enable_flags */
// Enables the camera state flags.
void camera_enable_flags(void) {
    camera_flag_1 = 1;
    camera_flag_0 = 1;
}
/* fzgx:end camera_enable_flags */

/* fzgx:begin camera_disable_flags */
// Clears the camera state flags.
void camera_disable_flags(void) {
    camera_flag_1 = 0;
    camera_flag_0 = 0;
}
/* fzgx:end camera_disable_flags */

/* fzgx:begin camera_are_flags_enabled */
// Returns whether the camera state flag is set.
BOOL camera_are_flags_enabled(void) {
    return camera_flag_1;
}
/* fzgx:end camera_are_flags_enabled */
