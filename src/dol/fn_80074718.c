#include "types.h"

typedef struct GlobalState {
    u8 unk_00[0x10];
    u8 unk_10;
    u8 unk_11[3];
    s32 unk_14;
} GlobalState;

extern GlobalState *lbl_801A6D38;
extern void GXSetPointSize(u8, s32);

void fn_80074718(u8 value, s32 arg) {
    if (lbl_801A6D38->unk_10 != value || lbl_801A6D38->unk_14 != arg) {
        GXSetPointSize(value, arg);
        lbl_801A6D38->unk_10 = value;
        lbl_801A6D38->unk_14 = arg;
    }
}
