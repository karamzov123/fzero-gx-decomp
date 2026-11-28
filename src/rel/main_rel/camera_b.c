#include "types.h"
#include "rel/main_rel/globals.h"
#include "rel/main_rel/camera.h"
#include "rel/main_rel/car_test.h"
#include "rel/main_rel/car.h"
#include "dolphin/hw_regs.h"
#include "psvec.h"





typedef signed short s16;

typedef unsigned char u8;

typedef struct camera_reset_transition_Camera {
u8 pad_00[0xA4];
s16 unk_A4;
} camera_reset_transition_Camera;

typedef signed long s32;

typedef unsigned long u32;

typedef float f32;

typedef struct Transform {
u8 pad_08[0x8];
f32 unk_08;
u8 pad_0c[0xc];
f32 unk_18;
u8 pad_1c[0xc];
f32 unk_28;
u8 pad_2c[0x24];
u8 unk_50[0x2c];
u32 unk_7C;
} Transform;

typedef struct camera_update_transition_Camera {
u8 pad_00[0x78];
s16 unk_78;
u8 pad_7A[0x2A];
s16 unk_A4;
} camera_update_transition_Camera;

typedef struct CameraTarget {
    u8 pad_000[0x394];
    void *data;
} CameraTarget;

typedef struct LiveCameraPool {
    u8 pad_0[0x1E8];
    f64 damping;
    f64 scale;
    f64 scale2;
} LiveCameraPool;

typedef struct {
    f32 x, y, z;
} CamVec;

typedef struct {
    f32 x;
    f32 y;
    f32 z;
} Fn183D28Vec3;

typedef struct fn_1_8D08_Vec { f32 x, y, z; } fn_1_8D08_Vec;

typedef struct fn_1_90E0_Vec3 {
f32 x;
f32 y;
f32 z;
} fn_1_90E0_Vec3;

struct fn_1_A888_Vec3 {
    f32 x;
    f32 y;
    f32 z;
};

typedef struct camera_get_position_delta_Vec3 {
    f32 x;
    f32 y;
    f32 z;
} camera_get_position_delta_Vec3;

typedef struct fn_1_8B10_CameraObject {
    s16 pad_00;
    s16 kind;
    u8 pad_04[0xA0];
    s16 index;
} fn_1_8B10_CameraObject;

typedef struct CameraOutput {
    f32 x0;
    f32 y0;
    s16 flags0;
    u8 pad_0A[2];
    f32 x1;
    f32 y1;
    s16 flags1;
    u8 pad_16[2];
    f32 x2;
    f32 y2;
    s16 flags2;
} CameraOutput;

typedef struct Vec3f {
f32 x, y, z;
} Vec3f;

typedef struct {
    u8 pad_0[0x214];
    u16 unk_214;
} ABACState;

typedef struct Sig_camera_get_target_orientation_camera_get_target_orientation_CameraObject {
u8 pad_0[0xEC];
f32 unk_EC[3][4];
u8 pad_11C[0xAC];
f32 unk_1C8;
u8 pad_1CC[0x2D0];
Transform *unk_49C;
u8 pad_4A0[0x38];
f32 unk_4D8;
u8 pad_4DC[0xB0];
u32 unk_58C;
u8 pad_590[4];
f32 unk_594[3][4];
} Sig_camera_get_target_orientation_camera_get_target_orientation_CameraObject;

typedef fn_1_90E0_Vec3 V90;

struct C90 {
u8 pad_0[0x50];
V90 unk_50;
u8 pad_5C[0x20];
u32 unk_7C;
u8 pad_80[0x88];
f32 unk_108;
};

typedef struct {
    u8 pad_0[2];
    s16 unk_2;
    u8 pad_4[0xA2];
    s16 unk_A6;
    s16 unk_A8;
} ABACObject;

typedef struct camera_get_target_orientation_CameraObject {
    u8 pad_49c[0x49c];
    Transform *unk_49C;
} camera_get_target_orientation_CameraObject;

typedef struct LiveCameraVec {
    f32 values[3];
} LiveCameraVec;

typedef struct LiveCamera_fn_1_B4D4 {
    u8 pad_00[0x10];
    LiveCameraVec position;
    u8 pad_1C[0xC];
    LiveCameraVec position2;
    u8 pad_34[0x74];
    s16 unk_A8;
    u8 pad_AA[0x62];
    s32 unk_10C;
    s32 timer;
    LiveCameraVec saved;
    LiveCameraVec offset;
    LiveCameraVec velocity;
    LiveCameraVec saved2;
    LiveCameraVec offset2;
    LiveCameraVec velocity2;
} LiveCamera_fn_1_B4D4;

struct fn_1_AA54_lbl_1_rodata_388 {
    f64 unk_0;
};

typedef struct { f32 x, y, z; } Vec;

typedef struct {
u8 pad_0[0x8];
f32 unk_8;
u8 pad_C[0x6C];
s16 unk_78;
u8 pad_7A[0x12];
Vec unk_8C;
Vec unk_98;
s16 unk_A4;
u8 pad_A6[0x13E];
Vec unk_1E4;
f32 unk_1F0;
f32 unk_1F4;
u8 pad_1F8[2];
s16 unk_1FA;
} fn_1_AEB8_Camera;

typedef struct {
    u8 pad_0[0x2];
    s16 unk_2;
    u8 pad_4[0x4];
    f32 unk_8;
    u8 pad_C[0x4];
    CamVec unk_10;
    u8 pad_1C[0xC];
    CamVec unk_28;
    f32 unk_34[3][4];
    u8 pad_64[0x14];
    s16 unk_78;
    u8 pad_7A[0x12];
    CamVec unk_8C;
    CamVec unk_98;
    s16 unk_A4;
    u8 pad_A6[0x14A];
    f32 unk_1F0;
    f32 unk_1F4;
    u8 pad_1F8[0x2];
    s16 unk_1FA;
} fn_1_AFC8_Camera;

typedef struct CameraStateLocal {
    u8 pad_d4[0xd4];
    f32 unk_D4;
    f32 unk_D8;
    f32 unk_DC;
} CameraStateLocal;
extern void *fn_1_868C0(s8 index);
extern s8 fn_1_A5DC4(void);
extern const f32 lbl_1_rodata_200;
extern const f32 lbl_1_rodata_204;
extern void lbl_8006E1B0(void *,void *);
extern f32 fn_1_A888(void *arg0);
extern s32 fn_1_58C4(void);
extern u32 fn_1_5910(void);
extern u32 fn_1_F2F34(void);
extern void lbl_8006E1C0(void *,void *);
extern void mathutil_mtxA_rotate_x(s16);
extern u8 fn_1_FA4C0(void);
extern void lbl_8006DC6C(void *);
extern void fn_1_862D4(s16, fn_1_8D08_Vec *);
extern void fn_1_8636C(int index, void *arg);
extern void fn_1_8A0C(s16 index);
extern void fn_1_8B10(fn_1_8B10_CameraObject *camera, CameraOutput *output);
extern void fn_8006F038(fn_1_90E0_Vec3 *arg0, fn_1_90E0_Vec3 *arg1, s16 arg2);
extern u32 fn_8006E250(void *, void *);
extern void lbl_8006DBAC(fn_1_90E0_Vec3 *a);
extern u8 fn_1_86678(int index);
extern u8 fn_1_3BB0(u32 arg0);
extern void *fn_1_86254(int index);
extern u32 fn_1_8627C(s32 index);
extern f32 fn_1_8652C(int index);
extern u32 fn_1_864E8(int index);
extern void fn_1_AA54(void *);
extern void fn_1_ABAC(ABACObject *arg0);
extern s32 camera_get_state(void);
extern void camera_get_position_delta(u32 index, camera_get_position_delta_Vec3 *out);
extern u32 fn_1_8677C(u32 arg0);
extern f32 fn_1_8655C(int index);
extern f32 camera_get_target_orientation(camera_get_target_orientation_CameraObject *camera);
extern s16 fn_1_8683C(int index);
extern void fn_1_869E0(int index, u32 *out);
extern f32 fn_1_86574(int index);
extern s16 fn_1_7B054(void);
extern void fn_1_FA450(u8 value);
extern void fn_1_B4D4(LiveCamera_fn_1_B4D4 *camera);
extern void camera_reset_transition(camera_reset_transition_Camera *);
extern void camera_update_transition(camera_update_transition_Camera *);
extern u16 fn_1_8664C(int index);
extern void fn_1_A8EB0(int arg0, int arg1);
extern void fn_1_A8E78(int arg);
extern f32 fn_1_A6FE8(void);
extern void fn_1_862A8(int,void *);
extern void fn_1_549F4(void *,void *,f32,f32,f32,f32);
extern void fn_1_54DCC(u8 *data);
extern void lbl_8006DAEC();
extern void fn_80008C20(void *,void *,void *);
extern void lbl_8006DB74(void *);
extern void fn_8006E2B0(void *,void *);
extern void fn_8006EE70(void *,void *);
extern void fn_8006EFB4(void *,void *,f32);
extern void lbl_8006DB30(void);
extern void lbl_8006DD14(void *,void *);
extern void mathutil_mtxA_rotate_y(s32);
extern void fn_80008DB4(void *,void *,void *,f32);
extern void lbl_8006D5A4(void *,void *,void *,f32);
extern void lbl_8006E0B4(f32,f32,f32);
extern u32 fn_80007D58(f32 *arg0);
extern u32 fn_80007CDC(f32 *arg0);
extern void lbl_8006D784(void *);
extern void fn_8006EDBC(void *,void *,s16 *,s16 *);
extern void lbl_8006D1BC(s16,f32 *,f32 *);
extern void lbl_8006D8E4(f32,f32);
extern void mathutil_mtxA_rotate_x__fzgx_offset_C(f32,f32);
extern s16 lbl_8006D24C(f32,f32);
extern void fn_8006F1F0(void *,void *,void *);
extern void fn_8006F4E0(s16 *arg0);
extern int fn_1_20A5C(void *, void *);
extern u32 fn_1_15578(void *, void *, void *, void *, u32, void *, u32, u32, u32, u32);
extern f64 lbl_1_rodata_360;
extern struct fn_1_AA54_lbl_1_rodata_388 lbl_1_rodata_388;
extern s16 camera_get_entry_field_0xa8(u32 index);
extern void camera_set_entry_field_0xa8(u8 index, s16 value);
extern s16 camera_get_entry_field_0xa4(u32 index);
extern void fn_1_715C(u8 index, s16 value);
extern u8 fn_1_40BB4(void);
extern u8 lbl_1_bss_CC0[152];
extern void fn_1_8658C(u8 index, camera_get_position_delta_Vec3 *out);
extern void fn_1_AEB8(fn_1_AEB8_Camera *camera);
extern void fn_1_AFC8(fn_1_AFC8_Camera *cam);
extern void fn_1_863E4(int index, void *arg);
extern Transform *lbl_801A6D00;
extern CameraStateLocal *lbl_801A66CC;
extern u32 lbl_1_bss_F5C;
extern void fn_1_8840(void);
extern u8 fn_1_86634(int index);
extern f32 lbl_1_rodata_2E0[32];
extern f32 lbl_8006D6FC(f32 *value, void *target);
extern s32 fn_1_6514(s32 value);

/* fzgx:begin fn_1_8B10 */


typedef struct CameraData {
    u8 pad_000[0x118];
    f32 x;
    f32 y;
} CameraData;

typedef struct fn_1_8B10_CameraEntry {
    f32 x;
    f32 y;
    s16 flags0;
    u8 pad_0A[2];
    f32 x1;
    f32 y1;
    s16 flags1;
    u8 pad_16[2];
    f32 x2;
    f32 y2;
    s16 flags2;
    u8 pad_22[2];
} fn_1_8B10_CameraEntry;





void fn_1_8B10(fn_1_8B10_CameraObject *camera, CameraOutput *output) {
    CameraTarget *target;
    CameraData *data;

    target = ((CameraTarget *)fn_1_868C0(camera->kind));
    if (camera->index == 0 && target != 0 && (data = target->data) != 0) {
        output->x0 = lbl_1_rodata_200 + data->x;
        output->y0 = data->y;
        output->flags0 = 0;
        output->x1 = lbl_1_rodata_200 + data->x;
        output->y1 = data->y;
        output->flags1 = 0;
        output->x2 = lbl_1_rodata_200 + data->x;
        output->y2 = data->y;
        output->flags2 = 0x1AAA;
    } else {
        output->x0 = (*(fn_1_8B10_CameraEntry (*)[])&lbl_1_data_36EC)[camera->index].x;
        output->y0 = (*(fn_1_8B10_CameraEntry (*)[])&lbl_1_data_36EC)[camera->index].y;
        output->flags0 = (*(fn_1_8B10_CameraEntry (*)[])&lbl_1_data_36EC)[camera->index].flags0;
        output->x1 = (*(fn_1_8B10_CameraEntry (*)[])&lbl_1_data_36EC)[camera->index].x1;
        output->y1 = (*(fn_1_8B10_CameraEntry (*)[])&lbl_1_data_36EC)[camera->index].y1;
        output->flags1 = (*(fn_1_8B10_CameraEntry (*)[])&lbl_1_data_36EC)[camera->index].flags1;
        output->x2 = (*(fn_1_8B10_CameraEntry (*)[])&lbl_1_data_36EC)[camera->index].x2;
        output->y2 = (*(fn_1_8B10_CameraEntry (*)[])&lbl_1_data_36EC)[camera->index].y2;
        output->flags2 = (*(fn_1_8B10_CameraEntry (*)[])&lbl_1_data_36EC)[camera->index].flags2;

        if (fn_1_A5DC4() != 0) {
            f32 adjust;
            switch (camera->index) {
            case 1:
                adjust = lbl_1_rodata_200;
                break;
            case 2:
                adjust = lbl_1_rodata_204;
                break;
            case 3:
                adjust = lbl_1_rodata_204;
                break;
            default:
                adjust = lbl_1_rodata_200;
                break;
            }
            output->x0 -= adjust;
            output->x1 -= adjust;
            output->x2 -= adjust;
        }
    }
}
/* fzgx:end fn_1_8B10 */

/* fzgx:begin fn_1_8D08 */
#include "mathutil_lc.h"
/* begin game/main_rel/car_test_types.h (deltawave784/windows-and-types@cf9407c75) */
#ifndef GAME_MAIN_REL_CAR_TEST_TYPES_H
#define GAME_MAIN_REL_CAR_TEST_TYPES_H

// Types (and the externs that name them) of car_test.c, hoisted out of its prologue so that
// a block can compile standalone and under the prologue. Hand-owned (librarian).




#endif  // GAME_MAIN_REL_CAR_TEST_TYPES_H
#ifndef GAME_MAIN_REL_CAR_TYPES_H
#define GAME_MAIN_REL_CAR_TYPES_H

#ifndef GAME_VEC3_H
#define GAME_VEC3_H

#endif  // GAME_VEC3_H

#endif  // GAME_MAIN_REL_CAR_TYPES_H

/* end game/main_rel/car_types.h */

typedef struct Sig_fn_1_8B10_CameraOutput {
    f32 x0;
    f32 y0;
    s16 flags0;
    u8 pad_0A[2];
    f32 x1;
    f32 y1;
    s16 flags1;
    u8 pad_16[2];
    f32 x2;
    f32 y2;
    s16 flags2;
} Sig_fn_1_8B10_CameraOutput;
typedef struct Sig_fn_1_8B10_fn_1_8B10_CameraObject {
    s16 pad_00;
    s16 kind;
    u8 pad_04[0xA0];
    s16 index;
} Sig_fn_1_8B10_fn_1_8B10_CameraObject;


