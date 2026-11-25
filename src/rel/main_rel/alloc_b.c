#include "types.h"
#include "rel/main_rel/globals.h"
#include "rel/main_rel/alloc.h"
#define LiveCamera _cam_LiveCamera
#define live_camera _cam_live_camera
#include "rel/main_rel/camera.h"
#undef LiveCamera
#undef live_camera

extern char lbl_1_data_2C9C[20];
extern void OSPanic(const char *message, int line, const char *file, ...);
extern void fn_80009AA8(u32 value, u32 count, const char *file, int line);
extern u32 fn_1_435C(u32 value);
extern void fn_1_426C(s16 value);
extern u32 lbl_1_bss_F5C;
extern u32 lbl_1_bss_F60[2];
extern s32 memcmp(Obj_1_bss_7AC20 *, u32 *, u32);
extern u32 lbl_801A6410;
extern Obj_1_bss_F68_Target *fn_1_45D0(u32, u32, u8 *, u32);
extern void fn_800793D4(Obj_1_bss_F68_Target *, u32, u32);
extern void fn_1_6394(void);
extern void fn_1_63D4(void);
extern void fn_1_DF74(void);
extern u8 lbl_1_bss_F76;
extern void fn_1_DA6C(LiveCamera *);
extern void fn_1_DE14(LiveCamera *);
extern void fn_1_E174(void);
extern void fn_1_F3D0(LiveCamera *);
s32 fn_1_3FC28(void);
void fn_1_3EF14(u32 *);
extern void fn_8006CE1C(f32);
extern void fn_1_4BB0(void);
extern f32 fn_1_4D14(Obj_1_data_2CDC *);
extern void fn_1_4CD8(void);
extern void fn_1_4E60(Obj_1_data_2CDC *);
extern void fn_1_4DE0(Obj_1_data_2CDC *, u32);
extern void fn_1_4010(s32, void (*)(Obj_1_data_2CDC *, u32));
extern void fn_8006CDFC(u32 *);
extern void fn_1_4060(void);

/* fzgx:begin fn_1_5948 */
struct Sig_fn_1_549F4_Sig_fn_8006F1F0_fn_8006F1F0_Arg0 { f32 unk_0; f32 unk_4; f32 unk_8; };
struct Sig_fn_1_549F4_fn_1_549F4_Arg1 { u32 unk_0; u16 unk_4; };
extern CameraState *camera_get_state_object(void);
extern u32 camera_update_state(CameraState *);
extern f32 fn_1_A6FE8(void);
extern void fn_1_549F4(struct Sig_fn_1_549F4_Sig_fn_8006F1F0_fn_8006F1F0_Arg0 *, struct Sig_fn_1_549F4_fn_1_549F4_Arg1 *, f32, f32, f32, f32);
extern void fn_8006F4E0(s16 *);
extern u32 fn_1_A7024(f32, f32, f32, f32);
extern u16 fn_1_A5D88(void);
extern u16 fn_1_A5DB0(void);
extern s32 fn_1_A5DC4(void);
extern void fn_1_54E00(void *);
extern void fn_1_727C(void);
extern void lbl_8006DD14(void *, void *);
extern void *lbl_8006D784(void *);
extern void OSReport(const char *, ...);
extern void OSPanic(const char *, int, const char *, ...);
extern u32 fn_80038EEC(f32, f32, f32, f32, f32, f32);
extern u32 fn_80074188(u32, u32, u32, u32);
extern s32 fn_80007CDC(f32 *);
extern s32 fn_80007D58(f32 *);
extern void *lbl_801A66CC;
extern void *lbl_801A6D00;
extern u8 lbl_1_data_32A8[12];
extern const f32 lbl_1_rodata_188;
extern const f32 lbl_1_rodata_18C;
extern const f32 lbl_1_rodata_190;
extern const f32 lbl_1_rodata_194;
extern const f32 lbl_1_rodata_198;
extern const f32 lbl_1_rodata_19C;
extern const f32 lbl_1_rodata_1A0;
extern const f32 lbl_1_rodata_1A4;
extern const f32 lbl_1_rodata_1A8;
extern const f32 lbl_1_rodata_1AC;
extern const f64 lbl_1_rodata_1B0;
extern const f32 lbl_1_rodata_1B8;
extern const f64 lbl_1_rodata_1C0;
extern const f32 lbl_1_rodata_1C8;
extern const f64 lbl_1_rodata_1D0;
extern const f32 lbl_1_rodata_1D8;

