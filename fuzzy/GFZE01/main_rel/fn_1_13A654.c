/* Non-matching: best partial attempt (73.97% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "rel/main_rel/sel_static_disp.h"

extern const f32 lbl_1_rodata_861C;
extern const f32 lbl_1_rodata_8C00;
extern const f32 lbl_1_rodata_8C04;
extern const f32 lbl_1_rodata_8C08;
extern const f32 lbl_1_rodata_864C;
extern const f32 lbl_1_rodata_880C;
extern const f32 lbl_1_rodata_8638;
extern const f32 lbl_1_rodata_8C0C;
extern const f32 lbl_1_rodata_87D0;
extern f32 lbl_1_rodata_26F8[22];

extern s32 fn_1_141F94(u32);

typedef struct {
    u8 pad_00[0xE];
    s16 unk_E;
    u8 pad_10[0x10];
} Entry;

typedef struct {
    f32 f_00;
    f32 f_04;
    f32 f_08;
    f32 f_0C;
    f32 f_10;
    f32 f_14;
    f32 f_18;
    f32 f_1C;
    f32 f_20;
    f32 f_24;
    f32 f_28;
    f32 f_2C;
    s32 i_30;
    f32 f_34;
    f32 f_38;
    f32 f_3C;
    f32 f_40;
    f32 f_44;
    f32 f_48;
    f32 f_4C;
    f32 f_50;
    f32 f_54;
} Params;

typedef struct {
    u16 h_00;
    u8 pad_02[0x22];
    u32 ptr_24;
    u8 pad_28[0x10];
    f32 f_38;
    f32 f_3C;
    f32 f_40;
    f32 f_44;
    f32 f_48;
    f32 f_4C;
} Kart;

extern void fn_1_8CED0(void *, u16, u16);
extern u32 fn_1_8D3F8(void *, void *, u32 (*)(u32), u32);
typedef struct Sig_fn_1_131B90_Obj Sig_fn_1_131B90_Obj;
extern s32 fn_1_131B90(Sig_fn_1_131B90_Obj *);

void fn_1_13A654(Kart *self)
{
    s32 i;
    s16 e;

    self->f_38 = lbl_1_rodata_861C;
    self->f_3C = lbl_1_rodata_8C00;
    self->f_40 = lbl_1_rodata_8C04;
    self->f_44 = lbl_1_rodata_8C08;
    self->f_48 = lbl_1_rodata_864C;
    self->f_4C = lbl_1_rodata_861C;

    for (i = 0; i < 4; i++) {
        Params prm;
        s32 v;

        e = ((Entry *)&lbl_1_bss_8B3A0)[i].unk_E;
        v = fn_1_141F94((u8)i);
        if (e == -1) {
            continue;
        }
        self->h_00 = (u16)i;
        prm = *(Params *)&lbl_1_rodata_26F8;
        prm.i_30 = 10;
        prm.f_04 = (f32)(300 * (s32)(u8)v + 224);
        prm.f_08 = (f32)(200 * (s32)(u8)v + 176);
        prm.f_0C = lbl_1_rodata_880C;
        if (lbl_1_bss_8CA28.unk_0) {
            prm.f_10 *= lbl_1_rodata_8638;
            prm.f_14 *= lbl_1_rodata_8638;
        }
        prm.f_10 *= lbl_1_rodata_8C0C;
        prm.f_14 *= lbl_1_rodata_8C0C;
        fn_1_8CED0((void *)(self->ptr_24 + i * 0x64), 0xA0, 0x8C);
        *(f32 *)(self->ptr_24 + i * 0x64 + 0x44) = lbl_1_rodata_87D0;
        fn_1_8D3F8((void *)(self->ptr_24 + i * 0x64), &prm,
                   (u32 (*)(u32))fn_1_131B90, (u32)self);
    }
}