typedef struct fn_1_8D08_Camera {
    s16 unk_00;
    s16 index;            /* 0x02 */
    s16 unk_04;
    s16 angle;            /* 0x06 */
    f32 unk_08;
    f32 unk_0C;
    fn_1_8D08_Vec pos;    /* 0x10 */
    u8 pad_1C[0xC];
    fn_1_8D08_Vec look;   /* 0x28 */
    f32 mtx[3][4];        /* 0x34 */
    fn_1_8D08_Vec unk_64;
    f32 lerp;             /* 0x70 */
    u8 pad_74[4];
    s16 unk_78;
    u8 pad_7A[2];
    f32 unk_7C;
    f32 unk_80;
    f32 unk_84;
    s32 unk_88;
    fn_1_8D08_Vec target; /* 0x8C */
    fn_1_8D08_Vec unk_98;
    s16 mode;             /* 0xA4 */
    s16 prevMode;         /* 0xA6 */
    u16 unk_A8;
    u8 pad_AA[0x1E4 - 0xAA];
    fn_1_8D08_Vec unk_1E4;
    f32 unk_1F0;
    f32 unk_1F4;
    s16 unk_1F8;
    s16 unk_1FA;
} fn_1_8D08_Camera;


/* Native shared literal pool, including the preceding camera literals. */
const f32 fzgx_pool_fzgx_camera_literal_0 = 0.3f;
const f32 fzgx_pool_fzgx_camera_literal_1 = 1.1f;
const u32 fzgx_pool_fzgx_camera_up_x[1] = {0};
const u32 fzgx_pool_fzgx_camera_up_y[1] = {0x3F800000};
const u32 fzgx_pool_fzgx_camera_up_z[1] = {0};
const fn_1_8D08_Vec fzgx_pool_fzgx_camera_target = {0.0f, 0.0f, 0.0f};
const u32 fzgx_pool_fzgx_camera_fwd_x[1] = {0};
const u32 fzgx_pool_fzgx_camera_fwd_y[1] = {0};
const u32 fzgx_pool_fzgx_camera_fwd_z[1] = {0xBF800000};
const f32 fzgx_pool_fzgx_camera_height[1] = {55.0f};
const f32 fzgx_pool_fzgx_camera_zero[1] = {0.0f};
const f32 fzgx_pool_fzgx_camera_distance[1] = {-10.0f};
const f64 fzgx_pool_fzgx_camera_half[1] = {0.5};

/* translate the locked-cache matrix A */

/* look point: matrix A applied to (0, 0, -10) */
#define camera_update_look(cam) { \
    /* Read the scale before the locked-cache matrix column. */ \
    dist = *(volatile f32 *)fzgx_pool_fzgx_camera_distance; \
    /* Preserve locked-cache matrix access order. */ \
    x = mathutilDataV->mtxA[0][2]; \
    x = x * dist + mathutilData->mtxA[0][3]; \
    y = mathutilData->mtxA[1][2]; \
    y = y * dist + mathutilData->mtxA[1][3]; \
    z = mathutilData->mtxA[2][2]; \
    z = z * dist + mathutilData->mtxA[2][3]; \
    cam->look.x = x; \
    cam->look.y = y; \
    cam->look.z = z; \
}

static inline f32 (* fn_1_8D08_read_pointer_(fn_1_8D08_Camera * owner))[4] { return owner->mtx; }
static inline f32 (* fn_1_8D08_read_pointer__(fn_1_8D08_Camera * owner))[4] { return owner->mtx; }
#pragma opt_lifetimes off
void fn_1_8D08(fn_1_8D08_Camera *cam, f32 arg1) {
    f32 z;
    f32 y;
    f32 x;
    f32 dist;
    Sig_fn_1_8B10_CameraOutput out;
    f32 mtx[3][4];
    fn_1_8D08_Vec pos;

    cam->unk_A8 = 0;
    cam->mode = 1;
    if ((u32)fn_1_58C4() == 1 && (s32)fn_1_F2F34() == 0) {
        cam->mode = fn_1_FA4C0();
    }
    cam->prevMode = cam->mode;
    fn_1_8B10( (fn_1_8B10_CameraObject *)((Sig_fn_1_8B10_fn_1_8B10_CameraObject *)cam), (CameraOutput *)(Sig_fn_1_8B10_CameraOutput *)(&out));
    fn_1_862D4(cam->index, &pos);
    fn_1_8636C(cam->index, fn_1_8D08_read_pointer__(cam));
    lbl_8006DC6C(fn_1_8D08_read_pointer_(cam));
    {
        f32 fzgx_lc0_z;
        f32 fzgx_lc0_y;
        f32 fzgx_lc0_x;
        /* Capture the first coordinate before the remaining matrix-translation loads. */
        fzgx_lc0_x = *(volatile f32 *)&((&pos)->x);
        fzgx_lc0_y = (&pos)->y;
        fzgx_lc0_z = (&pos)->z;
        /* Locked-cache stores must complete before copying the pool vector. */
        /* Preserve locked-cache matrix access order. */
        mathutilDataV->mtxA[0][3] = fzgx_lc0_x;
        /* Preserve locked-cache matrix access order. */
        mathutilDataV->mtxA[1][3] = fzgx_lc0_y;
        /* Preserve locked-cache matrix access order. */
        mathutilDataV->mtxA[2][3] = fzgx_lc0_z;
    }
    {
        fn_1_8D08_Vec up;
        u32 c, b, a;
        /* Ordered word copy following the locked-cache stores. */
        /* Preserve ordered vector initialization around the locked-cache accesses. */
        a = *(volatile const u32 *)fzgx_pool_fzgx_camera_up_x;
        /* Preserve ordered vector initialization around the locked-cache accesses. */
        b = *(volatile const u32 *)fzgx_pool_fzgx_camera_up_y;
        /* Preserve ordered vector initialization around the locked-cache accesses. */
        c = *(volatile const u32 *)fzgx_pool_fzgx_camera_up_z;
        /* Preserve ordered vector initialization around the locked-cache accesses. */
        ((u32 *)&up)[0] = a;
        /* Preserve ordered vector initialization around the locked-cache accesses. */
        ((u32 *)&up)[1] = b;
        /* Preserve ordered vector initialization around the locked-cache accesses. */
        ((u32 *)&up)[2] = c;
        lbl_8006E1C0( (void *)(fn_1_8D08_Vec *)(&up), (void *)(fn_1_8D08_Vec *)(&cam->unk_64));
    }
    {
        fn_1_8D08_Vec target = fzgx_pool_fzgx_camera_target;
        target.y = out.x0;
        target.z = out.y0;
        cam->target = target;
    }
    cam->angle = out.flags0;
    cam->unk_08 = fzgx_pool_fzgx_camera_height[0];
    cam->unk_0C = arg1;
    cam->unk_84 = fzgx_pool_fzgx_camera_zero[0];
    cam->unk_78 = 0;
    cam->unk_7C = fzgx_pool_fzgx_camera_zero[0];
    cam->unk_80 = fzgx_pool_fzgx_camera_zero[0];
    cam->unk_88 = 0;
    lbl_8006DC6C(fn_1_8D08_read_pointer__(cam));
    {
        f32 fzgx_lc1_z;
        f32 fzgx_lc1_y;
        f32 fzgx_lc1_x;
        /* Capture the first coordinate before the remaining matrix-translation loads. */
        fzgx_lc1_x = *(volatile f32 *)&((&pos)->x);
        fzgx_lc1_y = (&pos)->y;
        fzgx_lc1_z = (&pos)->z;
        mathutilData->mtxA[0][3] = fzgx_lc1_x;
        mathutilData->mtxA[1][3] = fzgx_lc1_y;
        mathutilData->mtxA[2][3] = fzgx_lc1_z;
    }
    lbl_8006E1B0( (void *)((Fn183D28Vec3 *)&cam->target), (void *)((Fn183D28Vec3 *)&cam->pos));
    lbl_8006DC6C(fn_1_8D08_read_pointer__(cam));
    {
        f32 fzgx_lc2_z;
        f32 fzgx_lc2_y;
        f32 fzgx_lc2_x;
        /* Capture the first coordinate before the remaining matrix-translation loads. */
        fzgx_lc2_x = *(volatile f32 *)&((&cam->pos)->x);
        fzgx_lc2_y = (&cam->pos)->y;
        fzgx_lc2_z = (&cam->pos)->z;
        mathutilData->mtxA[0][3] = fzgx_lc2_x;
        mathutilData->mtxA[1][3] = fzgx_lc2_y;
        mathutilData->mtxA[2][3] = fzgx_lc2_z;
    }
    mathutil_mtxA_rotate_x(cam->angle);
    camera_update_look(cam);
    cam->unk_1E4 = cam->pos;
    cam->unk_1F0 = fzgx_pool_fzgx_camera_zero[0];
    cam->unk_1F4 = fzgx_pool_fzgx_camera_zero[0];
    cam->unk_1FA = 0;
    /* Complete initialization before the ordered forward-vector copy. */
    /* Preserve ordered vector initialization around the locked-cache accesses. */
    *(volatile s16 *)&cam->unk_1F8 = -1;
    {
        u32 b, a;
        /* Preserve ordered vector initialization around the locked-cache accesses. */
        a = *(volatile const u32 *)fzgx_pool_fzgx_camera_fwd_x;
        /* Preserve ordered vector initialization around the locked-cache accesses. */
        b = *(volatile const u32 *)fzgx_pool_fzgx_camera_fwd_y;
        /* Preserve ordered vector initialization around the locked-cache accesses. */
        ((u32 *)&cam->unk_98)[0] = a;
        /* Preserve ordered vector initialization around the locked-cache accesses. */
        ((u32 *)&cam->unk_98)[1] = b;
        /* Preserve ordered vector initialization around the locked-cache accesses. */
        b = *(volatile const u32 *)fzgx_pool_fzgx_camera_fwd_z;
        /* Preserve ordered vector initialization around the locked-cache accesses. */
        ((u32 *)&cam->unk_98)[2] = b;
    }
    {
        fn_1_8D08_Vec pos2;
        fn_1_862D4(cam->index, &pos2);
        fn_1_8636C(cam->index, mtx);
        lbl_8006DC6C(mtx);
        {
            f32 fzgx_lc3_z;
            f32 fzgx_lc3_y;
            f32 fzgx_lc3_x;
            /* Capture the first coordinate before the remaining matrix-translation loads. */
            fzgx_lc3_x = *(volatile f32 *)&((&pos2)->x);
            fzgx_lc3_y = (&pos2)->y;
            fzgx_lc3_z = (&pos2)->z;
            mathutilData->mtxA[0][3] = fzgx_lc3_x;
            mathutilData->mtxA[1][3] = fzgx_lc3_y;
            mathutilData->mtxA[2][3] = fzgx_lc3_z;
        }
    }
    cam->lerp = fn_1_A888( (void *)(fn_1_8D08_Camera *)(cam));
    cam->unk_78 = 0;
    if (cam->mode < 5) {
        cam->target.y = cam->target.y + (f32)(cam->lerp * (out.x2 - cam->target.y));
        cam->target.z = cam->target.z + (f32)(cam->lerp * (out.y2 - cam->target.y));
        {
            f64 angle = cam->angle;
            f32 delta;
            f32 weight = cam->lerp;
            f32 step;
            f64 half;
            delta = out.flags2 - cam->angle;
            step = weight * delta;
            half = step * fzgx_pool_fzgx_camera_half[0];
            cam->angle = angle + half;
        }
        lbl_8006DC6C(fn_1_8D08_read_pointer__(cam));
        {
            f32 fzgx_lc4_z;
            f32 fzgx_lc4_y;
            f32 fzgx_lc4_x;
            /* Capture the first coordinate before the remaining matrix-translation loads. */
            fzgx_lc4_x = *(volatile f32 *)&((&pos)->x);
            fzgx_lc4_y = (&pos)->y;
            fzgx_lc4_z = (&pos)->z;
            mathutilData->mtxA[0][3] = fzgx_lc4_x;
            mathutilData->mtxA[1][3] = fzgx_lc4_y;
            mathutilData->mtxA[2][3] = fzgx_lc4_z;
        }
        lbl_8006E1B0( (void *)((Fn183D28Vec3 *)&cam->target), (void *)((Fn183D28Vec3 *)&cam->pos));
        lbl_8006DC6C(fn_1_8D08_read_pointer__(cam));
        {
            f32 fzgx_lc5_z;
            f32 fzgx_lc5_y;
            f32 fzgx_lc5_x;
            /* Capture the first coordinate before the remaining matrix-translation loads. */
            fzgx_lc5_x = *(volatile f32 *)&((&cam->pos)->x);
            fzgx_lc5_y = (&cam->pos)->y;
            fzgx_lc5_z = (&cam->pos)->z;
            mathutilData->mtxA[0][3] = fzgx_lc5_x;
            mathutilData->mtxA[1][3] = fzgx_lc5_y;
            mathutilData->mtxA[2][3] = fzgx_lc5_z;
        }
        mathutil_mtxA_rotate_x(cam->angle);
        {
            f32 look_z;
            /* Read the scale before the locked-cache matrix column. */
            dist = *(volatile f32 *)fzgx_pool_fzgx_camera_distance;
            /* Preserve locked-cache matrix access order. */
            x = mathutilDataV->mtxA[0][2];
            x = x * dist + mathutilData->mtxA[0][3];
            y = mathutilData->mtxA[1][2];
            /* Preserve matrix-column load order. */
            /* Preserve locked-cache matrix access order. */
            z = mathutilDataV->mtxA[1][3];
            y = y * dist + z;
            look_z = mathutilData->mtxA[2][2];
            look_z = look_z * dist + mathutilData->mtxA[2][3];
            cam->look.x = x;
            cam->look.y = y;
            cam->look.z = look_z;
        }
    }
    fn_1_8A0C(((s32)fn_1_5910()));
}
#pragma opt_lifetimes reset
/* fzgx:end fn_1_8D08 */

/* fzgx:begin fn_1_90E0 noprologue */
#include "dolphin/hw_regs.h"

typedef signed char s8;
typedef signed short s16;
typedef signed long s32;

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned long u32;

typedef float f32;
typedef double f64;

/* lbl_1_data_3678: .data size 0xC, 1 refs from camera.c (own data block) */

typedef struct Vec3 {
f32 x;
f32 y;
f32 z;
} Vec3;
typedef struct Vec3f {
f32 x, y, z;
} Vec3f;
typedef struct camera_reset_transition_Camera {
u8 pad_00[0xA4];
s16 unk_A4;
} camera_reset_transition_Camera;
typedef struct camera_update_transition_Camera {
u8 pad_00[0x78];
s16 unk_78;
u8 pad_7A[0x2A];
s16 unk_A4;
} camera_update_transition_Camera;
typedef struct Transform {
u8 pad_08[0x8];
f32 unk_08;
u8 pad_0c[0xc];
f32 unk_18;
u8 pad_1c[0xc];
f32 unk_28;
u8 pad_2c[0x24];
u8 unk_50[0x2c];
u32 unk_7C;
} Transform;

extern void fn_1_862D4(int index, Vec3 *out);

extern void fn_8006F038(Vec3 *arg0, Vec3 *arg1, s16 arg2);

 /* fzgx-allow: S2 SDK asynchronous state */



typedef struct {
u32 x;
u32 y;
u32 z;
} Triple;

typedef struct Fn1967A8Resource Fn1967A8Resource;
struct Fn1967A8Resource {
u8 unk_00;
u8 unk_01[0x07];
u32 unk_08;
u8 unk_0C[0x10];
u32 unk_1C;
};

extern void fn_1_41F58(Fn1967A8Resource *arg0, s32 arg1, void (*arg2)(void), void *arg3);

extern void fn_8006E250(Vec3f *, Vec3f *);

extern void lbl_8006DBAC(Vec3 *a);

