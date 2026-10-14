/* Non-matching: best partial attempt (30.87% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"
#include "rel/main_rel/sel_static_disp.h"

extern const f64 lbl_1_rodata_99A8;
extern const f64 lbl_1_rodata_99B0[5];
extern int fn_1_8623C(void);

typedef struct {
    u8 pad_0[4];
    u8 unk_4, unk_5;
    u8 pad_6[0x12];
    f32 unk_18;
    u8 pad_1C[4];
    s32 unk_20;
    u8 pad_24[4];
    s32 unk_28;
    u8 pad_2C[4];
    u8 unk_30;
} State;


#define UPDATE(activeMax, capMax, capExpr) do { \
    int index = fn_1_8623C(); \
    int mode = s->unk_30; \
    int base = ((u8 *)&lbl_1_bss_3C30)[index * 0xA0 + lbl_1_bss_3C30.unk_A7]; \
    int target = ((u8 *)&lbl_1_bss_3C30)[index * 0xA0 + lbl_1_bss_3C30.unk_A7 + 0xE2]; \
    int value = target - (mode - 1); \
    s->unk_20 = target; \
    s->unk_20 = value; \
    if (value < 0) s->unk_20 = 0; \
    else if (value >= ((activeMax) - mode)) s->unk_20 = (activeMax) - mode; \
    s->unk_18 = (f32)((capExpr) - mode); \
} while (0)

void fn_1_14A328(void) {
    State *s = (State *)&lbl_1_bss_8E518;
    if ((s32)lbl_1_bss_25BA0.unk_0 != 0) return;
    if (((lbl_1_bss_9F8.unk_8 >> 8) & 1) == 0) return;
    if (lbl_1_bss_3C30.unk_0 & 0x04000000) {
        int count = lbl_1_bss_3C30.unk_9;
        if (count < 2) {
            s->unk_5 = 8;
            return;
        }
        s->unk_5 = 7;
        s->unk_4 = 0;
        if (lbl_1_bss_960 == 1) s->unk_30 = 4;
        else s->unk_30 = count < 6 ? count : 6;
        if (s->unk_28 != 0) {
            int index = fn_1_8623C();
            int mode = s->unk_30;
            int base = ((u8 *)&lbl_1_bss_3C30)[index * 0xA0 + lbl_1_bss_3C30.unk_A7];
            int target = ((u8 *)&lbl_1_bss_3C30)[index * 0xA0 + lbl_1_bss_3C30.unk_A7 + 0xE2];
            int value = target - (mode - 1);
            s->unk_20 = target;
            s->unk_20 = value;
            if (value < 0) s->unk_20 = 0;
            else if (value >= count - mode) s->unk_20 = count - mode;
            s->unk_18 = (f32)s->unk_20;
        } else {
            UPDATE(lbl_1_bss_3C30.unk_9, lbl_1_bss_3C30.unk_9, lbl_1_bss_3C30.unk_9);
        }
    } else {
        switch (lbl_1_bss_3C30.unk_5) {
        case 1:
            s->unk_5 = 1;
            s->unk_4 = 0;
            if (lbl_1_bss_960 == 1) s->unk_30 = 4;
            else s->unk_30 = lbl_1_bss_3C30.unk_9 < 6 ? lbl_1_bss_3C30.unk_9 : 6;
            if (s->unk_28 != 0) {
                int count = lbl_1_bss_3C30.unk_9;
                int index = fn_1_8623C();
                int mode = s->unk_30;
                int base = ((u8 *)&lbl_1_bss_3C30)[index * 0xA0 + lbl_1_bss_3C30.unk_A7];
                int target = ((u8 *)&lbl_1_bss_3C30)[index * 0xA0 + lbl_1_bss_3C30.unk_A7 + 0xE2];
                int value = target - (mode - 1);
                s->unk_20 = target;
                s->unk_20 = value;
                if (value < 0) s->unk_20 = 0;
                else if (value >= count - mode) s->unk_20 = count - mode;
                s->unk_18 = (f32)s->unk_20;
            } else {
                UPDATE(lbl_1_bss_3C30.unk_9, lbl_1_bss_3C30.unk_9, lbl_1_bss_3C30.unk_9);
            }
            break;
        case 0:
        case 6:
            s->unk_5 = 3;
            s->unk_4 = 0;
            if (lbl_1_bss_960 == 1) s->unk_30 = 4;
            else s->unk_30 = lbl_1_bss_3C30.unk_9 < 6 ? lbl_1_bss_3C30.unk_9 : 6;
            if (s->unk_28 != 0) {
                int count = lbl_1_bss_3C30.unk_9;
                int index = fn_1_8623C();
                int mode = s->unk_30;
                int base = ((u8 *)&lbl_1_bss_3C30)[index * 0xA0 + lbl_1_bss_3C30.unk_A7];
                int target = ((u8 *)&lbl_1_bss_3C30)[index * 0xA0 + lbl_1_bss_3C30.unk_A7 + 0xE2];
                int value = target - (mode - 1);
                s->unk_20 = target;
                s->unk_20 = value;
                if (value < 0) s->unk_20 = 0;
                else if (value >= count - mode) s->unk_20 = count - mode;
                s->unk_18 = (f32)s->unk_20;
            } else {
                UPDATE(lbl_1_bss_3C30.unk_9, lbl_1_bss_3C30.unk_9, lbl_1_bss_3C30.unk_9);
            }
            break;
        case 2: s->unk_5 = 6; break;
        default: s->unk_5 = 8; break;
        }
    }
}
