/* Non-matching: best partial attempt (49.80% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"

typedef struct CameraState {
    u32 unk_0;
    f32 unk_4[3];
    f32 unk_10[3];
    f32 unk_1C;
    s16 unk_20;
    u16 unk_22;
} CameraState;
struct fn_1_C3B8_lbl_1_bss_1010 {
    u8 pad_0[5];
    u8 unk_5;
    u8 pad_6[2];
    CameraState unk_8;
    u8 pad_2C[0x10];
    s32 unk_3C;
    s32 unk_40;
    s32 unk_44;
    f32 unk_48;
    u8 pad_4C[0x64];
    f32 unk_B0;
    f32 unk_B4;
    f32 unk_B8;
    f32 unk_BC;
    f32 unk_C0;
    f32 unk_C4;
    CameraState unk_C8;
    CameraState unk_EC;
};
extern f32 lbl_1_rodata_400;
extern f32 lbl_1_rodata_4A0;
extern struct fn_1_C3B8_lbl_1_bss_1010 lbl_1_bss_1010;
extern const f64 lbl_1_rodata_480;
extern void *lbl_8006D5A4(void *, void *, void *, f32);

void fn_1_C3B8(void) {
    struct fn_1_C3B8_lbl_1_bss_1010 *p_lbl_1_bss_1010 = &lbl_1_bss_1010;
    s32 *v0 = &p_lbl_1_bss_1010->unk_3C;
    CameraState loc_3C = p_lbl_1_bss_1010->unk_C8;
    CameraState loc_18 = p_lbl_1_bss_1010->unk_EC;
    f32 v8;
    switch(v0[1]) {
    case 0:
        v8 = (f32)p_lbl_1_bss_1010->unk_3C / (f32)v0[2];
        lbl_8006D5A4(loc_3C.unk_4, loc_18.unk_4, p_lbl_1_bss_1010->unk_8.unk_4, v8);
        lbl_8006D5A4(loc_3C.unk_10, loc_18.unk_10, p_lbl_1_bss_1010->unk_8.unk_10, v8);
        p_lbl_1_bss_1010->unk_8.unk_1C = loc_3C.unk_1C + (f32)(v8 * (loc_18.unk_1C - loc_3C.unk_1C));
        p_lbl_1_bss_1010->unk_8.unk_20 = loc_3C.unk_20 + (s16)(v8 * (loc_18.unk_20 - loc_3C.unk_20));
        if (p_lbl_1_bss_1010->unk_3C >= v0[2]) p_lbl_1_bss_1010->unk_5 = 0;
        break;
    case 1:
    case 3:
        p_lbl_1_bss_1010->unk_B8 -= lbl_1_rodata_400;
        if (p_lbl_1_bss_1010->unk_B8 < p_lbl_1_bss_1010->unk_BC * lbl_1_rodata_4A0)
            p_lbl_1_bss_1010->unk_C0 -= p_lbl_1_bss_1010->unk_C4;
        else
            p_lbl_1_bss_1010->unk_C0 += p_lbl_1_bss_1010->unk_C4;
        v8 = p_lbl_1_bss_1010->unk_B0 + p_lbl_1_bss_1010->unk_C0;
        p_lbl_1_bss_1010->unk_B0 = v8;
        lbl_8006D5A4(loc_3C.unk_4, loc_18.unk_4, p_lbl_1_bss_1010->unk_8.unk_4, v8);
        lbl_8006D5A4(loc_3C.unk_10, loc_18.unk_10, p_lbl_1_bss_1010->unk_8.unk_10, v8);
        p_lbl_1_bss_1010->unk_8.unk_1C = loc_3C.unk_1C + (f32)(v8 * (loc_18.unk_1C - loc_3C.unk_1C));
        p_lbl_1_bss_1010->unk_8.unk_20 = loc_3C.unk_20 + (s16)(v8 * (loc_18.unk_20 - loc_3C.unk_20));
        if (p_lbl_1_bss_1010->unk_3C >= v0[2]) p_lbl_1_bss_1010->unk_5 = 0;
        break;
    case 2:
        lbl_8006D5A4(p_lbl_1_bss_1010->unk_8.unk_4, loc_18.unk_4, p_lbl_1_bss_1010->unk_8.unk_4, *(f32*)&v0[3]);
        lbl_8006D5A4(p_lbl_1_bss_1010->unk_8.unk_10, loc_18.unk_10, p_lbl_1_bss_1010->unk_8.unk_10, *(f32*)&v0[3]);
        p_lbl_1_bss_1010->unk_8.unk_1C += (f32)(*(f32*)&v0[3] * (loc_18.unk_1C - p_lbl_1_bss_1010->unk_8.unk_1C));
        p_lbl_1_bss_1010->unk_8.unk_20 += (s32)(*(f32*)&v0[3] * (loc_18.unk_20 - p_lbl_1_bss_1010->unk_8.unk_20));
        break;
    }
    p_lbl_1_bss_1010->unk_3C++;
}