typedef struct Sig_camera_get_target_orientation_camera_get_target_orientation_CameraObject {
u8 pad_0[0xEC];
f32 unk_EC[3][4];
u8 pad_11C[0xAC];
f32 unk_1C8;
u8 pad_1CC[0x2D0];
Transform *unk_49C;
u8 pad_4A0[0x38];
f32 unk_4D8;
u8 pad_4DC[0xB0];
u32 unk_58C;
u8 pad_590[4];
f32 unk_594[3][4];
} Sig_camera_get_target_orientation_camera_get_target_orientation_CameraObject;
typedef Vec3 V90;
typedef struct M90 { f32 m[3][4]; } M90;
struct fn_1_90E0_Arg0 {
u8 pad_0[2];
s16 unk_2;
s16 unk_4, unk_6;
f32 unk_8, unk_C;
V90 unk_10, unk_1C, unk_28;
M90 unk_34;
V90 unk_64;
f32 unk_70, unk_74;
s16 unk_78;
u8 pad_7A[2];
f32 unk_7C, unk_80, unk_84;
s32 unk_88;
V90 unk_8C;
u8 pad_98[0xC];
s16 unk_A4, unk_A6, unk_A8;
u8 pad_AA[2];
M90 unk_AC, unk_DC;
u8 pad_10C[0xD4];
s32 unk_1E0;
V90 unk_1E4;
f32 unk_1F0, unk_1F4;
s16 unk_1F8, unk_1FA;
};
struct C90 {
u8 pad_0[0x50];
V90 unk_50;
u8 pad_5C[0x20];
u32 unk_7C;
u8 pad_80[0x88];
f32 unk_108;
};
typedef struct Output90 {
f32 x0, y0; s16 a0; u8 pad_A[2];
f32 x1, y1; s16 a1; u8 pad_16[2];
f32 x2, y2; s16 a2; u8 pad_22[2];
} Output90;

static const u32 fzgx_pool_rodata_lbl_1_rodata_200[1] = {  /* fzgx-allow: A1 retail data bytes and bindings */
    0x3E99999A
};
static const u32 fzgx_pool_rodata_lbl_1_rodata_204[10] = {  /* fzgx-allow: A1 retail data bytes and bindings */
    0x3F8CCCCD, 0x0, 0x3F800000, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0xBF800000
};
#pragma section code_type ".fzgxpool"
/* places the native literal 55.0f at retail's pool offset 0x2C */
static void fzgx_pool_literals_lbl_1_rodata_200_2C(void) {
    volatile f32 s;  /* fzgx-allow: S2 layout primer sink */
    s = 55.0f;
}
#pragma section code_type ".text"
static const u32 fzgx_pool_rodata_lbl_1_rodata_230[1] = {  /* fzgx-allow: A1 retail data bytes and bindings */
    0x0
};
static const u32 fzgx_pool_rodata_lbl_1_rodata_200_34[1] = {  /* fzgx-allow: A1 retail data bytes and bindings */
    0xC1200000  /* fzgx-allow: A1 retail data bytes */
};
#pragma section code_type ".fzgxpool"
/* places the native literal 0.5 at retail's pool offset 0x38 and MWCC's signed
   int-to-float constant (0x4330000080000000) at 0x40 */
static void fzgx_pool_conversion_lbl_1_rodata_200_40(void) {
    volatile s32 i;  /* fzgx-allow: S2 layout primer sink */
    volatile u8 b;  /* fzgx-allow: S2 layout primer sink */
    volatile f32 s;  /* fzgx-allow: S2 layout primer sink */
    volatile f64 d;  /* fzgx-allow: S2 layout primer sink */
    b = *(u8 *)fzgx_pool_rodata_lbl_1_rodata_200;
    b = *(u8 *)fzgx_pool_rodata_lbl_1_rodata_204;
    b = *(u8 *)fzgx_pool_rodata_lbl_1_rodata_230;
    b = *(u8 *)fzgx_pool_rodata_lbl_1_rodata_200_34;
    d = 0.5;
    s = i;
}
#pragma section code_type ".text"
static const u32 fzgx_pool_rodata_lbl_1_rodata_200_48[3] = {  /* fzgx-allow: A1 retail data bytes and bindings */
    0x0, 0x3F800000, 0x0
};
static const u32 fzgx_pool_rodata_lbl_1_rodata_200_54[3] = {  /* fzgx-allow: A1 retail data bytes and bindings */
    0x0, 0x0, 0x0
};
static const u32 fzgx_pool_rodata_lbl_1_rodata_200_60[3] = {  /* fzgx-allow: A1 retail data bytes and bindings */
    0x0, 0x3F800000, 0x0
};
static const u32 fzgx_pool_rodata_lbl_1_rodata_200_6C[3] = {  /* fzgx-allow: A1 retail data bytes and bindings */
    0x0, 0x3F800000, 0x0
};
static const u32 fzgx_pool_rodata_lbl_1_rodata_200_78[3] = {  /* fzgx-allow: A1 retail data bytes and bindings */
    0x0, 0x0, 0x0
};
static const u32 fzgx_pool_rodata_lbl_1_rodata_200_84[3] = {  /* fzgx-allow: A1 retail data bytes and bindings */
    0x0, 0x40400000, 0x0
};
static const u32 fzgx_pool_rodata_lbl_1_rodata_200_90[1] = {  /* fzgx-allow: A1 retail data bytes and bindings */
    0x44BB8000
};
static const u32 fzgx_pool_rodata_lbl_1_rodata_200_94[1] = {  /* fzgx-allow: A1 retail data bytes and bindings */
    0x42540000
};
static const u32 fzgx_pool_rodata_lbl_1_rodata_200_98[1] = {  /* fzgx-allow: A1 retail data bytes and bindings */
    0x40400000
};
static const u32 fzgx_pool_rodata_lbl_1_rodata_200_9C[1] = {  /* fzgx-allow: A1 retail data bytes and bindings */
    0x3C23D70A
};
#pragma section code_type ".fzgxpool"
/* places the native literals 0.05 and 4e-5f at retail's pool offsets 0xA0, 0xA8 */
static void fzgx_pool_literals_lbl_1_rodata_200_A0(void) {
    volatile f32 s;  /* fzgx-allow: S2 layout primer sink */
    volatile f64 d;  /* fzgx-allow: S2 layout primer sink */
    d = 0.05;
    s = 4e-5f;
}
#pragma section code_type ".text"
static const u32 fzgx_pool_rodata_lbl_1_rodata_200_AC[1] = {  /* fzgx-allow: A1 retail data bytes and bindings */
    0x42A00000
};
static const u32 fzgx_pool_rodata_lbl_1_rodata_200_B0[1] = {  /* fzgx-allow: A1 retail data bytes and bindings */
    0x42D80000
};
static const u32 fzgx_pool_rodata_lbl_1_rodata_200_B4[1] = {  /* fzgx-allow: A1 retail data bytes and bindings */
    0x3FACCCCD
};
static const u32 fzgx_pool_rodata_lbl_1_rodata_200_B8[1] = {  /* fzgx-allow: A1 retail data bytes and bindings */
    0x42B40000
};
static const u32 fzgx_pool_rodata_lbl_1_rodata_200_BC[1] = {  /* fzgx-allow: A1 retail data bytes and bindings */
    0x3F99999A
};
static const u32 fzgx_pool_rodata_lbl_1_rodata_200_C0[2] = {  /* fzgx-allow: A1 retail data bytes and bindings */
    0x3E4CCCCD, 0x0
};
static const u32 fzgx_pool_rodata_lbl_1_rodata_200_C8[2] = {  /* fzgx-allow: A1 retail data bytes and bindings */
    0x3F847AE1, 0x47AE147B
};
static const u32 fzgx_pool_rodata_lbl_1_rodata_200_D0[1] = {  /* fzgx-allow: A1 retail data bytes and bindings */
    0x3D4CCCCD
};
static const u32 fzgx_pool_rodata_lbl_1_rodata_200_D4[1] = {  /* fzgx-allow: A1 retail data bytes and bindings */
    0x3DCCCCCD
};
static const u32 fzgx_pool_rodata_lbl_1_rodata_200_D8[2] = {  /* fzgx-allow: A1 retail data bytes and bindings */
    0x3FC33333, 0x33333333
};
static const u32 fzgx_pool_rodata_lbl_1_rodata_2E0[1] = {  /* fzgx-allow: A1 retail data bytes and bindings */
    0x3F800000
};
static const u32 fzgx_pool_rodata_lbl_1_rodata_200_E4[1] = {  /* fzgx-allow: A1 retail data bytes and bindings */
    0x43360B61
};
static const u32 fzgx_pool_rodata_lbl_1_rodata_200_E8[2] = {  /* fzgx-allow: A1 retail data bytes and bindings */
    0x3ECCCCCD, 0x0
};
static const u32 fzgx_pool_rodata_lbl_1_rodata_200_F0[2] = {  /* fzgx-allow: A1 retail data bytes and bindings */
    0x3FBEB851, 0xEB851EB8
};
static const u32 fzgx_pool_rodata_lbl_1_rodata_200_F8[2] = {  /* fzgx-allow: A1 retail data bytes and bindings */
    0x459C4000, 0x0
};
static const u32 fzgx_pool_rodata_lbl_1_rodata_200_100[2] = {  /* fzgx-allow: A1 retail data bytes and bindings */
    0x3FF33333, 0x33333333
};
static const u32 fzgx_pool_rodata_lbl_1_rodata_200_108[2] = {  /* fzgx-allow: A1 retail data bytes and bindings */
    0x3FF66666, 0x66666666
};
static const u32 fzgx_pool_rodata_lbl_1_rodata_200_110[2] = {  /* fzgx-allow: A1 retail data bytes and bindings */
    0x3FFB3333, 0x33333333
};
#pragma section code_type ".fzgxpool"
/* places the native literals 0.08, 0.2 and 0.04 at retail's pool offsets 0x118, 0x120, 0x128 */
static void fzgx_pool_literals_lbl_1_rodata_200_118(void) {
    volatile f64 d;  /* fzgx-allow: S2 layout primer sink */
    d = 0.08;
    d = 0.2;
    d = 0.04;
}
#pragma section code_type ".text"
static const u32 fzgx_pool_rodata_lbl_1_rodata_200_130[2] = {  /* fzgx-allow: A1 retail data bytes and bindings */
    0x3F000000, 0x0
};
#pragma section code_type ".fzgxpool"
/* places the native literal 0.1 at retail's pool offset 0x138 */
static void fzgx_pool_literals_lbl_1_rodata_200_138(void) {
    volatile f64 d;  /* fzgx-allow: S2 layout primer sink */
    d = 0.1;
}
#pragma section code_type ".text"
static const u32 fzgx_pool_rodata_lbl_1_rodata_200_140[1] = {  /* fzgx-allow: A1 retail data bytes and bindings */
    0x3FC00000
};
static const u32 fzgx_pool_rodata_lbl_1_rodata_200_144[1] = {  /* fzgx-allow: A1 retail data bytes and bindings */
    0x40133333
};
static const u32 fzgx_pool_rodata_lbl_1_rodata_200_148[2] = {  /* fzgx-allow: A1 retail data bytes and bindings */
    0x3F333333, 0x0
};
static const u32 fzgx_pool_rodata_lbl_1_rodata_200_150[2] = {  /* fzgx-allow: A1 retail data bytes and bindings */
    0x3FD33333, 0x33333333
};
static const u32 fzgx_pool_rodata_lbl_1_rodata_200_158[2] = {  /* fzgx-allow: A1 retail data bytes and bindings */
    0x404B8000, 0x0
};
static const u32 fzgx_pool_rodata_lbl_1_rodata_360[2] = {  /* fzgx-allow: A1 retail data bytes and bindings */
    0x4062C000, 0x0
};
static const u32 fzgx_pool_rodata_lbl_1_rodata_200_168[1] = {  /* fzgx-allow: A1 retail data bytes and bindings */
    0x42820000
};
static const u32 fzgx_pool_rodata_lbl_1_rodata_200_16C[1] = {  /* fzgx-allow: A1 retail data bytes and bindings */
    0x39782F05
};
static const u32 fzgx_pool_rodata_lbl_1_rodata_200_170[1] = {  /* fzgx-allow: A1 retail data bytes and bindings */
    0x42700000
};
static const u32 fzgx_pool_rodata_lbl_1_rodata_200_174[1] = {  /* fzgx-allow: A1 retail data bytes and bindings */
    0x3991A2B4
};
static const u32 fzgx_pool_rodata_lbl_1_rodata_200_178[2] = {  /* fzgx-allow: A1 retail data bytes and bindings */
    0x401CC28F, 0x5C28F5C3
};
static const u32 fzgx_pool_rodata_lbl_1_rodata_200_180[1] = {  /* fzgx-allow: A1 retail data bytes and bindings */
    0x40A00000
};
static const u32 fzgx_pool_rodata_lbl_1_rodata_200_184[1] = {  /* fzgx-allow: A1 retail data bytes and bindings */
    0x403C28F6
};
#pragma section code_type ".fzgxpool"
static void fzgx_data_layout_lbl_1_rodata_200(void) {
    volatile u8 s;  /* fzgx-allow: S2 layout primer sink: keeps the retail .data objects in retail order */
    s = *(u8 *)fzgx_pool_rodata_lbl_1_rodata_200;
    s = *(u8 *)fzgx_pool_rodata_lbl_1_rodata_204;
    s = *(u8 *)fzgx_pool_rodata_lbl_1_rodata_230;
    s = *(u8 *)fzgx_pool_rodata_lbl_1_rodata_200_34;
    s = *(u8 *)fzgx_pool_rodata_lbl_1_rodata_200_48;
    s = *(u8 *)fzgx_pool_rodata_lbl_1_rodata_200_54;
    s = *(u8 *)fzgx_pool_rodata_lbl_1_rodata_200_60;
    s = *(u8 *)fzgx_pool_rodata_lbl_1_rodata_200_6C;
    s = *(u8 *)fzgx_pool_rodata_lbl_1_rodata_200_78;
    s = *(u8 *)fzgx_pool_rodata_lbl_1_rodata_200_84;
    s = *(u8 *)fzgx_pool_rodata_lbl_1_rodata_200_90;
    s = *(u8 *)fzgx_pool_rodata_lbl_1_rodata_200_94;
    s = *(u8 *)fzgx_pool_rodata_lbl_1_rodata_200_98;
    s = *(u8 *)fzgx_pool_rodata_lbl_1_rodata_200_9C;
    s = *(u8 *)fzgx_pool_rodata_lbl_1_rodata_200_AC;
    s = *(u8 *)fzgx_pool_rodata_lbl_1_rodata_200_B0;
    s = *(u8 *)fzgx_pool_rodata_lbl_1_rodata_200_B4;
    s = *(u8 *)fzgx_pool_rodata_lbl_1_rodata_200_B8;
    s = *(u8 *)fzgx_pool_rodata_lbl_1_rodata_200_BC;
    s = *(u8 *)fzgx_pool_rodata_lbl_1_rodata_200_C0;
    s = *(u8 *)fzgx_pool_rodata_lbl_1_rodata_200_C8;
    s = *(u8 *)fzgx_pool_rodata_lbl_1_rodata_200_D0;
    s = *(u8 *)fzgx_pool_rodata_lbl_1_rodata_200_D4;
    s = *(u8 *)fzgx_pool_rodata_lbl_1_rodata_200_D8;
    s = *(u8 *)fzgx_pool_rodata_lbl_1_rodata_2E0;
    s = *(u8 *)fzgx_pool_rodata_lbl_1_rodata_200_E4;
    s = *(u8 *)fzgx_pool_rodata_lbl_1_rodata_200_E8;
    s = *(u8 *)fzgx_pool_rodata_lbl_1_rodata_200_F0;
    s = *(u8 *)fzgx_pool_rodata_lbl_1_rodata_200_F8;
    s = *(u8 *)fzgx_pool_rodata_lbl_1_rodata_200_100;
    s = *(u8 *)fzgx_pool_rodata_lbl_1_rodata_200_108;
    s = *(u8 *)fzgx_pool_rodata_lbl_1_rodata_200_110;
    s = *(u8 *)fzgx_pool_rodata_lbl_1_rodata_200_130;
    s = *(u8 *)fzgx_pool_rodata_lbl_1_rodata_200_140;
    s = *(u8 *)fzgx_pool_rodata_lbl_1_rodata_200_144;
    s = *(u8 *)fzgx_pool_rodata_lbl_1_rodata_200_148;
    s = *(u8 *)fzgx_pool_rodata_lbl_1_rodata_200_150;
    s = *(u8 *)fzgx_pool_rodata_lbl_1_rodata_200_158;
    s = *(u8 *)fzgx_pool_rodata_lbl_1_rodata_360;
    s = *(u8 *)fzgx_pool_rodata_lbl_1_rodata_200_168;
    s = *(u8 *)fzgx_pool_rodata_lbl_1_rodata_200_16C;
    s = *(u8 *)fzgx_pool_rodata_lbl_1_rodata_200_170;
    s = *(u8 *)fzgx_pool_rodata_lbl_1_rodata_200_174;
    s = *(u8 *)fzgx_pool_rodata_lbl_1_rodata_200_178;
    s = *(u8 *)fzgx_pool_rodata_lbl_1_rodata_200_180;
    s = *(u8 *)fzgx_pool_rodata_lbl_1_rodata_200_184;
}
#pragma section code_type ".text"

