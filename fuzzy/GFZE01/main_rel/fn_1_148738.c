/* Non-matching: best partial attempt (84.05% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"
#include "font.h"

struct fn_1_148738_Copy88 { u32 a[22]; };
extern f32 lbl_1_rodata_92C0[22];
extern int fn_1_4F734(FontDrawPacket *);
extern u16 fn_1_48690(u32);

#pragma opt_propagation off
void fn_1_148738(u32 arg0, void *arg1, f32 arg2) {
    f32 *p_lbl_1_rodata_92C0;
    s32 v3;
    s32 v4;
    s32 v5;
    s32 v6;
    s32 v0;
    struct fn_1_148738_Copy88 loc_8;
    u16 t1;
    f32 v17;
    f32 v18;
    p_lbl_1_rodata_92C0 = lbl_1_rodata_92C0;
    v3 = *(s32 *)((u8 *)arg1 + 100) + 16;
    v4 = *(s32 *)((u8 *)arg1 + 104) + *(s32 *)((u8 *)arg1 + 116);
    v4 += 383;
    v6 = (((((arg0 - 4) <= 1) == 1 || (s32)arg0 == 9) == 1 || (s32)arg0 == 10) == 1 || (s32)arg0 == 6);
    if (v6 != 0) {
        loc_8 = *(struct fn_1_148738_Copy88 *)((u8 *)p_lbl_1_rodata_92C0 + 88);
        loc_8.a[0] = 0x971d;
        *(f32 *)((u8 *)&loc_8 + 4) = (f32)v4;
        *(f32 *)((u8 *)&loc_8 + 8) = (f32)v3;
        *(f32 *)((u8 *)&loc_8 + 12) = 46.0f;
        fn_1_4F734((FontDrawPacket *)&loc_8);
        loc_8 = *(struct fn_1_148738_Copy88 *)((u8 *)p_lbl_1_rodata_92C0 + 88);
        loc_8.a[0] = 0x970b;
        t1 = fn_1_48690(0x971d);
        v17 = (f32)(u32)*(u8 *)((u8 *)arg1 + 54) * (f32)((s32)t1 - 2);
        v18 = v17 / 100.0f;
        *(f32 *)((u8 *)&loc_8 + 4) = (f32)(v4 - 4) + v18;
        *(f32 *)((u8 *)&loc_8 + 8) = (f32)(v3 - 10);
        *(f32 *)((u8 *)&loc_8 + 12) = 45.0f;
        fn_1_4F734((FontDrawPacket *)&loc_8);
    }
}
