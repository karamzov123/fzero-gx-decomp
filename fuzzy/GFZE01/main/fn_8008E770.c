/* Non-matching: best partial attempt (92.43% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"
#include "dolphin/os/OSInterrupt.h"
#include "dolphin/types.h"

extern BOOL OSDisableInterrupts(void);
extern BOOL OSRestoreInterrupts(BOOL);
extern OSInterruptMask __OSUnmaskInterrupts(OSInterruptMask);
extern void fn_8008EB4C(s32, s32);

struct fn_8008E770_lbl_801A6678_T {
    s32 unk_0;
    u32 unk_4;
    u32 unk_8;
    volatile u32 unk_C;
    u32 unk_10;
    void *unk_14;
};

extern struct fn_8008E770_lbl_801A6678_T *lbl_801A6678;

static inline s16 fn_8008E770_array_read(s32 index, s16 *array) { return array[index]; }
BOOL fn_8008E770(s16 *data, s32 len, u32 flag, u32 val) {
    BOOL old;
    u32 shift;
    u32 acc;

    shift = 2;
    old = OSDisableInterrupts() + 0;
    if ((lbl_801A6678->unk_C & 3) || !(lbl_801A6678->unk_C & 4)) {
        OSRestoreInterrupts(old);
        return 0;
    }

    lbl_801A6678->unk_4 = val;
    if (lbl_801A6678->unk_4 != 0) {
        fn_8008EB4C(0, 1);
        __OSUnmaskInterrupts(0x200000u >> (shift * 3));
    }
    lbl_801A6678->unk_C |= 2;
    if (flag != 0) {
        s32 i = 0;
        acc = 0;
        while (i < len) {
            acc |= (u32)fn_8008E770_array_read(i, data) << ((3 - i) * 8);
            i++;
        }
        *(vu32 *)0xCC006838 = acc;
    }
    lbl_801A6678->unk_14 = data;
    lbl_801A6678->unk_10 = (flag != 1) ? len : 0;
    *(vu32 *)0xCC006834 = ((flag << 2) | 1) | ((len - 1) << 4);
    OSRestoreInterrupts(old);
    return 1;
}