/* camera.c .data before fn_1_90E0's jump table, in retail order */
static u8 lbl_1_data_3678[0xC] = {
    0x00, 0x01, 0x05, 0x07, 0x08, 0x0C, 0x0D, 0x10, 0x12, 0x17, 0x00, 0x00
};
static char lbl_1_data_3684[9] = "OVERTAKE";
static char lbl_1_data_3690[5] = "JUMP";
static char lbl_1_data_3698[9] = "ENEMYHIT";
static char lbl_1_data_36A4[8] = "WALLHIT";
static char lbl_1_data_36AC[11] = "SIDEBYSIDE";
static char lbl_1_data_36B8[6] = "START";
static char lbl_1_data_36C0[5] = "GOAL";
static char lbl_1_data_36C8[4] = "LAP";
static char *lbl_1_data_36CC[8] = {
    lbl_1_data_3684, lbl_1_data_3690, lbl_1_data_3698, lbl_1_data_36A4,
    lbl_1_data_36AC, lbl_1_data_36B8, lbl_1_data_36C0, lbl_1_data_36C8
};
/* the table of fn_1_8B10 */
u32 lbl_1_data_36EC[0x36] = {
    0x3FC00000, 0x0, 0xFF2C0000, 0x3FC00000, 0x0, 0xFF2C0000, 0x3FC00000, 0x0,
    0x1AAA0000, 0x403C28F6, 0x40E6147B, 0xF7EF0000, 0x40800000, 0x40A00000, 0xFA000000, 0x404F5C29,
    0x410EB852, 0x9000000, 0x40F33333, 0x4144CCCD, 0xF2000000, 0x410CCCCD, 0x40BCCCCD, 0xEF000000,
    0x40833333, 0x41100000, 0x10000000, 0x41480000, 0x416B0A3D, 0xEE080000, 0x41480000, 0x416B0A3D,
    0xEE080000, 0x41080000, 0x41A80000, 0x13000000, 0x3FC00000, 0x40C00000, 0xFCDE0000, 0x3FE66666,
    0x4089999A, 0x660000, 0x40133333, 0x40E00000, 0x11050000, 0x40C00000, 0x41200000, 0xF4F90000,
    0x40C00000, 0x4124CCCD, 0xFD080000, 0x40923D71, 0x41711EB8, 0x11050000
};
/* the table of fn_1_90E0 */
static u32 lbl_1_data_37C4[0x60] = {
    0x3F000000, 0x3FC00000, 0x40A00000, 0x3F000000, 0x3FC00000, 0x0, 0x20000000, 0x0,
    0xBF000000, 0x3FC00000, 0x40A00000, 0xBF000000, 0x3FC00000, 0x0, LC_BASE, 0x0,
    0x40800000, 0x41200000, 0xC1500000, 0x0, 0x3E4CCCCD, 0x41500000, 0x15550000, 0x0,  /* fzgx-allow: A1 retail data bytes */
    0xC0800000, 0x41200000, 0xC1500000, 0x0, 0x3E4CCCCD, 0x41500000, 0xEAAB0000, 0x0,  /* fzgx-allow: A1 retail data bytes */
    0x40800000, 0x3F000000, 0x40A00000, 0x0, 0x3F666666, 0x0, 0xE380000, 0x0,
    0xC0800000, 0x3F000000, 0x40A00000, 0x80000000, 0x3F666666, 0x0, 0xF1C80000, 0x0,  /* fzgx-allow: A1 retail data bytes */
    0x41000000, 0x40400000, 0xC0A00000, 0x0, 0x40000000, 0x0, 0x0, 0x0,  /* fzgx-allow: A1 retail data bytes */
    0xC1000000, 0x40400000, 0xC0A00000, 0x0, 0x40000000, 0x0, 0x0, 0x0,  /* fzgx-allow: A1 retail data bytes */
    0xC0200000, 0x40000000, 0x41000000, 0xBF800000, 0x3FE66666, 0xBF800000, 0x0, 0x0,  /* fzgx-allow: A1 retail data bytes */
    0x40200000, 0x40000000, 0x41000000, 0x3F800000, 0x3FE66666, 0xBF800000, 0x0, 0x0,
    0xBFC00000, 0x40000000, 0xC0733333, 0x3E4CCCCD, 0x3FCCCCCD, 0x0, 0x0, 0x0,  /* fzgx-allow: A1 retail data bytes */
    0x3FC00000, 0x40000000, 0xC0733333, 0xBE4CCCCD, 0x3FCCCCCD, 0x0, 0x0, 0x0  /* fzgx-allow: A1 retail data bytes */
};

/* pool reads */
#define P32(s) (*(f32 *)((u8 *)s))
#define P64(s) (*(f64 *)((u8 *)s))
#define PV(s) (*(V90 *)((u8 *)s))
#define PVV(s) (*(volatile V90 *)((u8 *)s))  /* fzgx-allow: S2 volatile view keeps the verified load order */

