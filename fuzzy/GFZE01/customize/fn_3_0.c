/* Non-matching: best partial attempt (98.39% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"

typedef struct {
    volatile u8 field_0;
    u8 pad[3];
    u32 field_4[1];
} Part;

typedef struct {
    Part parts[3];
    u8 pad_18[2];
    volatile s16 indices[3];
} Bss20;

extern u16 lbl_3_bss_20[104];
extern u8 lbl_3_bss_140[];

extern void fn_80008BA8(void *, void *, u32);
extern s16 fn_1_14F118(s16, s16);
extern s32 fn_1_F809C(s32);
extern s16 fn_1_14F090(s16, s16);
extern s16 fn_1_14F01C(s16);
extern u32 fn_1_151BE8(s16, s16);
extern s32 fn_1_8D690(s16);

static inline void helper(Bss20 *bss20) {
    s16 i;
    volatile s16 *pIndex;
    s32 j;

    for (i = 0; i < 3; i++) {
        bss20->indices[i] = 0;
        bss20->parts[i].field_0 = fn_1_14F090(i, bss20->indices[i]);
        pIndex = &bss20->indices[i];
        while (fn_1_F809C(bss20->parts[i].field_0) == 0) {
            s32 val;

            if ((val = *pIndex + 1) > fn_1_14F01C(i) - 1) {
                val = 0;
            } else if (val < 0) {
                val = fn_1_14F01C(i) - 1;
            }
            *pIndex = val;
            bss20->parts[i].field_0 = fn_1_14F090(i, *pIndex);
        }
        for (j = 0; (s16)j < 1; j++) {
            bss20->parts[i].field_4[j] = fn_1_151BE8(bss20->parts[i].field_0, (s16)j);
        }
    }
    lbl_3_bss_20[103] = 6;
}

static inline u32 fn_3_0_operand(u32 right, u32 left) { left *= right; return left; }
#pragma opt_dead_assignments off
static inline volatile s16 *fn_3_0_array_read(volatile s16 *array) { return array; }
void fn_3_0(u32 arg0, s32 arg1) {
    struct { Bss20 *value; } bss20;
    s32 offset = (fn_3_0_operand(((0x81c0)), (((s16)arg0))));
    u8 *p = (u8 *)&lbl_3_bss_140 + offset;
    u32 flags = *(u32 *)p;

    if (flags & 0x80000000) {
        if (flags & 0x40000000) {
            s16 i;
            s32 flag = 0;

            fn_80008BA8(lbl_3_bss_20, p + 0x81A4, 0x18);
            bss20.value = (Bss20 *)lbl_3_bss_20;
            for (i = 0; i < 3; i++) {
                bss20.value->indices[i] = fn_1_14F118(bss20.value->parts[i].field_0, i);
                if (fn_3_0_array_read(bss20.value->indices)[i] == -1) {
                    flag = 1;
                }
                if (arg1 != 0 && fn_1_F809C(bss20.value->parts[i].field_0) == 0) {
                    flag = 1;
                }
                if (flag == 1) {
                    helper(bss20.value);
                    return;
                }
            }

            if (arg1 != 0 && fn_1_8D690(lbl_3_bss_140[offset + 0x81A0]) == 0) {
                lbl_3_bss_20[103] = 6;
            } else {
                lbl_3_bss_20[103] = lbl_3_bss_140[offset + 0x81A0];
            }
        } else {
            helper((Bss20 *)lbl_3_bss_20);
            lbl_3_bss_20[103] = lbl_3_bss_140[offset + 0x81A0];
        }
    } else {
        helper((Bss20 *)lbl_3_bss_20);
    }
}
#pragma opt_dead_assignments reset