/* camera mode byte; retail reads it as a signed char */
#define CAM_MODE (*(s8 *)&(*p_lbl_1_bss_F68)->unk_48)

typedef struct {
    u8 pad_0[0x58];
    struct { f32 x; f32 y; } vp[4];
} CamViewport;

#pragma opt_propagation off
void fn_1_5948(u32 arg0) {
    f32 v6;
    f32 v7;
    Obj_1_bss_F68_Target **p_lbl_1_bss_F68;
    u8 *p_lbl_1_data_32A8;
    f32 lab_t1;
    f32 v9, v10;
    f32 v14, v11, v12, v13, v15, v16;
    f32 v40, v38;
    f32 *v39, *v41, *v42;
    void *v43;
    f32 v47;
    CameraState *v4;
    u8 *v1;
    f32 loc_C, loc_8;
    struct Sig_fn_1_549F4_fn_1_549F4_Arg1 loc_10;

    p_lbl_1_bss_F68 = &lbl_1_bss_F68;
    p_lbl_1_data_32A8 = lbl_1_data_32A8;
    if (CAM_MODE == 11) return;
    (*p_lbl_1_bss_F68)->unk_4A = arg0;
    if (((*p_lbl_1_bss_F68)->unk_0 & 0x80000000) != 0) {
        lbl_8006DD14((u8 *)lbl_801A6D00 + 0x30, lbl_801A66CC);
        v4 = camera_get_state_object();
        camera_update_state(v4);
        fn_8006F4E0((s16 *)&loc_10);
        {
            fn_1_549F4((void *)&((f32 *)v4)[1], &loc_10, *(f32 *)((u8 *)v4 + 0x1C), (v6 = fn_1_A6FE8()), 0.0f, 0.0f);
        }
        fn_1_A7024(*(f32 *)((u8 *)v4 + 0x1C), (v7 = fn_1_A6FE8()), lbl_1_rodata_18C, lbl_1_rodata_190);
        return;
    }
    v9 = fn_1_A5D88();
    v10 = fn_1_A5DB0();
    switch (arg0) {
    case 0:
        switch (CAM_MODE) {
        case 0: case 9: break;
        case 1: case 3:
            v11 = lbl_1_rodata_188;
            v12 = lbl_1_rodata_194;
            v13 = lbl_1_rodata_198;
            v14 = v11;
            (*p_lbl_1_bss_F68)->unk_58 = v12;
            v15 = v11;
            (*p_lbl_1_bss_F68)->unk_5C = v13;
            break;
        case 2:
            v11 = lbl_1_rodata_188;
            v12 = lbl_1_rodata_198;
            v13 = lbl_1_rodata_194;
            v14 = v11;
            v15 = v11;
            break;
        case 4:
            v14 = lbl_1_rodata_188;
            v11 = lbl_1_rodata_198;
            v13 = v11;
            v15 = v14;
            v12 = v11;
            break;
        case 5: case 6: case 7: case 8:
            v11 = lbl_1_rodata_188;
            v13 = lbl_1_rodata_198;
            v14 = v11;
            v12 = v13;
            v15 = v11;
            break;
        case 10:
            v11 = lbl_1_rodata_188;
            v13 = lbl_1_rodata_194;
            v12 = v13;
            v15 = lbl_1_rodata_19C;
            v14 = v11;
            break;
        default:
            OSReport((char *)p_lbl_1_data_32A8 + 0x1A4, arg0, CAM_MODE);
            OSPanic((char *)p_lbl_1_data_32A8 + 0x70, 0x252, (char *)p_lbl_1_data_32A8 + 0x1B8);
            break;
        }
        v16 = lbl_1_rodata_194;
        break;
    case 1:
        switch (CAM_MODE) {
        case 1:
            v14 = lbl_1_rodata_188;
            v11 = lbl_1_rodata_198;
            v12 = lbl_1_rodata_194;
            v13 = v11;
            v16 = v12;
            break;
        case 2:
            v14 = lbl_1_rodata_198;
            v11 = lbl_1_rodata_188;
            v13 = lbl_1_rodata_194;
            v16 = v13;
            v12 = v14;
            break;
        case 3:
            v14 = lbl_1_rodata_188;
            v11 = lbl_1_rodata_198;
            v16 = lbl_1_rodata_194;
            v13 = v11;
            v12 = v11;
            break;
        case 4:
            v11 = lbl_1_rodata_188;
            v12 = lbl_1_rodata_194;
            v16 = v12;
            v13 = lbl_1_rodata_198;
            v14 = v11;
            break;
        case 5: case 6: case 7: case 8:
            v14 = lbl_1_rodata_198;
            v11 = lbl_1_rodata_188;
            v16 = lbl_1_rodata_194;
            v13 = v14;
            v12 = v14;
            break;
        case 10:
            v11 = lbl_1_rodata_1A0;
            v13 = lbl_1_rodata_1A4;
            v12 = v13;
            v16 = lbl_1_rodata_19C;
            v14 = v11;
            break;
        default:
            OSReport((char *)p_lbl_1_data_32A8 + 0x1A4, arg0, CAM_MODE);
            OSPanic((char *)p_lbl_1_data_32A8 + 0x70, 0x28E, (char *)p_lbl_1_data_32A8 + 0x1B8);
            break;
        }
        v15 = lbl_1_rodata_188;
        break;
    case 2:
        switch (CAM_MODE) {
        case 3: case 4:
            v11 = lbl_1_rodata_198;
            v14 = v11;
            v13 = v11;
            v12 = v11;
            break;
        case 5:
            v14 = lbl_1_rodata_188;
            v11 = lbl_1_rodata_198;
            v12 = lbl_1_rodata_194;
            v13 = v11;
            break;
        case 6: case 7: case 8:
            v14 = lbl_1_rodata_188;
            v11 = lbl_1_rodata_198;
            v13 = v11;
            v12 = v11;
            break;
        default:
            OSReport((char *)p_lbl_1_data_32A8 + 0x1A4, arg0, CAM_MODE);
            OSPanic((char *)p_lbl_1_data_32A8 + 0x70, 0x2B1, (char *)p_lbl_1_data_32A8 + 0x1DC);
            break;
        }
        v15 = lbl_1_rodata_188;
        v16 = lbl_1_rodata_194;
        break;
    case 3:
        switch (CAM_MODE) {
        case 6: case 8:
            v11 = lbl_1_rodata_198;
            v14 = v11;
            v13 = v11;
            v12 = v11;
            break;
        default:
            OSReport((char *)p_lbl_1_data_32A8 + 0x1A4, arg0, CAM_MODE);
            OSPanic((char *)p_lbl_1_data_32A8 + 0x70, 0x2C6, (char *)p_lbl_1_data_32A8 + 0x200);
            break;
        }
        v15 = lbl_1_rodata_188;
        v16 = lbl_1_rodata_194;
        break;
    }
    if (CAM_MODE == 0 || CAM_MODE == 9) {
        Obj_1_bss_F68_Target *viewport;
        viewport = (Obj_1_bss_F68_Target *)((u8 *)*p_lbl_1_bss_F68 + arg0 * 8);
        viewport->unk_58 = lbl_1_rodata_194;
        viewport = (Obj_1_bss_F68_Target *)((u8 *)*p_lbl_1_bss_F68 + arg0 * 8);
        viewport->unk_5C = lbl_1_rodata_194;
        lab_t1 = lbl_1_rodata_188;
        fn_80038EEC(lbl_1_rodata_188, lab_t1, v9, v10, lbl_1_rodata_188, lbl_1_rodata_194);
        fn_80074188(0, 0, v9, v10);
    } else {
        Obj_1_bss_F68_Target *viewport;
        u32 viewportOffset;
        viewportOffset = arg0 * 8;
        v14 *= v9;
        v11 *= v10;
        viewport = (Obj_1_bss_F68_Target *)((u8 *)*p_lbl_1_bss_F68 + viewportOffset);
        viewport->unk_58 = v12;
        v12 *= v9;
        viewport = (Obj_1_bss_F68_Target *)((u8 *)*p_lbl_1_bss_F68 + viewportOffset);
        viewport->unk_5C = v13;
        v13 *= v10;
        lab_t1 = v11;
        fn_80038EEC(v14, lab_t1, v12, v13, v15, v16);
        fn_80074188(v14, v11, v12, v13);
    }
    if ((arg0 == 0 && (CAM_MODE == 9 || (u8)(CAM_MODE - 9) <= 1)) ||
        (arg0 == 3 && CAM_MODE == 6)) {
        v1 = (u8 *)p_lbl_1_bss_F68[2];
        v38 = *(f32 *)(v1 + 0x58);
        v39 = (f32 *)(v1 + 0xFC);
        v40 = *(f32 *)(v1 + 0x60);
        v41 = (f32 *)(v1 + 0x12C);
        v42 = (f32 *)(v1 + 0x1C);
        v43 = v1 + 0x15C;
    } else if (arg0 == 1 && CAM_MODE == 10) {
        v1 = (u8 *)p_lbl_1_bss_F68[1];
        v38 = *(f32 *)(v1 + 8);
        v39 = (f32 *)(v1 + 0xAC);
        v40 = *(f32 *)(v1 + 0xC);
        v41 = (f32 *)(v1 + 0xDC);
        v42 = (f32 *)(v1 + 0x10);
        v43 = v1 + 0x15C;
    } else {
        v1 = (u8 *)p_lbl_1_bss_F68[1] + arg0 * 0x1FC;
        v38 = *(f32 *)(v1 + 8);
        v39 = (f32 *)(v1 + 0xAC);
        v40 = *(f32 *)(v1 + 0xC);
        v41 = (f32 *)(v1 + 0xDC);
        v42 = (f32 *)(v1 + 0x10);
        v43 = v1 + 0x15C;
    }
    if (fn_80007CDC(v42) != 0 || fn_80007D58(v41) != 0 ||
        (loc_C = v38, (*(u32 *)&loc_C & 0x7F800000) == 0x7F800000) ||
        (loc_8 = v40, (*(u32 *)&loc_8 & 0x7F800000) == 0x7F800000)) {
        OSReport((char *)p_lbl_1_data_32A8 + 0x224);
        OSReport((char *)p_lbl_1_data_32A8 + 0x240, CAM_MODE);
        OSReport((char *)p_lbl_1_data_32A8 + 0x250, arg0);
        OSReport((char *)p_lbl_1_data_32A8 + 0x260, v42[0]);
        OSReport((char *)p_lbl_1_data_32A8 + 0x270, v42[1]);
        OSReport((char *)p_lbl_1_data_32A8 + 0x280, v42[2]);
        OSReport((char *)p_lbl_1_data_32A8 + 0x290, v38);
        OSReport((char *)p_lbl_1_data_32A8 + 0x2A0, v40);
        v42[0] = lbl_1_rodata_188;
        v42[1] = lbl_1_rodata_188;
        v42[2] = lbl_1_rodata_188;
        lbl_8006D784(v41);
        v38 = lbl_1_rodata_1A8;
        v40 = fn_1_A6FE8();
    }
    lbl_8006DD14(v39, lbl_801A66CC);
    lbl_8006DD14(v41, (u8 *)lbl_801A6D00 + 0x30);
    fn_1_54E00(v43);
    v47 = lbl_1_rodata_18C;
    if (v38 < lbl_1_rodata_1AC) v47 = (v47 * lbl_1_rodata_1B0);
    else if (v38 < lbl_1_rodata_1B8) v47 = (v47 * lbl_1_rodata_1C0);
    else if (v38 < lbl_1_rodata_1C8) v47 = (v47 * lbl_1_rodata_1D0);
    if ((s8)fn_1_A5DC4() != 0) {
        switch (*((u8 *)p_lbl_1_bss_F68 + 0xD)) {
        case 0: break;
        case 1: v38 *= lbl_1_rodata_1D8; break;
        case 2: v38 *= lbl_1_rodata_1A0; break;
        }
    }
    fn_1_A7024(v38, v40, v47, lbl_1_rodata_190);
    fn_1_727C();
}
#pragma opt_propagation reset
/* fzgx:end fn_1_5948 */