extern u8 fn_1_86678(int);
extern u8 fn_1_3BB0(u32);
extern Sig_camera_get_target_orientation_camera_get_target_orientation_CameraObject *fn_1_86254(int);
extern struct C90 *fn_1_8627C(s32);
extern void fn_1_8636C(int, void *);
extern f32 fn_1_8652C(int);
extern u32 fn_1_864E8(int);
extern void fn_1_AA54(void *);
extern void fn_1_ABAC(void *);
extern void fn_1_8B10(void *, Output90 *);
extern s32 camera_get_state(void);
extern void fn_1_A888(void *);
extern void camera_get_position_delta(u32, void *);
extern s32 fn_1_8677C(u32);
extern f32 fn_1_8655C(int);
extern f32 camera_get_target_orientation(Sig_camera_get_target_orientation_camera_get_target_orientation_CameraObject *);
extern s16 fn_1_8683C(int);
extern void fn_1_869E0(int, void *);
extern f32 fn_1_86574(int);
extern s16 fn_1_7B054(void);
extern u32 fn_1_58C4(void);
extern s32 fn_1_F2F34(void);
extern void fn_1_FA450(s32);
extern void fn_1_B4D4(void *);
extern void camera_reset_transition(camera_reset_transition_Camera *);
extern void camera_update_transition(camera_update_transition_Camera *);
extern u16 fn_1_8664C(int);
extern void fn_1_A8EB0(int,int);
extern void fn_1_A8E78(void *);
extern f32 fn_1_A6FE8(void);
extern void fn_1_862A8(int,void *);
extern void fn_1_549F4(void *,void *,f32,f32,f32,f32);
extern void fn_1_54DCC(void *);
extern void lbl_8006DAEC(void);
extern void fn_80008C20(void *,void *,void *);
extern void lbl_8006DB74(void *);
extern void lbl_8006DC6C(void *);
extern void fn_8006E2B0(void *,void *);
extern void fn_8006EE70(void *,void *);
extern void fn_8006EFB4(void *,void *,f32);
extern void lbl_8006DB30(void);
extern void lbl_8006E1C0(void *,void *);
extern void lbl_8006DD14(void *,void *);
extern void mathutil_mtxA_rotate_y(s32);
extern void fn_80008DB4(void *,void *,void *,f32);
extern void lbl_8006E1B0(void *,void *);
extern void mathutil_mtxA_rotate_x(s16);
extern void lbl_8006D5A4(void *,void *,void *,f32);
extern void lbl_8006E0B4(f32,f32,f32);
extern s32 fn_80007D58(void *);
extern s32 fn_80007CDC(void *);
extern void lbl_8006D784(void *);
extern void fn_8006EDBC(void *,void *,s16 *,s16 *);
extern void lbl_8006D1BC(s16,f32 *,f32 *);
extern void lbl_8006D8E4(f32,f32);
extern void mathutil_mtxA_rotate_x__fzgx_offset_C(f32,f32);
/* case 3's camera object */
#define OBJ90 ((Sig_camera_get_target_orientation_camera_get_target_orientation_CameraObject *)v3)
extern s16 lbl_8006D24C(f32,f32);
extern void fn_8006F1F0(void *,void *,void *);
extern void fn_8006F4E0(void *);
static inline int bad90(f32 x) {
return (*(u32 *)&x & 0x7F800000) == 0x7F800000;
}
static inline void set90(V90 *v, f32 x, f32 y, f32 z) {
v->x = x;
v->y = y;
v->z = z;
}
static inline void trans90(V90 *v) {
struct { u32 value; } fzgx_lc;
f32 x = *(volatile f32 *)&v->x;  /* fzgx-allow: S2 volatile view keeps the verified load order */
f32 y = v->y;
f32 z = v->z;
fzgx_lc.value = LC_BASE;
((volatile f32 *)fzgx_lc.value)[3] = x;  /* fzgx-allow: S2 volatile view keeps the verified load order */
((volatile f32 *)fzgx_lc.value)[7] = y;  /* fzgx-allow: S2 volatile view keeps the verified load order */
((volatile f32 *)fzgx_lc.value)[11] = z;  /* fzgx-allow: S2 volatile view keeps the verified load order */
}
/* mtxA column 2 scaled plus the translation column */
static inline void project90(V90 *v, f32 scale) {
f32 x, cx, y, cy, z, cz;
x = ((f32 *)LC_BASE)[2];
cx = ((f32 *)LC_BASE)[3];
y = ((f32 *)LC_BASE)[6];
cy = ((f32 *)LC_BASE)[7];
z = ((f32 *)LC_BASE)[10];
cz = ((f32 *)LC_BASE)[11];
x = __fmadds(x, scale, cx);
y = __fmadds(y, scale, cy);
z = __fmadds(z, scale, cz);
v->x = x;
v->y = y;
v->z = z;
}
/* eased approach rate: shrinks as `cur` nears 3.0, clamped to [0.08, hi] */
#define RATE90(cur) (0.2 - 0.04 * (f32)(P32(fzgx_pool_rodata_lbl_1_rodata_200_98) - (cur)))
#define CLAMP90(cur, hi) ((RATE90(cur) < 0.08) ? 0.08 : (RATE90(cur) > (hi)) ? (hi) : RATE90(cur))
/* speed-dependent fov blend rate, clamped to [0.01, 0.05] */
#define FOVRATE90(speed) (0.05 - 4e-5f * (speed))
static inline void fn_1_90E0_call_lbl_8006E0B4(f32 a0, f32 a1, f32 a2) { lbl_8006E0B4(a0, a1, a2); }
#pragma opt_propagation off
#pragma opt_lifetimes off
void fn_1_90E0(struct fn_1_90E0_Arg0 *arg0) {
Sig_camera_get_target_orientation_camera_get_target_orientation_CameraObject * obj3;
Sig_camera_get_target_orientation_camera_get_target_orientation_CameraObject *t3;
s8 v0;
s32 v1;
u32 v2;
signed int v3;
Sig_camera_get_target_orientation_camera_get_target_orientation_CameraObject * target_state90;
s16 v4;
M90 loc_134;
Output90 loc_110;
M90 loc_E0;
Triple loc_D4;
V90 loc_C8;
V90 loc_BC;
V90 loc_B0;
V90 loc_A4;
V90 loc_98;
V90 loc_8C;
V90 loc_80;
V90 loc_74;
V90 loc_68;
V90 loc_5C;
V90 loc_50;
s16 loc_30[4];
s16 loc_28[4];
f32 loc_24, loc_20, loc_1C, loc_18;
s16 loc_A, loc_8;
struct C90 *t4;
f32 t7;
u32 t8;
f32 x, y, fov, k;
f32 fovt;
f32 rate;
s16 angle;
u8 *entry;
union {
s32 invalid;
Sig_camera_get_target_orientation_camera_get_target_orientation_CameraObject *object;
} transition_state90;
#define bad transition_state90.invalid

v0 = fn_1_86678(arg0->unk_2);
if (v0 == 0xFFFFFFFF) {
v1 = 0;
} else {
switch (fn_1_3BB0(v0) & 0xFF) {
case 2: case 3: case 4: v1 = 1; break;
default: v1 = 0; break;
}
}
lbl_8006DAEC();
arg0->unk_1C = arg0->unk_10;
t3 = fn_1_86254(arg0->unk_2);
t4 = fn_1_8627C(arg0->unk_2);
fn_1_862D4(arg0->unk_2, (Vec3 *)&loc_D4);
fn_1_8636C(arg0->unk_2, &loc_134);
t7 = fn_1_8652C(arg0->unk_2);
t8 = fn_1_864E8(arg0->unk_2);
if (t4) {
if (t4->unk_7C & 0x1000000) v3 = 1;
else v3 = 0;
} else v3 = 0;
fn_1_AA54(arg0);
switch (arg0->unk_A8) {
case 0: {
arg0->unk_1E0 = 0;
fn_1_ABAC(arg0);
fn_1_8B10(arg0, &loc_110);
fovt = ((t7) < (P32(fzgx_pool_rodata_lbl_1_rodata_230))) ? (P32(fzgx_pool_rodata_lbl_1_rodata_230)) : (t7) > (P32(fzgx_pool_rodata_lbl_1_rodata_200_90)) ? (P32(fzgx_pool_rodata_lbl_1_rodata_200_90)) : (t7) ;
if (bad90(fovt)) fovt = P32(fzgx_pool_rodata_lbl_1_rodata_230) ;
fovt /= P32(fzgx_pool_rodata_lbl_1_rodata_200_90) ;
fov = P32(fzgx_pool_rodata_lbl_1_rodata_200_94) * (f32)(fovt * fovt);
x = loc_110.x0 + (fovt * (loc_110.x1 - loc_110.x0));
y = loc_110.y0 + (fovt * (loc_110.y1 - loc_110.y0));
angle = loc_110.a0 + (fovt * (loc_110.a1 - loc_110.a0));
if ((s8)camera_get_state() == 1) fov /= P32(fzgx_pool_rodata_lbl_1_rodata_200_98) ;
fov = 55.0f + fov;
if (arg0->unk_A4 == 3) {
fov = 55.0f;
x = loc_110.x0;
y = loc_110.y0;
angle = loc_110.a0;
}
if (arg0->unk_A4 < 5) {
fn_1_A888(arg0);
x += (arg0->unk_70 * (loc_110.x2 - x));
y += (arg0->unk_70 * (loc_110.y2 - y));
angle = angle + (arg0->unk_70 * (loc_110.a2 - angle)) / 2.0;
}
rate = (FOVRATE90(t7) < P32(fzgx_pool_rodata_lbl_1_rodata_200_9C)) ? P32(fzgx_pool_rodata_lbl_1_rodata_200_9C) : (FOVRATE90(t7) > 0.05) ? 0.05 : FOVRATE90(t7);
if (t8 & 0x400040) {
arg0->unk_74 = (((f32)(arg0->unk_8 * P32(fzgx_pool_rodata_lbl_1_rodata_200_B4))) < (P32(fzgx_pool_rodata_lbl_1_rodata_200_AC)) ? (P32(fzgx_pool_rodata_lbl_1_rodata_200_AC)) : ((f32)(arg0->unk_8 * P32(fzgx_pool_rodata_lbl_1_rodata_200_B4))) > (P32(fzgx_pool_rodata_lbl_1_rodata_200_B0)) ? (P32(fzgx_pool_rodata_lbl_1_rodata_200_B0)) : ((f32)(arg0->unk_8 * P32(fzgx_pool_rodata_lbl_1_rodata_200_B4)))) ;
if ((s8)camera_get_state() == 1)
arg0->unk_74 = (((f32)(arg0->unk_8 * P32(fzgx_pool_rodata_lbl_1_rodata_200_BC))) < (arg0->unk_8) ? (arg0->unk_8) : ((f32)(arg0->unk_8 * P32(fzgx_pool_rodata_lbl_1_rodata_200_BC))) > (P32(fzgx_pool_rodata_lbl_1_rodata_200_B8)) ? (P32(fzgx_pool_rodata_lbl_1_rodata_200_B8)) : ((f32)(arg0->unk_8 * P32(fzgx_pool_rodata_lbl_1_rodata_200_BC)))) ;
} else if ((t8 & 0x20) && arg0->unk_A4 != 3) {
if (arg0->unk_88 < 20) arg0->unk_88++;
if (arg0->unk_88 > 10) {
if (arg0->unk_84 < t7)
arg0->unk_8 = ((arg0->unk_8) + (f32)((P32(fzgx_pool_rodata_lbl_1_rodata_200_C0)) * ((arg0->unk_74) - (arg0->unk_8)))) ;
else
arg0->unk_8 = ((f32)((arg0->unk_8) + ((fov) - (arg0->unk_8)) * (P64(fzgx_pool_rodata_lbl_1_rodata_200_C8)))) ;
arg0->unk_84 = t7;
} else {
if (arg0->unk_A4 == 2)
arg0->unk_8 = ((arg0->unk_8) + (f32)((P32(fzgx_pool_rodata_lbl_1_rodata_200_D0)) * ((P32(fzgx_pool_rodata_lbl_1_rodata_200_AC)) - (arg0->unk_8)))) ;
else
arg0->unk_8 = ((arg0->unk_8) + (f32)((P32(fzgx_pool_rodata_lbl_1_rodata_200_D4)) * ((P32(fzgx_pool_rodata_lbl_1_rodata_200_AC)) - (arg0->unk_8)))) ;
if ((s8)camera_get_state() == 1)
arg0->unk_8 = ((arg0->unk_8) + (f32)((P32(fzgx_pool_rodata_lbl_1_rodata_200_D4)) * ((fov) - (arg0->unk_8)))) ;
}
} else {
if (arg0->unk_88 > 0) arg0->unk_88--;
if (arg0->unk_88 > 10) {
if (arg0->unk_84 < t7)
arg0->unk_8 = ((arg0->unk_8) + (f32)((P32(fzgx_pool_rodata_lbl_1_rodata_200_C0)) * ((arg0->unk_74) - (arg0->unk_8)))) ;
else
arg0->unk_8 = ((f32)((arg0->unk_8) + ((fov) - (arg0->unk_8)) * (P64(fzgx_pool_rodata_lbl_1_rodata_200_C8)))) ;
arg0->unk_84 = t7;
} else
arg0->unk_8 = ((arg0->unk_8) + ((rate) * ((fov) - arg0->unk_8))) ;
}
arg0->unk_8C.y = ((f32)((arg0->unk_8C.y) + ((x) - (arg0->unk_8C.y)) * (P64(fzgx_pool_rodata_lbl_1_rodata_200_D8)))) ;
arg0->unk_8C.z = ((f32)((arg0->unk_8C.z) + ((y) - (arg0->unk_8C.z)) * (P64(fzgx_pool_rodata_lbl_1_rodata_200_D8)))) ;
arg0->unk_6 = arg0->unk_6 + P64(fzgx_pool_rodata_lbl_1_rodata_200_D8) * (angle - arg0->unk_6);
camera_get_position_delta((u8)arg0->unk_2, &loc_B0);
if (!v1 && fn_1_8677C(arg0->unk_2) == 1 && arg0->unk_A4 != 0 && !(t8 & 0x100)) {
fn_80008C20(&arg0->unk_10, &arg0->unk_64, &loc_B0);
lbl_8006DB74(&loc_E0);
} else if ((t8 & 2) && arg0->unk_A4 != 0 && P32(fzgx_pool_rodata_lbl_1_rodata_230) == t3->unk_1C8) {
lbl_8006DC6C(&loc_134);
fn_8006E2B0(&loc_B0, &loc_B0);
fn_8006EE70(&loc_B0, &loc_28);
if (loc_28[0] > -0x100) loc_28[0] = -0x100;
if (loc_28[0] < -0x500) loc_28[0] = -0x500;
if (loc_28[1] > 100) loc_28[1] = 100;
if (loc_28[1] < -100) loc_28[1] = -100;
lbl_8006DAEC();
fn_8006EFB4(&loc_28, &loc_B0, P32(fzgx_pool_rodata_lbl_1_rodata_2E0) );
lbl_8006DB30();
lbl_8006E1C0(&loc_B0, &loc_B0);
fn_80008C20(&arg0->unk_10, &arg0->unk_64, &loc_B0);
lbl_8006DB74(&loc_E0);
} else {
lbl_8006DD14(&loc_134, &loc_E0);
}
lbl_8006DBAC((Vec3 *)&loc_E0);
mathutil_mtxA_rotate_y((s32)(P32(fzgx_pool_rodata_lbl_1_rodata_200_E4) * (s16)(s32)(P32(fzgx_pool_rodata_lbl_1_rodata_200_E8) * t3->unk_4D8)));
lbl_8006DB74(&loc_E0);
k = (((f32)(t7 / P32(fzgx_pool_rodata_lbl_1_rodata_200_F8))) < 0.05) ? 0.05 : ((f32)(t7 / P32(fzgx_pool_rodata_lbl_1_rodata_200_F8))) > (P64(fzgx_pool_rodata_lbl_1_rodata_200_F0)) ? (P64(fzgx_pool_rodata_lbl_1_rodata_200_F0)) : ((f32)(t7 / P32(fzgx_pool_rodata_lbl_1_rodata_200_F8))) ;
k *= fn_1_8655C(arg0->unk_2);
if (arg0->unk_A4 == 2) k *= P64(fzgx_pool_rodata_lbl_1_rodata_200_100) ;
if (arg0->unk_A4 == 3) k *= P64(fzgx_pool_rodata_lbl_1_rodata_200_108) ;
if (arg0->unk_A4 == 0) k = P32(fzgx_pool_rodata_lbl_1_rodata_200_C0) ;
if (v3) {
camera_get_target_orientation(t3);
k = P32(fzgx_pool_rodata_lbl_1_rodata_200_C0) ;
}
if (fn_1_8683C(arg0->unk_2) == 0)
fn_80008DB4(&arg0->unk_34, &loc_E0, &arg0->unk_34, k);
lbl_8006DC6C(&arg0->unk_34);
trans90((V90 *)&loc_D4);
lbl_8006E1B0(&arg0->unk_8C, &arg0->unk_10);
trans90(&arg0->unk_10);
mathutil_mtxA_rotate_x(arg0->unk_6);
project90(&arg0->unk_28, P32(fzgx_pool_rodata_lbl_1_rodata_200_34) );
if (fn_1_8683C(arg0->unk_2) != 0)
fn_1_869E0(arg0->unk_2, &loc_C8);
else {
lbl_8006DC6C(&loc_134);
trans90((V90 *)&loc_D4);
loc_C8 = PVV(fzgx_pool_rodata_lbl_1_rodata_200_48) ;
lbl_8006E1C0(&loc_C8, &loc_C8);
}
v2 = t8 & 2;
k = P32(fzgx_pool_rodata_lbl_1_rodata_200_D4) ;
if (v2) k = P32(fzgx_pool_rodata_lbl_1_rodata_200) ;
k *= fn_1_86574(arg0->unk_2);
if (arg0->unk_A4 == 2) k *= P64(fzgx_pool_rodata_lbl_1_rodata_200_100) ;
if (arg0->unk_A4 == 3) k *= P64(fzgx_pool_rodata_lbl_1_rodata_200_110) ;
if (arg0->unk_A4 == 0) k = P32(fzgx_pool_rodata_lbl_1_rodata_200_C0) ;
lbl_8006D5A4(&arg0->unk_64, &loc_C8, &arg0->unk_64, k);
if (arg0->unk_A4 == 1 || arg0->unk_A4 == 2 || arg0->unk_A4 == 4) {
s32 active = 0;
if (v2) {
if (arg0->unk_78 < 5) arg0->unk_78++;
} else arg0->unk_78 = 0;
if (arg0->unk_78 > 1) active = 1;
if (active) {
s32 special;
if (v3) goto special_camera90; /* Keep the verified branch to special_camera90. */
{
s16 c = fn_1_7B054();
special = 0;
if (c == 0x21 || c == 0x57) special = 1;
}
if (special) {
special_camera90:
switch (arg0->unk_A4) {
case 4:
arg0->unk_7C += (-P32(fzgx_pool_rodata_lbl_1_rodata_200_130) - arg0->unk_7C) * CLAMP90(arg0->unk_7C, 0.2);
arg0->unk_80 += (P32(fzgx_pool_rodata_lbl_1_rodata_200_130) - arg0->unk_80) * CLAMP90(arg0->unk_80, 0.2);
break;
case 1:
arg0->unk_7C += (-P32(fzgx_pool_rodata_lbl_1_rodata_200_140) - arg0->unk_7C) * CLAMP90(arg0->unk_7C, 0.1);
arg0->unk_80 += (P32(fzgx_pool_rodata_lbl_1_rodata_200_140) - arg0->unk_80) * CLAMP90(arg0->unk_80, 0.1);
break;
case 2:
arg0->unk_7C += (f32)(P32(fzgx_pool_rodata_lbl_1_rodata_200_C0) * (-P32(fzgx_pool_rodata_lbl_1_rodata_200_144) - arg0->unk_7C));
arg0->unk_80 += (f32)(P32(fzgx_pool_rodata_lbl_1_rodata_200_C0) * (P32(fzgx_pool_rodata_lbl_1_rodata_200_144) - arg0->unk_80));
break;
default:
arg0->unk_7C += (f32)(P32(fzgx_pool_rodata_lbl_1_rodata_200_C0) * (-P32(fzgx_pool_rodata_lbl_1_rodata_200_144) - arg0->unk_7C));
arg0->unk_80 += (f32)(P32(fzgx_pool_rodata_lbl_1_rodata_200_C0) * (P32(fzgx_pool_rodata_lbl_1_rodata_200_144) - arg0->unk_80));
break;
}
} else {
switch (arg0->unk_A4) {
case 4:
arg0->unk_7C += (P32(fzgx_pool_rodata_lbl_1_rodata_200_130) - arg0->unk_7C) * CLAMP90(arg0->unk_7C, 0.2);
arg0->unk_80 += (P32(fzgx_pool_rodata_lbl_1_rodata_200_130) - arg0->unk_80) * CLAMP90(arg0->unk_80, 0.2);
break;
case 1:
arg0->unk_7C += (P32(fzgx_pool_rodata_lbl_1_rodata_200_140) - arg0->unk_7C) * CLAMP90(arg0->unk_7C, 0.2);
arg0->unk_80 += (P32(fzgx_pool_rodata_lbl_1_rodata_200_140) - arg0->unk_80) * CLAMP90(arg0->unk_80, 0.2);
break;
case 2:
arg0->unk_7C += (f32)(P32(fzgx_pool_rodata_lbl_1_rodata_200_C0) * (P32(fzgx_pool_rodata_lbl_1_rodata_200_144) - arg0->unk_7C));
arg0->unk_80 += (f32)(P32(fzgx_pool_rodata_lbl_1_rodata_200_C0) * (P32(fzgx_pool_rodata_lbl_1_rodata_200_144) - arg0->unk_80));
break;
default:
arg0->unk_7C += (f32)(P32(fzgx_pool_rodata_lbl_1_rodata_200_C0) * (P32(fzgx_pool_rodata_lbl_1_rodata_200_144) - arg0->unk_7C));
arg0->unk_80 += (f32)(P32(fzgx_pool_rodata_lbl_1_rodata_200_C0) * (P32(fzgx_pool_rodata_lbl_1_rodata_200_144) - arg0->unk_80));
break;
}
}
} else {
arg0->unk_7C += (f32)(P32(fzgx_pool_rodata_lbl_1_rodata_200_D0) * -arg0->unk_7C);
arg0->unk_80 += (f32)(P32(fzgx_pool_rodata_lbl_1_rodata_200_D0) * -arg0->unk_80);
}
lbl_8006DC6C(&arg0->unk_34);
trans90((V90 *)&loc_D4);
loc_A4 = arg0->unk_8C;
loc_A4.y -= arg0->unk_7C;
lbl_8006E1B0(&loc_A4, &arg0->unk_10);
fn_8006E250((Vec3f *)&arg0->unk_28, (Vec3f *)&loc_A4);
loc_A4.y -= (f32)(arg0->unk_80 * P32(fzgx_pool_rodata_lbl_1_rodata_200_148) );
lbl_8006E1B0(&loc_A4, &arg0->unk_28);
}
if (fn_1_58C4() == 1 && fn_1_F2F34() == 0) fn_1_FA450(arg0->unk_A6);
fn_1_B4D4(arg0);
break;
}
case 1: {
u8 *entry;
fn_1_ABAC(arg0);
entry = ((u8 *)lbl_1_data_37C4);
entry += arg0->unk_A4 * 0x20;
lbl_8006DC6C(&loc_134);
trans90((V90 *)&loc_D4);
lbl_8006E1B0(entry, &arg0->unk_10);
lbl_8006E1B0(entry + 0xC, &arg0->unk_28);
arg0->unk_8 = ((f32)((arg0->unk_8) + ((P64(fzgx_pool_rodata_lbl_1_rodata_200_158)) - (arg0->unk_8)) * (P64(fzgx_pool_rodata_lbl_1_rodata_200_150)))) ;
break;
case 2:
if (!arg0->unk_1E0) camera_reset_transition((camera_reset_transition_Camera *)arg0);
camera_update_transition((camera_update_transition_Camera *)arg0);
arg0->unk_1E0++;
break;
case 3: {
#define obj3 target_state90
if (P64(fzgx_pool_rodata_lbl_1_rodata_360) == fn_1_8664C(arg0->unk_2)) {
arg0->unk_1E4 = arg0->unk_10;
arg0->unk_1F0 = P32(fzgx_pool_rodata_lbl_1_rodata_230) ;
arg0->unk_1F4 = P32(fzgx_pool_rodata_lbl_1_rodata_230) ;
}
entry = (u8 *)fn_1_86254(arg0->unk_2);
fn_1_8B10(arg0, &loc_110);
{
#undef OBJ90
#define OBJ90 ((Sig_camera_get_target_orientation_camera_get_target_orientation_CameraObject *)entry)
{
V90 v = PV(fzgx_pool_rodata_lbl_1_rodata_200_54) ;
v.y = loc_110.x0;
v.z = loc_110.y0;
loc_80 = v;
}
lbl_8006DBAC((Vec3 *)(entry + (s32)&((Sig_camera_get_target_orientation_camera_get_target_orientation_CameraObject *)0)->unk_594));
lbl_8006E1B0(&loc_80, &loc_BC);
loc_C8 = PV(fzgx_pool_rodata_lbl_1_rodata_200_60) ;
lbl_8006E1C0(&loc_C8, &loc_C8);
lbl_8006DC6C(&loc_134);
trans90((V90 *)&loc_D4);
lbl_8006E1B0(&loc_80, &loc_8C);
trans90(&loc_8C);
mathutil_mtxA_rotate_x(loc_110.a0);
project90(&loc_98, P32(fzgx_pool_rodata_lbl_1_rodata_200_34) );
#pragma fp_contract off
if ((f32)(u32)(fn_1_8664C(arg0->unk_2) - 20) < P32(fzgx_pool_rodata_lbl_1_rodata_200_168) ) arg0->unk_1F4 -= P32(fzgx_pool_rodata_lbl_1_rodata_200_16C) ;
else arg0->unk_1F4 += P32(fzgx_pool_rodata_lbl_1_rodata_200_16C) ;
arg0->unk_1F0 += arg0->unk_1F4;
arg0->unk_1F0 = ((arg0->unk_1F0) < (P32(fzgx_pool_rodata_lbl_1_rodata_230)) ? (P32(fzgx_pool_rodata_lbl_1_rodata_230)) : (arg0->unk_1F0) > (P32(fzgx_pool_rodata_lbl_1_rodata_2E0)) ? (P32(fzgx_pool_rodata_lbl_1_rodata_2E0)) : (arg0->unk_1F0)) ;
lbl_8006D5A4(&arg0->unk_1E4, &loc_BC, &arg0->unk_10, arg0->unk_1F0);
lbl_8006D5A4(&arg0->unk_28, &loc_98, &arg0->unk_28, P32(fzgx_pool_rodata_lbl_1_rodata_200_C0) );
lbl_8006D5A4(&arg0->unk_64, &loc_C8, &arg0->unk_64, P32(fzgx_pool_rodata_lbl_1_rodata_200_C0) );
lbl_8006DD14((entry + (s32)&((Sig_camera_get_target_orientation_camera_get_target_orientation_CameraObject *)0)->unk_EC), &arg0->unk_34);
arg0->unk_8 = ((f32)((arg0->unk_8) + ((P64(fzgx_pool_rodata_lbl_1_rodata_200_158)) - (arg0->unk_8)) * (P64(fzgx_pool_rodata_lbl_1_rodata_200_150)))) ;
break;
}
}
}
case 5:
if (!(t3->unk_58C & 0x10))
lbl_8006D5A4(&arg0->unk_28, &loc_D4, &arg0->unk_28, P32(fzgx_pool_rodata_lbl_1_rodata_200_C0) );
fn_1_B4D4(arg0);
break;
case 6: {
if (arg0->unk_1F8 < 0) {
arg0->unk_1E4 = arg0->unk_10;
arg0->unk_1F0 = P32(fzgx_pool_rodata_lbl_1_rodata_230) ;
arg0->unk_1F4 = P32(fzgx_pool_rodata_lbl_1_rodata_230) ;
arg0->unk_1F8 = 120;
}
if (arg0->unk_1F8) arg0->unk_1F8--;
t3 = fn_1_86254(arg0->unk_2);
lbl_8006DC6C(&loc_134);
trans90((V90 *)&loc_D4);
loc_C8 = PVV(fzgx_pool_rodata_lbl_1_rodata_200_6C) ;
lbl_8006E1C0(&loc_C8, &loc_C8);
arg0->unk_A4 = 5;
fn_1_8B10(arg0, &loc_110);
{
V90 v = PV(fzgx_pool_rodata_lbl_1_rodata_200_78) ;
v.y = loc_110.x0;
v.z = loc_110.y0;
loc_68 = v;
}
fn_80008C20(&loc_D4, &loc_C8, &t4->unk_50);
if (!(t4->unk_7C & 0x1000000))
fn_1_90E0_call_lbl_8006E0B4(-t4->unk_108, P32(fzgx_pool_rodata_lbl_1_rodata_230) , P32(fzgx_pool_rodata_lbl_1_rodata_230) );
lbl_8006E1B0(&loc_68, &loc_BC);
lbl_8006DC6C(&loc_134);
trans90((V90 *)&loc_D4);
loc_68 = PVV(fzgx_pool_rodata_lbl_1_rodata_200_84) ;
lbl_8006E1B0(&loc_68, &loc_74);
if ((f32)(u32)arg0->unk_1F8 < P32(fzgx_pool_rodata_lbl_1_rodata_200_170) ) arg0->unk_1F4 -= P32(fzgx_pool_rodata_lbl_1_rodata_200_174) ;
else arg0->unk_1F4 += P32(fzgx_pool_rodata_lbl_1_rodata_200_174) ;
arg0->unk_1F0 += arg0->unk_1F4;
arg0->unk_1F0 = ((arg0->unk_1F0) < (P32(fzgx_pool_rodata_lbl_1_rodata_230)) ? (P32(fzgx_pool_rodata_lbl_1_rodata_230)) : (arg0->unk_1F0) > (P32(fzgx_pool_rodata_lbl_1_rodata_2E0)) ? (P32(fzgx_pool_rodata_lbl_1_rodata_2E0)) : (arg0->unk_1F0)) ;
if (arg0->unk_1F8 == 0) arg0->unk_1F0 = P32(fzgx_pool_rodata_lbl_1_rodata_2E0) ;
lbl_8006D5A4(&arg0->unk_1E4, &loc_BC, &arg0->unk_10, arg0->unk_1F0);
lbl_8006D5A4(&arg0->unk_28, &loc_74, &arg0->unk_28, P32(fzgx_pool_rodata_lbl_1_rodata_200_C0) );
lbl_8006D5A4(&arg0->unk_64, &loc_C8, &arg0->unk_64, P32(fzgx_pool_rodata_lbl_1_rodata_200_C0) );
lbl_8006DD14(&t3->unk_EC, &arg0->unk_34);
arg0->unk_8 = ((f32)((arg0->unk_8) + ((P64(fzgx_pool_rodata_lbl_1_rodata_200_158)) - (arg0->unk_8)) * (P64(fzgx_pool_rodata_lbl_1_rodata_200_150)))) ;
fn_1_B4D4(arg0);
break;
}
}
bad = 0;
fn_1_A8EB0(20,5);
if (fn_80007D58(&arg0->unk_DC)) { fn_1_A8E78("NaN cam_mtx\n"); bad = 1; }
if (fn_80007D58(&arg0->unk_AC)) { fn_1_A8E78("NaN cam_old_mtx\n"); bad = 1; }
if (fn_80007CDC(&arg0->unk_10)) { fn_1_A8E78("NaN cam_pos\n"); bad = 1; }
if (fn_80007CDC(&arg0->unk_64)) { fn_1_A8E78("NaN cam_up_vec\n"); bad = 1; }
if (fn_80007CDC(&arg0->unk_28)) { fn_1_A8E78("NaN cam_intr\n"); bad = 1; }
if (bad90(arg0->unk_8)) { fn_1_A8E78("NaN cam_pers\n"); bad = 1; }
if (bad90(arg0->unk_C)) { fn_1_A8E78("NaN cam_asp\n"); bad = 1; }
if (bad) {
lbl_8006D784(&arg0->unk_DC);
lbl_8006D784(&arg0->unk_AC);
lbl_8006D784(&arg0->unk_34);
set90(&arg0->unk_10, P32(fzgx_pool_rodata_lbl_1_rodata_230) , P32(fzgx_pool_rodata_lbl_1_rodata_200_184) , P64(fzgx_pool_rodata_lbl_1_rodata_200_178) + (f32)(P32(fzgx_pool_rodata_lbl_1_rodata_200_180) *arg0->unk_2));
set90(&arg0->unk_1C, P32(fzgx_pool_rodata_lbl_1_rodata_230) , P32(fzgx_pool_rodata_lbl_1_rodata_200_184) , P64(fzgx_pool_rodata_lbl_1_rodata_200_178) + (f32)(P32(fzgx_pool_rodata_lbl_1_rodata_200_180) *arg0->unk_2));
set90(&arg0->unk_28, P32(fzgx_pool_rodata_lbl_1_rodata_230) , P32(fzgx_pool_rodata_lbl_1_rodata_2E0) , P32(fzgx_pool_rodata_lbl_1_rodata_200_180) *arg0->unk_2);
arg0->unk_64.x = P32(fzgx_pool_rodata_lbl_1_rodata_230) ;
arg0->unk_64.y = P32(fzgx_pool_rodata_lbl_1_rodata_2E0) ;
arg0->unk_64.z = P32(fzgx_pool_rodata_lbl_1_rodata_230) ;
arg0->unk_8 = 55.0f;
arg0->unk_C = fn_1_A6FE8();
}
lbl_8006DD14(&arg0->unk_DC, &arg0->unk_AC);
if (arg0->unk_A8 == 2) {
fn_1_862A8(arg0->unk_2, &loc_50);
fn_8006EDBC(&arg0->unk_10, &arg0->unk_28, &loc_A, &loc_8);
lbl_8006D1BC(loc_A, &loc_24, &loc_20);
lbl_8006D1BC(loc_8, &loc_1C, &loc_18);
lbl_8006D8E4(loc_1C, loc_18);
mathutil_mtxA_rotate_x__fzgx_offset_C(loc_24, loc_20);
fn_8006E2B0(&loc_50, &loc_5C);
{
s16 yaw = -lbl_8006D24C(loc_5C.x, loc_5C.y);
fn_8006F038(&arg0->unk_10, &arg0->unk_28, (arg0->unk_1FA + yaw));
}
} else {
fn_8006F1F0(&arg0->unk_10, &arg0->unk_64, &arg0->unk_28);
}
lbl_8006DB74(&arg0->unk_DC);
fn_8006F4E0(&loc_30);
fn_1_549F4(&arg0->unk_10, &loc_30, arg0->unk_8, arg0->unk_C, P32(fzgx_pool_rodata_lbl_1_rodata_230) , P32(fzgx_pool_rodata_lbl_1_rodata_230) );
fn_1_54DCC((u8 *)arg0 + 0x15C);
lbl_8006DB30();
}
#pragma opt_propagation reset

