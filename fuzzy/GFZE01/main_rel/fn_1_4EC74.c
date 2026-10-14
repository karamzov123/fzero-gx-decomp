/* Non-matching: best partial attempt (97.47% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"

extern const struct fn_1_4EC74_lbl_1_rodata_2750_pool {
    f32 unk_0;
} lbl_1_rodata_2750;

typedef struct FontData {
    u8 pad0[0x30];
    s16 flags;
    u8 pad34[0x0c];
    u32 size;
    u16 height;
    u16 depth;
    void *buffer;
} FontData;

extern f32 fn_1_519AC(u32);
extern u32 __cvt_fp2unsigned(f32);
extern void DCFlushRange(void *, u32);
extern void GXInitTexObj(void *, void *, u16, u16, u32, u32, u32, u32);
extern void GXInitTexObjLOD(void *, s32, s32, f32, f32, f32, s32, s32, s32);
extern void fn_80073778(void *, s32);
extern void fn_1_4EDAC(FontData *, f32, f32);
extern const f64 lbl_1_rodata_2758;
extern u8 lbl_1_bss_4E6B0[32];

#pragma opt_dead_assignments off
#pragma opt_common_subs off
#pragma opt_lifetimes off
s32 fn_1_4EC74(FontData *font) {
    f32 scale;

    if (((0x02000000) & (font->flags))) {
        return 0;
    }

    scale = fn_1_519AC(font->size);
    scale = (f32)font->height * scale;
    DCFlushRange(font->buffer, __cvt_fp2unsigned(((f32)font->depth * scale)));

    {
        u16 w = font->height;
        u16 h = font->depth;
        GXInitTexObj(lbl_1_bss_4E6B0, font->buffer, w, h, font->size, 0, 0, 0);
    }
    GXInitTexObjLOD(lbl_1_bss_4E6B0, 0, 0, lbl_1_rodata_2750.unk_0, lbl_1_rodata_2750.unk_0, lbl_1_rodata_2750.unk_0, 0, 0, 0);
    fn_80073778(lbl_1_bss_4E6B0, 0);
    fn_1_4EDAC(font, (f32)font->height, (f32)font->depth);
    return 1;
}
#pragma opt_lifetimes reset

#pragma opt_common_subs reset

#pragma opt_dead_assignments reset

