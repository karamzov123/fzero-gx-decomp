/* Non-matching: best partial attempt (94.86% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"
#include "rel/main_rel/camera.h"

typedef struct {
    u32 x;
    f32 y;
    s16 z;
} AFC8E3;

typedef struct {
    AFC8E3 e[3];
} AFC8Grp;

typedef struct {
    f32 x;
    f32 y;
    f32 z;
} AFC8Tri;

typedef struct {
    u32 unk_0;
    f32 unk_4;
    AFC8Grp unk_8;
    AFC8Grp unk_2C;
    s16 unk_50;
} AFC8Ent;

typedef struct {
    u8 pad_00[2];
    s16 unk_2;
    u8 pad_4[4];
    f32 unk_8;
    u8 pad_C[4];
    f32 unk_10[3];
    u8 pad_1C[0xC];
    f32 unk_28[3];
    u8 unk_34[0x44];
    s16 unk_78;
    u8 pad_7A[0x12];
    f32 unk_8C[3];
    f32 unk_98[3];
    s16 unk_A4;
    u8 pad_A6[0x14A];
    f32 unk_1F0;
    f32 unk_1F4;
    u8 pad_1F8[2];
    s16 unk_1FA;
} AFC8Cam;

extern void * lbl_8006D5A4(void *, void *, void *, f32);
extern void * lbl_8006DC6C(void *);
extern u32 lbl_8006E1B0(void *, void *);
extern void fn_1_862D4(int, void *);
extern void fn_1_863E4(int, void *);
extern void fn_80008DB4(u8 *, f32, u8 *, void *);

void fn_1_AFC8(AFC8Cam *cam) {
    AFC8Ent *e;
    AFC8Grp b;
    AFC8Grp a;
    AFC8Tri tri;
    u8 tmp[0x30];
    s16 idx;
    s16 n;
    f32 t;
    u32 q;
    f32 step;

    idx = cam->unk_A4;
    if (*(s16 *)&lbl_1_bss_960 == 14) {
        camera_transition_count = 14;
        e = (AFC8Ent *)((u8 *)lbl_1_data_3BD0 + idx * 0x54);
    } else {
        camera_transition_count = 5;
        e = (AFC8Ent *)((u8 *)&lbl_1_data_3A2C + idx * 0x54);
    }

    b = e->unk_8;
    a = e->unk_2C;

    n = cam->unk_78;
    if (n <= 0) {
        return;
    }

    switch (e->unk_50) {
    case 0:
        t = (f32)(1.0 - (f32)n / (f32)(s32)e->unk_0);
        lbl_8006D5A4((f32 *)&b.e[0].y, (f32 *)&a.e[0].y, (void *)cam->unk_8C, t);
        lbl_8006D5A4((f32 *)&b.e[1].y, (f32 *)&a.e[1].y, (void *)cam->unk_98, t);
        cam->unk_8 = b.e[2].y + (f32)(t * (a.e[2].y - b.e[2].y));
        cam->unk_1FA = (s16)(b.e[2].z + (s16)(t * (f32)(a.e[2].z - b.e[2].z)));
        break;
    case 3:
        q = e->unk_0 * e->unk_0 >> 2;
        step = 1.0f / (f32)q;
        if ((f32)n < (f32)e->unk_0 * 0.5f) {
            cam->unk_1F4 = cam->unk_1F4 - step;
        } else {
            cam->unk_1F4 = cam->unk_1F4 + step;
        }
        cam->unk_1F0 = cam->unk_1F0 + cam->unk_1F4;
        if (cam->unk_1F0 < 0.0f) {
            cam->unk_1F0 = 0.0f;
        } else if (cam->unk_1F0 > 1.0f) {
            cam->unk_1F0 = 1.0f;
        }
        t = cam->unk_1F0;
        lbl_8006D5A4((f32 *)&b.e[0].y, (f32 *)&a.e[0].y, (void *)cam->unk_8C, t);
        lbl_8006D5A4((f32 *)&b.e[1].y, (f32 *)&a.e[1].y, (void *)cam->unk_98, t);
        cam->unk_8 = b.e[2].y + (f32)(t * (a.e[2].y - b.e[2].y));
        cam->unk_1FA = (s16)(b.e[2].z + (s16)(t * (f32)(a.e[2].z - b.e[2].z)));
        break;
    case 2:
        lbl_8006D5A4((void *)cam->unk_8C, (f32 *)&a.e[0].y, (void *)cam->unk_8C, e->unk_4);
        lbl_8006D5A4((void *)cam->unk_98, (f32 *)&a.e[1].y, (void *)cam->unk_98, e->unk_4);
        cam->unk_8 = cam->unk_8 + (f32)(e->unk_4 * (a.e[2].y - cam->unk_8));
        cam->unk_1FA = (s16)(cam->unk_1FA + (s32)(e->unk_4 * (f32)(a.e[2].z - cam->unk_1FA)));
        break;
    }

    fn_1_862D4(cam->unk_2, &tri);
    fn_1_863E4(cam->unk_2, tmp);
    fn_80008DB4(&cam->unk_34[0], 0.1f, tmp, &cam->unk_34[0]);
    lbl_8006DC6C(&cam->unk_34[0]);
    *(f32 *)(0xE0000000 + 0x0C) = tri.x;
    *(f32 *)(0xE0000000 + 0x1C) = tri.y;
    *(f32 *)(0xE0000000 + 0x2C) = tri.z;
    lbl_8006E1B0(cam->unk_8C, cam->unk_10);
    lbl_8006E1B0(cam->unk_98, cam->unk_28);
}
