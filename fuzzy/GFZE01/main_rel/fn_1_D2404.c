/* Non-matching: best partial attempt (98.60% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"
#include "rel/main_rel/globals.h"
#include "rel/main_rel/face.h"

extern u32 fn_1_58C4(void);
extern void fn_1_D2F50(void);
extern s32 fn_1_D2E44(u32);
extern void fn_1_D2110(Obj_1_bss_7ACD8_Target *);
extern u32 fn_1_864E8(u32);
extern s16 fn_1_3F0C8(void);
extern s32 fn_1_3F440(u8);
extern s8 fn_1_86690(s8);
extern s16 fn_1_12C7B8(s16);
extern s32 fn_1_D123C(u32);
extern void fn_1_D2F84(void);
extern void fn_80071718(u32);
extern void fn_800711A8(u32);

struct FaceState {
    u32 unk_0;
    u32 unk_4;
    s32 unk_8;
    s8 unk_C;
    u8 unk_D;
    u16 unk_E;
    u32 unk_10;
};

#pragma opt_propagation off
#pragma opt_common_subs off
#pragma opt_lifetimes off
#pragma opt_dead_assignments off
void fn_1_D2404(void) {
    struct FaceState *state = (struct FaceState *)&lbl_1_bss_7ACD8;
    u32 v;
    u32 k_mask;
    s8 lane;
    u32 k_id;
    u32 i_2;
    Obj_1_bss_7ACD8_Target *obj;
    u32 index;
    Obj_1_bss_7ACD8_Target * entry_2_2;
    u32 k;
    u32 j;
    Obj_1_bss_7ACD8_Target *entry;
    u32 i;
    s32 found;
    s32 found2;
    Obj_1_bss_7ACD8_Target *entry_2;
    Obj_1_bss_7ACD8_Target *p;
    u32 val;

    if (fn_1_58C4() <= 1 && (s32)lbl_1_data_3D924 != -1) {
        fn_1_D2F50();
        entry = (Obj_1_bss_7ACD8_Target *)state->unk_0;
        i = 0;
        while ((i & 0xFF) < state->unk_D) {
            entry->unk_14 = fn_1_D2E44(entry->unk_4 & 0xFF) & 0xFF;
            i++;
            entry = (Obj_1_bss_7ACD8_Target *)((u8 *)entry + 0x64);
        }
        obj = (Obj_1_bss_7ACD8_Target *)state->unk_0;
        i_2 = 0;
        while ((i_2 & 0xFF) < state->unk_D) {
            fn_1_D2110(obj);
            if (obj->unk_3C != 0) {
                obj->unk_3C--;
            }
            if (obj->unk_38 != 0) {
                obj->unk_38--;
            }
            if (fn_1_864E8(obj->unk_4) & 0x2800000) {
                if (fn_1_3F0C8() == 0x29) {
                    obj->unk_38 = 10;
                }
            }
            if (obj->unk_10 != obj->unk_14) {
                obj->unk_1C--;
            } else {
                obj->unk_1C = 20;
            }
            if (obj->unk_1C == 0) {
                entry_2 = (Obj_1_bss_7ACD8_Target *)state->unk_0;
                j = 0;
                while ((j & 0xFF) < state->unk_D) {
                    if ((s32)state->unk_10 == 0 && entry_2->unk_10 < 6 && entry_2->unk_14 >= 6) {
                        index = (entry_2->unk_4 & 0xFF) << 2;
                        if (*(u32 *)(state->unk_8 + index) != 0) {
                            fn_80071718(*(u32 *)(state->unk_8 + index));
                            *(u32 *)(state->unk_8 + index) = 0;
                        }
                        if (*(u32 *)(state->unk_4 + index) != 0) {
                            fn_800711A8(*(u32 *)(state->unk_4 + index));
                            *(u32 *)(state->unk_4 + index) = 0;
                        }
                    }
                    if (entry_2->unk_10 != 0 && entry_2->unk_14 == 0 && fn_1_3F0C8() == 0x29) {
                        entry_2->unk_3C = 70;
                    } else {
                        entry_2->unk_3C = 0;
                    }
                    entry_2->unk_10 = entry_2->unk_14;
                    if ((s32)state->unk_10 != 0) {
                        entry_2->unk_18 = entry_2->unk_4;
                    } else {
                        entry_2->unk_18 = fn_1_3F440(entry_2->unk_14 & 0xFF);
                    }
                    j++;
                    entry_2_2 = (Obj_1_bss_7ACD8_Target *)((u8 *)entry_2_2 + 0x64);
                }
                if ((s32)state->unk_10 == 0) {
                    lane = (s8)i_2;
                    k = 0;
                    while ((k & 0xFF) < state->unk_C) {
                        k_id = k & 0xFF;
                        val = fn_1_D2E44(k_id);
                        if ((val & 0xFF) < 6) {
{
    Obj_1_bss_7ACD8_Target * fzgx_loop_p_4110;
    u32 fzgx_loop_j_4110;
                            entry_2_2 = (Obj_1_bss_7ACD8_Target *)state->unk_0;
                            found = 1;
                            fzgx_loop_p_4110 = entry_2_2;
                            fzgx_loop_j_4110 = 0;
                            while ((fzgx_loop_j_4110 & 0xFF) < state->unk_D) {
                                if (fzgx_loop_p_4110->unk_10 < 6 && found != 0 && k_id == fzgx_loop_p_4110->unk_4) {
                                    found = 0;
                                }
                                fzgx_loop_j_4110++;
                                fzgx_loop_p_4110 = (Obj_1_bss_7ACD8_Target *)((u8 *)fzgx_loop_p_4110 + 0x64);
                            }
    p = fzgx_loop_p_4110;
    j = fzgx_loop_j_4110;
}
                            if (found != 0) {
                                v = val & 0xFF;
                                k_mask = k & 0xFF;
                                found2 = 1;
                                j = 0;
                                while ((j & 0xFF) < state->unk_D) {
                                    if (entry_2_2->unk_10 >= 6 && found2 != 0) {
                                        entry_2_2->unk_10 = v;
                                        entry_2_2->unk_14 = v;
                                        entry_2_2->unk_4 = k_id;
                                        entry_2_2->unk_8 = fn_1_12C7B8(fn_1_86690(lane));
                                        if ((s32)state->unk_10 != 0) {
                                            entry_2_2->unk_18 = k_mask;
                                        } else {
                                            entry_2_2->unk_18 = fn_1_3F440(entry_2_2->unk_14 & 0xFF);
                                        }
                                        if (fn_1_D123C(k) != 0) {
                                            entry_2_2->unk_0 &= 0x7FFFFFFF;
                                        } else {
                                            entry_2_2->unk_0 |= 0x80000000;
                                        }
                                        if (entry_2_2->unk_14 == 0) {
                                            entry_2_2->unk_3C = 70;
                                        } else {
                                            entry_2_2->unk_3C = 0;
                                        }
                                        found2 = 0;
                                    }
                                    j++;
                                    entry_2_2 = (Obj_1_bss_7ACD8_Target *)((u8 *)entry_2_2 + 0x64);
                                }
                            }
                        }
                        k++;
                    }
                }
            }
            i_2++;
            obj = (Obj_1_bss_7ACD8_Target *)((u8 *)obj + 0x64);
        }
        fn_1_D2F84();
    }
}
#pragma opt_dead_assignments reset

#pragma opt_lifetimes reset

#pragma opt_common_subs reset
#pragma opt_propagation reset
