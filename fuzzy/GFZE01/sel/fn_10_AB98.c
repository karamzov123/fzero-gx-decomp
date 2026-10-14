/* Non-matching: best partial attempt (89.14% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"

extern void fn_10_C594(void);
extern s16 fn_1_12EF24(s16 a, s16 b);
extern s32 fn_1_F89E4(u8 idx);
extern void fn_1_7B2E8(u32 value);

extern s8 lbl_10_data_2B4[0x1A0];

typedef struct {
    u8 pad0[0x8C];
    s16 unk8C;
    s16 unk8E;
    s16 value90;
    u32 flags94;
} SelItem;

typedef struct {
    s16 value;
} SelState;

extern SelState lbl_1_bss_8B3A0;

void fn_10_AB98(SelItem *arg0) {
    SelItem *self = arg0;
    s32 flag = 0;
    s32 c = flag;
    s32 f2 = 0;
    s32 idx;
    s32 t;
    s16 a;
    s16 cnt;
    s16 step;

    if (self->unk8C == 0) {
        s32 v = self->value90;

        idx = (v < 0) ? 0 : ((v > 110) ? 110 : v);

        if ((self->flags94 & 0x2) != 0) {
            if (lbl_10_data_2B4[idx] == 0) {
                flag = 1;
            }
        }

        a = (s16)flag;
        cnt = (s16)(((a >> 31) ^ a) - (a >> 31));
        step = (cnt < 0) ? -1 : (a > 0);

        for (; cnt > 0; cnt--) {
            t = idx + step;

            idx = (t < 0) ? 0 : ((t > 110) ? 110 : t);

            if ((self->flags94 & 0x2) != 0) {
                while (lbl_10_data_2B4[idx] == 0) {
                    t = idx + step;

                    idx = (t < 0) ? 0 : ((t > 110) ? 110 : t);
                }
            }
        }

        self->unk8E = (s16)idx;
        self->value90 = self->unk8E;
    } else {
        do {
            s32 v;

            f2 = 0;
            v = self->unk8E + flag;

            self->unk8E = (s16)((v > 5) ? 0 : ((v < 0) ? 5 : v));
            self->value90 = fn_1_12EF24(self->unk8C, self->unk8E);

            if (self->value90 == -1 && flag == 0) {
                flag = 1;
            }

            if (self->unk8C == 5) {
                if (self->unk8E == 5) {
                    if (fn_1_F89E4(0) == 0) {
                        goto found;
                    }
                }

                if (self->unk8E == 5) {
                    goto tail;
                }

                if (fn_1_F89E4((u8)(self->unk8E + 1)) == 0) {
                    goto found;
                }
            }

        found:
            f2 = 1;
            if (flag == 0) {
                flag = f2;
            }

        tail:
            c++;

            if (self->value90 != -1 && lbl_10_data_2B4[self->value90] != 0 && f2 == 0) {
                break;
            }
        } while ((s8)c < 6);
    }

    if (lbl_1_bss_8B3A0.value != 1) {
        fn_10_C594();
    }

    if (lbl_1_bss_8B3A0.value != 1) {
        if ((self->flags94 & 0x80000000) == 0) {
            fn_1_7B2E8(self->value90);
        }
    }
}