/* fzgx:begin fn_1_627C */
extern char lbl_1_data_2C9C[20];
extern void OSPanic(const char *message, int line, const char *file, ...);
extern void fn_80009AA8(u32 value, u32 count, const char *file, int line);
extern u32 fn_1_435C(u32 value);
extern void fn_1_426C(s16 value);
extern u32 lbl_1_bss_F5C;
extern u32 lbl_1_bss_F60[2];
extern s32 memcmp(Obj_1_bss_7AC20 *, u32 *, u32);
extern u32 lbl_801A6410;
extern Obj_1_bss_F68_Target *fn_1_45D0(u32, u32, u8 *, u32);
extern void fn_800793D4(Obj_1_bss_F68_Target *, u32, u32);
extern void fn_1_6394(void);
extern void fn_1_63D4(void);
extern void fn_1_DF74(void);
extern u8 lbl_1_bss_F76;
extern void fn_1_DA6C(LiveCamera *);
extern void fn_1_DE14(LiveCamera *);
extern void fn_1_E174(void);
extern void fn_1_F3D0(LiveCamera *);
s32 fn_1_3FC28(void);
void fn_1_3EF14(u32 *);
extern void fn_8006CE1C(f32);
extern void fn_1_4BB0(void);
extern f32 fn_1_4D14(Obj_1_data_2CDC *);
extern void fn_1_4CD8(void);
extern void fn_1_4E60(Obj_1_data_2CDC *);
extern void fn_1_4DE0(Obj_1_data_2CDC *, u32);
extern void fn_1_4010(s32, void (*)(Obj_1_data_2CDC *, u32));
extern void fn_8006CDFC(u32 *);
extern void fn_1_4060(void);

