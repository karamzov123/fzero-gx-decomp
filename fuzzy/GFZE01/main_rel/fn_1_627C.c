/* Non-matching: best partial attempt (98.00% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"
#include "rel/main_rel/globals.h"

extern Obj_1_bss_F68_Target *lbl_1_bss_F68;

extern const f64 lbl_1_rodata_1E0;
extern const f32 lbl_1_rodata_188;
extern const f32 lbl_1_rodata_194;
extern u16 fn_1_A5D88(void);
extern u16 fn_1_A5DB0(void);
extern u32 fn_80038EEC(f32, f32, f32, f32, f32, f32);
extern u32 __cvt_fp2unsigned(f32);
extern u32 fn_80074188(u32, u32, u32, u32);

void fn_1_627C(void) {
    f32 lab_t4;
    f32 f31;
    Obj_1_bss_F68_Target *obj;
    u32 mode;

    obj = *(Obj_1_bss_F68_Target **)&lbl_1_bss_F68;
    mode = obj->unk_48;
    if ((s8) mode == 0xB) {
        return;
    }
    if ((((0x80000000) & (obj->unk_0))) != 0) {
        return;
    }
    if ((s8) mode == 0) {
        return;
    }
    if ((s8) mode != 9) {
        return;
    }
    f31 = (f32) fn_1_A5D88();
    (void) f31;  /* fzgx: keeps the web at its definition */
{
    f32 f30;
    f30 = (f32) fn_1_A5DB0();
    lab_t4 = lbl_1_rodata_188;
    fn_80038EEC(lbl_1_rodata_188, lbl_1_rodata_188, f31, f30, lab_t4, lbl_1_rodata_194);
    fn_80074188(0, 0, (u32) f31, (u32) f30);
}
}
