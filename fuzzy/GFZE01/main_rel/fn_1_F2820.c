/* Non-matching: best partial attempt (89.97% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"

typedef struct Fn_1_F2820_Object {
    u8 pad_0[0xA0];
    u16 half_A0;
    u16 half_A2;
} Fn_1_F2820_Object;

typedef struct Fn_1_F2820_State {
    u8 pad_0[0x8];
    u32 field_8;
    u8 pad_C[0x4];
    u32 field_10;
    u8 pad_14[5];
    u8 byte_19;
    u8 byte_1A;
    u8 pad_1B[1];
    u8 cnt[4];
    u8 pad_20[8];
    s32 word[4];
    u8 pad_38[8];
    u32 object;
} Fn_1_F2820_State;

typedef struct Fn_1_F2820_Global {
    u8 pad_0[4];
    u8 byte_4;
    u8 pad_5[0x47];
    u16 half_4C;
} Fn_1_F2820_Global;

extern u16 lbl_1_bss_7EFD0;
extern s32 fn_1_864E8(s32);
extern s8 fn_1_86624(void);
extern u8 fn_1_86678(s32);
extern u8 fn_1_F2D30(u8 *, u8 **, u32);
extern void fn_1_F2CD8(u8 *, u8 **, u32);

void fn_1_F2820(u8 *arg0, u8 *arg1, u8 *arg2) {
    u8 *base;
    u8 *tmp;
    Fn_1_F2820_Global *p;
    Fn_1_F2820_State *state;
    u8 found;
    u32 key;
    u8 k0;
    u8 j;
    u32 i;
    s32 idx;
    u32 flags;

    p = (Fn_1_F2820_Global *)&lbl_1_bss_7EFD0;
    tmp = 0;
    flags = *(volatile u8 *)&p->byte_4; /* byte-width read widened: keeps the wide bit tests */
    state = (Fn_1_F2820_State *)((u8 *)p + 8);
    base = (u8 *)state->object + 0xA4;
    if ((flags >> 0) & 1) {
        if (!((flags >> 3) & 1)) {
            if (!((flags >> 4) & 1)) {
                if ((flags >> 1) & 1) {
                    found = 0;
                    for (i = 0; (i & 0xFF) < 4; i++) {
                        j = (u8)i;
                        if (j < (s8)fn_1_86624()) {
                            key = fn_1_86678(j);
                            if (key != 0xFF) {
                                fn_1_F2CD8(base + ((Fn_1_F2820_Object *)state->object)->half_A0 * 7, &tmp, i);
                                if (state->byte_19 != 0) {
                                    if (tmp[6] == 0) {
                                        if (base + ((Fn_1_F2820_Object *)state->object)->half_A0 * 7 == tmp) {
                                            ((Fn_1_F2820_Object *)state->object)->half_A0 = ((Fn_1_F2820_Object *)state->object)->half_A0 - 1;
                                        }
                                        fn_1_F2CD8(tmp - 7, &tmp, i);
                                    } else {
                                        tmp[6] = tmp[6] - 1;
                                    }
                                } else {
                                    found = 1;
                                }
                                k0 = (u8)((j & 3) | 4 | (arg0[key * 6] & 0xF8));
                                if (state->byte_1A == 0 && tmp[0] == k0 &&
                                    (s8)tmp[1] == (s8)arg0[key * 6 + 1] &&
                                    (s8)tmp[2] == (s8)arg0[key * 6 + 2] &&
                                    (s8)tmp[3] == (s8)arg0[key * 6 + 3] &&
                                    tmp[4] == arg0[key * 6 + 4] &&
                                    tmp[5] == arg0[key * 6 + 5] && tmp[6] < 0xFF) {
                                    tmp[6] = tmp[6] + 1;
                                } else {
                                    fn_1_F2D30(tmp, &tmp, i);
                                    idx = (s32)(tmp - base) / 7;
                                    if (idx >= state->field_10) {
                                        p->byte_4 |= 0x10;
                                    } else {
                                        tmp[6] = 0;
                                        tmp[0] = k0;
                                        tmp[1] = arg0[key * 6 + 1];
                                        tmp[2] = arg0[key * 6 + 2];
                                        tmp[3] = arg0[key * 6 + 3];
                                        tmp[4] = arg0[key * 6 + 4];
                                        tmp[5] = arg0[key * 6 + 5];
                                        ((Fn_1_F2820_Object *)state->object)->half_A0 = (u16)idx;
                                    }
                                }
                            }
                        }
                    }
                    if (found != 0) {
                        *(u32 *)((u8 *)p + 8) = *(u32 *)((u8 *)p + 8) + 1;
                    }
                    ((Fn_1_F2820_Object *)state->object)->half_A2 = ((Fn_1_F2820_Object *)state->object)->half_A0;
                    p->half_4C = ((Fn_1_F2820_Object *)state->object)->half_A0;
                } else if ((flags >> 2) & 1) {
                    for (i = 0; (i & 0xFF) < 4; i++) {
                        j = (u8)i;
                        if (state->word[j] != 0) {
                            if (!((fn_1_864E8(j) >> 26) & 1)) {
                                fn_1_F2CD8(base + ((Fn_1_F2820_Object *)state->object)->half_A0 * 7, &tmp, i);
                                if (state->byte_19 != 0) {
                                    if (((u8 *)p + 8)[0x1C + j] == 0) {
                                        if (base + ((Fn_1_F2820_Object *)state->object)->half_A0 * 7 == tmp) {
                                            ((Fn_1_F2820_Object *)state->object)->half_A0 = ((Fn_1_F2820_Object *)state->object)->half_A0 - 1;
                                        }
                                        fn_1_F2CD8(tmp - 7, &tmp, i);
                                        ((u8 *)p + 8)[0x1C + j] = tmp[6];
                                    } else {
                                        ((u8 *)p + 8)[0x1C + j] = ((u8 *)p + 8)[0x1C + j] - 1;
                                    }
                                }
                                arg0[j * 6] = tmp[0] & 0xF8;
                                arg0[j * 6 + 1] = tmp[1];
                                arg0[j * 6 + 2] = tmp[2];
                                arg0[j * 6 + 3] = tmp[3];
                                arg0[j * 6 + 4] = tmp[4];
                                arg0[j * 6 + 5] = tmp[5];
                                if (((u8 *)p + 8)[0x1C + j] >= tmp[6]) {
                                    fn_1_F2D30(base + ((Fn_1_F2820_Object *)state->object)->half_A0 * 7, &tmp, i);
                                    idx = (s32)(tmp - base) / 7;
                                    if (idx <= p->half_4C) {
                                        ((Fn_1_F2820_Object *)state->object)->half_A0 = (u16)idx;
                                        ((u8 *)p + 8)[0x1C + j] = 0;
                                    }
                                } else {
                                    ((u8 *)p + 8)[0x1C + j] = ((u8 *)p + 8)[0x1C + j] + 1;
                                }
                                arg1[j] = arg0[j * 6] & ~arg2[j];
                            }
                        }
                    }
                    if (((Fn_1_F2820_Object *)state->object)->half_A0 > p->half_4C) {
                        p->byte_4 |= 0x10;
                    }
                }
            }
        }
    }
}