static u8 lbl_1_data_39D4[0x58] = {
    0x50U, 0x45U, 0x52U, 0x53U, 0x3AU, 0x25U, 0x33U, 0x2EU, 0x31U, 0x66U, 0x0AU, 0x00U, 0x79U, 0x3AU, 0x25U, 0x36U,
    0x2EU, 0x32U, 0x66U, 0x20U, 0x79U, 0x5FU, 0x6FU, 0x66U, 0x73U, 0x3AU, 0x25U, 0x36U, 0x2EU, 0x32U, 0x66U, 0x0AU,
    0x7AU, 0x3AU, 0x25U, 0x36U, 0x2EU, 0x32U, 0x66U, 0x20U, 0x7AU, 0x5FU, 0x6FU, 0x66U, 0x73U, 0x3AU, 0x25U, 0x36U,
    0x2EU, 0x32U, 0x66U, 0x0AU, 0x00U, 0x00U, 0x00U, 0x00U, 0x70U, 0x69U, 0x74U, 0x63U, 0x68U, 0x3AU, 0x25U, 0x30U,
    0x34U, 0x68U, 0x78U, 0x20U, 0x70U, 0x69U, 0x74U, 0x63U, 0x68U, 0x5FU, 0x6FU, 0x66U, 0x73U, 0x3AU, 0x25U, 0x30U,
    0x34U, 0x68U, 0x78U, 0x0AU, 0x00U, 0x00U, 0x00U, 0x00U
};

u8 lbl_1_data_3A2C[0x1A4] = {
    0x00U, 0x00U, 0x00U, 0x39U, 0x3CU, 0x23U, 0xD7U, 0x0AU, 0x00U, 0x00U, 0x00U, 0x00U, 0xC0U, 0x15U, 0xD2U, 0xF2U,
    0x3FU, 0x31U, 0xA9U, 0xFCU, 0xC0U, 0x8AU, 0xB8U, 0x52U, 0x41U, 0x08U, 0x87U, 0x2BU, 0x3FU, 0x83U, 0x12U, 0x6FU,
    0x41U, 0x68U, 0x5EU, 0x35U, 0x42U, 0x0CU, 0x00U, 0x00U, 0x00U, 0x00U, 0x00U, 0x00U, 0x00U, 0x00U, 0x00U, 0x00U,
    0xC0U, 0x60U, 0xD4U, 0xFEU, 0x40U, 0x17U, 0xBEU, 0x77U, 0xC0U, 0x68U, 0x00U, 0x00U, 0x41U, 0x32U, 0x41U, 0x89U,
    0xC0U, 0x9BU, 0x0AU, 0x3DU, 0x41U, 0x31U, 0x85U, 0x1FU, 0x42U, 0x24U, 0x00U, 0x00U, 0x00U, 0x00U, 0x00U, 0x00U,
    0x00U, 0x02U, 0x00U, 0x00U, 0x00U, 0x00U, 0x00U, 0x52U, 0x3DU, 0x30U, 0x20U, 0xC5U, 0x00U, 0x00U, 0x00U, 0x00U,
    0x3FU, 0xE5U, 0x1EU, 0xB8U, 0x3FU, 0x3BU, 0x22U, 0xD1U, 0xC0U, 0x4FU, 0x1AU, 0xA0U, 0xBCU, 0xE5U, 0x60U, 0x42U,
    0x3FU, 0x81U, 0x68U, 0x73U, 0x3DU, 0xF5U, 0xC2U, 0x8FU, 0x42U, 0x96U, 0x00U, 0x00U, 0xE8U, 0x00U, 0x00U, 0x00U,
    0x00U, 0x00U, 0x00U, 0x00U, 0x3FU, 0xFCU, 0x49U, 0xBAU, 0x40U, 0x82U, 0x66U, 0x66U, 0x40U, 0x11U, 0x89U, 0x37U,
    0xBFU, 0x8BU, 0x22U, 0xD1U, 0xBFU, 0xE2U, 0x8FU, 0x5CU, 0xBDU, 0xEFU, 0x9DU, 0xB2U, 0x42U, 0x3CU, 0x00U, 0x00U,
    0x00U, 0x00U, 0x00U, 0x00U, 0x00U, 0x03U, 0x00U, 0x00U, 0x00U, 0x00U, 0x00U, 0x2FU, 0x3CU, 0x23U, 0xD7U, 0x0AU,
    0x00U, 0x00U, 0x00U, 0x00U, 0xC0U, 0xFCU, 0x72U, 0xB0U, 0x3FU, 0xFFU, 0xBEU, 0x77U, 0xC0U, 0xDCU, 0xF5U, 0xC3U,
    0x40U, 0x46U, 0x24U, 0xDDU, 0x3FU, 0x98U, 0xF5U, 0xC3U, 0x40U, 0x0BU, 0x43U, 0x96U, 0x42U, 0xC0U, 0x00U, 0x00U,
    0xE0U, 0x00U, 0x00U, 0x00U, 0x00U, 0x00U, 0x00U, 0x00U, 0xC0U, 0x48U, 0x62U, 0x4EU, 0x3FU, 0x3FU, 0x3BU, 0x64U,
    0xC0U, 0x0EU, 0xD9U, 0x17U, 0x40U, 0x46U, 0x24U, 0xDDU, 0x3FU, 0x98U, 0xF5U, 0xC3U, 0x40U, 0x0BU, 0x43U, 0x96U,
    0x42U, 0x74U, 0x00U, 0x00U, 0x10U, 0x00U, 0x00U, 0x00U, 0x00U, 0x03U, 0x00U, 0x00U, 0x00U, 0x00U, 0x00U, 0x30U,
    0x3DU, 0xA1U, 0xCAU, 0xC1U, 0x00U, 0x00U, 0x00U, 0x00U, 0x40U, 0xD9U, 0xDBU, 0x23U, 0x41U, 0x2DU, 0x64U, 0x5AU,
    0xC1U, 0x4BU, 0xBEU, 0x77U, 0xBFU, 0xE2U, 0xB0U, 0x21U, 0x3FU, 0x52U, 0x6EU, 0x98U, 0xBCU, 0x34U, 0x39U, 0x58U,
    0x42U, 0x44U, 0x00U, 0x00U, 0xD8U, 0x00U, 0x00U, 0x00U, 0x00U, 0x00U, 0x00U, 0x00U, 0x40U, 0x06U, 0x45U, 0xA2U,
    0x3EU, 0x96U, 0x87U, 0x2BU, 0x40U, 0x6DU, 0x3FU, 0x7DU, 0x3EU, 0x9CU, 0x28U, 0xF6U, 0x3FU, 0x5AU, 0x1CU, 0xACU,
    0x3EU, 0xC4U, 0x9BU, 0xA6U, 0x42U, 0x8AU, 0x00U, 0x00U, 0x00U, 0x00U, 0x00U, 0x00U, 0x00U, 0x02U, 0x00U, 0x00U,
    0x00U, 0x00U, 0x01U, 0xF4U, 0x3CU, 0x54U, 0xFDU, 0xF4U, 0x00U, 0x00U, 0x00U, 0x00U, 0xC0U, 0x0FU, 0x8DU, 0x50U,
    0x40U, 0x2BU, 0xA5U, 0xE3U, 0x42U, 0x57U, 0xDEU, 0x35U, 0x3FU, 0xF3U, 0xB6U, 0x46U, 0xC0U, 0xA1U, 0xF3U, 0xB6U,
    0xC0U, 0x78U, 0xA3U, 0xD7U, 0x42U, 0x5CU, 0x00U, 0x00U, 0xF8U, 0x00U, 0x00U, 0x00U, 0x00U, 0x00U, 0x00U, 0x00U,
    0xC0U, 0x13U, 0xA5U, 0xE3U, 0x40U, 0xACU, 0x93U, 0x75U, 0xC2U, 0x23U, 0x59U, 0x17U, 0x3DU, 0xFBU, 0xE7U, 0x6DU,
    0x3EU, 0xCFU, 0xDFU, 0x3BU, 0x3FU, 0xBEU, 0x14U, 0x7BU, 0x42U, 0xA0U, 0x00U, 0x00U, 0x08U, 0x00U, 0x00U, 0x00U,
    0x00U, 0x02U, 0x00U, 0x00U
};
/* fzgx:end fn_1_90E0 */

