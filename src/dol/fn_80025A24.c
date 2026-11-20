#include "types.h"

typedef struct Fn80025A24State {
    u32 unk_00;
    u32 unk_04;
    u32 unk_08;
    u32 unk_0C;
    u32 unk_10;
    u32 unk_14;
    u32 unk_18;
    u32 unk_1C;
    u32 unk_20;
    u32 unk_24;
    u32 unk_28;
    u32 unk_2C;
    u32 unk_30;
    u32 unk_34;
    u32 unk_38;
    u32 unk_3C;
    u32 unk_40;
    u32 unk_44;
    u32 unk_48;
    u32 unk_4C;
    u32 unk_50;
    u32 unk_54;
    u32 unk_58;
    u32 unk_5C;
} Fn80025A24State;

extern void fn_80025C70(Fn80025A24State *state);
extern u32 (*lbl_801A64F8)(u32);
extern BOOL OSDisableInterrupts(void);
extern BOOL OSRestoreInterrupts(BOOL);

s32 fn_80025A24(Fn80025A24State *arg0) {
    u32 i;
    u32 j;
    u32 t0;
    u32 *p0;
    u32 *p1;
    u32 *p2;
    s32 old;

    fn_80025C70(arg0);
    old = OSDisableInterrupts();

    arg0->unk_00 = (((arg0->unk_3C - 5) << 5) + 0x9f) / 160;
    arg0->unk_0C = 0;
    arg0->unk_18 = (arg0->unk_48 << 7) / 100;
    arg0->unk_24 = (arg0->unk_54 << 7) / 100;

    arg0->unk_04 = (((arg0->unk_40 - 5) << 5) + 0x9f) / 160;
    arg0->unk_10 = 0;
    arg0->unk_1C = (arg0->unk_4C << 7) / 100;
    arg0->unk_28 = (arg0->unk_58 << 7) / 100;

    arg0->unk_08 = (((arg0->unk_44 - 5) << 5) + 0x9f) / 160;
    arg0->unk_14 = 0;
    arg0->unk_20 = (arg0->unk_50 << 7) / 100;
    arg0->unk_2C = (arg0->unk_5C << 7) / 100;

    arg0->unk_30 = lbl_801A64F8(arg0->unk_00 * 0x280);
    arg0->unk_34 = lbl_801A64F8(arg0->unk_04 * 0x280);
    arg0->unk_38 = lbl_801A64F8(arg0->unk_08 * 0x280);

    p0 = (u32 *)arg0->unk_30;
    p1 = (u32 *)arg0->unk_34;
    p2 = (u32 *)arg0->unk_38;

    for (i = 0; i < arg0->unk_00 * 0xa0; i++) {
        *p0++ = 0;
    }
    i = 0;
    while (i < arg0->unk_04 * 0xa0) {
        *p1++ = 0;
        i++;
    }
    i = 0;
    while (i < arg0->unk_08 * 0xa0) {
        *p2++ = 0;
        i++;
    }

    OSRestoreInterrupts(old);
    return 1;
}
