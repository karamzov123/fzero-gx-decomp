#include "types.h"

typedef struct Fn8006B92CData {
    u8 pad_0[0xF4];
    void *items[64];
    u8 pad_1F4[0x1000];
    u32 unk_11F4;
} Fn8006B92CData;

extern u32 lbl_801A6C8C;
extern void fn_8006C7E8(void *arg0, void *arg1);
extern void fn_8006B99C(void);

#pragma optimize_for_size on
void fn_8006B92C(Fn8006B92CData *arg0) {
    s32 i;

    fn_8006C7E8(arg0, arg0);
    arg0->unk_11F4 = 0xFF;
    for (i = 0; i < 64; i++) {
        arg0->items[i] = 0;
    }
    if ((s32)lbl_801A6C8C == 0) {
        fn_8006B99C();
        lbl_801A6C8C = 1;
    }
}
