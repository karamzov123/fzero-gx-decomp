/* Non-matching: best partial attempt (96.62% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"
#include "font.h"

struct fn_10_139E4_Copy88 { u32 a[22]; };

extern f32 lbl_10_rodata_3AC;
extern f32 lbl_10_rodata_5D0;
extern f64 lbl_10_rodata_1E0;
extern int fn_1_4F734(FontDrawPacket *);
extern u32 fn_1_5158C(FontDrawPacket *, u32,s16,s16);
extern u8 lbl_1_rodata_26F8[];
extern void fn_1_51564(u16, u16, u16, u16, u16, u16);

#pragma opt_propagation off
static inline u32 fn_10_139E4_operand_operand(u32 left, u32 right) { return ((right) ^ (left)); }
#pragma opt_lifetimes off
static inline u32 fn_10_139E4_operand(u32 right, u32 left) { return fn_10_139E4_operand_operand((left), (right)); }
#pragma opt_lifetimes reset

#pragma opt_loop_invariants off
void fn_10_139E4(void) {
    FontDrawPacket loc_8;
    u32 v3;
    s32 v2;
    s32 v1;
    u16 lab_t4;
    u8 *p_lbl_1_rodata_26F8;
    u32 v0;
    /* frame */
    p_lbl_1_rodata_26F8 = (u8 *)&lbl_1_rodata_26F8;
    v0 = (0x10000 - 25333);
    v1 = 0;
    v2 = 29;
    do {
    lab_t4 = 2;
    fn_1_51564(0, 0, 24, 20, lab_t4, 2);
    loc_8 = *(FontDrawPacket *)(u32)p_lbl_1_rodata_26F8;
    v3 = ((u32)v1 >> 31);
    loc_8.image = v0;
    loc_8.y = (348.0f);
    loc_8.x = (f32)(s32)v2;
    loc_8.z = (2.0f);
    loc_8.flags = 10;
    fn_1_5158C((FontDrawPacket *)&loc_8, v0, (s16)((fn_10_139E4_operand(((v1 & 0x1)), (v3))) - v3), (s16)((s32)(v3 + v1) >> 1));
    fn_1_4F734((FontDrawPacket *)&loc_8);
    v1++;
    v2 += 150;
    } while ((s32)v1 < 4);
}
#pragma opt_loop_invariants reset

#pragma opt_propagation reset

