#include "types.h"

extern const u32 lbl_12_rodata_C78[102];
extern s32 fn_12_24A88(void *, s32);

void fn_12_2CD8C(void) {
    if (lbl_12_rodata_C78[73] != 0x5A5A5A5A) {
        fn_12_24A88(0, 0xFF000201);
    }
}
