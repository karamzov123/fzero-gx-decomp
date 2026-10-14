/* Non-matching: best partial attempt (91.94% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"
#include "rel/main_rel/ghost.h"

extern const f64 lbl_1_rodata_6B68;
extern void fn_1_F5458(void *, u32, f32, f32 *, void *);
extern void fn_80008BEC(void *, int, u32);
extern void lbl_8006DB74(u32);
extern void mathutil_mtxA_from_quat(void *);

#pragma opt_propagation off
#pragma opt_loop_invariants off
#pragma opt_lifetimes off
s8 fn_1_F0D10(u32 arg0, u32 arg1) {
    u32 v0 = arg0 << 1;
    u32 v1 = arg0 << 2;
    f32 v2;
    struct { u32 a[4]; } loc_8;
    u32 *counts = (u32 *)((u8 *)&lbl_1_bss_7B180 + 0x1824);
    f32 **times = (f32 **)((u8 *)&lbl_1_bss_7B180 + 0x1600);
    u16 *frames = (u16 *)((u8 *)&lbl_1_bss_7B180 + 0x1800);
    void **data = (void **)((u8 *)&lbl_1_bss_7B180 + 0x1728);
    struct { u8 value; } frame;
    void * lab_t0;
    void * lab_t4;
    frame.value = *(u16 *)((u8 *)frames + v0);
    v2 = (f32)frame.value;
    lab_t0 = &loc_8;
    lab_t4 = *(void **)((u8 *)data + v1);
    fn_1_F5458(lab_t0, *(u32 *)((u8 *)counts + v1), v2, *(f32 **)((u8 *)times + v1), lab_t4);
    v2 = (f32)(u32)*(u16 *)(((v0) + ((u8 *)frames)));
    if (v2 >= (*(f32 **)((u8 *)times + v1))[*(u32 *)((u8 *)counts + v1) - 1]) {
        fn_80008BEC((void *)arg1, 0, 48);
        return 0;
    } else {
        mathutil_mtxA_from_quat(&loc_8);
        lbl_8006DB74(arg1);
        return 1;
    }
}
#pragma opt_lifetimes reset

#pragma opt_loop_invariants reset

