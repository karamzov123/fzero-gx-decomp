/* Non-matching: best partial attempt (70.40% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"
#include "rel/main_rel/globals.h"
#include "rel/main_rel/camera.h"

extern f32 lbl_1_rodata_230[44];

typedef struct AEB8_P3 {
    u32 f0;
    u32 f1;
    u32 f2;
} AEB8_P3;

typedef struct AEB8_Q6 {
    AEB8_P3 p;
    u32 f3;
    u32 f4;
    u32 f5;
} AEB8_Q6;

typedef struct AEB8_R7 {
    u32 f0;
    AEB8_Q6 q;
} AEB8_R7;

typedef struct AEB8_E {
    u32 unk_0;
    f32 unk_4;
    AEB8_R7 r;
    u32 unk_24;
    u32 unk_28;
    u8 pad_2C[0x28];
} AEB8_E;

typedef struct AEB8_Cam {
    u8 pad_00[0x8];
    f32 unk_8;
    u8 pad_0C[0x6C];
    s16 unk_78;
    u8 pad_7A[0x12];
    AEB8_Q6 unk_8C;
    s16 unk_A4;
    u8 pad_A6[0x13E];
    AEB8_P3 unk_1E4;
    f32 unk_1F0;
    f32 unk_1F4;
    u8 pad_1F8[2];
    volatile s16 unk_1FA;
} AEB8_Cam;

// scratch frame: the two dead aggregates plus the two pun slots
typedef struct AEB8_Frame {
    AEB8_P3 p;
    AEB8_R7 r;
    u32 f;
    u32 s;
} AEB8_Frame;

void fn_1_AEB8(AEB8_Cam *cam) {
    u32 d;
    AEB8_E *e;
    u32 a, b, c, g, h, i, j, k;
    f32 z;
    f32 fv;
    s16 sv;
    // dead aggregates kept in the frame
    volatile AEB8_Frame fr;

    if (*(s16 *)&lbl_1_bss_960 == 0xE) {
        e = (AEB8_E *)((u8 *)lbl_1_data_3BD0 + cam->unk_A4 * 0x54);
        camera_transition_count = 0xE;
    } else {
        e = (AEB8_E *)((u8 *)&lbl_1_data_3A2C + cam->unk_A4 * 0x54);
        camera_transition_count = 5;
    }

    a = e->r.q.p.f0;
    b = e->r.q.p.f1;
    c = e->r.q.p.f2;
    d = e->r.f0;
    g = e->r.q.f3;
    h = e->r.q.f4;
    i = e->r.q.f5;
    j = e->unk_24;
    k = e->unk_28;

    cam->unk_1E4.f0 = a;
    cam->unk_1E4.f1 = b;
    cam->unk_1E4.f2 = c;
    z = lbl_1_rodata_230[0];
    cam->unk_1F0 = z;
    cam->unk_1F4 = z;

    fr.f = j;
    cam->unk_78 = e->unk_0;
    fv = *(volatile f32 *)&fr.f;
    cam->unk_8C.p.f0 = a;
    cam->unk_8C.p.f1 = b;
    cam->unk_8C.p.f2 = c;
    cam->unk_8C.f3 = g;
    cam->unk_8C.f4 = h;
    cam->unk_8C.f5 = i;
    fr.s = k;
    sv = *(volatile s16 *)&fr.s;
    cam->unk_1FA = sv;
    cam->unk_8 = fv;
    cam->unk_1FA = sv;

    fr.r.f0 = d;
    fr.r.q.p.f0 = a;
    fr.r.q.p.f1 = b;
    fr.r.q.p.f2 = c;
    fr.r.q.f3 = g;
    fr.r.q.f4 = h;
    fr.r.q.f5 = i;
    fr.p.f0 = a;
    fr.p.f1 = b;
    fr.p.f2 = c;
}