/* fzgx:begin fn_1_A888 noprologue */
#include "mathutil_lc.h"
#include "types.h"
#include "rel/main_rel/globals.h"
#include "rel/main_rel/camera.h"

extern s8 fn_1_86634(s32 index);

extern s8 fn_1_86634(s32 index);

extern f32 lbl_1_rodata_2E0[32];
extern f32 lbl_8006D6FC(f32 *value, void *target);
u32 fn_1_6514(u32);

struct Vec3 {
    f32 x;
    f32 y;
    f32 z;
};

struct Self {
    u8 pad_0[0x2];
    s16 id;
    u8 pad_4[0x6C];
    f32 fov;
};

struct Ent {
    u8 pad_0[0x7C];
    u32 flags;
};

struct Pool {
    f32 a_000;
    u8 pad_004[0x2C];
    f32 a_030;
    u8 pad_034[0xCC];
    f64 b_100;
    u8 pad_108[0x10];
    f64 b_118;
    u8 pad_120[0x70];
    f32 a_190;
    f32 a_194;
    f32 a_198;
    u8 pad_19C[0x4];
    f64 b_1A0;
    f64 b_1A8;
};

struct Big {
    u8 pad_0[0x30];
};

extern void lbl_8006DAEC(void *);
extern void *fn_1_8627C(s32);
extern void fn_1_862D4(void *, struct Vec3 *);
extern void fn_1_8636C(s32, void *);
extern void *lbl_8006DC6C(void *);
extern void lbl_8006E1B0(void *, void *);
extern int fn_1_20A5C(void *, void *);
extern u32 fn_1_15578(void *, void *, void *, void *, u32, void *, u32, u32, u32, u32);
extern u32 fn_8006E250(void *, void *);
extern void lbl_8006DB30(void);

static inline void fn_1_A888_setpos(f32 z, f32 y, f32 x) {
    mathutilData->mtxA[0][3] = x;
    mathutilData->mtxA[1][3] = y;
    mathutilData->mtxA[2][3] = z;
}

static inline void fn_1_A888_setpos2(f32 a, f32 b, f32 c) {
    mathutilData->mtxA[0][3] = a;
    mathutilData->mtxA[1][3] = b;
    mathutilData->mtxA[2][3] = c;
}

#pragma opt_propagation off
typedef struct {
    f32 c_0; /* 0x000: 0.30000001192092896 */
    u8 pad_4[0x2c];
    f32 c_30; /* 0x030: 0.0 */
    u8 pad_34[0xcc];
    f64 c_100; /* 0x100: 1.2 */
    u8 pad_108[0x10];
    f64 c_118; /* 0x118: 0.08 */
    u8 pad_120[0x70];
    f32 c_190; /* 0x190: -13.0 */
    f32 c_194; /* 0x194: -20.0 */
    f32 c_198; /* 0x198: 13.0 */
    u8 pad_19c[0x4];
    f64 c_1a0; /* 0x1a0: 0.0 */
    f64 c_1a8; /* 0x1a8: 3.0 */
} CameraPoolA888;
extern const u8 lbl_1_rodata_200[];

f32 fn_1_A888(void *arg0) {
    const CameraPoolA888 *ro_pool = (const CameraPoolA888 *)&lbl_1_rodata_200;

    f32 fzgx_live_;
    f32 *fzgx_value;
    f64 fzgx_live;
    struct Self *self = (struct Self *)arg0;
    struct Ent *ent;
    s32 flag;
    u32 w3;
    u32 w2;
    struct Vec3 pos;
    struct Vec3 v3c;
    struct Vec3 v30;
    struct Vec3 v24;
    struct Vec3 v18;
    struct Big big;
    f32 res;
    f64 t;
    struct { f64 value; } val;
    f32 cur;
    f64 scaled;

    lbl_8006DAEC(self);
    ent = fn_1_8627C(self->id);
    if (ent == 0) {
        return (ro_pool->c_30);
    }
    flag = (((*(u32 *)((u8 *)ent + 0x7C)) >> 24) & 1);
    fn_1_862D4((void *)self->id, &pos);
    fn_1_8636C(self->id, &big);
    lbl_8006DC6C(&big);

    fzgx_live = pos.x;
    fzgx_live_ = pos.y;
    fn_1_A888_setpos(pos.z, fzgx_live_, fzgx_live);

    fzgx_value = &v3c.x;
    *fzgx_value = (ro_pool->c_30);
    v3c.y = ro_pool->c_190;
    v3c.z = ro_pool->c_194;
    lbl_8006E1B0(&v3c, &v30);

    v3c.y = ro_pool->c_198;
    lbl_8006E1B0(&v3c, &v24);

    w3 = fn_1_20A5C(&v24, &w2);
    fn_1_15578(&v30, &v24, &w2, &v18, 0x80000 + 1, &w3, 1, 0, 0, 0);
    lbl_8006DC6C(&big);

{
    f64 fzgx_live_2;
    fzgx_live_2 = pos.x;
    fzgx_live_ = pos.y;
    fn_1_A888_setpos2(fzgx_live_2, fzgx_live_, pos.z);
}
    fn_8006E250(&v30, &v30);

    t = (ro_pool->c_100) + v30.y;
    if (t < ro_pool->c_1a0) {
        val.value = ro_pool->c_1a0;
    } else if (t > ro_pool->c_1a8) {
        val.value = ro_pool->c_1a8;
    } else {
        val.value = t;
    }
    res = (f32)val.value / ro_pool->c_1a8;
    if (flag) {
        res = ro_pool->c_0;
    }
    cur = self->fov;
    scaled = (ro_pool->c_118) * (res - cur);
    self->fov = (cur + scaled);
    lbl_8006DB30();
    return res;
}
#pragma opt_propagation reset
/* fzgx:end fn_1_A888 */

/* fzgx:begin fn_1_AA54 noprologue */
struct fn_1_AA54_Arg0 {
    u8 pad_0[0x2];
    s16 unk_2;
};
struct fn_1_AA54_lbl_1_rodata_388 {
    f64 unk_0;
};
extern f64 lbl_1_rodata_360;
extern struct fn_1_AA54_lbl_1_rodata_388 lbl_1_rodata_388;
extern u8 fn_1_86678(int);
extern s16 camera_get_entry_field_0xa8(u32);
extern u32 fn_1_864E8(int);
extern void camera_set_entry_field_0xa8(u8, s16);
extern u16 fn_1_8664C(int);


void fn_1_AA54(void *arg0) {
    s16 temp_r28;
    u8 temp_r31;
    u8 temp_r3;

    temp_r31 = fn_1_86678((*(s16 *)((u8 *)(arg0) + 2)));
    temp_r3 = fn_1_86634((*(s16 *)((u8 *)(arg0) + 2)));
    temp_r28 = camera_get_entry_field_0xa8(temp_r3);
    if ((lbl_1_bss_960 != 9) && (fn_1_864E8((*(s16 *)((u8 *)(arg0) + 2))) & 0x10000)) {
        camera_set_entry_field_0xa8(temp_r3, 2);
        return;
    }
    if (!(fn_1_864E8((*(s16 *)((u8 *)(arg0) + 2))) & 1)) {
        if (fn_1_864E8((*(s16 *)((u8 *)(arg0) + 2))) & 0x800) {
            camera_set_entry_field_0xa8(temp_r3, 5);
            return;
        }
        if (!(fn_1_864E8((*(s16 *)((u8 *)(arg0) + 2))) & 0x80)) {
            goto block_7; /* Preserves the retail branch. */
        }
    } else {
block_7:
        if ((*(f64 *)(&lbl_1_rodata_360)) == fn_1_8664C((*(s16 *)((u8 *)(arg0) + 2)))) {
            camera_set_entry_field_0xa8(temp_r3, 3);
            return;
        }
        if (fn_1_8664C((*(s16 *)((u8 *)(arg0) + 2))) == 0x14) {
            camera_set_entry_field_0xa8(temp_r3, 0);
            return;
        }
        if ((s8) temp_r31 >= 0) {
            camera_set_entry_field_0xa8(temp_r3, temp_r28);
        }
    }
}
/* fzgx:end fn_1_AA54 */

/* fzgx:begin fn_1_ABAC noprologue */
#include "types.h"
#include "rel/main_rel/globals.h"
#include "rel/main_rel/camera.h"

extern s8 fn_1_86634(s32 index);

extern s8 fn_1_86634(s32 index);

extern f32 lbl_1_rodata_2E0[32];
extern f32 lbl_8006D6FC(f32 *value, void *target);
u32 fn_1_6514(u32);

typedef struct {
    u8 pad_0[2];
    s16 unk_2;
    u8 pad_4[0xA2];
    s16 unk_A6;
    s16 unk_A8;
} ABACObject;
typedef struct {
    u8 pad_0[0x214];
    u16 unk_214;
} ABACState;

extern ABACState *fn_1_86254(int);
extern s32 fn_1_F2F34(void);
extern s32 camera_get_entry_field_0xa4(u32);
extern u16 fn_1_86678(int);
extern void fn_1_715C(u8, s32);
extern u32 fn_1_864E8(int);
extern s32 fn_1_40BB4(void);
extern u8 lbl_1_bss_CC0[152];

typedef union {
    u16 raw;
    struct {
        u16 pad:12;
        u16 decrease:1;
        u16 increase:1;
        u16 rest:2;
    } bits;
} ABACFlags;
static inline u32 abac_increase(u16 raw) {
    return (raw >> 2) & 1;
}
static inline u32 abac_decrease(u16 raw) {
    return (raw >> 3) & 1;
}
typedef struct {
    u8 pad:6;
    u8 increase:1;
    u8 decrease:1;
} ABACByteFlags;

void fn_1_ABAC(ABACObject *arg0) {
    u16 controller;
    ABACState *state;
    s8 camera;
    struct { s32 value; } value;

    state = fn_1_86254(arg0->unk_2);
    if (fn_1_F2F34()) {
        controller = 0;
        camera = 0;
        value.value = camera_get_entry_field_0xa4(0);
    } else {
        controller = fn_1_86678(arg0->unk_2);
        camera = fn_1_86634(arg0->unk_2);
        value.value = camera_get_entry_field_0xa4((u8)camera);
    }
    if (state->unk_214 > 1) {
        fn_1_715C(camera, 5);
    } else if (1 == state->unk_214) {
        fn_1_715C(camera, arg0->unk_A6);
    } else if (fn_1_864E8(arg0->unk_2) & 0x80) {
        fn_1_715C(camera, 5);
    } else {
        arg0->unk_A6 = value.value;
        if ((s8)controller != -1 && lbl_1_bss_960 != 10 && !fn_1_40BB4()) {
            if (fn_1_F2F34()) {
                /* Volatile input flags are sampled separately for each direction. */
                if (abac_increase(*(volatile u16 *)((u8 *)&lbl_1_bss_9F8.unk_10 + (s8)controller * 0x14)) ||
                    abac_increase(((Obj_1_bss_9F8 *)((u8 *)&lbl_1_bss_9F8 + (s8)controller * 0x14))->unk_12)) {
                    value.value = value.value + 1;
                }
                /* Volatile input flags are sampled separately for each direction. */
                if (abac_decrease(*(u16 *)((u8 *)&lbl_1_bss_9F8.unk_10 + (s8)controller * 0x14)) ||
                    abac_decrease(((Obj_1_bss_9F8 *)((u8 *)&lbl_1_bss_9F8 + (s8)controller * 0x14))->unk_12)) {
                    value.value = value.value - 1;
                }
            } else {
                if (((ABACByteFlags *)&lbl_1_bss_CC0[(s8)controller])->increase) {
                    value.value = (s16)(((1) + value.value));
                }
                if (((ABACByteFlags *)&lbl_1_bss_CC0[(s8)controller])->decrease) {
                    value.value = value.value - 1;
                }
            }
            if ((s16)value.value <= 0) value.value = 0;
            if (arg0->unk_A8 == 1) {
                if ((u32)(s16)value.value >= 12) value.value = 11;
            } else {
                if ((u32)(s16)value.value >= 4) value.value = 3;
            }
            fn_1_715C(camera, value.value);
        }
    }
}
/* fzgx:end fn_1_ABAC */

/* fzgx:begin camera_get_position_delta noprologue */
typedef struct Vec3 {
    f32 x;
    f32 y;
    f32 z;
} Vec3;

extern void fn_1_862D4(u8 index, Vec3 *out);
extern void fn_1_8658C(u8 index, Vec3 *out);

// Computes the displacement between two camera positions.
void camera_get_position_delta(u32 index, Vec3 *out) {
    u8 idx = index;
    Vec3 first;
    Vec3 second;

    fn_1_862D4(idx, &first);
    fn_1_8658C(idx, &second);
    out->x = first.x - second.x;
    out->y = first.y - second.y;
    out->z = first.z - second.z;
}
/* fzgx:end camera_get_position_delta */

/* fzgx:begin camera_reset_transition noprologue */
typedef struct camera_reset_transition_Camera {
    u8 pad_00[0xA4];
    s16 unk_A4;
} camera_reset_transition_Camera;

extern void fn_1_AEB8(camera_reset_transition_Camera *);

// Resets the camera transition state before refreshing the camera.
void camera_reset_transition(camera_reset_transition_Camera *camera) {
    camera->unk_A4 = 0;
    fn_1_AEB8(camera);
}
/* fzgx:end camera_reset_transition */

/* fzgx:begin camera_update_transition */


// Advances the camera's transition state and updates its active view.
void camera_update_transition(camera_update_transition_Camera *camera) {
    if (camera->unk_78 == 0) {
        camera->unk_A4++;
        if (camera->unk_A4 >= camera_transition_count) {
            camera->unk_A4 = 0;
        }
        fn_1_AEB8( (fn_1_AEB8_Camera *)(camera_update_transition_Camera *)(camera));
    }

    fn_1_AFC8( (fn_1_AFC8_Camera *)(camera_update_transition_Camera *)(camera));

    if (camera->unk_78 != 0) {
        camera->unk_78--;
    }
}
/* fzgx:end camera_update_transition */

/* fzgx:begin fn_1_AEB8 */


typedef struct {
u32 unk_0;
f32 unk_4;
u32 unk_8;
u32 unk_C;
u32 unk_10;
u32 unk_14;
u32 unk_18;
u32 unk_1C;
u32 unk_20;
u32 unk_24;
u32 unk_28;
u32 unk_2C;
u32 unk_30;
u32 unk_34;
u32 unk_38;
u32 unk_3C;
u32 unk_40;
u32 unk_44;
u32 unk_48;
u32 unk_4C;
s16 unk_50;
u8 pad_52[0x152];
} Obj_1_data_3A2C_fn_1_AEB8;


