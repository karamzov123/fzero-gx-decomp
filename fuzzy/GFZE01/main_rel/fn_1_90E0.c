/* Non-matching: best partial attempt (2.56% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"

struct fn_1_90E0_Vec3 {
    f32 x;
    f32 y;
    f32 z;
};

struct fn_1_90E0_Cam {
    u8 pad_0[0x2];
    s16 unk_2;
    u8 pad_4[0x4];
    f32 unk_8;
    f32 unk_C;
    f32 unk_10;
    f32 unk_14;
    f32 unk_18;
    struct fn_1_90E0_Vec3 unk_1C;
    u8 pad_28[0x3C];
    struct {
        f32 x;
        f32 y;
        f32 z;
    } unk_64;
    u8 pad_70[0x4];
    f32 unk_74;
    s16 unk_78;
    u8 pad_7A[0x2];
    f32 unk_7C;
    f32 unk_80;
    u32 unk_84;
    u32 unk_88;
    struct {
        f32 x;
        f32 y;
        f32 z;
    } unk_90;
    struct {
        f32 x;
        f32 y;
        f32 z;
    } unk_9C;
    s16 unk_A4;
    s16 unk_A8;
    u8 pad_AA[0x1FC - 0xAA];
};

void fn_1_90E0(struct fn_1_90E0_Cam *cam) {
    f32 unk_d4[3];
    f32 unk_134[3];
    f32 unk_e0[3];
    f32 unk_b0[3];
    f32 unk_c8[3];
    f32 unk_110[3];
    f32 unk_128[3];
    s32 r26;
    s32 r25;
    s32 r30;
    s32 r31;
    s32 r27;
    f32 f28;
    f32 f29;
    f32 f30;
    f32 f31;

    if (fn_1_86678(cam->unk_2) == -1) {
        r26 = 0;
    } else {
        u8 t = (u8)fn_1_3BB0((s8)fn_1_86678(cam->unk_2));
        r26 = (t >= 2 && t < 5) ? 1 : 0;
    }
    lbl_8006DAEC();
    cam->unk_1C = *(struct fn_1_90E0_Vec3 *)&cam->unk_10;
    r27 = fn_1_86254(cam->unk_2);
    r30 = fn_1_8627C(cam->unk_2);
    fn_1_862D4(cam->unk_2, unk_d4);
    fn_1_8636C(cam->unk_2, unk_134);
    f31 = fn_1_8652C(cam->unk_2);
    r31 = fn_1_864E8(cam->unk_2);
    if (r30 != 0) {
        r25 = ((*(u32 *)((u8 *)r30 + 0x7C)) & 0x80) ? 1 : 0;
    } else {
        r25 = 0;
    }
    fn_1_AA54(cam);
    switch (cam->unk_A8) {
    case 0:
    case 1:
    case 2:
    case 3:
    case 4:
    case 5:
    case 6:
        break;
    }
}
