/* Non-matching: best partial attempt (95.29% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "dolphin/types.h"

typedef struct { u32 x, y, z; } Triple;
typedef struct {
    u8 unk_0;
    u8 pad_1[3];
    s16 unk_4;
    s16 unk_6;
    u8 pad_8[0xC];
    s16 unk_14;
    u8 pad_16[0x1E];
    Triple unk_34;
    u8 pad_40[0x18];
    f32 unk_58;
    u8 pad_5C[0xC];
    s16 unk_68;
    u8 pad_6A[4];
    s16 unk_6E;
    Triple unk_70;
    Triple unk_7C;
} Camera;
typedef struct {
    u8 pad_0[0x1C];
    s32 unk_1C;
} Entry;
extern f32 lbl_1_rodata_4E0[5];
extern u32 lbl_801A63C0;
extern f32 lbl_1_bss_17F0;
extern f32 lbl_1_bss_17F4;
extern Entry lbl_1_data_47B4[];
extern u32 fn_1_862A8(u32, void *);
extern void fn_1_8636C(int, void *);
extern void fn_1_862D4(int, Triple *);
extern void fn_1_8645C(int, void *);
extern u32 lbl_8006DBAC(void *);
extern void lbl_8006E1B0(void *, void *);

void fn_1_11748(Camera *camera)
{
    u8 *pool = (u8 *)lbl_1_rodata_4E0;
    f32 zero;
    Triple temp;

    if (camera->unk_0 == 5 || camera->unk_0 <= 1 || camera->unk_0 == 2) {
        lbl_801A63C0 = lbl_801A63C0 * 0x676A4B6B + 0x33CB;
        camera->unk_4 = camera->unk_14 = ((lbl_801A63C0 >> 16) & 0x7FFF) % 20;
    }
    camera->unk_68 = 2;
    zero = *(f32 *)(pool + 0x14);
    camera->unk_34 = *(Triple *)(pool + 0x150);
    camera->unk_6E = 0;
    lbl_1_bss_17F0 = zero;
    lbl_1_bss_17F4 = zero;
    fn_1_862A8(camera->unk_6, &camera->unk_70);
    fn_1_8636C(camera->unk_6, &camera->unk_7C);
    camera->unk_58 = *(f32 *)(pool + 0x128);
    fn_1_862D4(camera->unk_6, &temp);
    if (lbl_1_data_47B4[camera->unk_4].unk_1C != 0) {
        fn_1_8645C(camera->unk_6, &camera->unk_7C);
        lbl_8006DBAC(&camera->unk_7C);
        lbl_8006E1B0(&lbl_1_data_47B4[camera->unk_4], (u8 *)camera + 0x1C);
    }
}
