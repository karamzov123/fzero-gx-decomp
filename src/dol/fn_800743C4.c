#include "types.h"

typedef struct {
    u8 pad[0xB04];
    u16 unk_B04;
    u16 unk_B06;
} State;

extern State *lbl_801A6D38;
extern void fn_80034B7C(u32, u32);

void fn_800743C4(s32 a, u32 b) {
    if (lbl_801A6D38->unk_B04 != (u16)a ||
        lbl_801A6D38->unk_B06 != (u16)b) {
        fn_80034B7C(a, b);
        lbl_801A6D38->unk_B04 = a;
        lbl_801A6D38->unk_B06 = b;
    }
}
