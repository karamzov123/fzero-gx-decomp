/* Non-matching: best partial attempt (90.71% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"

typedef struct {
    u32 v0;
    u32 v1;
    u32 v2;
    u32 v3;
    u32 v4;
    u32 v5;
    u32 v6;
    u32 v7;
    u32 v8;
} CamState;

typedef struct {
    u32 unk_0;
    u32 mode;
    s32 counter;
    f32 value;
} CamParams;

typedef struct {
    u8 pad_00[4];
    u8 unk_4;
    u8 unk_5;
    u8 pad_06[2];
    CamState cur;
    u8 pad_2C[0x10];
    u32 unk_3C;
    u8 pad_40[0x88];
    CamState live;
    u8 pad_EC[0x24];
    CamState saved;
} CameraGlobals;

typedef struct {
    u16 unk_0;
    u16 unk_2;
    u8 pad_4[4];
    u16 unk_8;
    u16 unk_A;
    u8 pad_C[4];
    u16 unk_10;
    u16 unk_12;
    u8 pad_14[4];
} CameraFlags;

typedef struct {
    u8 pad_0[2];
    u8 unk_2;
    u8 unk_3;
} CameraInput;

extern CameraGlobals lbl_1_bss_1010;
extern CameraFlags lbl_1_bss_D58;
extern CameraInput lbl_1_data_4068;
extern f32 lbl_1_bss_BF0[32];

extern void camera_save_slot(u8 slot);
extern void camera_snapshot(void);
extern void fn_1_C038(s32 arg, f32 value0, f32 value1);
extern u32 fn_1_C10C(u32 slot);
extern void fn_1_C178(void *arg);
extern void camera_report_position(void);
extern void fn_1_C268(s32 arg);
extern void fn_1_C304(s32 arg);
extern u32 fn_1_C3B8(void);

void fn_1_C770(void) {
    CameraInput *in = &lbl_1_data_4068;
    CameraGlobals *cam = &lbl_1_bss_1010;
    CameraFlags *flags = &lbl_1_bss_D58;
    s32 dir;
    s32 step;
    s32 step_2;

    dir = 0;
    if (flags->unk_10 & 0x00800000) {
        dir = 1;
    } else if (flags->unk_10 & 0x00400000) {
        dir = -1;
    }

    step = 1;
    if (0.0f != lbl_1_bss_BF0[5]) {
        step_2 = (s32)(10.0f * lbl_1_bss_BF0[5]);
    }

    if ((s32)in->unk_3 == 1) {
        s32 value = (s32)in->unk_2 + dir * step_2;
        in->unk_2 = (value > 15) ? 0 : ((value < 0) ? 15 : value);
    }

    if ((s32)in->unk_3 == 2 && dir != 0) {
        cam->unk_4 = 0;
    }

    if ((s32)in->unk_3 == 3 && dir != 0) {
        camera_save_slot(0);
    }

    if ((s32)in->unk_3 == 4 && dir != 0) {
        camera_save_slot(1);
    }

    if ((s32)in->unk_3 == 5) {
        CamParams *prm = (CamParams *)&cam->unk_3C;
        f64 delta = 0.0001 * dir * step_2;
        f64 value = (f64)prm->value + delta;
        if (value > 0.5) {
            value = 0.0;
        } else if (value < 0.0) {
            value = 0.0;
        }
        prm->value = (f32)value;
    }

    if ((s32)in->unk_3 == 6) {
        CamParams *prm = (CamParams *)&cam->unk_3C;
        s32 value = prm->counter + dir * step_2;
        prm->counter = (value > 1000) ? 0 : ((value < 0) ? 1000 : value);
    }

    if ((s32)in->unk_3 == 7 && dir != 0) {
        CamParams *prm = (CamParams *)&cam->unk_3C;
        cam->unk_5 = 1;
        cam->saved = cam->cur;
        prm->mode = 0;
        camera_snapshot();
    }

    if ((s32)in->unk_3 == 8 && dir != 0) {
        CamParams *prm = (CamParams *)&cam->unk_3C;
        cam->unk_5 = 1;
        cam->saved = cam->cur;
        prm->mode = 3;
        fn_1_C038(prm->counter, 0.0f, 1.0f);
        camera_snapshot();
    }

    if ((s32)in->unk_3 == 9 && dir != 0) {
        CamParams *prm = (CamParams *)&cam->unk_3C;
        cam->unk_5 = 1;
        cam->saved = cam->cur;
        prm->mode = 2;
        camera_snapshot();
    }

    if ((s32)in->unk_3 == 10 && dir != 0) {
        fn_1_C10C(0);
    }

    if ((s32)in->unk_3 == 11 && dir != 0) {
        fn_1_C10C(1);
    }

    if ((s32)in->unk_3 == 12 && dir != 0) {
        cam->unk_4 = 0;
    }

    if ((s32)in->unk_3 == 13 && dir != 0) {
        fn_1_C178((void *)((u8 *)in + 0x180));
    }

    if ((s32)in->unk_3 == 14 && dir != 0) {
        fn_1_C178((void *)((u8 *)in + 0x188));
    }

    if ((s32)in->unk_3 == 15 && dir != 0) {
        fn_1_C178((void *)((u8 *)in + 0x194));
    }

    if ((s32)in->unk_3 == 16 && dir != 0) {
        camera_report_position();
    }

    if ((s32)in->unk_3 == 17 && dir != 0) {
        fn_1_C268((s32)(u32)((u8 *)in + 0x1A0));
    }

    if ((s32)in->unk_3 == 18 && dir != 0) {
        fn_1_C304((s32)(u32)((u8 *)in + 0x1B4));
    }

    if (flags->unk_10 & 0x10000000) {
        s32 cmd = (s32)in->unk_3;
        in->unk_3 = (cmd - 1 > 38) ? 0 : ((cmd - 1 < 0) ? 38 : cmd - 1);
    } else if (flags->unk_10 & 0x20000000) {
        s32 cmd = (s32)in->unk_3;
        in->unk_3 = (cmd + 1 > 38) ? 0 : ((cmd + 1 < 0) ? 38 : cmd + 1);
    }

    if (cam->unk_5 != 0) {
        fn_1_C3B8();
    }

    if ((flags->unk_0 & 0x00200000) && (flags->unk_8 & 0x00000800)) {
        cam->unk_5 = 0;
        cam->unk_4 = 0;
    }
}