extern u16 fn_1_A5D88(void);
extern u16 fn_1_A5DB0(void);
extern const f64 lbl_1_rodata_1E0;
extern const f32 lbl_1_rodata_188;
extern const f32 lbl_1_rodata_194;
extern u32 fn_80038EEC(f32, f32, f32, f32, f32, f32);
extern u32 fn_80074188(u32, u32, u32, u32);

#pragma opt_common_subs off
void fn_1_627C(void) {
    f32 width;
    f32 height;
    s8 signedMode;
    Obj_1_bss_F68_Target *obj = lbl_1_bss_F68;
    u8 mode = obj->unk_48;
    signedMode = mode;
    if (signedMode == 11 || (obj->unk_0 & 0x80000000) || (s8)mode == 0 || signedMode == 9) {
        return;
    }
    width = fn_1_A5D88();
    height = fn_1_A5DB0();
    fn_80038EEC(lbl_1_rodata_188, lbl_1_rodata_188, width, height, lbl_1_rodata_188, lbl_1_rodata_194);
    fn_80074188(0, 0, width, height);
}
/* fzgx:end fn_1_627C */

/* fzgx:begin fn_1_6394 */
void fn_1_6394(void) {
    fn_1_DA6C(live_camera);
    fn_1_DE14(live_camera);
    fn_1_E174();
}
/* fzgx:end fn_1_6394 */

/* fzgx:begin fn_1_63D4 */
 // Update the camera using the active camera object.
void fn_1_63D4(void) {
    fn_1_F3D0(live_camera);
}
/* fzgx:end fn_1_63D4 */
