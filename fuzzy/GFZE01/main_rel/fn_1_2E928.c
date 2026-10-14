/* Non-matching: best partial attempt (96.16% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "rel/main_rel/stcoli.h"

extern f32 lbl_1_rodata_D48[9];
extern u8 lbl_1_rodata_DB38[32];
extern void *fn_1_2E3B4(void *, void *);

struct fn_1_2E928_record {
    u8 pad_0[4];
    u16 total;
    u8 pad_6[0x12];
    u16 speed;
    u8 pad_1A[0xA];
    u32 packed1;
    u8 pad_28[0x10];
    u32 packed2;
    u8 pad_3C[0x10];
    u16 score;
};
#pragma opt_common_subs on
static inline u8 *fn_1_2E928_array_read(u8 *array) { return array; }
#pragma opt_dead_assignments off
#pragma opt_lifetimes off
void fn_1_2E928(void *arg0) {
    u32 v0;
    u8 *v1;
    u8 *v2;
    f32 v3;
    s32 v8;
    u32 v9;
    s32 v10;
    u16 v12;
    u32 v13;
    u8 *v14;
    Obj_1_bss_3C30 *state = &lbl_1_bss_3C30;
    v0 = state->unk_A7;
    v1 = *(u8 **)((u8 *)arg0 + 0x49C);
    v2 = (u8 *)&((Obj_1_bss_3C30 *)((u8 *)state + (*(s16 *)((u8 *)arg0 + 4) * 0xA0)))->unk_D4;
    if (fn_1_2E928_array_read(v2)[v0 + 0xE] == 0xFE || fn_1_2E928_array_read(v2)[v0 + 0xE] == 0xFF) {
        *(u32 *)(((v0 << 2) + 0x24) + v2) = *(u16 *)(v1 + 0x1E2) | ((v1[0x1E0] << 20) | (v1[0x1E1] << 12));
        *(u32 *)(((state->unk_A7 << 2) + 0x38) + v2) = *(u16 *)(v1 + 0x1D6) | ((v1[0x1D4] << 20) | (v1[0x1D5] << 12));
        v3 = *(f32 *)((u8 *)arg0 + 0xD8);
        if (v3 > lbl_1_rodata_D48[0]) {
            *(u16 *)(fn_1_2E928_array_read(v2 + (state->unk_A7 << 1)) + 0x18) = 9999;
        } else {
            *(u16 *)(fn_1_2E928_array_read(v2 + (state->unk_A7 << 1)) + 0x18) = (s32)v3;
        }
        if (*(u8 *)((u8 *)arg0 + 0x482) > 30) {
            v2[state->unk_A7 + 0x13] = 30;
        } else {
            v2[state->unk_A7 + 0x13] = *(u8 *)((u8 *)arg0 + 0x482);
        }
        if ((*(u32 *)arg0 & 0x10000) == 0) {
            v2[state->unk_A7 + 0xE] = 0xFE;
            if (lbl_1_bss_3C30.unk_5 != 0) {
                v2[state->unk_A7 + 9] = 0;
                *(u16 *)(((v2) + (((state->unk_A7 << 1)) + (0x4C)))) = 0;
            }
        } else {
            s32 id = *(s16 *)((u8 *)arg0 + 4);
            for (v8 = 0; v8 < lbl_1_bss_3C30.unk_9; v8++) {
                if (id == *(u8 *)(0xE + (((u8 *)&lbl_1_bss_3C30) + v8))) break;
            }
            v2[state->unk_A7 + 0xE] = v8;
            *(u16 *)(((v2) + (((state->unk_A7 << 1)) + (0x4C)))) = 0;
            if (lbl_1_bss_3C30.unk_5 != 0) {
                if (v8 < 30) v2[state->unk_A7 + 9] = fn_1_2E928_array_read(lbl_1_rodata_DB38)[v8];
                else v2[state->unk_A7 + 9] = 0;
            }
            *(u16 *)(v2 + 4) += fn_1_2E928_array_read(v2)[state->unk_A7 + 9];
            v9 = state->unk_A7;
            v10 = 4 - fn_1_2E928_array_read(v2)[v9 + 0xE];
            if (v10 < 1) v10 = 1;
            else if (v10 == 4) v10++;
            v12 = *(u16 *)((u8 *)arg0 + 0x210);
            *(u16 *)(((v2) + ((((u32)v9 << 1)) + (0x4C)))) = v10 * (v12 + ((fn_1_2E928_array_read(v2)[v9 + 9]) << 1));
            v13 = *(u32 *)(v2 + 0x78);
            v14 = v2 + (state->unk_A7 << 1);
            *(u32 *)(v2 + 0x78) = v13 + *(u16 *)(v14 + 0x4C);
        }
        fn_1_2E3B4(v2, arg0);
    }
}
#pragma opt_lifetimes reset

#pragma opt_dead_assignments reset

#pragma opt_common_subs reset