typedef struct {
u32 unk_0;
Vec position;
Vec target;
f32 value;
s16 count;
s16 pad;
} TransitionConfig;
typedef struct {
s32 mode;
f32 unk_4;
TransitionConfig config;
u8 pad_2C[0x28];
} TransitionPreset;
void fn_1_AEB8(fn_1_AEB8_Camera *camera) {
TransitionPreset *preset;
TransitionConfig config;
Vec position;
s32 index = camera->unk_A4;
if (lbl_1_bss_960 == 14) {
camera_transition_count = 14;
preset = &((TransitionPreset *)lbl_1_data_3BD0)[index];
} else {
camera_transition_count = 5;
preset = &((TransitionPreset *)&lbl_1_data_3A2C)[index];
}
config = preset->config;
position = config.position;
camera->unk_1E4 = position;
camera->unk_1F0 = 0.0f;
camera->unk_1F4 = 0.0f;
camera->unk_78 = preset->mode;
camera->unk_8C = config.position;
camera->unk_98 = config.target;
camera->unk_1FA = config.count;
camera->unk_8 = config.value;
camera->unk_1FA = config.count;
}
/* fzgx:end fn_1_AEB8 */

/* fzgx:begin fn_1_AFC8 noprologue */
#include "types.h"
#include "rel/main_rel/globals.h"
#include "rel/main_rel/camera.h"

extern s8 fn_1_86634(s32 index);

extern s8 fn_1_86634(s32 index);

extern f32 lbl_1_rodata_2E0[32];
extern f32 lbl_8006D6FC(f32 *value, void *target);
u32 fn_1_6514(u32);

#pragma section code_type ".fzgxpool"
__declspec(section ".fzgxpool") static void fzgx_pool_prime1(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 0.30000001192092896f;
    s = 1.100000023841858f;
}
static const u32 fzgx_pool_table2[9] = {0x00000000, 0x3F800000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0xBF800000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep2(void) { const u32 *volatile cp; cp = fzgx_pool_table2; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime3(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 55.0f;
    s = 0.0f;
    s = -10.0f;
    d = 0.5;
    d = 4503601774854144.0;
}
static const u32 fzgx_pool_table4[18] = {0x00000000, 0x3F800000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x3F800000, 0x00000000, 0x00000000, 0x3F800000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x40400000, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep4(void) { const u32 *volatile cp; cp = fzgx_pool_table4; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime5(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 1500.0f;
    s = 53.0f;
    s = 3.0f;
    s = 0.009999999776482582f;
    d = 0.05;
    s = 3.9999998989515007e-05f;
    s = 80.0f;
    s = 108.0f;
    s = 1.350000023841858f;
    s = 90.0f;
    s = 1.2000000476837158f;
    s = 0.20000000298023224f;
}
static const u32 fzgx_pool_table6[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep6(void) { const u32 *volatile cp; cp = fzgx_pool_table6; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime7(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 0.01;
    s = 0.05000000074505806f;
    s = 0.10000000149011612f;
    d = 0.15;
    s = 1.0f;
    s = 182.04444885253906f;
    s = 0.4000000059604645f;
}
static const u32 fzgx_pool_table8[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep8(void) { const u32 *volatile cp; cp = fzgx_pool_table8; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime9(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 0.12;
    s = 5000.0f;
}
static const u32 fzgx_pool_table10[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep10(void) { const u32 *volatile cp; cp = fzgx_pool_table10; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime11(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 1.2;
    d = 1.4;
    d = 1.7;
    d = 0.08;
    d = 0.2;
    d = 0.04;
    s = 0.5f;
}
static const u32 fzgx_pool_table12[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep12(void) { const u32 *volatile cp; cp = fzgx_pool_table12; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime13(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 0.1;
    s = 1.5f;
    s = 2.299999952316284f;
    s = 0.699999988079071f;
}
static const u32 fzgx_pool_table14[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep14(void) { const u32 *volatile cp; cp = fzgx_pool_table14; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime15(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 0.3;
    d = 55.0;
    d = 150.0;
    s = 65.0f;
    s = 0.00023668639187235385f;
    s = 60.0f;
    s = 0.00027777778450399637f;
    d = 7.19;
    s = 5.0f;
    s = 2.940000057220459f;
    d = 4503599627370496.0;
    s = -13.0f;
    s = -20.0f;
    s = 13.0f;
}
static const u32 fzgx_pool_table16[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep16(void) { const u32 *volatile cp; cp = fzgx_pool_table16; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime17(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 0.0;
    d = 3.0;
    s = 1.159999966621399f;
    s = 89128.9609375f;
    s = 64.0f;
}
static const u32 fzgx_pool_table18[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep18(void) { const u32 *volatile cp; cp = fzgx_pool_table18; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime19(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 3.513671875f;
}
static const u32 fzgx_pool_table20[7] = {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep20(void) { const u32 *volatile cp; cp = fzgx_pool_table20; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime21(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 1.0;
    d = 0.75;
    d = 0.8;
    d = 0.72;
}
#pragma section code_type ".text"

#include "dolphin/hw_regs.h"

/* the TU's .rodata pool from lbl_1_rodata_200 in retail bytes, with this function's literals primed at their
 * retail offsets, so MWCC addresses them off one pool base */

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

/* one 0x54-byte entry of the transition tables lbl_1_data_3A2C / lbl_1_data_3BD0 */
typedef struct {
    s32 unk_0;
    f32 unk_4;
    CamKey unk_8;
    CamKey unk_2C;
    s16 unk_50;
} CamPreset;

/* one 0x1FC-byte game_camera_entries record (camera.h) */
typedef struct {
    u8 pad_0[0x2];
    s16 unk_2;
    u8 pad_4[0x4];
    f32 unk_8;
    u8 pad_C[0x4];
    CamVec unk_10;
    u8 pad_1C[0xC];
    CamVec unk_28;
    f32 unk_34[3][4];
    u8 pad_64[0x14];
    s16 unk_78;
    u8 pad_7A[0x12];
    CamVec unk_8C;
    CamVec unk_98;
    s16 unk_A4;
    u8 pad_A6[0x14A];
    f32 unk_1F0;
    f32 unk_1F4;
    u8 pad_1F8[0x2];
    s16 unk_1FA;
} Camera;

extern void fn_1_862D4(s16 index, CamVec *out);
extern void fn_1_863E4(s16 index, f32 (*out)[4]);
extern void fn_80008DB4(f32 (*a)[4], f32 (*b)[4], f32 (*out)[4], f32 t);
extern void lbl_8006DC6C(f32 (*m)[4]);
extern void lbl_8006E1B0(CamVec *in, CamVec *out);
extern void lbl_8006D5A4(CamVec *a, CamVec *b, CamVec *out, f32 t);


/* While cam->unk_78 (counted down by camera_update_transition) is positive, blends the camera toward the current
 * transition preset (lbl_1_data_3BD0 entry cam->unk_A4 in game mode 14, else lbl_1_data_3A2C): mode 0 from unk_8
 * to unk_2C by the elapsed fraction, mode 3 by the eased value unk_1F0 (step unk_1F4), mode 2 by the fixed
 * fraction unk_4 from where the camera is. Then it passes unk_34, car cam->unk_2's orientation (fn_1_863E4) and
 * 0.1 to fn_80008DB4, loads unk_34 into mtxA with the car's position (fn_1_862D4) as translation, and passes
 * unk_8C/unk_10 and unk_98/unk_28 to lbl_8006E1B0. */
void fn_1_AFC8(Camera *cam) {
    CamPreset *preset;
    CamKey from;
    CamKey to;
    CamVec pos;
    f32 mtx[3][4];
    f32 t;
    u32 n;
    f32 z;
    f32 y;
    f32 x;
    s32 index;
    f32 step;

    index = cam->unk_A4;
    if (lbl_1_bss_960 == 14) {
        camera_transition_count = 14;
        preset = &((CamPreset *)lbl_1_data_3BD0)[index];
    } else {
        camera_transition_count = 5;
        preset = &((CamPreset *)&lbl_1_data_3A2C)[index];
    }
    from = preset->unk_8;
    to = preset->unk_2C;
    if (cam->unk_78 > 0) {
        switch (preset->unk_50) {
        case 0:
            t = 1.0 - (f32)cam->unk_78 / preset->unk_0;
            lbl_8006D5A4(&from.pos, &to.pos, &cam->unk_8C, t);
            lbl_8006D5A4(&from.at, &to.at, &cam->unk_98, t);
            cam->unk_8 = from.unk_1C + (f32)(t * (to.unk_1C - from.unk_1C));
            cam->unk_1FA = from.unk_20 + (s16)(t * (to.unk_20 - from.unk_20));
            break;
        case 3:
            n = preset->unk_0;
            step = 1.0f / (n * n / 4);
            if ((u32)cam->unk_78 < n / 2.0f) {
                cam->unk_1F4 -= step;
            } else {
                cam->unk_1F4 += step;
            }
            cam->unk_1F0 += cam->unk_1F4;
            cam->unk_1F0 = ((cam->unk_1F0 < (0.0f)) ? (0.0f) : ((cam->unk_1F0 > (1.0f)) ? (1.0f) : cam->unk_1F0));
            t = cam->unk_1F0;
            lbl_8006D5A4(&from.pos, &to.pos, &cam->unk_8C, t);
            lbl_8006D5A4(&from.at, &to.at, &cam->unk_98, t);
            cam->unk_8 = from.unk_1C + (f32)(t * (to.unk_1C - from.unk_1C));
            cam->unk_1FA = from.unk_20 + (s16)(t * (to.unk_20 - from.unk_20));
            break;
        case 2:
            lbl_8006D5A4(&cam->unk_8C, &to.pos, &cam->unk_8C, preset->unk_4);
            lbl_8006D5A4(&cam->unk_98, &to.at, &cam->unk_98, preset->unk_4);
            cam->unk_8 += (f32)(preset->unk_4 * (to.unk_1C - cam->unk_8));
            cam->unk_1FA += (s32)(preset->unk_4 * (to.unk_20 - cam->unk_1FA));
            break;
        }
        fn_1_862D4(cam->unk_2, &pos);
        fn_1_863E4(cam->unk_2, mtx);
        fn_80008DB4(cam->unk_34, mtx, cam->unk_34, 0.1f);
        lbl_8006DC6C(cam->unk_34);
        /* mtxA's translation column in the locked cache */
        x = *(volatile f32 *)&pos.x;  /* fzgx-allow: S2 volatile view keeps the verified load order */
        y = pos.y;
        z = pos.z;
        *(f32 *)(LC_BASE + 0xC) = x;
        *(f32 *)(LC_BASE + 0x1C) = y;
        *(f32 *)(LC_BASE + 0x2C) = z;
        lbl_8006E1B0(&cam->unk_8C, &cam->unk_10);
        lbl_8006E1B0(&cam->unk_98, &cam->unk_28);
    }
}
/* fzgx:end fn_1_AFC8 */

/* fzgx:begin camera_get_target_orientation noprologue */
typedef struct Transform {
    u8 pad_08[0x8];
    f32 unk_08;
    u8 pad_0c[0xc];
    f32 unk_18;
    u8 pad_1c[0xc];
    f32 unk_28;
    u8 pad_2c[0x24];
    u8 unk_50[0x2c];
    u32 unk_7C;
} Transform;

typedef struct CameraStateLocal {
    u8 pad_d4[0xd4];
    f32 unk_D4;
    f32 unk_D8;
    f32 unk_DC;
} CameraStateLocal;

typedef struct camera_get_target_orientation_CameraObject {
    u8 pad_49c[0x49c];
    Transform *unk_49C;
} camera_get_target_orientation_CameraObject;

extern Transform *lbl_801A6D00;
extern CameraStateLocal *lbl_801A66CC;

// Updates the camera orientation from the active target transform.
f32 camera_get_target_orientation(camera_get_target_orientation_CameraObject *camera) {
    Transform *target = camera->unk_49C;

    if (target == 0) {
        return lbl_1_rodata_2E0[0];
    }
    if ((target->unk_7C & 0x01800000) == 0) {
        return lbl_1_rodata_2E0[0];
    }

    lbl_801A66CC->unk_D4 = -lbl_801A6D00->unk_08;
    lbl_801A66CC->unk_D8 = -lbl_801A6D00->unk_18;
    lbl_801A66CC->unk_DC = -lbl_801A6D00->unk_28;
    return lbl_8006D6FC(&lbl_801A66CC->unk_D4, &target->unk_50);
}
/* fzgx:end camera_get_target_orientation */

/* fzgx:begin fn_1_B4D4 noprologue */
#include "psvec.h"


typedef struct LiveCameraVec {
    f32 values[3];
} LiveCameraVec;

typedef struct LiveCamera_fn_1_B4D4 {
    u8 pad_00[0x10];
    LiveCameraVec position;
    u8 pad_1C[0xC];
    LiveCameraVec position2;
    u8 pad_34[0x74];
    s16 unk_A8;
    u8 pad_AA[0x62];
    s32 unk_10C;
    s32 timer;
    LiveCameraVec saved;
    LiveCameraVec offset;
    LiveCameraVec velocity;
    LiveCameraVec saved2;
    LiveCameraVec offset2;
    LiveCameraVec velocity2;
} LiveCamera_fn_1_B4D4;

typedef struct LiveCameraPool {
    u8 pad_0[0x1E8];
    f64 damping;
    f64 scale;
    f64 scale2;
} LiveCameraPool;

extern const LiveCameraPool lbl_1_rodata_200;
extern u32 lbl_1_bss_F5C;
extern void fn_1_8840(void);

void fn_1_B4D4(LiveCamera_fn_1_B4D4 *camera) {
    const LiveCameraPool *pool = &lbl_1_rodata_200;
    f64 damping;
    f64 scale;
    f64 scale2;
    f64 product;
    u32 i;
    f64 product_2;
    u32 tmp_ra3;

    if (!camera->unk_10C) {
        camera->saved = camera->position;
        camera->saved2 = camera->position2;
    } else {
        if ((lbl_1_bss_F5C & 0x50000000) == 0) {
            damping = (0.75);
            scale = (0.80000000000000004);
            scale2 = (0.71999999999999997);
            for (i = 0; i < 3; i++) {
                product = damping * (*((camera->offset.values) + i));
                camera->velocity.values[i] =
                    ((*((camera->velocity.values) + i)) - product);
            }
            for (i = 0; i < 3; i++) {
                camera->velocity.values[i] =
                    ((*((camera->velocity.values) + i)) * scale);
            }
            for (i = 0; i < 3; i++) {
                camera->offset.values[i] =
                    (*((camera->offset.values) + i)) + (*((camera->velocity.values) + i));
            }
            {
    u32 fzgx_loop_i_7616;
for (fzgx_loop_i_7616 = 0; fzgx_loop_i_7616 < 3; fzgx_loop_i_7616++) {
                product_2 = scale2 * (*((camera->offset2.values) + fzgx_loop_i_7616));
                camera->velocity2.values[fzgx_loop_i_7616] =
                    ((*((camera->velocity2.values) + fzgx_loop_i_7616)) - product_2);
            }
    i = fzgx_loop_i_7616;
}
            for (i = 0; i < 3; i++) {
                camera->velocity2.values[i] =
                    ((*((camera->velocity2.values) + i)) * damping);
            }
            for (i = 0; i < 3; i++) {
                camera->offset2.values[i] =
                    (*((camera->offset2.values) + i)) + (*((camera->velocity2.values) + i));
            }
        }
        psvec_add(&camera->saved.values[0], &camera->offset.values[0],
                  &camera->position.values[0]);
        if (!camera->unk_A8) {
            psvec_add(&camera->saved2.values[0], &camera->offset2.values[0],
                      &camera->position2.values[0]);
        }
        if ((lbl_1_bss_F5C & 0x50000000) == 0 && camera->timer > 0) {
            camera->timer--;
            tmp_ra3 = camera->timer;
            if ((s32)tmp_ra3 == 0) {
                fn_1_8840();
            }
        }
    }
}
/* fzgx:end fn_1_B4D4 */
