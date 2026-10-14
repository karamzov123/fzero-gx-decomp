/* Non-matching: best partial attempt (97.19% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"

typedef struct {
    u8 pad0[0x14];
    s32 state;
} SelState;

typedef struct {
    u8 pad0[0x94];
    u32 flags94;
    u8 pad98[0xc];
    u8 *object;
    u8 padA8[0x98];
    u32 flags140;
} GlobalSel;

extern u8 lbl_10_bss_0[];
extern GlobalSel lbl_1_bss_8B3A0;
extern s16 lbl_1_bss_96A;
extern u32 lbl_1_bss_6EAB4;

extern s32 fn_1_4C10(void);
extern u8 fn_1_D6688(void);
extern u32 fn_1_12F258(void);
extern void fn_1_A2D84(u32);
extern s32 fn_1_12F228(void);
extern void fn_1_4A00(u32, u32, u32);
extern u8 fn_10_8780(void);

static inline u8 *fn_10_8600_array_read(u8 *array) { return array; }
#pragma opt_propagation on
static inline u8 fn_10_8600_array_read_(s32 index, u8 *array) { return array[index]; }
void fn_10_8600(void) {
    u8 result;
    s32 ready;
    u8 *obj;
    u8 *far;

    far = lbl_10_bss_0 + 0x50000;

    if (((SelState *)lbl_10_bss_0)->state == -1) {
        fn_1_4C10();
    }

    if ((lbl_1_bss_8B3A0.flags140 & 0x80000000) != 0 &&
        (lbl_1_bss_8B3A0.flags140 & 0x40000000) == 0 &&
        (lbl_1_bss_8B3A0.flags94 & 8) == 0) {
        ready = 1;
    } else {
        if (fn_1_4C10() != 0) {
            ready = 1;
        } else {
            ready = 0;
        }
    }

    if (ready == 0) {
        if (((SelState *)lbl_10_bss_0)->state != -1) {
            s16 value = (s16)((SelState *)lbl_10_bss_0)->state;
            ((SelState *)lbl_10_bss_0)->state = -1;
            lbl_1_bss_96A = value;
        } else {
            result = fn_1_D6688();
            if (result != 0 || fn_10_8600_array_read_(0x5600, far) < 0xb4) {
                if (((0) != (fn_10_8600_array_read_(0x5600, far)))) {
                    far[0x5600]--;
                }
            }
            if (fn_1_12F258() == 0x12c) {
                fn_1_A2D84(0xA9122100u);
            }
            if (fn_1_12F228() != 0) {
                far[0x5601] = 1;
                obj = lbl_1_bss_8B3A0.object;
                obj[0x19] = 1;
                if (result == 0) {
                    if (((0) != (fn_10_8600_array_read_(0x5600, far)))) {
                        return;
                    }
                }
                if (fn_10_8780() != 0) {
                    u32 arg5;
                    s16 value;
                    ((SelState *)lbl_10_bss_0)->state = 0xf;
                    arg5 = ((u32 *)far)[-0x6c78 / 4];
                    fn_1_4A00(0, (u8)(((s16 *)far)[-0x6c74 / 2]), arg5);
                    ((u32 *)far)[0x1744 / 4] = 0;
                    lbl_1_bss_6EAB4 |= 0x24;
                }
            }
        }
    }
}
#pragma opt_propagation reset

