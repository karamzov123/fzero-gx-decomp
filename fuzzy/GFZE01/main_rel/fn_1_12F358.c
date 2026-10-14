/* Non-matching: best partial attempt (96.07% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"
#include "rel/main_rel/archive.h"

extern u8 lbl_1_data_2B0D4[112];
extern u8 fn_1_F8CF0(s32);
extern void fn_1_A2D84(u32);

struct fn_1_12F358_state {
    u8 pad_0[0x9E];
    u8 unk_9E;
};
struct fn_1_12F358_entry {
    u8 pad_0[8];
    u16 unk_8;
    u8 pad_A[0xA];
};

#pragma opt_propagation on
#pragma opt_strength_reduction off
static inline u32 fn_1_12F358_flags(struct fn_1_12F358_state *state) {
    u32 address;
    u32 entry = (u32)&lbl_1_bss_9F8;
    { struct {
    u8 lab_pad[8]; u16 value; } holder;
    holder.value = (u32)state;
    address = holder.value; }
{
    u32 index = *(u8 *)(address + 0x9E);
    entry += index * 20;
}
    return (((struct fn_1_12F358_entry *)entry)->unk_8 >> 4) & 1;
}

static inline u8 fn_1_12F358_array_read(s32 index, u8 *array) { return array[index]; }
#pragma opt_loop_invariants on
#pragma opt_strength_reduction on
#pragma opt_common_subs off
void fn_1_12F358(u16 arg0) {
    struct { u8 *value; } p_lbl_1_data_2B0D4;
    s32 v0;
    Obj_1_bss_8B2E0 *p_lbl_1_bss_8B2E0;
    s32 lab_t0;
    p_lbl_1_bss_8B2E0 = &lbl_1_bss_8B2E0;
    v0 = (s16)arg0;
    p_lbl_1_data_2B0D4.value = lbl_1_data_2B0D4;
    if ((fn_1_12F358_array_read(v0, p_lbl_1_data_2B0D4.value) == 1 || fn_1_12F358_array_read(v0, p_lbl_1_data_2B0D4.value) == 17) && fn_1_F8CF0(0)) {
        if (fn_1_12F358_flags((struct fn_1_12F358_state *)(p_lbl_1_bss_8B2E0 + 1))) {
            if ((*((u8 *)p_lbl_1_bss_8B2E0 + 0x310) = (*((u8 *)p_lbl_1_bss_8B2E0 + 0x310) != 1))) {
                lab_t0 = 0xA9010100;
                fn_1_A2D84(lab_t0);
            } else {
                lab_t0 = 0xA9010000;
                fn_1_A2D84(lab_t0);
            }
        }
    } else {
        *((u8 *)p_lbl_1_bss_8B2E0 + 0x310) = 0;
    }
    if (fn_1_12F358_array_read(v0, p_lbl_1_data_2B0D4.value) == 4 && fn_1_F8CF0(1)) {
        if (fn_1_12F358_flags((struct fn_1_12F358_state *)(1 + p_lbl_1_bss_8B2E0))) {
            if ((*((u8 *)p_lbl_1_bss_8B2E0 + 0x311) = (*((u8 *)p_lbl_1_bss_8B2E0 + 0x311) != 1))) {
                lab_t0 = 0xA9010100;
                fn_1_A2D84(lab_t0);
            } else {
                lab_t0 = 0xA9010000;
                fn_1_A2D84(lab_t0);
            }
        }
    } else {
        *((u8 *)p_lbl_1_bss_8B2E0 + 0x311) = 0;
    }
    return;
}
#pragma opt_common_subs reset

#pragma opt_strength_reduction reset

#pragma opt_loop_invariants reset

