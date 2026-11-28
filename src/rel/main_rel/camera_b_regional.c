/* Previously matched Japan/PAL units of camera_b.c, retained until that TU matches those releases as one unit. */
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
